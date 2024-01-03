## MASTER CLOCKS
create_clock [get_ports core_clk]  -name core_clk  -period 25
# create_clock [get_ports tck]  -name tck -period 200

# set_clock_groups -logically_exclusive -group core_clk -group tck

set_propagated_clock [all_clocks]

## FALSE PATHS
set_false_path -from [get_port core_rstn]

## INPUT/OUTPUT DELAYS
set input_delay_value 5
set output_delay_value 5
# set output_delay_value 20
puts "\[INFO\]: Setting output delay to: $output_delay_value"
puts "\[INFO\]: Setting input delay to: $input_delay_value"

## HK INPUTS 
set hk_min_input_delay 2 
set_input_delay 1 -clock [get_clocks core_clk] [get_ports irq[*]]
set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports flash_io0_di]
set_input_delay 3 -clock [get_clocks core_clk] [get_ports flash_io1_di]
set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports flash_io2_di]
set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports flash_io3_di]
set_input_delay 1.1 -clock [get_clocks core_clk] [get_ports hk_dat_i[*]]
set_input_delay 1.1 -clock [get_clocks core_clk] [get_ports hk_ack_i]
set_input_delay 5.80 -clock [get_clocks core_clk] [get_ports spi_sdi]
set_input_delay 5.60 -clock [get_clocks core_clk] [get_ports debug_in]
# set_input_delay $hk_min_input_delay -clock [get_clocks core_clk] [get_ports sram_ro_clk]
# set_input_delay $hk_min_input_delay -clock [get_clocks core_clk] [get_ports sram_ro_csb]
# set_input_delay $hk_min_input_delay -clock [get_clocks core_clk] [get_ports sram_ro_addr[*]]


## USER PROJECT WRAPPER INPUTS
set user_input_delay 3 
set_input_delay $user_input_delay -clock [get_clocks core_clk] [get_ports la_input[*]]
set_input_delay $user_input_delay -clock [get_clocks core_clk] [get_ports mprj_ack_i]
set_input_delay $user_input_delay -clock [get_clocks core_clk] [get_ports mprj_dat_i[*]]

## PADFRAME INPUTS
set padframe_input_delay 3 
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
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mgmt_soc_dff_A[*]}]
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mgmt_soc_dff_Di[*]}]
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mgmt_soc_dff_EN}]
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {mgmt_soc_dff_WE[*]}]
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
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {sram_ro_addr[*]}]
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {sram_ro_clk}]
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {sram_ro_csb}]
# set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {sram_ro_data[*]}]
set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {trap}]
set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {uart_enabled}]
set_output_delay $output_delay_value -clock [get_clocks core_clk] -add_delay [get_ports {user_irq_ena[*]}]

## INPUT DRIVER
#set_driving_cell -lib_cell $::env(SYNTH_DRIVING_CELL) -pin $::env(SYNTH_DRIVING_CELL_PIN) [all_inputs]
set cap_load 0.15
puts "\[INFO\]: Setting load to: $cap_load"
set_load $cap_load [all_outputs]

set_clock_uncertainty 0.250 [get_clocks core_clk]
# set_clock_uncertainty 0.5 [get_clocks tck]

# set ::env(SYNTH_CLOCK_TRANSITION) 0.5
# puts "\[INFO\]: Setting clock transition to: $::env(SYNTH_CLOCK_TRANSITION)"
# set_clock_transition $::env(SYNTH_CLOCK_TRANSITION) [get_clocks core_clk]
set_driving_cell -lib_cell sky130_fd_sc_hd__clkbuf_4 -pin {X} [all_inputs]

puts "\[INFO\]: Setting timing derate to: [expr {$::env(SYNTH_TIMING_DERATE) * 10}] %"
set_timing_derate -early 0.95
set_timing_derate -late 1.05
set_max_fanout 20 [current_design]

set_max_transition 0.75 [current_design]
set_max_transition 0.5 [get_clocks core_clk] -clock_path
# set clk_input [get_port core_clk)]
# set clk_indx [lsearch [all_inputs] $clk_input]
# set all_inputs_wo_clk [lreplace [all_inputs] $clk_indx $clk_indx ""]

# set_input_transition 5.0 $all_inputs_wo_clk
