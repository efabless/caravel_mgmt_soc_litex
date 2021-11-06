`timescale 1 ns / 1 ps
module mgmt_soc_tb;
    //reg core_clk;
    reg sys_clk;
	//reg core_rst;
	reg sys_rst;
	reg serial_rx;
	wire serial_tx;
	wire spi_master_clk;
	wire spi_master_cs_n;
	wire spi_master_mosi;
	wire spi_master_miso;
	wire spiflash_cs_n;
	wire spiflash_clk;
	wire spiflash_miso;
	wire spiflash_mosi;
	//input wire spiflash_wp,
	//input wire spiflash_hold,
	reg serial_dbg_rx;
	wire serial_dbg_tx;
	output wire gpio_out_pad;
	reg gpio_in_pad;
	output wire gpio_outenb_pad;
	output wire gpio_inenb_pad;
	output wire gpio_mode0_pad;
	output wire gpio_mode1_pad;
	wire [127:0] la_output;
	reg [127:0] la_input;
	wire [127:0] la_oenb;
	wire [127:0] la_iena;
	output wire mprj_wb_iena;
	output wire [2:0] user_irq_ena;

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
		$display("%c[1;31m",27);
		$display ("Monitor: Timeout, Test Failed");
		$display("%c[0m",27);

//		#10_250;
		$finish;
	end

    top muv (
        //.core_clk(core_clk),
        .sys_clk(sys_clk),
        //.core_rst(core_rst),
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
        .serial_dbg_rx(1'b0),
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