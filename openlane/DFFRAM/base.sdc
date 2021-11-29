create_clock [get_ports $::env(CLOCK_PORT)]  -name $::env(CLOCK_PORT)  -period $::env(CLOCK_PERIOD)
set_propagated_clock [get_clocks $::env(CLOCK_PORT)]

set input_delay_value [expr $::env(CLOCK_PERIOD) * $::env(IO_PCT)]
set output_delay_value [expr $::env(CLOCK_PERIOD) * $::env(IO_PCT)]
puts "\[INFO\]: Setting output delay to: $output_delay_value"
puts "\[INFO\]: Setting input delay to: $input_delay_value"

set_max_fanout $::env(SYNTH_MAX_FANOUT) [current_design]

### MANAGEMENT CORE INPUTS

# ADRESS
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[0]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[1]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[2]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[3]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[4]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[5]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[6]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {A[7]}]

## DATA IN
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[0]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[10]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[11]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[12]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[13]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[14]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[15]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[16]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[17]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[18]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[19]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[1]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[20]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[21]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[22]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[23]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[24]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[25]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[26]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[27]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[28]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[29]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[2]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[30]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[31]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[3]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[4]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[5]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[6]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[7]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[8]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {Di[9]}]

## ENABLE
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {EN}]

## WRITE ENABLE
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[0]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[1]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[2]}]
set_input_delay 5.0000 -clock [get_clocks {CLK}] -add_delay [get_ports {WE[3]}]

## OUTPUT DELAY
set_output_delay $output_delay_value  -clock [get_clocks $::env(CLOCK_PORT)] [all_outputs]

# TODO set this as parameter
set_driving_cell -lib_cell $::env(SYNTH_DRIVING_CELL) -pin $::env(SYNTH_DRIVING_CELL_PIN) [all_inputs]
set cap_load [expr $::env(SYNTH_CAP_LOAD) / 1000.0]
puts "\[INFO\]: Setting load to: $cap_load"
set_load  $cap_load [all_outputs]

puts "\[INFO\]: Setting timing derate to: [expr {$::env(SYNTH_TIMING_DERATE) * 10}] %"
set_timing_derate -early [expr {1-$::env(SYNTH_TIMING_DERATE)}]
set_timing_derate -late [expr {1+$::env(SYNTH_TIMING_DERATE)}]