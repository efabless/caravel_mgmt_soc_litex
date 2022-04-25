# SPDX-FileCopyrightText: 2020 Efabless Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

export IVERILOG_DUMPER = fst

# RTL/GL/GL_SDF
SIM?=RTL
SIMS = RTL GL GL_SDF

VCDS = RTL.vcd GL.vcd
VVPS = $(foreach i,$(SIMS),$(i).vvp)
#all: GL.vcd
#ALL: $(VCDS) GL_SDF.vcd
.PHONY: all
all: $(SIM)



##############################################################################
# Runing the simulations
##############################################################################
.PHONY: RTL
.PHONY: RTL.vvp
RTL.vvp : $(BLOCKS)_tb.v $(BLOCKS).hex
	# this is RTL
ifeq ($(CONFIG),caravel_user_project)
	iverilog -Ttyp -DFUNCTIONAL -DSIM -DUSE_POWER_PINS -DUNIT_DELAY=#1 \
		-f$(VERILOG_PATH)/includes/includes.rtl.caravel \
		-f$(USER_PROJECT_VERILOG)/includes/includes.rtl.$(CONFIG) -o $@ $<
else
	iverilog -Ttyp -DFUNCTIONAL -DSIM -DUSE_POWER_PINS -DUNIT_DELAY=#1 \
		-f$(VERILOG_PATH)/includes/includes.rtl.$(CONFIG) \
		-f$(CARAVEL_PATH)/rtl/__user_project_wrapper.v -o $@ $<
endif

.PHONY: GL
.PHONY: GL.vvp
GL.vvp : $(BLOCKS)_tb.v $(BLOCKS).hex
	# this is gl
ifeq ($(CONFIG),caravel_user_project)
	iverilog -Ttyp -DFUNCTIONAL -DGL -DUSE_POWER_PINS -DUNIT_DELAY=#1 \
        -f$(VERILOG_PATH)/includes/includes.gl.caravel \
        -f$(USER_PROJECT_VERILOG)/includes/includes.gl.$(CONFIG) -o $@ $<
else
	iverilog -Ttyp -DFUNCTIONAL -DGL -DUSE_POWER_PINS -DUNIT_DELAY=#1 \
        -f$(VERILOG_PATH)/includes/includes.gl.$(CONFIG) \
		-f$(CARAVEL_PATH)/gl/__user_project_wrapper.v -o $@ $<
endif

.PHONY: GL_SDF
.PHONY: GL_SDF.vcd
GL_SDF.vcd : $(BLOCKS)_tb.v $(BLOCKS).hex
	# this is GL_SDF
ifeq ($(CONFIG),caravel_user_project)
	cvc64 +interp \
		+define+SIM +define+FUNCTIONAL +define+GL +define+USE_POWER_PINS +define+UNIT_DELAY +define+ENABLE_SDF \
		+change_port_type +dump2fst +fst+parallel2=on   +nointeractive \
		-f $(VERILOG_PATH)/includes/includes.gl+sdf.caravel \
		-f $(USER_PROJECT_VERILOG)/includes/includes.gl+sdf.$(CONFIG) $< | tee $@.log
else
	cvc64 +interp \
		+define+SIM +define+FUNCTIONAL +define+GL +define+USE_POWER_PINS +define+UNIT_DELAY +define+ENABLE_SDF \
		+change_port_type +dump2fst +fst+parallel2=on   +nointeractive \
		-f $(VERILOG_PATH)/includes/includes.gl+sdf.$(CONFIG) \
		-f $CARAVEL_PATH/gl/__user_project_wrapper.v $< | tee $@.log
endif
	echo "logged to $(realpath $@.log )"

GL_SDF : % : %.vcd
	# GL_SDF done simulation $(BLOCKS)


RTL GL : % : %.vcd
	# RTL GL done simulating $(BLOCKS)


RTL.vcd GL.vcd : %.vcd : %.vvp
	vvp $< | tee $<.log


##############################################################################
# Comiple firmeware
##############################################################################

%.elf: %.c $(LINKER_SCRIPT) $(SOURCE_FILES)
	${GCC_PATH}/${GCC_PREFIX}-gcc -g \
	-I$(FIRMWARE_PATH) \
	-I$(VERILOG_PATH)/dv/generated \
	-I$(VERILOG_PATH)/dv/ \
	-I$(VERILOG_PATH)/common \
	  $(CPUFLAGS) \
	-Wl,-Bstatic,-T,$(LINKER_SCRIPT),--strip-debug \
	-ffreestanding -nostdlib -o $@ $(SOURCE_FILES) $<

%.lst: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objdump -d -S $< > $@

%.hex: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objcopy -O verilog $< $@
	# to fix flash base address
	sed -ie 's/@10/@00/g' $@

%.bin: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objcopy -O binary $< /dev/stdout | tail -c +1048577 > $@



# ---- Clean ----

clean:
	rm  -f *.elf *.hex *.bin *.vvp *.log *.vcd *.lst *.hexe

.PHONY: clean hex all


