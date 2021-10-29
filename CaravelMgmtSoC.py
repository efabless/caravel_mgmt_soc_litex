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
 
    ("serial_dbg", 0,
        Subsignal("rx", Pins("1")),
        Subsignal("tx", Pins("1")),
    ),

    ("serial", 0,
        Subsignal("rx", Pins("1")),
        Subsignal("tx", Pins("1")),
    ),

    # SPIFlash
    # SPI Mode
    ("spiflash", 0,
        Subsignal("cs_n", Pins("1")),
        Subsignal("clk",  Pins("1")),
        Subsignal("miso", Pins("1")),
        Subsignal("mosi", Pins("1")),
        Subsignal("wp",   Pins("1")),
        Subsignal("hold", Pins("1")),
    ),
    # QSPI mode
    ("spiflash4x", 0,
        Subsignal("cs_n", Pins("1")),
        Subsignal("clk",  Pins("1")),
        Subsignal("dq",   Pins("1 1 1 1")),
    ),

    # SPI master Controller
    ("spi_master", 0,
        Subsignal("clk",  Pins(1)),
        Subsignal("cs_n", Pins(1)),
        Subsignal("mosi", Pins(1)),
        Subsignal("miso", Pins(1)),
    ),

    # GPIO Pin
    ("gpio", 0,
        Subsignal("o",  Pins(1)),
        Subsignal("i", Pins(1)),
        Subsignal("oe", Pins(1)),
    ),

    # Logic Analyzer
    ("la", 0,
     Subsignal("o", Pins(128)),
     Subsignal("i", Pins(128)),
     Subsignal("oe", Pins(128)),
    ),
    ("la_ien", 0,
     Subsignal("o", Pins(128)),
    ),

    # User's input control
    ("mprj_wb_iena", 0,
     Pins(1)
     # Subsignal("o", Pins(1)),
    ),

    ("user_irq_ena", 0,
     Pins(3)
     # Subsignal("o", Pins(3)),
    ),

     # 6 IRQ lines
    ("irq", 0,
     Pins(6)
     # Subsignal("i", Pins(6)),
    ),

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


