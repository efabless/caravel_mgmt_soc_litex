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
//`include "picorv32.v"
`include "VexRiscv_MinDebug.v"
//`include "VexRiscv_LiteDebug.v"
`include "spiflash.v"
`include "wb_rw_test.v"
`include "mgmt_core_wrapper.v"

module debug_tb;
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
//	wire [37:0] mprj_io;
	wire debug_uart_tx;
	wire debug_uart_rx;
	wire uart_loopback;
	wire SDO;

	assign checkbits = la_output[31:16];
//	assign uart_tx = la_output[6];

	always #12.5 core_clk <= (core_clk === 1'b0);

	initial begin
		core_clk = 0;
	end

	initial begin
		$dumpfile("debug.vcd");
		$dumpvars(0, debug_tb);

		$display("Wait for Debug o/p");
		repeat (50) begin
			repeat (1000) @(posedge core_clk);
			// Diagnostic. . . interrupts output pattern.
		end
        $display("%c[1;31m",27);
		`ifdef GL
			$display ("Monitor: Timeout, Test Debug (GL) Failed");
		`else
			$display ("Monitor: Timeout, Test Debug (RTL) Failed");
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
		if(checkbits == 16'hA000) begin
			$display("Debug Test started");
		end
		else if(checkbits == 16'hAB00) begin
			`ifdef GL
				$display("Debug Test (GL) passed");
			`else
				$display("UART Test (RTL) passed");
			`endif
			$finish;
		end
	end

	wire VDD3V3;
	wire VDD1V8;
	wire VSS;

	assign VDD3V3 = power1;
	assign VDD1V8 = power2;
	assign VSS = 1'b0;
	
//	assign la_output[3] = 1'b1;  // Force CSB high.

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
		.hk_ack_i(1'b0),
		.debug_out(debug_uart_tx),
		.debug_in(debug_uart_rx)
//		.ser_tx(uart_loopback),
//		.ser_rx(uart_loopback)
	);

	spiflash #(
		.FILENAME("debug.hex")
	) spiflash (
		.csb(flash_csb),
		.clk(flash_clk),
		.io0(flash_io0),
		.io1(flash_io1),
		.io2(),			// not used
		.io3()			// not used
	);

    // Testbench UART
	wb_rw_test debug_uart (
		.rx(debug_uart_tx),
		.tx(debug_uart_rx)
	);
		
endmodule
`default_nettype wire
