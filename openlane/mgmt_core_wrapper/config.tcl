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


set ::env(DESIGN_NAME) mgmt_core_wrapper

set ::env(CLOCK_PORT) "core_clk"
set ::env(CLOCK_NET) "core_clk"
set ::env(CLOCK_PERIOD) "25"

set ::env(RESET_PORT) "core_rstn"

set ::env(BASE_SDC_FILE) $::env(DESIGN_DIR)/base.sdc 

set ::env(SYNTH_STRATEGY) "DELAY 0"
set ::env(SYNTH_MAX_FANOUT) 8
set ::env(SYNTH_READ_BLACKBOX_LIB) 1


set ::env(FP_PIN_ORDER_CFG) $::env(DESIGN_DIR)/pin_order.cfg
set ::env(FP_SIZING) absolute
set ::env(DIE_AREA) "0 0 2620 820"

set ::env(MACRO_PLACEMENT_CFG) $::env(DESIGN_DIR)/macro_placement.cfg
set ::env(PL_TARGET_DENSITY) 0.1
set ::env(PL_TIME_DRIVEN) 0
set ::env(DPL_CELL_PADDING) 2
set ::env(GPL_CELL_PADDING) 2

set ::env(LEFT_MARGIN_MULT) 22
set ::env(RIGHT_MARGIN_MULT) 22
set ::env(TOP_MARGIN_MULT) "5"
set ::env(BOTTOM_MARGIN_MULT) "5"

## PDN
set ::env(FP_PDN_CORE_RING) 1
set ::env(FP_PDN_VPITCH) 50
set ::env(FP_PDN_HPITCH) 130

set ::env(FP_PDN_VWIDTH) 1.6
set ::env(FP_PDN_CORE_RING_VWIDTH) 1.6

## CTS
set ::env(CTS_CLK_BUFFER_LIST) "sky130_fd_sc_hd__clkbuf_4 sky130_fd_sc_hd__clkbuf_8 sky130_fd_sc_hd__clkbuf_16"
set ::env(CTS_SINK_CLUSTERING_MAX_DIAMETER) 50
set ::env(CTS_SINK_CLUSTERING_SIZE) 20

## Placement
set ::env(PL_RESIZER_DESIGN_OPTIMIZATIONS) 0
set ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) 0

set ::env(PL_RESIZER_MAX_SLEW_MARGIN) 2
set ::env(PL_RESIZER_MAX_CAP_MARGIN) 2

## Routing
set ::env(GRT_OVERFLOW_ITERS) 200

set ::env(PL_RESIZER_HOLD_SLACK_MARGIN) 0.2
set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) 0
set ::env(GLB_RESIZER_HOLD_SLACK_MARGIN) 0.3

## Diode Insertion
set ::env(DIODE_INSERTION_STRATEGY) 4

## Internal Macros
set ::env(VERILOG_FILES_BLACKBOX) "\
    $::env(MCW_ROOT)/verilog/gl/DFFRAM.v"

set ::env(EXTRA_LEFS) "\
    $::env(MCW_ROOT)/lef/DFFRAM.lef"

set ::env(EXTRA_GDS_FILES) "\
    $::env(MCW_ROOT)/gds/DFFRAM.gds"

set ::env(VERILOG_FILES) "\
    $::env(MCW_ROOT)/verilog/rtl/mgmt_core_wrapper.v
    $::env(MCW_ROOT)/verilog/rtl/defines.v \
    $::env(MCW_ROOT)/verilog/rtl/mgmt_core.v \
    $::env(MCW_ROOT)/verilog/rtl/picorv32.v \
    $::env(MCW_ROOT)/verilog/rtl/ibex_all.v \
    $::env(MCW_ROOT)/verilog/rtl/VexRiscv_MinDebugCache.v"


set ::env(QUIT_ON_MAGIC_DRC) 0
set ::env(QUIT_ON_TIMING_VIOLATIONS) 0
set ::env(QUIT_ON_LVS_ERROR) 0
set ::env(STA_REPORT_POWER) 0
set ::env(RUN_IRDROP_REPORT) 0
set ::env(FP_PDN_CHECK_NODES) 0

set ::env(GRT_ADJUSTMENT) "0.22"
set ::env(PL_TARGET_DENSITY) "0.35"

set ::env(FP_PDN_MACRO_HOOKS) "DFFRAM VPWR VGND VPWR VGND, DFFRAM_1 VPWR VGND VPWR VGND"
