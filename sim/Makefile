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

VERILATOR_DIR=/usr/local/Cellar/verilator/4.200_1/share/verilator/include



sim: test.hex
	#iverilog -pfileline=1 -o test.vvp *.v
	iverilog -o test.vvp *.v
	vvp test.vvp

sim2: test.hex mgmt_soc.v mgmt_soc_tb.v
	#verilator --trace --top mgmt_soc_tb --timescale '1 ns / 1 ps' -cc *.v
	verilator --trace --top top --timescale '1 ns / 1 ps' -Wno-COMBDLY -Wno-WIDTH -Wno-CASEINCOMPLETE -Wno-PINMISSING -cc mgmt_soc.v picorv32.v
	make -C obj_dir/ -f Vtop.mk
	g++ -I obj_dir -I$(VERILATOR_DIR) testbench.cpp $(VERILATOR_DIR)/verilated.cpp $(VERILATOR_DIR)/verilated_vcd_c.cpp obj_dir/Vtop__ALL.a -Wc++11-extensions -o testbench

sim_cvc: test.hex mgmt_soc.v mgmt_soc_tb.v
	# run this first before using the target:  docker run --rm -it -v $(pwd):/data cvc
	cvc64 +interp *.v
	

test.elf: test.c start.s link.ld
	riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 -Wl,-Bstatic,-T,link.ld,--strip-debug -ffreestanding -nostdlib -mstrict-align -o $@  start.s test.c

test.bin: test.elf
	riscv64-unknown-elf-objcopy -O binary $<  $@

test.hex: test.elf
	riscv64-unknown-elf-objcopy -O verilog $<  $@
	riscv64-unknown-elf-objdump -D $< > test.lst

clean:
	rm -f *.elf *.hex *.bin *.vvp *.vcd *.log

.PHONY: clean hex all
