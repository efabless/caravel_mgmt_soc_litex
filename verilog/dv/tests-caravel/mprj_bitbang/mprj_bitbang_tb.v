// SPDX-FileCopyrightText: 2020 Efabless Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// SPDX-License-Identifier: Apache-2.0

`default_nettype none
/*	
	Testbench of GPIO configuration through bit-bang method
	using the StriVe housekeeping SPI.
*/

`timescale 1 ns / 1 ps

// `include "__uprj_netlists.v"
//`include "caravel_netlists.v"
//`include "spiflash.v"
//`include "tbuart.v"

module mprj_bitbang_tb;
	reg clock;
	reg SDI, CSB, SCK, RSTB;
	reg power1, power2;

	wire gpio;
	wire [15:0] checkbits;
	wire [37:0] mprj_io;
	wire uart_tx;
	wire uart_rx;

	wire flash_csb;
	wire flash_clk;
	wire flash_io0;
	wire flash_io1;
	wire flash_io2;
	wire flash_io3;

	wire SDO;

	always #12.5 clock <= (clock === 1'b0);

	initial begin
		clock = 0;
	end

	initial begin		// Power-up sequence
		power1 <= 1'b0;
		power2 <= 1'b0;
		#200;
		power1 <= 1'b1;
		#200;
		power2 <= 1'b1;
	end

    // The main testbench is here.

    // First define tasks for SPI functions

	task start_csb;
	    begin
		SCK <= 1'b0;
		SDI <= 1'b0;
		CSB <= 1'b0;
		#50;
	    end
	endtask

	task end_csb;
	    begin
		SCK <= 1'b0;
		SDI <= 1'b0;
		CSB <= 1'b1;
		#50;
	    end
	endtask

	task write_byte;
	    input [7:0] odata;
	    begin
		SCK <= 1'b0;
		for (i=7; i >= 0; i=i-1) begin
		    #50;
		    SDI <= odata[i];
                    #50;
		    SCK <= 1'b1;
                    #100;
		    SCK <= 1'b0;
		end
	    end
	endtask

	task read_byte;
	    output [7:0] idata;
	    begin
		SCK <= 1'b0;
		SDI <= 1'b0;
		for (i=7; i >= 0; i=i-1) begin
		    #50;
                    idata[i] = SDO;
                    #50;
		    SCK <= 1'b1;
                    #100;
		    SCK <= 1'b0;
		end
	    end
	endtask

	task read_write_byte
	    (input [7:0] odata,
	    output [7:0] idata);
	    begin
		SCK <= 1'b0;
		for (i=7; i >= 0; i=i-1) begin
		    #50;
		    SDI <= odata[i];
                    idata[i] = SDO;
                    #50;
		    SCK <= 1'b1;
                    #100;
		    SCK <= 1'b0;
		end
	    end
	endtask

	task bitbang_one_clock;
	    begin
	        start_csb();
	        write_byte(8'h80);
	        write_byte(8'h13);
	        write_byte(8'h16);
	        end_csb();

	        start_csb();
	        write_byte(8'h80);
	        write_byte(8'h13);
	        write_byte(8'h06);
	        end_csb();
	    end
	endtask

	task bitbang_load;
	    begin
	        start_csb();
	        write_byte(8'h80);
	        write_byte(8'h13);
	        write_byte(8'h0e);
	        end_csb();

	        start_csb();
	        write_byte(8'h80);
	        write_byte(8'h13);
	        write_byte(8'h06);
	        end_csb();
	    end
	endtask

	task bitbang_thirteen_clocks;
	    begin
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
		bitbang_one_clock();
	    end
	endtask

	integer i;

    // Now drive the digital signals on the housekeeping SPI
	reg [7:0] tbdata;

	`ifdef ENABLE_SDF
		initial begin
			$sdf_annotate("../../../../sdf/DFFRAM.sdf", uut.soc.DFFRAM_0) ;
			$sdf_annotate("../../../../sdf/mgmt_core.sdf", uut.soc.core) ;
			$sdf_annotate("../../../../../caravel/sdf/housekeeping.sdf", uut.housekeeping) ;
			$sdf_annotate("../../../../../caravel/sdf/chip_io.sdf", uut.padframe) ;
			$sdf_annotate("../../../../../caravel/sdf/mprj_logic_high.sdf", uut.mgmt_buffers.mprj_logic_high_inst) ;
			$sdf_annotate("../../../../../caravel/sdf/mprj2_logic_high.sdf", uut.mgmt_buffers.mprj2_logic_high_inst) ;
			$sdf_annotate("../../../../../caravel/sdf/mgmt_protect_hv.sdf", uut.mgmt_buffers.powergood_check) ;
			$sdf_annotate("../../../../../caravel/sdf/mgmt_protect.sdf", uut.mgmt_buffers) ;
			$sdf_annotate("../../../../../caravel/sdf/caravel_clocking.sdf", uut.clocking) ;
			$sdf_annotate("../../../../../caravel/sdf/digital_pll.sdf", uut.pll) ;
			$sdf_annotate("../../../../../caravel/sdf/xres_buf.sdf", uut.rstb_level) ;
			$sdf_annotate("../../../../../caravel/sdf/user_id_programming.sdf", uut.user_id_value) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_bidir_1[0] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_bidir_1[1] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_bidir_2[1] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_bidir_2[2] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[0] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[1] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[2] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[3] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[4] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[5] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[6] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[7] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[8] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[9] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1[10] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1a[0] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1a[1] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1a[2] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1a[3] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1a[4] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_1a[5] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[0] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[1] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[2] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[3] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[4] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[5] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[6] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[7] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[8] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[9] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[10] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[11] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[12] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[13] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[14] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_control_block.sdf", uut.\gpio_control_in_2[15] ) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block_1803.sdf", uut.gpio_defaults_block_0) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block_1803.sdf", uut.gpio_defaults_block_1) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block_0403.sdf", uut.gpio_defaults_block_2) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block_0403.sdf", uut.gpio_defaults_block_3) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block_0403.sdf", uut.gpio_defaults_block_4) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_5) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_6) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_7) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_8) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_9) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_10) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_11) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_12) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_13) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_14) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_15) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_16) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_17) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_18) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_19) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_20) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_21) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_22) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_23) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_24) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_25) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_26) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_27) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_28) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_29) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_30) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_31) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_32) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_33) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_34) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_35) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_36) ;
			$sdf_annotate("../../../../../caravel/sdf/gpio_defaults_block.sdf", uut.gpio_defaults_block_37) ;
		end
	`endif

	initial begin
	    $dumpfile("mprj_bitbang.vcd");
	    $dumpvars(0, mprj_bitbang_tb);

	    CSB <= 1'b1;
	    SCK <= 1'b0;
	    SDI <= 1'b0;
	    RSTB <= 1'b0;

	    // Delay, then bring chip out of reset
	    #1000;
	    RSTB <= 1'b1;
	    #2000;

	    // Give 100us for the startup code to complete and the GPIO output
	    // value set.
	    #200000;

	    // NOTE:  The SPI takes precedence over the wishbone back-door
	    // access and the GPIO lines will not get set from the program
	    // while CSB is held low.  The C program keeps attempting a
	    // write and should succeed after the following code finishes
	    // and CSB is raised.

	    start_csb();
	    write_byte(8'h80);	// Write stream command
	    write_byte(8'h13);	// Address (register 19 = GPIO bit-bang control)
	    write_byte(8'h66);	// Data = 0x01 (enable bit-bang mode)
	    end_csb();

	    // Clock 12 times.  Set data when clock is zero.
	    // (NOTE:  Bits moved up by 1 compared to previous caravel version.
	    //  the testbench was updated by bit shifting all the data up by 1.)
	    // Bits: (0 = serial xfer)
	    //	      1 = bit-bang enable
	    //	      2 = bit-bang resetn
	    //	      3 = bit-bang load
	    //	      4 = bit-bang clock
	    //	      5 = bit-bang data user 1
	    //	      6 = bit-bang data user 2

	    // Apply data 0x1809 (management standard output) to
	    // first block of user 1 and user 2 (GPIO 0 and 37)
	    // bits 0, 1, 9, and 12 are "1" (data go in backwards)

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h76);	// bit 0
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h66);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h76);	// bit 1
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 2
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 3
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 4
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 5
	    end_csb();
		
	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 6
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 7
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 8
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h66);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h76);	// bit 9
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 10
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h16);	// bit 11
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h66);
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h76);	// bit 12
	    end_csb();

	    start_csb();
	    write_byte(8'h80);
	    write_byte(8'h13);
	    write_byte(8'h06);
	    end_csb();


	    // Toggle GPIO external control enable and clock forward 2 registers
	    // This moves ahead of the bidirectional registers at the front.
	    bitbang_thirteen_clocks();
	    bitbang_thirteen_clocks();
	    bitbang_thirteen_clocks();
	    bitbang_thirteen_clocks();
	    bitbang_thirteen_clocks();
	    bitbang_thirteen_clocks();
	    bitbang_load();

	    // There is no point in resetting bit bang mode because at
	    // this point the SPI pins just got disabled by loading zeros.

	    //#10000;
	    #5000;

	    // Timeout condition
		`ifdef GL
			$display("Monitor: Test GPIO bit-bang (GL) Failed");
		`else
			$display("Monitor: Test GPIO bit-bang (RTL) Failed");
		`endif

 	    $finish;
	end

	initial begin
	    // Wait for channel 31 to go high
	    wait(mprj_io[31] == 1'b1);

		`ifdef GL
			$display("Monitor: Test GPIO bit-bang (GL) Passed");
		`else
			$display("Monitor: Test GPIO bit-bang (RTL) Passed");
		`endif
		#1000
 	    $finish;
	end

	wire VDD3V3;
	wire VDD1V8;
	wire VSS;

	assign VDD3V3 = power1;
	assign VDD1V8 = power2;
	assign VSS = 1'b0;

	wire hk_sck;
	wire hk_csb;
	wire hk_sdi;

	assign hk_sck = SCK;
	assign hk_csb = CSB;
	assign hk_sdi = SDI;

	assign checkbits = mprj_io[31:16];
	assign uart_tx = mprj_io[6];
	assign mprj_io[5] = uart_rx;
	assign mprj_io[4] = hk_sck;
	assign mprj_io[3] = hk_csb;
	assign mprj_io[2] = hk_sdi;
	assign SDO = mprj_io[1];

    // assign mprj_io[3] = 1'b1;  // Force CSB high
	assign mprj_io[0] = 1'b0;  // Disable debug mode

	caravel uut (
		.vddio	  (VDD3V3),
		.vssio	  (VSS),
		.vdda	  (VDD3V3),
		.vssa	  (VSS),
		.vccd	  (VDD1V8),
		.vssd	  (VSS),
		.vdda1    (VDD3V3),
		.vdda2    (VDD3V3),
		.vssa1	  (VSS),
		.vssa2	  (VSS),
		.vccd1	  (VDD1V8),
		.vccd2	  (VDD1V8),
		.vssd1	  (VSS),
		.vssd2	  (VSS),
		.clock	  (clock),
		.gpio     (gpio),
		.mprj_io  (mprj_io),
		.flash_csb(flash_csb),
		.flash_clk(flash_clk),
		.flash_io0(flash_io0),
		.flash_io1(flash_io1),
		.resetb	  (RSTB)
	);

	spiflash #(
		.FILENAME("mprj_bitbang.hex")
	) spiflash (
		.csb(flash_csb),
		.clk(flash_clk),
		.io0(flash_io0),
		.io1(flash_io1),
		.io2(),			// not used
		.io3()			// not used
	);

	tbuart tbuart (
		.ser_rx(uart_tx)
	);
		
endmodule
`default_nettype wire
