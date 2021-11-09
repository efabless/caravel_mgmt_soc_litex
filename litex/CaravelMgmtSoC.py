#
# This file is part of LiteX-Boards.
#
# Copyright (c) 2020 Piotr Esden-Tempski <piotr@esden.net>
# SPDX-License-Identifier: BSD-2-Clause

from litex.build.generic_platform import *
from litex.build.lattice import LatticePlatform


# IOs ----------------------------------------------------------------------------------------------
_io = [
    ("core_clk", 0, Pins(1)),
    ("core_rst", 0, Pins(1)),
    # ("sys_clk", 0, Pins(1)),
    # ("sys_rst", 0, Pins(1)),

        # Serial
 
    ("serial_dbg", 0,
        Subsignal("rx", Pins("1")),
        Subsignal("tx", Pins("1")),
    ),

    ("ser", 0,
        Subsignal("rx", Pins("1")),
        Subsignal("tx", Pins("1")),
    ),

    # SPIFlash
    # SPI Mode
    # ("flash", 0,
    #     Subsignal("cs_n", Pins("1")),
    #     Subsignal("clk",  Pins("1")),
    #     Subsignal("miso", Pins("1")),
    #     Subsignal("mosi", Pins("1")),
    #     Subsignal("wp",   Pins("1")),
    #     Subsignal("hold", Pins("1")),
    # ),
    # QSPI mode
    # ("spiflash4x", 0,
    ("flash", 0,
        Subsignal("cs_n", Pins(1)),
        # Subsignal("csb", Pins(1)),
        Subsignal("clk",  Pins(1)),
        # Subsignal("dq",   Pins(4)),
        Subsignal("io0_oeb", Pins(1)),
        Subsignal("io1_oeb", Pins(1)),
        Subsignal("io2_oeb", Pins(1)),
        Subsignal("io3_oeb", Pins(1)),
        Subsignal("io0_do", Pins(1)),
        Subsignal("io1_do", Pins(1)),
        Subsignal("io2_do", Pins(1)),
        Subsignal("io3_do", Pins(1)),
        Subsignal("io0_di",   Pins(1)),
        Subsignal("io1_di",   Pins(1)),
        Subsignal("io2_di",   Pins(1)),
        Subsignal("io3_di",   Pins(1)),
    ),

    # SPI master Controller
    ("spi", 0,
        Subsignal("clk",  Pins(1)),
        Subsignal("cs_n", Pins(1)),
        Subsignal("mosi", Pins(1)),
        Subsignal("miso", Pins(1)),
    ),

    # GPIO Pin
    ("gpio", 0,
        Subsignal("out_pad",  Pins(1)),
        Subsignal("in_pad", Pins(1)),
        Subsignal("outenb_pad", Pins(1)),
        Subsignal("inenb_pad", Pins(1)),
        Subsignal("mode0_pad", Pins(1)),
        Subsignal("mode1_pad", Pins(1)),
    ),

    # Logic Analyzer
    ("la", 0,
     Subsignal("output", Pins(128)),
     Subsignal("input", Pins(128)),
     Subsignal("oenb", Pins(128)),
     Subsignal("iena", Pins(128)),
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
    ("user_irq", 0,
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
        top_output = self.get_verilog(fragment, name="mgmt_core")
        top_output.write("mgmt_core.v")

    # def get_verilog(self, *args, special_overrides=dict(), **kwargs):
    #     so = dict(common.altera_special_overrides)
    #     so.update(special_overrides)
    #     return GenericPlatform.get_verilog(self, *args,
    #         special_overrides = so,
    #         attr_translate    = self.toolchain.attr_translate,
    #         **kwargs)
    #
    # def build(self, *args, **kwargs):
    #     return self.toolchain.build(self, *args, **kwargs)

    def get_verilog(self, fragment, **kwargs):
        return verilog.convert(fragment, platform=self, regular_comb=False, **kwargs)

    def _new_print_combinatorial_logic_sim(f, ns):
        r = ""
        if f.comb:
            from collections import defaultdict

            target_stmt_map = defaultdict(list)

            for statement in verilog.flat_iteration(f.comb):
                targets = verilog.list_targets(statement)
                for t in targets:
                    target_stmt_map[t].append(statement)

            groups = verilog.group_by_targets(f.comb)

            for n, (t, stmts) in enumerate(target_stmt_map.items()):
                assert isinstance(t, Signal)
                if len(stmts) == 1 and isinstance(stmts[0], verilog._Assign):
                    r += "assign " + verilog._print_node(ns, verilog._AT_BLOCKING, 0, stmts[0])
                else:
                    r += "always @(*) begin\n"
                    # r += "\t" + ns.get_name(t) + " <= " + _print_expression(ns, t.reset)[0] + ";\n"
                    # r += _print_node(ns, _AT_NONBLOCKING, 1, stmts, t)
                    r += "\t" + ns.get_name(t) + " = " + verilog._print_expression(ns, t.reset)[0] + ";\n"
                    r += verilog._print_node(ns, verilog._AT_BLOCKING, 1, stmts, t)
                    r += "end\n"
        r += "\n"
        return r

    verilog._print_combinatorial_logic_sim = _new_print_combinatorial_logic_sim

