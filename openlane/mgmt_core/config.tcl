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
# SPDX-License-Identifier: Apache-2.0

set script_dir [file dirname [file normalize [info script]]]

set ::env(ROUTING_CORES) "6"
set ::env(RUN_SIMPLE_CTS) "0"

set ::env(DESIGN_NAME) mgmt_core

set ::env(DESIGN_IS_CORE) 1

set ::env(RUN_KLAYOUT) 0

set ::env(CLOCK_PORT) "clk"
set ::env(CLOCK_NET) "clk"
set ::env(CLOCK_PERIOD) "25"

set ::env(SYNTH_STRATEGY) "DELAY 1"
set ::env(SYNTH_MAX_FANOUT) 6
set ::env(SYNTH_READ_BLACKBOX_LIB) 1

set ::env(FP_PDN_VPITCH) 50
set ::env(FP_PDN_HPITCH) 130

set ::env(FP_PIN_ORDER_CFG) $script_dir/pin_order.cfg
set ::env(FP_SIZING) absolute
set ::env(DIE_AREA) "0 0 2250 740"

set ::env(MACRO_PLACEMENT_CFG) $script_dir/macro_placement.cfg
set ::env(PL_TARGET_DENSITY) 0.215
set ::env(CELL_PAD) 0

# Disable resizer design optimizations to prevent adding a buffer after tristate cells
set ::env(PL_RESIZER_DESIGN_OPTIMIZATIONS) 1
set ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) 1
set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) 1

set ::env(PL_RESIZER_HOLD_SLACK_MARGIN) 0.25
set ::env(GLB_RESIZER_HOLD_SLACK_MARGIN) 0.25

set ::env(GLB_RT_ADJUSTMENT) 0
set ::env(GLB_RT_L2_ADJUSTMENT) 0.21
set ::env(GLB_RT_L3_ADJUSTMENT) 0.21
set ::env(GLB_RT_L4_ADJUSTMENT) 0.1
set ::env(GLB_RT_L5_ADJUSTMENT) 0.1
set ::env(GLB_RT_L6_ADJUSTMENT) 0.1
set ::env(GLB_RT_ALLOW_CONGESTION) 0
set ::env(GLB_RT_OVERFLOW_ITERS) 200

set ::env(DIODE_INSERTION_STRATEGY) 4

set ::env(VERILOG_FILES) "\
	$script_dir/../../verilog/rtl/defines.v\
	$script_dir/../../verilog/rtl/mgmt_core.v"

set ::env(VERILOG_FILES_BLACKBOX) "\
	$script_dir/../../verilog/rtl/defines.v\
	$::env(PDK_ROOT)/sky130A/libs.ref/sky130_sram_macros/verilog/sky130_sram_1kbyte_1rw1r_32x256_8.v"

set ::env(EXTRA_LEFS) "\
	$::env(PDK_ROOT)/sky130A/libs.ref/sky130_sram_macros/lef/sky130_sram_1kbyte_1rw1r_32x256_8.lef"

set ::env(EXTRA_GDS_FILES) "\
	$::env(PDK_ROOT)/sky130A/libs.ref/sky130_sram_macros/gds/sky130_sram_1kbyte_1rw1r_32x256_8.gds"

set ::env(EXTRA_LIBS) "\
	$::env(PDK_ROOT)/sky130A/libs.ref/sky130_sram_macros/lib/sky130_sram_1kbyte_1rw1r_32x256_8.lib"

set ::env(PL_RESIZER_MAX_SLEW_MARGIN) 0
set ::env(PL_RESIZER_MAX_CAP_MARGIN) 0