if {$::env(MODE) != "TEST"} {
    ## MASTER CLOCKS
    create_clock [get_ports core_clk]  -name core_clk  -period 25
    set_clock_uncertainty 0.1 [all_clocks]
    set_propagated_clock [all_clocks]

    ## FALSE PATHS
    set_false_path -from [get_port core_rstn]
    set_false_path -from [get_port trst]

    ## INPUT/OUTPUT DELAYS
    set input_delay_value 5
    set output_delay_value 5
    # set output_delay_value 20
    puts "\[INFO\]: Setting output delay to: $output_delay_value"
    puts "\[INFO\]: Setting input delay to: $input_delay_value"

    ## HK INPUTS 
    set hk_min_input_delay 3 
    set_input_delay $hk_min_input_delay -clock [get_clocks core_clk] [get_ports irq[*]]
    set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports flash_io0_di]
    set_input_delay 5.80 -clock [get_clocks core_clk] [get_ports flash_io1_di]
    set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports flash_io2_di]
    set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports flash_io3_di]
    set_input_delay 3.0 -clock [get_clocks core_clk] [get_ports hk_dat_i[*]]
    set_input_delay 3.0 -clock [get_clocks core_clk] [get_ports hk_ack_i]
    set_input_delay 5.80 -clock [get_clocks core_clk] [get_ports spi_sdi]
    set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports debug_in]


    ## USER PROJECT WRAPPER INPUTS
    set user_input_delay 5
    set_input_delay $user_input_delay -clock [get_clocks core_clk] [get_ports la_input[*]]
    set_input_delay $user_input_delay -clock [get_clocks core_clk] [get_ports mprj_ack_i]
    set_input_delay $user_input_delay -clock [get_clocks core_clk] [get_ports mprj_dat_i[*]]

    ## PADFRAME INPUTS
    set padframe_input_delay 4 
    set_input_delay $padframe_input_delay  -clock [get_clocks core_clk] [get_ports gpio_in_pad]

    ## OUTPUT DELAYS
    #set_output_delay $output_delay_value  -clock [get_clocks core_clk] [all_outputs]

    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {debug_mode}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {debug_oeb}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {debug_out}]

    set flash_output_delay 5 
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_clk}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_csb}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io0_do}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io0_oeb}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io1_do}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io1_oeb}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io2_do}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io2_oeb}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io3_do}]
    set_output_delay $flash_output_delay -clock [get_clocks core_clk] -add_delay [get_ports {flash_io3_oeb}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {gpio_inenb_pad}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {gpio_mode0_pad}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {gpio_mode1_pad}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {gpio_out_pad}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {gpio_outenb_pad}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {hk_cyc_o}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {hk_stb_o}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {la_iena[*]}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {la_oenb[*]}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {la_output[*]}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_adr_o[*]}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_cyc_o}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_dat_o[*]}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_sel_o[*]}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_stb_o}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_wb_iena}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mprj_we_o}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {qspi_enabled}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {ser_tx}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {spi_sck}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {spi_csb}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {spi_enabled}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {spi_sdo}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {spi_sdoenb}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {trap}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {uart_enabled}]
    set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {user_irq_ena[*]}]
}
## INPUT DRIVER
#set_driving_cell -lib_cell $::env(SYNTH_DRIVING_CELL) -pin $::env(SYNTH_DRIVING_CELL_PIN) [all_inputs]
set cap_load 0.1
puts "\[INFO\]: Setting load to: $cap_load"
set_load $cap_load [all_outputs]

# set ::env(SYNTH_CLOCK_TRANSITION) 0.5
# puts "\[INFO\]: Setting clock transition to: $::env(SYNTH_CLOCK_TRANSITION)"
# set_clock_transition $::env(SYNTH_CLOCK_TRANSITION) [get_clocks core_clk]
set_driving_cell -lib_cell sky130_fd_sc_hd__clkbuf_4 -pin {X} [all_inputs]

set derate 0.05
puts "\[INFO\]: Setting timing derate to: [expr {$derate * 100}] %"
set_timing_derate -early [expr {1 - $derate}]
set_timing_derate -late [expr {1 + $derate}]

set_max_transition 1.5 [current_design]

puts "\[INFO\]: Mode: $::env(MODE) operation"
if {$::env(MODE) == "TEST"} {
    set_case_analysis 1 [get_ports {tms}]
    set shift_pin [get_pins -of_objects "\__dut__.shift" -filter lib_pin_name==X]
    set_case_analysis 1 $shift_pin
    create_clock [get_ports tck]  -name tck -period 200
    set_clock_uncertainty 0.1 [get_clocks tck]

    set_clock_groups -logically_exclusive -group core_clk -group tck
    set_propagated_clock [all_clocks]
} else {
    set_case_analysis 0 [get_ports {tms}]
    set_case_analysis 0 [get_ports {tck}]
}