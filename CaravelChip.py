#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2020 Piotr Esden-Tempski <piotr@esden.net>
# SPDX-License-Identifier: BSD-2-Clause

from litex.build.generic_platform import *
from litex.build.lattice import LatticePlatform


# IOs ----------------------------------------------------------------------------------------------
_io = [
    ("sys_clk", 0, Pins(1)),
    ("sys_rst", 0, Pins(1)),
        # Serial
 
    ("serial", 0,
        Subsignal("rx", Pins("1")),
        Subsignal("tx", Pins("1")),
    ),

    # SPIFlash
    ("spiflash", 0,
        Subsignal("cs_n", Pins("1")),
        Subsignal("clk",  Pins("1")),
        Subsignal("miso", Pins("1")),
        Subsignal("mosi", Pins("1")),
        Subsignal("wp",   Pins("1")),
        Subsignal("hold", Pins("1")),
    ),

    ("spiflash4x", 0,
        Subsignal("cs_n", Pins("1")),
        Subsignal("clk",  Pins("1")),
        Subsignal("dq",   Pins("1 1 1 1")),
    )
]


# Platform -----------------------------------------------------------------------------------------

class Platform(GenericPlatform):
    def __init__(self, vname=""):
        GenericPlatform.__init__(self, "", _io)
        
    def build(self, fragment, build_dir, **kwargs):
        os.makedirs(build_dir, exist_ok=True)
        os.chdir(build_dir)
        top_output = self.get_verilog(fragment)
        top_output.write("mgmt_soc.v")


