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

module mprj_no_bitbang_tb;
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

	always #10 clock <= (clock === 1'b0);

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
		for (i=7; i >= 0; i--) begin
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
		for (i=7; i >= 0; i--) begin
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
		for (i=7; i >= 0; i--) begin
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

	initial begin
	    $dumpfile("mprj_no_bitbang.vcd");
	    $dumpvars(0, mprj_no_bitbang_tb);

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
	    // Wait for channel 35 to go high
	    wait(mprj_io[35] == 1'b1);

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
		.FILENAME("mprj_no_bitbang.hex")
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
