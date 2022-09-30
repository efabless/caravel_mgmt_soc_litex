// VIP
`include "caravel_mgmt_soc_litex/verilog/dv/vip/tbuart.v"
`include "caravel_mgmt_soc_litex/verilog/dv/vip/spiflash.v"
`include "caravel_mgmt_soc_litex/verilog/dv/vip/wb_rw_test.v"

// DFFRAM Behavioral Model
`include "caravel_mgmt_soc_litex/verilog/dv/vip/DFFRAM.v"

// DFFRAM Full RTL
// `include "caravel_mgmt_soc_litex/verilog/rtl/DFFRAM.v"
// `include "caravel_mgmt_soc_litex/verilog/rtl/DFFRAMBB.v"

// Mgmt Core Wrapper
`include "caravel_mgmt_soc_litex/verilog/rtl/defines.v"
`include "caravel_mgmt_soc_litex/verilog/rtl/mgmt_core.v"
`include "caravel_mgmt_soc_litex/verilog/rtl/mgmt_core_wrapper.v"
`include "caravel_mgmt_soc_litex/verilog/rtl/VexRiscv_MinDebugCache.v"

// Caravel

// These blocks need to stay in RTL
`include "caravel/verilog/rtl/pads.v"			
`include "caravel/verilog/rtl/defines.v" 		     		
`include "caravel/verilog/rtl/user_defines.v"		     
`include "caravel/verilog/rtl/mprj_io.v"
`include "caravel/verilog/rtl/simple_por.v"		     

// These blocks only needed for RTL sims							     
`include "caravel/verilog/rtl/digital_pll_controller.v" 
`include "caravel/verilog/rtl/ring_osc2x13.v"		
`include "caravel/verilog/rtl/clock_div.v"
`include "caravel/verilog/rtl/housekeeping_spi.v"
					     
`include "caravel/verilog/rtl/chip_io.v" 		     
`include "caravel/verilog/rtl/mprj_logic_high.v" 	     
`include "caravel/verilog/rtl/mprj2_logic_high.v"	     
`include "caravel/verilog/rtl/mgmt_protect.v"		     
`include "caravel/verilog/rtl/mgmt_protect_hv.v" 	     
`include "caravel/verilog/rtl/gpio_control_block.v"	     
`include "caravel/verilog/rtl/gpio_defaults_block.v"	     
`include "caravel/verilog/rtl/gpio_logic_high.v" 	     
`include "caravel/verilog/rtl/xres_buf.v"		     
`include "caravel/verilog/rtl/spare_logic_block.v"	     
`include "caravel/verilog/rtl/housekeeping.v"		     
`include "caravel/verilog/rtl/caravel_clocking.v"	     
`include "caravel/verilog/rtl/digital_pll.v"		     
`include "caravel/verilog/rtl/__user_project_wrapper.v"
`include "caravel/verilog/rtl/user_id_programming.v"	     
`include "caravel/verilog/rtl/caravel.v" 		     

// These blocks are manually designed 		
`include "caravel/verilog/gl/gpio_defaults_block_0403.v"     
`include "caravel/verilog/gl/gpio_defaults_block_1803.v"     


// STD CELLS - they need to be below the defines.v" files 
 `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_fd_io/verilog/sky130_fd_io.v"
 `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_fd_io/verilog/sky130_ef_io.v"
 `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_fd_sc_hd/verilog/primitives.v"
 `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_fd_sc_hd/verilog/sky130_fd_sc_hd.v"
 `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_fd_sc_hvl/verilog/primitives.v"
 `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_fd_sc_hvl/verilog/sky130_fd_sc_hvl.v"
// `include "/home/rady/caravel/files4vcs/pdk/sky130A/libs.ref/sky130_sram_macros/verilog/sky130_sram_2kbyte_1rw1r_32x512_8.v"


// STD CELLS - they need to be below the defines.v" files 
// `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/sky130_ef_io.v"
// `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/sky130_fd_io.v"
// `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/primitives_hd.v"
// `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/sky130_fd_sc_hd.v"
// `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/primitives_hvl.v"
// `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/sky130_fd_sc_hvl.v"
 `include "caravel_mgmt_soc_litex/verilog/cvc-pdk/sky130_sram_2kbyte_1rw1r_32x512_8.v"

