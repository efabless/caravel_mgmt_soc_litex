#!/usr/bin/env python3

# Copyright (c) 2020 Antmicro <www.antmicro.com>
# Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
# Copyright (c) 2021 Efabless <www.efaless.com>

# SPDX-License-Identifier: BSD-2-Clause

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
from litex.soc.cores.gpio import *
from GPIOASIC import *
from litex.soc.cores.spi import SPIMaster, SPISlave
import litex.soc.doc as lxsocdoc

from CaravelMgmtSoC import Platform
from OpenRAM import *

# MGMTSoC
class MGMTSoC(SoCMini):
    SoCMini.mem_map = {
        "sram":             0x10000000,
        "spiflash":         0x00000000,
        "csr":              0xf0000000,
        # "csr":              0x82000000,
        "vexriscv_debug":   0xf00f0000,
    }

    def __init__(self, sys_clk_freq=int(10e6), **kwargs ):

        platform = Platform("mgmt_soc")

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = CRG(platform.request("sys_clk"), rst=platform.request("sys_rst"))

        SoCMini.__init__(self, platform,
                         clk_freq=sys_clk_freq,
                         cpu_type="vexriscv",
                         # cpu_variant="minimal+debug",
                         cpu_variant="minimal",
                         cpu_reset_address=self.mem_map["spiflash"],
                         csr_data_width=32,
                         integrated_sram_size=0,
                         integrated_rom_size=0,
                         # with_uart=True,
                         # with_timer=True,
                         **kwargs)
        """
        SoCMini.__init__(self, platform,
                         clk_freq=sys_clk_freq,
                         cpu_type="picorv32",
                         cpu_variant="minimal",
                         cpu_reset_address=self.mem_map["spiflash"],
                         csr_data_width=32,
                         integrated_sram_size=0,
                         integrated_rom_size=0,
                         # with_uart=True,
                         # with_timer=True,
                         **kwargs)

        """
        """
        # Add a master SPI controller w/ a clock divider
        spi_master = SPIMaster(
            pads=platform.request("spi_master"),
            data_width=8,
            sys_clk_freq=sys_clk_freq,
            spi_clk_freq=1e5,
        )
        spi_master.add_clk_divider()
        self.submodules.spi_master = spi_master
        #self.add_interrupt(interrupt_name="spi_master")
        """

        """
        # Add a wb port for external slaves
        wb_bus = wishbone.Interface()
        self.bus.add_slave(name="extern_slave", slave=wb_bus, region=SoCRegion(origin=0x30000000, size=8192))
        platform.add_extension(wb_bus.get_ios("wb"))
        wb_pads = platform.request("wb")
        self.comb += wb_bus.connect_to_pads(wb_pads, mode="master")
        """

        #Use OpenRAM
        spram_size = 2 * 1024
        self.submodules.spram = OpenRAM(size=spram_size)
        self.register_mem("sram", self.mem_map["sram"], self.spram.bus, spram_size)

        # SPI Flash --------------------------------------------------------------------------------
        from litespi.modules import W25Q128JV
        from litespi.opcodes import SpiNorFlashOpCodes as Codes
        #self.add_spi_flash(name="flash", mode="1x", module=W25Q128JV(Codes.READ_1_1_4), with_master=False)
        # self.add_spi_flash(name="spiflash", mode="1x", module=W25Q128JV(Codes.READ_1_1_1), with_master=False)
        self.add_spi_flash(name="spiflash", mode="1x", module=W25Q128JV(Codes.READ_1_1_1), with_master=True)


        # Add ROM linker region --------------------------------------------------------------------
        self.bus.add_region("rom", SoCRegion(
            origin = self.mem_map["spiflash"],
            size   = 8*1024*1024,
            linker = True)
        )
        # Add Debug Interface (UART)
        # self.submodules.uart_bridge = UARTWishboneBridge(platform.request("serial_dbg"), sys_clk_freq, baudrate=115200)
        # self.add_wb_master(self.uart_bridge.wishbone)

        # Add a GPIO Pin
        # self.submodules.gpio = GPIOTristate(platform.request("gpio"))
        self.submodules.gpio = GPIOASIC(platform.request("gpio"))
        # self.add_csr("gpio")

        # Add the logic Analyzer
        # self.submodules.la = LogicAnalyzer(platform.request("la"))
        # self.submodules.la_ien = GPIOOut(platform.request("la_ien"))

        # Add the user's input control
        self.submodules.mprj_wb_iena = GPIOOut(platform.request("mprj_wb_iena"))
        # self.add_csr("mprj_wb_iena")
        self.submodules.user_irq_ena = GPIOOut(platform.request("user_irq_ena"))
        # self.add_csr("user_irq_ena")

        # Add 6 IRQ lines
        user_irq = platform.request("user_irq")
        for i in range(len(user_irq)):
            setattr(self.submodules,"user_irq_"+str(i),GPIOIn(user_irq[i], with_irq=True))
            self.irq.add("user_irq_"+str(i), use_loc_if_exists=True)


def main():
    soc     = MGMTSoC()
    builder = Builder(soc, compile_software=False)
    builder.build()

    lxsocdoc.generate_docs(soc, "build/documentation/", project_name="Caravel Management SoC", author="Efabless")

    # from migen.sim import Simulator, TopLevel
    # from migen.sim.vcd import TopLevel
    # sim = Simulator(soc, TopLevel("ledblinker.vcd"))
    # sim.run(200)


if __name__ == "__main__":
    main()