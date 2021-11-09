`timescale 1 ns / 1 ps
module mgmt_soc_tb;
    reg core_clk;
	reg core_rst;

//	wire serial_rx;
//	wire serial_tx;
	
//	wire spi_master_clk;
//	wire spi_master_cs_n;
//	wire spi_master_mosi;
//	wire spi_master_miso;
	
	wire spiflash_cs_n;
	wire spiflash_clk;
	wire spiflash_miso;
	wire spiflash_mosi;
	wire spiflash_wp;
	wire spiflash_hold;
//	wire spiflash_oeb = 1'b1;
//	wire spiflash_oeb = 1'b0;
	wire spiflash_oeb;

//	wire serial_dbg_rx = 1'b0;
//	wire serial_dbg_tx;
	
	wire gpio_out_pad;
	wire gpio_in_pad;
	wire gpio_outenb_pad;
	wire gpio_inenb_pad;
	wire gpio_mode0_pad;
	wire gpio_mode1_pad;
	
//	wire [127:0] la_output;
//	wire [127:0] la_input;
//	wire [127:0] la_oenb;
//	wire [127:0] la_iena;
	wire mprj_wb_iena;
	wire [2:0] user_irq_ena;

    // The Clock
    initial core_clk <= 0;
    always #50 core_clk <= (core_clk === 1'b0);     // 10MHz Clock

    // PoR
    initial begin
        core_rst <= 1'b0;
        #500;
        core_rst <= 1'b1;
		#5000;
		core_rst <= 1'b0;
	end

    initial begin
		$dumpfile("mgmt_soc_tb.vcd");
		$dumpvars(0, mgmt_soc_tb);

		// Repeat cycles of 1000 clock edges as needed to complete testbench
		repeat (25) begin
			repeat (1000) @(posedge core_clk);
			$display("+1000 cycles");
		end
		$display ("Monitor: Timeout, Test Failed");
		$finish;
	end

    top muv (
        .core_clk(core_clk),
        .core_rst(core_rst),
//        .serial_rx(serial_rx),
//        .serial_tx(serial_tx),
//        .spi_master_clk(spi_master_clk),
//        .spi_master_cs_n(spi_master_cs_n),
//        .spi_master_mosi(spi_master_mosi),
//        .spi_master_miso(spi_master_miso),
//        .spiflash_cs_n(spiflash_cs_n),
//        .spiflash_clk(spiflash_clk),
//        .spiflash_miso(spiflash_miso),
//        .spiflash_mosi(spiflash_mosi),
        .flash_cs_n(spiflash_cs_n),
	    .flash_clk(spiflash_clk),
	    .flash_io0_oeb(spiflash_oeb),
        .flash_io1_oeb(),
        .flash_io2_oeb(),
        .flash_io3_oeb(),
        .flash_io0_do(spiflash_mosi),
        .flash_io1_do(),
        .flash_io2_do(),
        .flash_io3_do(),
        .flash_io0_di(),
        .flash_io1_di(spiflash_miso),
        .flash_io2_di(),
        .flash_io3_di(),
//        .serial_dbg_rx(serial_dbg_rx),
//        .serial_dbg_tx(),
//        .spiflash_wp(),
//        .spiflash_hold(),
        .gpio_out_pad(gpio_out_pad),
        .gpio_in_pad(gpio_in_pad),
        .gpio_outenb_pad(gpio_outenb_pad),
        .gpio_inenb_pad(gpio_inenb_pad),
        .gpio_mode0_pad(gpio_mode0_pad),
        .gpio_mode1_pad(gpio_mode1_pad),
//        .la_output(),
//        .la_input(),
//        .la_oenb(),
//        .la_iena(),
        .mprj_wb_iena(),
        .user_irq_ena()
    );

    spiflash #(
		.FILENAME("test.hex")
	) spiflash (
		.csb(spiflash_cs_n),
		.clk(spiflash_clk),
		.io0(spiflash_mosi),
		.io1(spiflash_miso),
		.io2(),			// not used
		.io3()			// not used
	);

endmodule