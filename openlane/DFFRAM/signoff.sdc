###############################################################################
# Created by write_sdc
# Fri Oct  7 15:04:45 2022
###############################################################################
# current_design DFFRAM
###############################################################################
# Timing Constraints
###############################################################################
create_clock -name CLK -period 25.0000 [get_ports {CLK}]
set_clock_transition 0.2500 [get_clocks {CLK}]
set_clock_uncertainty 0.3000 CLK
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[0]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[1]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[2]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[3]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[4]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[5]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[6]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[7]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[0]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[10]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[11]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[12]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[13]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[14]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[15]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[16]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[17]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[18]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[19]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[1]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[20]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[21]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[22]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[23]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[24]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[25]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[26]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[27]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[28]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[29]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[2]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[30]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[31]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[3]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[4]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[5]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[6]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[7]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[8]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[9]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {EN}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[0]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[1]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[2]}]
set_input_delay 1.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[3]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[0]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[10]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[11]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[12]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[13]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[14]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[15]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[16]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[17]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[18]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[19]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[1]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[20]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[21]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[22]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[23]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[24]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[25]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[26]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[27]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[28]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[29]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[2]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[30]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[31]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[3]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[4]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[5]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[6]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[7]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[8]}]
set_output_delay 22.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Do[9]}]
###############################################################################
# Environment
###############################################################################
set_load -pin_load 0.1500 [get_ports {Do[31]}]
set_load -pin_load 0.1500 [get_ports {Do[30]}]
set_load -pin_load 0.1500 [get_ports {Do[29]}]
set_load -pin_load 0.1500 [get_ports {Do[28]}]
set_load -pin_load 0.1500 [get_ports {Do[27]}]
set_load -pin_load 0.1500 [get_ports {Do[26]}]
set_load -pin_load 0.1500 [get_ports {Do[25]}]
set_load -pin_load 0.1500 [get_ports {Do[24]}]
set_load -pin_load 0.1500 [get_ports {Do[23]}]
set_load -pin_load 0.1500 [get_ports {Do[22]}]
set_load -pin_load 0.1500 [get_ports {Do[21]}]
set_load -pin_load 0.1500 [get_ports {Do[20]}]
set_load -pin_load 0.1500 [get_ports {Do[19]}]
set_load -pin_load 0.1500 [get_ports {Do[18]}]
set_load -pin_load 0.1500 [get_ports {Do[17]}]
set_load -pin_load 0.1500 [get_ports {Do[16]}]
set_load -pin_load 0.1500 [get_ports {Do[15]}]
set_load -pin_load 0.1500 [get_ports {Do[14]}]
set_load -pin_load 0.1500 [get_ports {Do[13]}]
set_load -pin_load 0.1500 [get_ports {Do[12]}]
set_load -pin_load 0.1500 [get_ports {Do[11]}]
set_load -pin_load 0.1500 [get_ports {Do[10]}]
set_load -pin_load 0.1500 [get_ports {Do[9]}]
set_load -pin_load 0.1500 [get_ports {Do[8]}]
set_load -pin_load 0.1500 [get_ports {Do[7]}]
set_load -pin_load 0.1500 [get_ports {Do[6]}]
set_load -pin_load 0.1500 [get_ports {Do[5]}]
set_load -pin_load 0.1500 [get_ports {Do[4]}]
set_load -pin_load 0.1500 [get_ports {Do[3]}]
set_load -pin_load 0.1500 [get_ports {Do[2]}]
set_load -pin_load 0.1500 [get_ports {Do[1]}]
set_load -pin_load 0.1500 [get_ports {Do[0]}]
set_input_transition 5.0000 [get_ports {EN}]
set_input_transition 5.0000 [get_ports {A[7]}]
set_input_transition 5.0000 [get_ports {A[6]}]
set_input_transition 5.0000 [get_ports {A[5]}]
set_input_transition 5.0000 [get_ports {A[4]}]
set_input_transition 5.0000 [get_ports {A[3]}]
set_input_transition 5.0000 [get_ports {A[2]}]
set_input_transition 5.0000 [get_ports {A[1]}]
set_input_transition 5.0000 [get_ports {A[0]}]
set_input_transition 5.0000 [get_ports {Di[31]}]
set_input_transition 5.0000 [get_ports {Di[30]}]
set_input_transition 5.0000 [get_ports {Di[29]}]
set_input_transition 5.0000 [get_ports {Di[28]}]
set_input_transition 5.0000 [get_ports {Di[27]}]
set_input_transition 5.0000 [get_ports {Di[26]}]
set_input_transition 5.0000 [get_ports {Di[25]}]
set_input_transition 5.0000 [get_ports {Di[24]}]
set_input_transition 5.0000 [get_ports {Di[23]}]
set_input_transition 5.0000 [get_ports {Di[22]}]
set_input_transition 5.0000 [get_ports {Di[21]}]
set_input_transition 5.0000 [get_ports {Di[20]}]
set_input_transition 5.0000 [get_ports {Di[19]}]
set_input_transition 5.0000 [get_ports {Di[18]}]
set_input_transition 5.0000 [get_ports {Di[17]}]
set_input_transition 5.0000 [get_ports {Di[16]}]
set_input_transition 5.0000 [get_ports {Di[15]}]
set_input_transition 5.0000 [get_ports {Di[14]}]
set_input_transition 5.0000 [get_ports {Di[13]}]
set_input_transition 5.0000 [get_ports {Di[12]}]
set_input_transition 5.0000 [get_ports {Di[11]}]
set_input_transition 5.0000 [get_ports {Di[10]}]
set_input_transition 5.0000 [get_ports {Di[9]}]
set_input_transition 5.0000 [get_ports {Di[8]}]
set_input_transition 5.0000 [get_ports {Di[7]}]
set_input_transition 5.0000 [get_ports {Di[6]}]
set_input_transition 5.0000 [get_ports {Di[5]}]
set_input_transition 5.0000 [get_ports {Di[4]}]
set_input_transition 5.0000 [get_ports {Di[3]}]
set_input_transition 5.0000 [get_ports {Di[2]}]
set_input_transition 5.0000 [get_ports {Di[1]}]
set_input_transition 5.0000 [get_ports {Di[0]}]
set_input_transition 5.0000 [get_ports {WE[3]}]
set_input_transition 5.0000 [get_ports {WE[2]}]
set_input_transition 5.0000 [get_ports {WE[1]}]
set_input_transition 5.0000 [get_ports {WE[0]}]
# set_timing_derate -early 0.9500
# set_timing_derate -late 1.0500
###############################################################################
# Design Rules
###############################################################################
