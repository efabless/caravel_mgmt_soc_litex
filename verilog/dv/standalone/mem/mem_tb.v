`default_nettype none
/*
 *  SPDX-FileCopyrightText: 2017  Clifford Wolf, 2018  Tim Edwards
 *
 *  StriVe - A full example SoC using PicoRV32 in SkyWater s8
 *
 *  Copyright (C) 2017  Clifford Wolf <clifford@clifford.at>
 *  Copyright (C) 2018  Tim Edwards <tim@efabless.com>
 *
 *  Permission to use, copy, modify, and/or distribute this software for any
 *  purpose with or without fee is hereby granted, provided that the above
 *  copyright notice and this permission notice appear in all copies.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 *  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 *  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 *  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 *  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 *  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 *  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 *
 *  SPDX-License-Identifier: ISC
 */

`timescale 1 ns / 1 ps

`include "defines.v"
`include "sky130_sram_2kbyte_1rw1r_32x512_8.v"
`include "picorv32.v"
`include "VexRiscv_MinDebug.v"
`include "spiflash.v"
`include "mgmt_core_wrapper.v"

module mem_tb;
	reg core_clk;
	reg core_rstn;
	reg power1, power2;

	wire gpio;
    wire [15:0] checkbits;
	wire [127:0] la_output;
	wire flash_csb;
	wire flash_clk;
	wire flash_io0;
	wire flash_io1;

	assign checkbits = la_output[31:16];

	// External clock is used by default.  Make this artificially fast for the
	// simulation.  Normally this would be a slow clock and the digital PLL
	// would be the fast clock.

	always #10 core_clk <= (core_clk === 1'b0);

	initial begin
		core_clk = 0;
	end

	initial begin
		$dumpfile("mem.vcd");
		$dumpvars(0, mem_tb);

		// Repeat cycles of 1000 clock edges as needed to complete testbench
		repeat (10) begin
			repeat (5000) @(posedge core_clk);
			$display("+5000 cycles");
		end
		$display("%c[1;31m",27);
		`ifdef GL
			$display ("Monitor: Timeout, Test MEM (GL) Failed");
		`else
			$display ("Monitor: Timeout, Test MEM (RTL) Failed");
		`endif
		$display("%c[0m",27);
		$finish;
	end

	initial begin
		core_rstn <= 1'b0;
		#1000;
		core_rstn <= 1'b1;	    // Release reset
		#2000;
	end

	initial begin		// Power-up sequence
		power1 <= 1'b0;
		power2 <= 1'b0;
		#200;
		power1 <= 1'b1;
		#200;
		power2 <= 1'b1;
	end

	always @(checkbits) begin
		if(checkbits == 16'hA040) begin
			$display("Mem Test (word rw) started");
		end
		else if(checkbits == 16'hAB40) begin
			$display("%c[1;31m",27);
			`ifdef GL
				$display("Monitor: Test MEM (GL) [word rw] failed");
			`else
				$display("Monitor: Test MEM (RTL) [word rw] failed");
			`endif
			$display("%c[0m",27);
			$finish;
		end
		else if(checkbits == 16'hAB41) begin
			`ifdef GL
				$display("Monitor: Test MEM (GL) [word rw]  passed");
			`else
				$display("Monitor: Test MEM (RTL) [word rw]  passed");
			`endif
		end
		else if(checkbits == 16'hA020) begin
			$display("Mem Test (short rw) started");
		end
		else if(checkbits == 16'hAB20) begin
			$display("%c[1;31m",27);
			`ifdef GL
				$display("Monitor: Test MEM (GL) [short rw] failed");
			`else
				$display("Monitor: Test MEM (RTL) [short rw] failed");
			`endif
			$display("%c[0m",27);
			$finish;
		end
		else if(checkbits == 16'hAB21) begin
			`ifdef GL
				$display("Monitor: Test MEM (GL) [short rw]  passed");
			`else
				$display("Monitor: Test MEM (RTL) [short rw]  passed");
			`endif
		end
		else if(checkbits == 16'hA010) begin
			$display("Mem Test (byte rw) started");
		end
		else if(checkbits == 16'hAB10) begin
			$display("%c[1;31m",27);
			`ifdef GL
				$display("Monitor: Test MEM (GL) [byte rw] failed");
			`else
				$display("Monitor: Test MEM (RTL) [byte rw] failed");
			`endif
			$display("%c[0m",27);
			$finish;
		end
		else if(checkbits == 16'hAB11) begin
			`ifdef GL
				$display("Monitor: Test MEM (GL) [byte rw] passed");
			`else
				$display("Monitor: Test MEM (RTL) [byte rw] passed");
			`endif
			$finish;
		end

	end

	wire VDD3V3;
	wire VDD1V8;
	wire VSS;

	assign VSS = 1'b0;
	assign VDD3V3 = power1;
	assign VDD1V8 = power2;

//	assign la_output[3] = 1'b1;       // Force CSB high.

	mgmt_core_wrapper uut (
		.core_clk	  (core_clk),
		.gpio_out_pad     (gpio),
		.la_output  (la_output),
		.flash_csb(flash_csb),
		.flash_clk(flash_clk),
		.flash_io0_oeb(),
		.flash_io0_do(flash_io0),
		.flash_io1_di(flash_io1),
		.core_rstn	  (core_rstn),
        .mprj_dat_i(32'b0),
		.mprj_ack_i(1'b0),
        .hk_dat_i(32'b0),
		.hk_ack_i(1'b0)
	);

	spiflash #(
		.FILENAME("mem.hex")
	) spiflash (
		.csb(flash_csb),
		.clk(flash_clk),
		.io0(flash_io0),
		.io1(flash_io1),
		.io2(),			// not used
		.io3()			// not used
	);

endmodule
`default_nettype wire
