from migen import *
from litex.soc.interconnect import wishbone

kB = 1024

class OpenRAM(Module):
    def __init__(self, width=32, size=1*kB):
        self.bus = wishbone.Interface(width)

        # # #

        assert width in [32]
        assert size in [2*kB]
        depth_cascading = size//(1*kB)
        width_cascading = 1
        
        # Combine RAMs to increase Depth.
        for d in range(depth_cascading):
            # Combine RAMs to increase Width.
            for w in range(width_cascading):
                datain   = Signal(32)
                dataout  = Signal(32)
                maskwren = Signal(4)
                wren     = Signal()
                self.comb += [
                    
                    datain.eq(self.bus.dat_w[16*w:16*(w+1)]),
                    If(self.bus.adr[14:14+log2_int(depth_cascading)+1] == d,
                        wren.eq(self.bus.we & self.bus.stb & self.bus.cyc),
                        self.bus.dat_r[16*w:16*(w+1)].eq(dataout)
                    ),
                    # maskwren is nibble based
                    maskwren[0].eq(self.bus.sel[2*w + 0]),
                    maskwren[1].eq(self.bus.sel[2*w + 0]),
                    maskwren[2].eq(self.bus.sel[2*w + 1]),
                    maskwren[3].eq(self.bus.sel[2*w + 1]),
                ]
                self.specials += Instance("sram_1rw1r_32_256_8_sky130",
                    i_clk0      = ClockSignal("sys"),
                    #i_STANDBY    = 0b0,
                    #i_SLEEP      = 0b0,
                    #i_POWEROFF   = 0b1,
                    i_addr0   = self.bus.adr[:7],
                    i_din0    = datain,
                    i_wmask0  = maskwren,
                    i_web0    = wren,
                    i_csb0    = 0b1,
                    o_dout0   = dataout
                )

        self.sync += self.bus.ack.eq(self.bus.stb & self.bus.cyc & ~self.bus.ack)
