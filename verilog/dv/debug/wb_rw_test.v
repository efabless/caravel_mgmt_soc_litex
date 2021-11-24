`default_nettype none

`timescale 1 ns / 1 ps

module wb_rw_test(
    input wire rx,
    output wire tx,
    input wire start
);

//parameter BTIME = 8680;
parameter BTIME = 2175;
reg TX;
wire RX;

reg [31:0] data;

assign RX = rx;
assign tx = TX;

initial begin
    TX = 1'b1;
    #10000;
    wb_write (32'h01000094, 32'h775555ab);
    wb_read (32'h01000094, data);
    $display("output: %s", data);
end

task uart_put(input [7:0] b);
    integer i;
    begin
        TX = 1'b0;
        #BTIME;
        for(i=0; i<8; i=i+1) begin
            TX = b[i];
            #BTIME;
        end
        TX = 1'b1;
        #(BTIME*5);
    end
endtask

task uart_get(output [7:0] b);
    integer i;
    begin
        @(negedge RX);
        #BTIME;
        for(i=0; i<8; i=i+1) begin
            b[i] <= RX;
            #BTIME;
        end
        #(BTIME*5);
    end
endtask

task wb_read (input [31:0] addr, output [31:0] word);
    begin
        uart_put(8'h2);     // read cmd
        uart_put(8'h1);      // size
        uart_put(addr[31:24]);
        uart_put(addr[23:16]);
        uart_put(addr[15:8]);
        uart_put(addr[7:0]);
        uart_get(word[7:0]);
        uart_get(word[15:8]);
        uart_get(word[23:16]);
        uart_get(word[31:24]);
    end
endtask

task wb_write (input [31:0] addr, input [31:0] word);
    begin
        uart_put(8'h1);     // write cmd
        uart_put(8'h1);      // size
        uart_put(addr[31:24]);
        uart_put(addr[23:16]);
        uart_put(addr[15:8]);
        uart_put(addr[7:0]);
        uart_put(word[7:0]);
        uart_put(word[15:8]);
        uart_put(word[23:16]);
        uart_put(word[31:24]);
    end
endtask

endmodule
