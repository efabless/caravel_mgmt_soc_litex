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

module wishbone_tb;
	reg clock;
	reg RSTB;
	reg power1, power2;

	wire gpio;
    wire [31:0] checkbits;
	wire [127:0] la_output;
	wire flash_csb;
	wire flash_clk;
	wire flash_io0;
	wire flash_io1;
//	wire [37:0] mprj_io;
	wire uart_tx;
	wire uart_loopback;
	wire SDO;

	wire mprj_ack_i;
	wire mprj_cyc_o;
	wire mprj_stb_o;
	wire mprj_wb_iena;
	wire mprj_we_o;
	wire [31:0] mprj_adr_o;
	wire [31:0] mprj_dat_i;
	wire [31:0] mprj_dat_o;
	wire [3:0] mprj_sel_o;

	assign checkbits = la_output[31:0];

	always #12.5 clock <= (clock === 1'b0);

	initial begin
		clock = 0;
	end

	`ifdef ENABLE_SDF
		initial begin
			$sdf_annotate("../../../../sdf/DFFRAM.sdf", uut.DFFRAM_0 );
			$sdf_annotate("../../../../sdf/mgmt_core.sdf", uut.core);
		end
	`endif 

	initial begin
		$dumpfile("wishbone.vcd");
		$dumpvars(0, wishbone_tb);

		// Repeat cycles of 10000 clock edges as needed to complete testbench
		repeat (50) begin
			repeat (10000) @(posedge clock);
			$display("+10000 cycles");
		end
		$display("%c[1;31m",27);
		`ifdef GL
			$display ("Monitor: Timeout, Test WISHBONE (GL) Failed");
		`else
			$display ("Monitor: Timeout, Test WISHBONE (RTL) Failed");
		`endif
		 $display("%c[0m",27);
		$finish;
	end

	initial begin
		RSTB <= 1'b0;
		#1000;
		RSTB <= 1'b1;	    // Release reset
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
		if(checkbits == 32'h00000001) begin
			$display("WISHBONE Test started");
		end
		else if(checkbits == 32'hE0000000) begin
			`ifdef GL
				$display("Monitor: Test WISHBONE (GL) failed - first addr");
			`else
				$display("Monitor: Test WISHBONE (RTL) failed - first addr");
			`endif
			$finish;
		end
		else if(checkbits == 32'hE000001) begin
			`ifdef GL
				$display("Monitor: Test WISHBONE (GL) failed");
			`else
				$display("Monitor: Test WISHBONE (RTL) failed");
			`endif
			$finish;
		end
		else if(checkbits == 32'hE0000002) begin
			`ifdef GL
				$display("Monitor: Test WISHBONE (GL) failed - last addr");
			`else
				$display("Monitor: Test WISHBONE (RTL) failed - last addr");
			`endif
			$finish;
		end
		else if(checkbits == 32'h10000000) begin
			`ifdef GL
				$display("Monitor: Test WISHBONE (GL) passed");
			`else
				$display("Monitor: Test WISHBONE (RTL) passed");
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
	mgmt_core_wrapper uut (
	`ifdef USE_POWER_PINS
		.VPWR		  (VDD1V8),
		.VGND		  (VSS),
	`endif
		.core_clk	  (clock),
		.core_rstn	  (RSTB),
        .debug_in(1'b0),
        .debug_mode(),
        .debug_oeb(),
        .debug_out(),
		.gpio_out_pad(gpio),
        .gpio_in_pad(1'b0),
        .gpio_inenb_pad(),
        .gpio_mode0_pad(),
        .gpio_mode1_pad(),
        .gpio_outenb_pad(),
		.la_output (la_output),
        .la_iena(),
        .la_input(128'b0),
        .la_oenb(),
		.flash_csb(flash_csb),
		.flash_clk(flash_clk),
		.flash_io0_oeb(),
		.flash_io1_oeb(),
		.flash_io2_oeb(),
		.flash_io3_oeb(),
		.flash_io0_do(flash_io0),
		.flash_io0_di(1'b0),
		.flash_io1_do(),
		.flash_io1_di(flash_io1),
		.flash_io2_do(),
		.flash_io2_di(1'b0),
        .flash_io3_do(),
		.flash_io3_di(1'b0),
        .mprj_adr_o(mprj_adr_o),
        .mprj_sel_o(mprj_sel_o),
		.mprj_dat_i(mprj_dat_i),
		.mprj_ack_i(mprj_ack_i),
		.mprj_cyc_o(mprj_cyc_o),
        .mprj_stb_o(mprj_stb_o),
        .mprj_wb_iena(mprj_wb_iena),
        .mprj_we_o(mprj_we_o),
        .mprj_dat_o(mprj_dat_o),
        .hk_dat_i(32'b0),
		.hk_ack_i(1'b0),
		.hk_cyc_o(),
		.hk_stb_o(),
		.ser_rx(1'b1),
		.ser_tx(),
		.qspi_enabled(),
        .spi_csb(),
        .spi_enabled(),
        .spi_sck(),
        .spi_sdi(1'b0),
        .spi_sdo(),
        .spi_sdoenb(),
        .sram_ro_csb(),
        .sram_ro_clk(),
        .sram_ro_addr(8'b0),
        .sram_ro_data(),
        .trap(),
        .uart_enabled(),
        .irq(6'b0),
        .user_irq_ena()
	);

	spiflash #(
		.FILENAME("wishbone.hex")
	) spiflash (
		.csb(flash_csb),
		.clk(flash_clk),
		.io0(flash_io0),
		.io1(flash_io1),
		.io2(),			// not used
		.io3()			// not used
	);

	wb_dummy_slave wb_slave_i (
		.clk_i (clock),
		.rstn_i (RSTB),
		.wb_iena (1'b0),
		.cyc_i (mprj_cyc_o),
		.stb_i (mprj_stb_o),
		.we_i (mprj_we_o),
		.sel_i (mprj_sel_o),
		.adr_i (mprj_adr_o),
		.dat_i (mprj_dat_o),
		.ack_o (mprj_ack_i),
		.dat_o (mprj_dat_i)
	);

	// Testbench UART
	tbuart tbuart (
		.ser_rx(uart_tx)
	);
endmodule

// Dummy wishbone slave
// it simply registers the last written value, independently from the address, or sel values

module wb_dummy_slave (
	input clk_i,
	input rstn_i,

    input	  wb_iena,	// TODO: currently unused
    input 	  cyc_i,
    input 	  stb_i,
    input 	  we_i,
    input [3:0]  sel_i,
    input [31:0] adr_i,
    input [31:0] dat_i,
    output reg ack_o,
    output reg [31:0] dat_o
);

	wire we;
	wire ack;

	assign we = stb_i & cyc_i & we_i;
	assign ack = stb_i & cyc_i;

	always @(posedge clk_i)
	begin
		ack_o <= 1'b0;
		if (~rstn_i) begin
			dat_o <= 32'hDEADBEEF;
		end
		else if (we) begin
			dat_o <= dat_i;
			ack_o <= 1'b1;
		end
		else if (ack) begin
			ack_o <= 1'b1;
		end
	end

endmodule

`default_nettype wire
