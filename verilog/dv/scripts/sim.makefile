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


IVERILOG_DUMPER = fst
SIM_DEFINES = -DFUNCTIONAL -DSIM

# RTL/GL/GL_SDF
SIM?=RTL

.SUFFIXES:


all:  ${BLOCKS:=.vcd} ${BLOCKS:=.lst} 

hex:  ${BLOCKS:=.hex}

#.SUFFIXES:

##############################################################################
# Comiple firmeware
##############################################################################

%.elf: %.c $(LINKER_SCRIPT) $(SOURCE_FILES) check-env
	${GCC_PATH}/${GCC_PREFIX}-gcc \
	-I$(FIRMWARE_PATH) \
	-I$(VERILOG_PATH)/dv/generated \
	-I$(VERILOG_PATH)/common \
	  $(CPUFLAGS) \
	-Wl,-Bstatic,-T,$(LINKER_SCRIPT),--strip-debug \
	-ffreestanding -nostdlib -o $@ $(SOURCE_FILES) $<

%.lst: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objdump -D $< > $@

%.hex: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objcopy -O verilog $< $@ 
	# to fix flash base address
	sed -i 's/@10/@00/g' $@

%.bin: %.elf
	${GCC_PATH}/${GCC_PREFIX}-objcopy -O binary $< /dev/stdout | tail -c +1048577 > $@
	
	
##############################################################################
# Runing the simulations
##############################################################################

%.vvp: %_tb.v %.hex

## RTL
ifeq ($(SIM),RTL)
	iverilog -Ttyp $(SIM_DEFINES) \
	-I$(PDK_PATH) \
        -f$(VERILOG_PATH)/common/includes.rtl.$(CONFIG) \
	$< -o $@ 
endif 

## GL
ifeq ($(SIM),GL)
	iverilog -Ttyp $(SIM_DEFINES) -DGL -DUSE_POWER_PINS \
	-I$(PDK_PATH) \
        -f$(VERILOG_PATH)/common/includes.gl.$(CONFIG) \
	$< -o $@ 
endif 

## GL+SDF
ifeq ($(SIM),GL_SDF)
	$(eval VIP_PATH := $(shell realpath --relative-to=$(shell pwd) $(VIP_PATH)))
	$(eval COMMON_ABSOLUTE_PATH := $(shell realpath --relative-to=$(shell pwd) $(VERILOG_PATH)/common))
	$(eval PDK_ABSOLUTE_PATH := $(shell realpath --relative-to=$(shell pwd) $(PDK_PATH)))
	$(eval RTL_ABSOLUTE_PATH := $(shell realpath --relative-to=$(shell pwd) $(VERILOG_PATH)/rtl))
	$(eval VERILOG_ABSOLUTE_PATH := $(shell realpath --relative-to=$(shell pwd) $(VERILOG_PATH)))
	$(eval CARAVEL_VERILOG_ABSOLUTE_PATH := $(shell realpath --relative-to=$(shell pwd) $(CARAVEL_VERILOG_PATH)))
	$(eval CURRENT_DIRECTORY := $(shell pwd))
	
	cvc +interp +incdir+$(COMMON_ABSOLUTE_PATH)+$(VIP_PATH)+$(VERILOG_ABSOLUTE_PATH)+$(RTL_ABSOLUTE_PATH)+$(PDK_ABSOLUTE_PATH) \
	    +define+FUNCTIONAL +define+SIM +define+GL +define+USE_POWER_PINS +define+ENABLE_SDF +change_port_type +dump2fst \
	    -f $(VERILOG_PATH)/common/includes.gl+sdf.standalone  $<
	    
	    	cvc +interp +incdir+$(BEHAVIOURAL_MODELS_PATH)+$(RTL_ABSOLUTE_PATH)+$(VERILOG_ABSOLUTE_PATH)+$(PDK_ABSOLUTE_PATH)+$(CURRENT_DIRECTORY) \
	 	+define+FUNCTIONAL +define+SIM +define+GL +define+USE_POWER_PINS +define+ENABLE_SDF +change_port_type +dump2fst $<

endif

%.vcd: %.vvp

ifeq ($(SIM),RTL)
	vvp $<
	 mv $@ RTL-$@
endif
ifeq ($(SIM),GL)
	vvp $<
	 mv $@ GL-$@
endif
ifeq ($(SIM),GL_SDF)
	vvp $<
	 mv $@ GL_SDF-$@.vcd 
endif


check-env:
ifndef PDK_ROOT
	$(error PDK_ROOT is undefined, please export it before running make)
endif
ifeq (,$(wildcard $(PDK_ROOT)/sky130A))
	$(error $(PDK_ROOT)/sky130A not found, please install pdk before running make)
endif
ifeq (,$(wildcard $(GCC_PATH)/$(GCC_PREFIX)-gcc ))
	$(error $(GCC_PATH)/$(GCC_PREFIX)-gcc is not found, please export GCC_PATH and GCC_PREFIX before running make)
endif
# check for efabless style installation
ifeq (,$(wildcard $(PDK_ROOT)/sky130A/libs.ref/*/verilog))
SIM_DEFINES := ${SIM_DEFINES} -DEF_STYLE
endif


# ---- Clean ----

clean:
	rm -f *.elf *.hex *.bin *.vvp *.vcd *.log

.PHONY: clean hex all



