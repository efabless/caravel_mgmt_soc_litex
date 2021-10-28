#!/usr/bin/env python3

# This file is Copyright (c) 2019 Sean Cross <sean@xobs.io>
# This file is Copyright (c) 2018 David Shah <dave@ds0.me>

# License: BSD


import argparse
from os import path

from migen import *
from litex.soc.cores.spi_flash import SpiFlash
from litex.soc.integration.soc_core import SoCCore
from litex.soc.integration.builder import Builder, builder_argdict, builder_args
from litex.soc.integration.soc_core import soc_core_argdict, soc_core_args
from litex.soc.integration.doc import AutoDoc
from litex.soc.integration.soc import SoCRegion
from litex.soc.integration.soc_core import *
from litex.build.generic_platform import *
from litex.soc.cores.uart import UARTWishboneBridge
from litex.soc.cores.gpio import GPIOTristate
from litex.soc.cores.spi import SPIMaster, SPISlave
import litex.soc.doc as lxsocdoc

from CaravelChip import Platform
from OpenRAM import *

# MGMTSoC
class MGMTSoC(SoCMini):
    SoCMini.mem_map = {
        "sram":             0x10000000,
        "spiflash":         0x20000000,
        "csr":              0xf0000000,
        "vexriscv_debug":   0xf00f0000,
    }

    def __init__(self, sys_clk_freq=int(10e6), **kwargs ):

        platform = Platform("mgmt_soc")

        kwargs["cpu_type"]="vexriscv"
        kwargs["cpu_variant"] = "minimal+debug"
        kwargs["integrated_sram_size"] = 0
        kwargs["integrated_rom_size"]  = 0
        kwargs["csr_data_width"] = 32
        kwargs["cpu_reset_address"] = self.mem_map["spiflash"]
        kwargs["uart_name"]   = "crossover"
        kwargs["with_timer"]   = True
        

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = CRG(platform.request("sys_clk"), rst=platform.request("sys_rst"))

        #print(kwargs)
        SoCMini.__init__(self, platform, clk_freq=sys_clk_freq, **kwargs)

        # Add a master SPI controller
        platform.add_extension([
                ("spi_master", 0,
                    Subsignal("clk",  Pins(1)),
                    Subsignal("cs_n", Pins(1)),
                    Subsignal("mosi", Pins(1)),
                    Subsignal("miso", Pins(1)),
                )
        ])
        self.submodules.spi_master = SPIMaster(
                pads         = platform.request("spi_master"),
                data_width   = 2,
                sys_clk_freq = sys_clk_freq,
                spi_clk_freq = 1e5,
        )

        # Add a GPIO Pin
        platform.add_extension([("gpio", 0, Pins(1))])
        self.submodules.gpio = GPIOTristate(platform.request("gpio"))
        #self.add_csr("gpio")
        
        # Add a master wb port
        wb_bus = wishbone.Interface()
        self.bus.add_master(master=wb_bus)
        platform.add_extension(wb_bus.get_ios("wb"))
        wb_pads = platform.request("wb")
        self.comb += wb_bus.connect_to_pads(wb_pads, mode="master")
        

        #Use OpenRAM
        spram_size = 2 * 1024
        self.submodules.spram = OpenRAM(size=spram_size)
        self.register_mem("sram", self.mem_map["sram"], self.spram.bus, spram_size)

        # SPI Flash --------------------------------------------------------------------------------
        from litespi.modules import W25Q128JV
        from litespi.opcodes import SpiNorFlashOpCodes as Codes
        self.add_spi_flash(mode="4x", module=W25Q128JV(Codes.READ_1_1_4), with_master=False)

        # Add ROM linker region --------------------------------------------------------------------
        self.bus.add_region("rom", SoCRegion(
            origin = self.mem_map["spiflash"],
            size   = 8*1024*1024,
            linker = True)
        )

        self.submodules.uart_bridge = UARTWishboneBridge(platform.request("serial"), sys_clk_freq, baudrate=115200)
        self.add_wb_master(self.uart_bridge.wishbone)


def main():
    soc     = MGMTSoC()
    builder = Builder(soc, compile_software=False)
    builder.build()

    lxsocdoc.generate_docs(soc, "build/documentation/", project_name="Caravel Management SoC", author="Efabless")


if __name__ == "__main__":
    main()