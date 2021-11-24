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
from litex.soc.cores.uart import UARTWishboneBridge, UART, RS232PHY
from litex.soc.cores.gpio import *
from GPIOASIC import *
from litex.soc.cores.spi import SPIMaster, SPISlave
import litex.soc.doc as lxsocdoc

from CaravelMgmtSoC import Platform
from OpenRAM import *

# SoCMini.mem_map = {
#     "dff": 0x00000000,
#     "sram": 0x01000000,
#     "flash": 0x10000000,
#     "mprj": 0x30000000,
#     "hk": 0x26000000,
#     "csr": 0x20000000,
# }

# MGMTSoC
class MGMTSoC(SoCMini):

    def __init__(self, sys_clk_freq=int(10e6), **kwargs ):

        ##
        ## Uncomment cpu selection for mgmt core below
        ##
        # cpu = 'picorv32'
        # cpu = 'ibex'
        cpu = 'vexriscv'

        platform = Platform("mgmt_soc")

        # CRG --------------------------------------------------------------------------------------
        self.submodules.crg = CRG(platform.request("core_clk"), rst=platform.request("core_rst"))

        if cpu == 'vexriscv':
            SoCMini.__init__(self, platform,
                             clk_freq=sys_clk_freq,
                             cpu_type="vexriscv",
                             cpu_variant="minimal+debug",
                             # cpu_reset_address=self.mem_map["flash"],
                             cpu_reset_address=0x10000000,
                             csr_data_width=32,
                             integrated_sram_size=0,
                             integrated_rom_size=0,
                             with_uart=True,
                             uart_baudrate=9600,
                             uart_name="serial",
                             with_timer=True,
                             **kwargs)

            self.mem_map = {
                "dff": 0x00000000,
                "sram": 0x01000000,
                "flash": 0x10000000,
                "mprj": 0x30000000,
                "hk": 0x26000000,
                # "csr": 0x20000000,
                "csr": 0xf0000000,
                "vexriscv_debug": 0xf00f0000
            }

        # self.cpu.cpu_reset_address = self.mem_map["flash"]
        elif cpu == 'ibex':
            self.mem_map = {
                "dff": 0x00000000,
                "sram": 0x01000000,
                "flash": 0x10000000,
                "mprj": 0x30000000,
                "hk": 0x26000000,
                "csr": 0x20000000,
                # "csr": 0xf0000000,
            }
            SoCMini.__init__(self, platform,
                             clk_freq=sys_clk_freq,
                             cpu_type="ibex",
                             cpu_variant="standard",
                             cpu_reset_address=self.mem_map["flash"],
                             csr_data_width=32,
                             integrated_sram_size=0,
                             integrated_rom_size=0,
                             with_uart=True,
                             uart_baudrate=9600,
                             uart_name="serial",
                             with_timer=True,
                             **kwargs)

            self.cpu.cpu_params["p_RegFile"] = 0  # Reg File = FlipFlop

        elif cpu == 'picorv32':
            self.mem_map = {
                "dff": 0x00000000,
                "sram": 0x01000000,
                "flash": 0x10000000,
                "mprj": 0x30000000,
                "hk": 0x26000000,
                "csr": 0x20000000,
                # "csr": 0xf0000000,
            }
            SoCMini.__init__(self, platform,
                             clk_freq=sys_clk_freq,
                             cpu_type="picorv32",
                             cpu_variant="minimal",
                             cpu_reset_address=self.mem_map["flash"],
                             csr_data_width=32,
                             integrated_sram_size=0,
                             integrated_rom_size=0,
                             with_uart=True,
                             uart_baudrate=9600,
                             uart_name="serial",
                             with_timer=True,
                             **kwargs)

        else:
            print("ERROR - cpu value not recognized")
            exit()

        #DFFRAM
        dff_size = 1 * 1024
        dff = self.submodules.mem = DFFRAM(size=dff_size)
        self.register_mem("dff", self.mem_map["dff"], self.mem.bus, dff_size)
        mgmt_soc_dff = platform.request("mgmt_soc_dff")
        self.comb += mgmt_soc_dff.WE.eq(dff.we)
        self.comb += mgmt_soc_dff.A.eq(dff.bus.adr)
        self.comb += dff.do.eq(mgmt_soc_dff.Do)
        self.comb += mgmt_soc_dff.Di.eq(dff.di)
        self.comb += mgmt_soc_dff.EN.eq(dff.en)

        #OpenRAM
        spram_size = 2 * 1024
        sram = self.submodules.spram = OpenRAM(size=spram_size)
        self.register_mem("sram", self.mem_map["sram"], self.spram.bus, spram_size)
        sram_ro_ports = platform.request("sram_ro")
        self.comb += sram_ro_ports.clk.eq(sram.clk1)
        self.comb += sram_ro_ports.csb.eq(sram.cs_b1)
        self.comb += sram_ro_ports.addr.eq(sram.adr1)
        self.comb += sram_ro_ports.data.eq(sram.dataout1)

        # SPI Flash --------------------------------------------------------------------------------
        from litespi.modules import W25Q128JV
        from litespi.opcodes import SpiNorFlashOpCodes as Codes
        self.new_add_spi_flash(name="flash", mode="1x", module=W25Q128JV(Codes.READ_1_1_1), with_master=True)
        # self.new_add_spi_flash(name="flash", mode="4x", module=W25Q128JV(Codes.READ_1_1_4), with_master=True)

        # Add a master SPI controller w/ a clock divider
        spi_master = SPIMaster(
            pads=platform.request("spi"),
            data_width=8,
            sys_clk_freq=sys_clk_freq,
            spi_clk_freq=1e5,
        )
        spi_master.add_clk_divider()
        self.submodules.spi_master = spi_master
        #self.add_interrupt(interrupt_name="spi_master")
        self.comb += spi_master.pads.sdoenb.eq(~spi_master.pads.cs_n)

        # Add a wb port for external slaves user_project
        mprj_ports = platform.request("mprj")
        mprj = wishbone.Interface()
        self.bus.add_slave(name="mprj", slave=mprj, region=SoCRegion(origin=self.mem_map["mprj"], size=0x0100000))
        self.submodules.mprj_wb_iena = GPIOOut(mprj_ports.wb_iena)
        self.comb += mprj_ports.cyc_o.eq(mprj.cyc)
        self.comb += mprj_ports.stb_o.eq(mprj.stb)
        self.comb += mprj_ports.we_o.eq(mprj.we)
        self.comb += mprj_ports.sel_o.eq(mprj.sel)
        self.comb += mprj_ports.adr_o.eq(mprj.adr)
        self.comb += mprj.dat_r.eq(mprj_ports.dat_i)
        self.comb += mprj_ports.dat_o.eq(mprj.dat_w)
        self.comb += mprj.ack.eq(mprj_ports.ack_i)

        # Add a wb port for external slaves housekeeping
        hk = wishbone.Interface()
        self.bus.add_slave(name="hk", slave=hk, region=SoCRegion(origin=self.mem_map["hk"], size=0x0100000))
        hk_ports = platform.request("hk")
        self.comb += hk_ports.stb_o.eq(hk.stb)
        self.comb += hk.dat_r.eq(hk_ports.dat_i)
        self.comb += hk.ack.eq(hk_ports.ack_i)

        # Add Debug Interface (UART)
        debug_ports = platform.request("debug")
        self.submodules.debug = UARTWishboneBridge(debug_ports, sys_clk_freq, baudrate=115200)
        self.add_wb_master(self.debug.wishbone)
        self.submodules.debug_oeb = GPIOOut(debug_ports.oeb)  #TODO add logic for this


        # Add a GPIO Pin
        self.submodules.gpio = GPIOASIC(platform.request("gpio"))

        # Add the logic Analyzer
        self.submodules.la = LogicAnalyzer(platform.request("la"))
        # self.submodules.la_ien = GPIOOut(platform.request("la_ien"))

        # Add the user's input control
        self.submodules.qspi_enabled = GPIOOut(platform.request("qspi_enabled"))
        self.submodules.uart_enabled = GPIOOut(platform.request("uart_enabled"))
        self.submodules.spi_enabled = GPIOOut(platform.request("spi_enabled"))
        self.submodules.debug_mode = GPIOOut(platform.request("debug_mode"))

        trap = platform.request("trap")
        if cpu == 'picorv32':
            self.comb += trap.eq(self.cpu.trap)

        self.submodules.user_irq_ena = GPIOOut(platform.request("user_irq_ena"))

        # Add 6 IRQ lines
        user_irq = platform.request("user_irq")
        for i in range(len(user_irq)):
            setattr(self.submodules,"user_irq_"+str(i),GPIOIn(user_irq[i], with_irq=True))
            self.irq.add("user_irq_"+str(i), use_loc_if_exists=True)

    #####################

    def new_add_spi_flash(self, name="flash", mode="4x", dummy_cycles=None, clk_freq=None, module=None, phy=None, rate="1:1", **kwargs):
        if module is None:
            # Use previous LiteX SPI Flash core with compat, will be deprecated at some point.
            from litex.compat.soc_add_spi_flash import add_spi_flash
            add_spi_flash(self, name, mode, dummy_cycles)
        # LiteSPI.
        else:
            # Imports.
            from litespi import LiteSPI
            # from litespi.phy.generic import LiteSPIPHY
            from generic import LiteSPIPHY
            from litespi.opcodes import SpiNorFlashOpCodes

            # Checks/Parameters.
            assert mode in ["1x", "4x"]
            if clk_freq is None: clk_freq = self.sys_clk_freq

            # PHY.
            spiflash_phy = phy
            if spiflash_phy is None:
                self.check_if_exists(name + "_phy")
                spiflash_pads = self.platform.request(name)
                # spiflash_pads = self.platform.request(name if mode == "1x" else name + mode)
                spiflash_phy = LiteSPIPHY(spiflash_pads, module, device=self.platform.device, default_divisor=int(self.sys_clk_freq/clk_freq), rate=rate)
                setattr(self.submodules, name + "_phy",  spiflash_phy)

            # Core.
            self.check_if_exists(name + "_mmap")
            spiflash_core = LiteSPI(spiflash_phy, mmap_endianness=self.cpu.endianness, **kwargs)
            setattr(self.submodules, name + "_core", spiflash_core)
            spiflash_region = SoCRegion(origin=self.mem_map.get(name, None), size=module.total_size)
            self.bus.add_slave(name=name, slave=spiflash_core.bus, region=spiflash_region)

            # Constants.
            self.add_constant("SPIFLASH_PHY_FREQUENCY", clk_freq)
            self.add_constant("SPIFLASH_MODULE_NAME", module.name.upper())
            self.add_constant("SPIFLASH_MODULE_TOTAL_SIZE", module.total_size)
            self.add_constant("SPIFLASH_MODULE_PAGE_SIZE", module.page_size)
            if SpiNorFlashOpCodes.READ_1_1_4 in module.supported_opcodes:
                self.add_constant("SPIFLASH_MODULE_QUAD_CAPABLE")
            if SpiNorFlashOpCodes.READ_4_4_4 in module.supported_opcodes:
                self.add_constant("SPIFLASH_MODULE_QPI_CAPABLE")

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