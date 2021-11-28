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

`timescale 1 ns / 1 ps

`include "defines.v"
`include "sky130_sram_2kbyte_1rw1r_32x512_8.v"
//`include "picorv32.v"
`include "VexRiscv_MinDebug.v"
`include "spiflash.v"
`include "mgmt_core_wrapper.v"

module spi_master_tb;
	reg core_clk;
	reg core_rstn;
	reg power1, power2;

	wire gpio;
	wire [15:0] checkbits;
	wire [7:0] spivalue;
	wire [127:0] la_output;
	wire flash_csb;
	wire flash_clk;
	wire flash_io0;
	wire flash_io1;

	wire spi_clk;
	wire spi_cs_n;
	wire spi_mosi;
	wire spi_miso;
	wire spi_sdoenb;

	assign checkbits = la_output[31:16];
	assign spivalue  = la_output[15:8];

	// External clock is used by default.  Make this artificially fast for the
	// simulation.  Normally this would be a slow clock and the digital PLL
	// would be the fast clock.

	always #10 core_clk <= (core_clk === 1'b0);

	initial begin
		core_clk = 0;
	end

	initial begin
		$dumpfile("spi_master.vcd");
		$dumpvars(0, spi_master_tb);
		repeat (50) begin
			repeat (5000) @(posedge core_clk);
			$display("+5000 cycles");
		end
		$display("%c[1;31m",27);
		`ifdef GL
			$display ("Monitor: Timeout, Test SPI Master (GL) Failed");
		`else
			$display ("Monitor: Timeout, Test SPI Master (RTL) Failed");
		`endif
		 $display("%c[0m",27);
		$finish;
	end

	// Monitor
	initial begin
	    wait(checkbits == 16'hA040);
			`ifdef GL
            	$display("Monitor: Test SPI Master (GL) Started");
			`else
			    $display("Monitor: Test SPI Master (RTL) Started");
			`endif
	    wait(checkbits == 16'hA041);
            $display("   SPI value = 0x%x (should be 0x93)", spivalue);
            if(spivalue !== 32'h93) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA042);
            $display("   SPI value = 0x%x (should be 0x01)", spivalue);
            if(spivalue !== 32'h01) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA043);
            $display("   SPI value = 0x%x (should be 0x00)", spivalue);
            if(spivalue !== 32'h00) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA044);
            $display("   SPI value = 0x%x (should be 0x13)", spivalue);
            if(spivalue !== 32'h13) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA045);
            $display("   SPI value = 0x%x (should be 0x02)", spivalue);
            if(spivalue !== 32'h02) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA046);
            $display("   SPI value = 0x%x (should be 0x63)", spivalue);
            if(spivalue !== 32'h63) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA047);
            $display("   SPI value = 0x%x (should be 0x57)", spivalue);
            if(spivalue !== 32'h57) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA048);
            $display("   SPI value = 0x%x (should be 0xb5)", spivalue);
            if(spivalue !== 32'hb5) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA049);
            $display("   SPI value = 0x%x (should be 0x00)", spivalue);
            if(spivalue !== 32'h00) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA04a);
            $display("   SPI value = 0x%x (should be 0x23)", spivalue);
            if(spivalue !== 32'h23) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end
	    wait(checkbits == 16'hA04b);
            $display("   SPI value = 0x%x (should be 0x20)", spivalue);
            if(spivalue !== 32'h20) begin
                $display("Monitor: Test SPI Master Failed");
                $finish;
            end

	    wait(checkbits == 16'hA090);
		 	`ifdef GL
            	$display("Monitor: Test SPI Master (GL) Passed");
			`else
		        $display("Monitor: Test SPI Master (RTL) Passed");
			`endif
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
		#1 $display("GPIO state = %b ", checkbits);
	end

	wire VDD3V3;
	wire VDD1V8;
	wire VSS;
	
	assign VDD3V3 = power1;
	assign VDD1V8 = power2;
	assign VSS = 1'b0;

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
        .core_rstn(core_rstn),
        .mprj_dat_i(32'b0),
		.mprj_ack_i(1'b0),
        .hk_dat_i(32'b0),
		.hk_ack_i(1'b0),
		.spi_sck(spi_clk),
	    .spi_csb(spi_cs_n),
        .spi_sdo(spi_miso),
        .spi_sdi(spi_mosi),
        .spi_sdoenb(spi_sdoenb)
	);

	spiflash #(
		.FILENAME("spi_master.hex")
	) spiflash (
		.csb(flash_csb),
		.clk(flash_clk),
		.io0(flash_io0),
		.io1(flash_io1),
		.io2(),			// not used
		.io3()			// not used
	);

	/* Instantiate a 2nd SPI flash so the SPI master can talk to it */

	spiflash #(
		.FILENAME("test_data")
	) test_spi (
		.csb(spi_cs_n),
		.clk(spi_clk),
		.io0(spi_miso),
		.io1(spi_mosi),
		.io2(),			// not used
		.io3()			// not used
	);

endmodule
`default_nettype wire
