#!/usr/bin/env python3

# This file is Copyright (c) 2019 Sean Cross <sean@xobs.io>
# This file is Copyright (c) 2018 David Shah <dave@ds0.me>

# License: BSD


import argparse
from os import path

from migen import *
from migen.genlib.resetsync import AsyncResetSynchronizer

from litex.soc.cores.ram import Up5kSPRAM
from litex.soc.cores.spi_flash import SpiFlash
#from litex.soc.cores.clock import iCE40PLL
from litex.soc.integration.soc_core import SoCCore
from litex.soc.integration.builder import Builder, builder_argdict, builder_args
#from litex.build.lattice.programmer import IceStormProgrammer
from litex.soc.integration.soc_core import soc_core_argdict, soc_core_args
from litex.soc.integration.doc import AutoDoc
from litex.soc.integration.soc import SoCRegion
from litex.soc.integration.soc_core import *

from litex.build.generic_platform import *
#from litex.build.lattice import LatticePlatform

#from litex_boards.platforms.icebreaker import Platform, break_off_pmod

from litex.soc.cores.uart import UARTWishboneBridge
#from rtl.leds import Leds

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

    def __init__(self, sys_clk_freq=int(100e6),
        with_gpio       = False, gpio_width=32,
        with_spi_master = True, spi_master_data_width=1, spi_master_clk_freq=1e6,
        **kwargs
    ):

        platform = Platform("mgmt_soc")

        kwargs["cpu_type"]="vexriscv"
        kwargs["cpu_variant"] = "minimal+debug"
        kwargs["integrated_sram_size"] = 0
        kwargs["integrated_rom_size"]  = 0
        kwargs["csr_data_width"] = 32
        kwargs["cpu_reset_address"] = self.mem_map["spiflash"]
        kwargs["uart_name"]   = "crossover"

        
        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = CRG(platform.request("sys_clk"), rst=platform.request("sys_rst"))

        #print(kwargs)
        SoCMini.__init__(self, platform, clk_freq=sys_clk_freq, **kwargs)

        if with_spi_master:
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
                data_width   = spi_master_data_width,
                sys_clk_freq = sys_clk_freq,
                spi_clk_freq = spi_master_clk_freq,
            )

        if with_gpio:
            platform.add_extension([("gpio", 0, Pins(gpio_width))])
            self.submodules.gpio = GPIOTristate(platform.request("gpio"))
            self.add_csr("gpio")

        
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




# Build --------------------------------------------------------------------------------------------

def soc_argdict(args):
    ret = {}
    for arg in [
        "with_pwm",
        "with_mmcm",
        "with_uart",
        "uart_fifo_depth",
        "with_ctrl",
        "with_timer",
        "with_gpio",
        "gpio_width",
        "with_spi_master",
        "spi_master_data_width",
        "spi_master_clk_freq",
        "csr_data_width",
        "csr_address_width",
        "csr_paging"]:
        ret[arg] = getattr(args, arg)
    return ret

def main():
    parser = argparse.ArgumentParser(description="LiteX standalone core generator")
    builder_args(parser)

    # Cores
    #parser.add_argument("--with-pwm",              action="store_true",   help="Add PWM core")
    #parser.add_argument("--with-mmcm",             action="store_true",   help="Add MMCM (Xilinx 7-series) core")
    #parser.add_argument("--with-uart",             action="store_true",   help="Add UART core")
    #parser.add_argument("--uart-fifo-depth",       default=16, type=int,  help="UART FIFO depth (default=16)")
    #parser.add_argument("--with-ctrl",             action="store_true",   help="Add bus controller core")
    parser.add_argument("--with-timer",            action="store_true",   help="Add timer core")
    parser.add_argument("--with-spi-master",       action="store_true",   help="Add SPI master core")
    parser.add_argument("--spi-master-data-width", default=8,   type=int, help="SPI master data width")
    parser.add_argument("--spi-master-clk-freq",   default=8e6, type=int, help="SPI master output clock frequency")
    parser.add_argument("--with-gpio",             action="store_true",   help="Add GPIO core")
    parser.add_argument("--gpio-width",            default=32,  type=int, help="GPIO signals width")

    # CSR settings
    parser.add_argument("--csr-data-width",    default=8,     type=int, help="CSR bus data-width (8 or 32, default=8)")
    parser.add_argument("--csr-address-width", default=14,    type=int, help="CSR bus address-width")
    parser.add_argument("--csr-paging",        default=0x800, type=int, help="CSR bus paging")

    args = parser.parse_args()

    soc     = MGMTSoC(**soc_argdict(args))
    builder = Builder(soc, **builder_argdict(args))
    builder.build()

    lxsocdoc.generate_docs(soc, "build/documentation/", project_name="Caravel Management SoC", author="Efabless")

if __name__ == "__main__":
    main()