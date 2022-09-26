#!/usr/bin/env python3

import os
import sys

infile = open("build/caravel_platform/gateware/mgmt_core.v","r")
addfile = open("debug_reset.v","r")
outfile = open("build/caravel_platform/gateware/mgmt_core_modified.v","wt")
line = infile.readline()
addline = addfile.readline()

while line != '':
     outfile.write(str(line))
     line = infile.readline()

     if "if (sys_rst) begin" in line:
          outfile.write(str(line))
          while addline != '':
               outfile.write(str(addline))
               addline = addfile.readline()
          line = infile.readline()

infile.close()
outfile.close()
addfile.close()