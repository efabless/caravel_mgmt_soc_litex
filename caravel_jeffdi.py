#!/usr/bin/env python3

# This file is Copyright (c) 2019 Sean Cross <sean@xobs.io>
# This file is Copyright (c) 2018 David Shah <dave@ds0.me>
# This file is Copyright (c) 2020 Piotr Esden-Tempski <piotr@esden.net>
# License: BSD

# This target was originally based on the Fomu target.

# This variable defines all the external programs that this module
# relies on.  lxbuildenv reads this variable in order to ensure
# the build will finish without exiting due to missing third-party
# programs.

import argparse
# from os import path

from migen import *

from litex.build.generic_platform import *

from litex.soc.integration.soc_core import *
from litex.soc.integration.builder import *
from litex.soc.interconnect import wishbone

from litex.soc.cores.gpio import GPIOTristate
from litex.soc.cores.spi import SPIMaster, SPISlave

# from migen.genlib.resetsync import AsyncResetSynchronizer
# from litex.soc.integration.doc import AutoDoc
from litex.soc.integration.soc import SoCRegion
import litex.soc.doc as lxsocdoc
from litex.soc.cores.uart import UARTWishboneBridge
from litespi.modules import W25Q128JV
from litespi.opcodes import SpiNorFlashOpCodes as Codes
from OpenRAM import *

# IOs ----------------------------------------------------------------------------------------------
_io = [
    ("sys_clk", 0, Pins("1")),
    ("sys_rst", 0, Pins("1")),

    # Serial
    ("serial", 0,
     Subsignal("tx", Pins("1")),
     Subsignal("rx", Pins("1")),
     ),

    # SPI Master
    ("spi_master", 0,
     Subsignal("cs_n", Pins(1)),
     Subsignal("clk", Pins(1)),
     Subsignal("miso", Pins(1)),
     Subsignal("mosi", Pins(1)),
     ),

    # SPIFlash
    ("spiflash", 0,
     Subsignal("cs_n", Pins("1")),
     Subsignal("clk", Pins("1")),
     Subsignal("miso", Pins("1")),
     Subsignal("mosi", Pins("1")),
     Subsignal("wp", Pins("1")),
     Subsignal("hold", Pins("1")),
     ),

    ("spiflash4x", 0,
     Subsignal("cs_n", Pins("1")),
     Subsignal("clk", Pins("1")),
     Subsignal("dq", Pins("1 1 1 1")),
     ),

    ("hkspi_sram", 0,
     Subsignal("hkspi_sram_clk", Pins("1")),
     Subsignal("hkspi_sram_csb", Pins("1")),
     Subsignal("hkspi_sram_addr", Pins("1 1 1 1")),
     Subsignal("hkspi_sram_data", Pins("1 1 1 1")),
     ),

    ("gpio", 0, Pins(32)),

    ("user_irq", 0, Pins("1")),

    ("trap", 0, Pins("1")),

]

# Platform -----------------------------------------------------------------------------------------


class Platform(GenericPlatform):
    def __init__(self, io):
        GenericPlatform.__init__(self, "", io)

    def build(self, fragment, build_dir, **kwargs):
        os.makedirs(build_dir, exist_ok=True)
        os.chdir(build_dir)
        top_output = self.get_verilog(fragment)
        top_output.write("mgmt_core.v")


# Caravel MgmtCore ----------------------------------------------------------------------------------------


class MgmtSoC(SoCMini):

    SoCMini.mem_map = {
        "sram":             0x10000000,
        "spiflash":         0x20000000,
        "csr":              0xf0000000,
        "vexriscv_debug":   0xf00f0000,
    }

    def __init__(self, sys_clk_freq=int(100e6),
        **kwargs
    ):

        gpio_width=32
        spi_master_data_width=8
        spi_master_clk_freq=1e6

        platform = Platform(_io)

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = CRG(platform.request("sys_clk"), rst=platform.request("sys_rst"))

        # SoCMini ----------------------------------------------------------------------------------
        SoCMini.__init__(self, platform,
                         clk_freq=sys_clk_freq,
                         cpu_type="vexriscv",
                         cpu_variant="minimal+debug",
                         cpu_reset_address = self.mem_map["spiflash"],
                         csr_data_width = 32,
                         integrated_sram_size = 0,
                         integrated_rom_size = 0,
                         uart_name = "crossover",
                         **kwargs)

        self.submodules.spi_master = SPIMaster(
            pads         = platform.request("spi_master"),
            data_width   = spi_master_data_width,
            sys_clk_freq = sys_clk_freq,
            spi_clk_freq = spi_master_clk_freq,
        )

        # GPIO
        self.submodules.gpio = GPIOTristate(platform.request("gpio"))
        self.add_csr("gpio")

        # Use this as CPU RAM.
        spram_size = 2 * 1024
        self.submodules.spram = OpenRAM(size=spram_size)
        self.register_mem("sram", self.mem_map["sram"], self.spram.bus, spram_size)

        # SPI Flash --------------------------------------------------------------------------------
        self.add_spi_flash(mode="4x", module=W25Q128JV(Codes.READ_1_1_4), with_master=False)

        # Add ROM linker region --------------------------------------------------------------------
        self.bus.add_region("rom", SoCRegion(
            origin = self.mem_map["spiflash"],
            size   = 8*1024*1024,
            linker = True)
        )

        self.submodules.uart_bridge = UARTWishboneBridge(platform.request("serial"), sys_clk_freq, baudrate=115200)
        self.add_wb_master(self.uart_bridge.wishbone)

        # # Wishbone Master
        # if kwargs["bus"] == "wishbone":
        wb_bus = wishbone.Interface()
        # self.bus.add_master(master=wb_bus)
        self.bus.add_slave(name="wb_slave", slave=wb_bus, region=SoCRegion(origin=0x30000000, size=8192))
        platform.add_extension(wb_bus.get_ios("wb"))
        wb_pads = platform.request("wb")
        self.comb += wb_bus.connect_to_pads(wb_pads, mode="master")

        # # IRQs
        for name, loc in sorted(self.irq.locs.items()):
            module = getattr(self, name)
        #     platform.add_extension([("irq_"+name, 0, Pins(1))])
            irq_pin = platform.request("irq_"+name)
            self.comb += irq_pin.eq(module.ev.irq)

# Build --------------------------------------------------------------------------------------------


def main():

    soc     = MgmtSoC()
    builder = Builder(soc, compile_software=False)
    builder.build()

    lxsocdoc.generate_docs(soc, "build/documentation/", project_name="Caravel Management SoC", author="Efabless")

if __name__ == "__main__":
    main()