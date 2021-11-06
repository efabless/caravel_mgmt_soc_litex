`timescale 1 ns / 1 ps
module mgmt_soc_tb;
    reg sys_clk;
	reg sys_rst;

	wire serial_rx;
	wire serial_tx;
	
	wire spi_master_clk;
	wire spi_master_cs_n;
	wire spi_master_mosi;
	wire spi_master_miso;
	
	wire spiflash_cs_n;
	wire spiflash_clk;
	wire spiflash_miso;
	wire spiflash_mosi;
	wire spiflash_wp;
	wire spiflash_hold;
	
	wire serial_dbg_rx = 1'b0;
	wire serial_dbg_tx;
	
	wire gpio_out_pad;
	wire gpio_in_pad;
	wire gpio_outenb_pad;
	wire gpio_inenb_pad;
	wire gpio_mode0_pad;
	wire gpio_mode1_pad;
	
	wire [127:0] la_output;
	wire [127:0] la_input;
	wire [127:0] la_oenb;
	wire [127:0] la_iena;
	wire mprj_wb_iena;
	wire [2:0] user_irq_ena;

    // The Clock
    initial sys_clk <= 0;
    always #50 sys_clk <= (sys_clk === 1'b0);     // 10MHz Clock

    // PoR
    initial begin
        sys_rst <= 1'b0;
        #500;
        sys_rst <= 1'b1;
		#5000;
		sys_rst <= 1'b0;
	end

    initial begin
		$dumpfile("mgmt_soc_tb.vcd");
		$dumpvars(0, mgmt_soc_tb);

		// Repeat cycles of 1000 clock edges as needed to complete testbench
		repeat (50) begin
			repeat (1000) @(posedge sys_clk);
			$display("+1000 cycles");
		end
		$display ("Monitor: Timeout, Test Failed");
		$finish;
	end

    top muv (
        .sys_clk(sys_clk),
        .sys_rst(sys_rst),
        .serial_rx(serial_rx),
        .serial_tx(serial_tx),
        .spi_master_clk(spi_master_clk),
        .spi_master_cs_n(spi_master_cs_n),
        .spi_master_mosi(spi_master_mosi),
        .spi_master_miso(spi_master_miso),
        .spiflash_cs_n(spiflash_cs_n),
        .spiflash_clk(spiflash_clk),
        .spiflash_miso(spiflash_miso),
        .spiflash_mosi(spiflash_mosi),
        .serial_dbg_rx(serial_dbg_rx),
        .serial_dbg_tx(),
        .spiflash_wp(),
        .spiflash_hold(),
        .gpio_out_pad(gpio_out_pad),
        .gpio_in_pad(gpio_in_pad),
        .gpio_outenb_pad(gpio_outenb_pad),
        .gpio_inenb_pad(gpio_inenb_pad),
        .gpio_mode0_pad(gpio_mode0_pad),
        .gpio_mode1_pad(gpio_mode1_pad),
        .la_output(),
        .la_input(),
        .la_oenb(),
        .la_iena(),
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