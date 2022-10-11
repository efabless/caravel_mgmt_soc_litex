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

package require openlane

variable SCRIPT_DIR [file dirname [file normalize [info script]]]
prep -design $SCRIPT_DIR -tag $::env(TAG) -overwrite -verbose 1
exec rm -rf $SCRIPT_DIR/runs/RAM256_interactive
exec ln -sf $SCRIPT_DIR/runs/$::env(TAG) $SCRIPT_DIR/runs/RAM256_interactive

set_netlist $::env(DESIGN_DIR)/RAM256.nl.v
set ::env(CURRENT_SDC) $::env(BASE_SDC_FILE)
init_floorplan
place_io_ol
#apply_def_template
tap_decap_or
run_power_grid_generation
global_placement_or
detailed_placement_or -def $::env(CURRENT_DEF) -log $::env(placement_logs)/detailed.log
ins_fill_cells
global_routing
detailed_routing
set detailed_routed_netlist [index_file $::env(routing_tmpfiles)/detailed.v]
write_verilog $detailed_routed_netlist -log $::env(routing_logs)/write_verilog_detailed.log
# for lvs
set_netlist $detailed_routed_netlist
run_parasitics_sta
run_irdrop_report
run_magic
run_magic_spice_export;
run_lvs; # requires run_magic_spice_export
run_magic_drc
run_antenna_check
run_lef_cvc
calc_total_runtime
save_final_views
save_final_views -save_path .. -tag $::env(RUN_TAG)
save_state
generate_final_summary_report
check_timing_violations

