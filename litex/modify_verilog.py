#!/usr/bin/env python3

import os
import sys

infile = open(sys.argv[1],"r")
addfile = open("debug_reset.v","r")
outfile = open(sys.argv[2],"wt")
line = infile.readline()
addline = addfile.readline()

while line != '':
     outfile.write(str(line))
     last_line = line
     line = infile.readline()

     # add logic for debug_uart reset initialization
     if "if (sys_rst) begin" in line:
          outfile.write(str(line))
          while addline != '':
               outfile.write(str(addline))
               addline = addfile.readline()
          line = infile.readline()

     if line.startswith("sky130_sram_2kbyte_1rw1r_32x512_8"):
          outfile.write(str(line))
          outfile.write("`ifdef USE_POWER_PINS\n")
          outfile.write("    .vccd1(VPWR),\n")
          outfile.write("    .vssd1(VGND),\n")
          outfile.write("`endif\n")
          line = infile.readline()

     if line.startswith("VexRiscv VexRiscv("):
          outfile.write(str(line))
          outfile.write("`ifdef USE_POWER_PINS\n")
          outfile.write("    .vccd1(VPWR),\n")
          outfile.write("    .vssd1(VGND),\n")
          outfile.write("`endif\n")
          line = infile.readline()

     # remove duplicate assign statements for uart
     while line.startswith("assign {uart_rx_fifo_fifo_out_last, uart_rx_fifo_fifo_out_first, uart_rx_fifo_fifo_out_payload_data}") or \
           line.startswith("assign {uart_tx_fifo_fifo_out_last, uart_tx_fifo_fifo_out_first, uart_tx_fifo_fifo_out_payload_data}"):
          if line == last_line:
               line = infile.readline()
          else:
               break

infile.close()
outfile.close()
addfile.close()
