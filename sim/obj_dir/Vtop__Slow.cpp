// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========
WData/*127:0*/ Vtop::__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[256][4];

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModule{_vcname__}
 {
    Vtop__Syms* __restrict vlSymsp = __VlSymsp = new Vtop__Syms(_vcontextp__, this, name());
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vtop::__Vconfigure(Vtop__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-12);
}

Vtop::~Vtop() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = nullptr);
}

void Vtop::_initial__TOP__1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_initial__TOP__1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__mgmtsoc_scratch_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_bus_errors_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_txfull_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rxempty_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_status_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_enable_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_txempty_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rxfull_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_load_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_reload_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_en_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_value_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_status_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_enable_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_cs_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_phyconfig_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_status_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_first = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_last = 0U;
    vlTOPp->top__DOT__gpio_mode1_re = 0U;
    vlTOPp->top__DOT__gpio_mode0_re = 0U;
    vlTOPp->top__DOT__gpio_ien_re = 0U;
    vlTOPp->top__DOT__gpio_oe_re = 0U;
    vlTOPp->top__DOT__gpio_in_re = 0U;
    vlTOPp->top__DOT__gpio_out_re = 0U;
    vlTOPp->top__DOT__la_ien_re = 0U;
    vlTOPp->top__DOT__la_oe_re = 0U;
    vlTOPp->top__DOT__la_in_re = 0U;
    vlTOPp->top__DOT__la_out_re = 0U;
    vlTOPp->top__DOT__mprj_wb_iena_re = 0U;
    vlTOPp->top__DOT__user_irq_ena_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rxtx_we = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_source_ready = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_source_first = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_source_last = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_mask = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_first = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_last = 0U;
    vlTOPp->top__DOT__csrbank0_reset0_we = 0U;
    vlTOPp->top__DOT__csrbank0_scratch0_we = 0U;
    vlTOPp->top__DOT__csrbank0_bus_errors_we = 0U;
    vlTOPp->top__DOT__csrbank1_mode10_we = 0U;
    vlTOPp->top__DOT__csrbank1_mode00_we = 0U;
    vlTOPp->top__DOT__csrbank1_ien0_we = 0U;
    vlTOPp->top__DOT__csrbank1_oe0_we = 0U;
    vlTOPp->top__DOT__csrbank1_in_we = 0U;
    vlTOPp->top__DOT__csrbank1_out0_we = 0U;
    vlTOPp->top__DOT__csrbank2_ien3_we = 0U;
    vlTOPp->top__DOT__csrbank2_ien2_we = 0U;
    vlTOPp->top__DOT__csrbank2_ien1_we = 0U;
    vlTOPp->top__DOT__csrbank2_ien0_we = 0U;
    vlTOPp->top__DOT__csrbank2_oe3_we = 0U;
    vlTOPp->top__DOT__csrbank2_oe2_we = 0U;
    vlTOPp->top__DOT__csrbank2_oe1_we = 0U;
    vlTOPp->top__DOT__csrbank2_oe0_we = 0U;
    vlTOPp->top__DOT__csrbank2_in3_re = 0U;
    vlTOPp->top__DOT__csrbank2_in3_we = 0U;
    vlTOPp->top__DOT__csrbank2_in2_re = 0U;
    vlTOPp->top__DOT__csrbank2_in2_we = 0U;
    vlTOPp->top__DOT__csrbank2_in1_re = 0U;
    vlTOPp->top__DOT__csrbank2_in1_we = 0U;
    vlTOPp->top__DOT__csrbank2_in0_we = 0U;
    vlTOPp->top__DOT__csrbank2_out3_we = 0U;
    vlTOPp->top__DOT__csrbank2_out2_we = 0U;
    vlTOPp->top__DOT__csrbank2_out1_we = 0U;
    vlTOPp->top__DOT__csrbank2_out0_we = 0U;
    vlTOPp->top__DOT__csrbank3_out0_we = 0U;
    vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_we = 0U;
    vlTOPp->top__DOT__csrbank4_master_cs0_we = 0U;
    vlTOPp->top__DOT__csrbank4_master_phyconfig0_we = 0U;
    vlTOPp->top__DOT__csrbank4_master_status_we = 0U;
    vlTOPp->top__DOT__csrbank5_clk_divisor0_we = 0U;
    vlTOPp->top__DOT__csrbank6_load0_we = 0U;
    vlTOPp->top__DOT__csrbank6_reload0_we = 0U;
    vlTOPp->top__DOT__csrbank6_en0_we = 0U;
    vlTOPp->top__DOT__csrbank6_update_value0_we = 0U;
    vlTOPp->top__DOT__csrbank6_value_we = 0U;
    vlTOPp->top__DOT__csrbank6_ev_status_we = 0U;
    vlTOPp->top__DOT__csrbank6_ev_pending_we = 0U;
    vlTOPp->top__DOT__csrbank6_ev_enable0_we = 0U;
    vlTOPp->top__DOT__csrbank7_txfull_we = 0U;
    vlTOPp->top__DOT__csrbank7_rxempty_we = 0U;
    vlTOPp->top__DOT__csrbank7_ev_status_we = 0U;
    vlTOPp->top__DOT__csrbank7_ev_pending_we = 0U;
    vlTOPp->top__DOT__csrbank7_ev_enable0_we = 0U;
    vlTOPp->top__DOT__csrbank7_txempty_we = 0U;
    vlTOPp->top__DOT__csrbank7_rxfull_we = 0U;
    vlTOPp->top__DOT__csrbank8_out0_we = 0U;
    vlTOPp->top__DOT__array_muxed6 = 0U;
    vlTOPp->top__DOT__array_muxed7 = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_pending_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_pending_r = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_first = 0U;
    vlTOPp->top__DOT__array_muxed1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_last = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_data = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_mask = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_last = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_rx_d = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_rx_d = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_sink_payload_data = 0U;
    vlTOPp->top__DOT__uart_bridge_incr = 0U;
    vlTOPp->top__DOT__uart_bridge_length = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_last = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_sink_ready = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_data = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_data = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_data = 0U;
    vlTOPp->top__DOT__uart_bridge_words_count = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_pending = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_pending = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt = 0U;
    vlTOPp->top__DOT__uart_bridge_cmd = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_len = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_count = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_source_payload_data = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_source_valid = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_sink_valid = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_width = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_pending_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_pending_r = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_tick = 0U;
    vlTOPp->top__DOT__slave_sel_r = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_dat_r = 0U;
    vlTOPp->top__DOT__mgmtsoc_wishbone_dat_r = 0U;
    vlTOPp->top__DOT__uart_bridge_data = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_count = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr = 0U;
    vlTOPp->top__DOT__rs232phy_rs232phyrx_state = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_sink_ready = 0U;
    vlTOPp->top__DOT__mgmtsoc_soc_rst = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_data = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_tick = 0U;
    vlTOPp->top__DOT__rs232phy_rs232phytx_state = 0U;
    vlTOPp->top__DOT__uart_bridge_bytes_count = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_source_valid = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data = 0U;
    vlTOPp->top__DOT__interface0_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface1_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface2_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface3_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface4_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface5_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface6_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface7_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__interface8_bank_bus_dat_r = 0U;
    vlTOPp->top__DOT__multiregimpl3_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl4_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl5_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl6_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl7_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl8_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl9_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl10_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl11_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl12_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl13_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl14_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl15_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl16_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl17_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl18_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl19_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl20_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl21_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl22_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl23_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl24_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl25_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl26_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl27_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl28_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl29_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl30_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl31_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl32_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl33_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl34_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl35_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl36_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl37_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl38_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl39_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl40_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl41_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl42_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl43_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl44_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl45_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl46_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl47_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl48_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl49_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl50_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl51_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl52_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl53_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl54_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl55_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl56_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl57_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl58_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl59_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl60_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl61_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl62_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl63_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl64_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl65_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl66_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl67_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl68_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl69_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl70_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl71_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl72_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl73_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl74_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl75_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl76_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl77_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl78_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl79_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl80_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl81_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl82_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl83_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl84_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl85_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl86_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl87_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl88_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl89_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl90_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl91_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl92_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl93_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl94_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl95_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl96_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl97_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl98_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl99_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl100_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl101_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl102_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl103_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl104_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl105_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl106_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl107_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl108_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl109_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl110_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl111_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl112_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl113_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl114_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl115_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl116_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl117_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl118_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl119_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl120_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl121_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl122_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl123_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl124_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl125_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl126_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl127_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl128_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl129_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl130_regs1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2 = 0U;
    vlTOPp->top__DOT__mgmtsoc_reset_re = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_count = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_tick = 0U;
    vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_count = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_tick = 0U;
    vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_ack = 0U;
    vlTOPp->top__DOT__mgmtsoc_wishbone_ack = 0U;
    vlTOPp->top__DOT__mgmtsoc_we = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid = 0U;
    vlTOPp->top__DOT__array_muxed2 = 0U;
    vlTOPp->top__DOT__array_muxed5 = 0U;
    vlTOPp->top__DOT__litespi_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_valid = 0U;
    vlTOPp->top__DOT__uart_bridge_wishbone_we = 0U;
    vlTOPp->top__DOT__state = 0U;
    vlTOPp->top__DOT__litespiphy_state = 0U;
    vlTOPp->top__DOT__uart_bridge_wishbone_stb = 0U;
    vlTOPp->top__DOT__uart_bridge_wishbone_cyc = 0U;
    vlTOPp->top__DOT__array_muxed0 = 0U;
    vlTOPp->top__DOT__uart_bridge_address = 0U;
    vlTOPp->top__DOT__uartwishbonebridge_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_scratch_storage = 0x12345678U;
    vlTOPp->top__DOT__mgmtsoc_bus_errors = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_phase = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_phase = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_trigger_d = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_trigger_d = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_consume = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_update_value_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_value_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_payload_data = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_phase = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_phase = 0U;
    vlTOPp->top__DOT__multiregimpl2_regs1 = 0U;
    vlTOPp->top__DOT__multiregimpl3_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl4_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl5_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl6_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl7_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl8_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl9_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl10_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl11_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl12_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl13_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl14_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl15_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl16_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl17_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl18_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl19_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl20_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl21_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl22_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl23_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl24_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl25_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl26_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl27_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl28_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl29_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl30_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl31_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl32_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl33_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl34_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl35_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl36_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl37_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl38_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl39_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl40_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl41_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl42_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl43_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl44_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl45_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl46_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl47_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl48_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl49_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl50_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl51_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl52_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl53_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl54_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl55_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl56_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl57_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl58_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl59_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl60_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl61_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl62_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl63_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl64_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl65_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl66_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl67_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl68_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl69_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl70_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl71_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl72_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl73_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl74_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl75_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl76_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl77_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl78_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl79_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl80_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl81_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl82_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl83_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl84_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl85_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl86_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl87_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl88_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl89_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl90_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl91_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl92_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl93_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl94_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl95_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl96_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl97_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl98_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl99_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl100_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl101_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl102_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl103_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl104_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl105_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl106_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl107_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl108_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl109_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl110_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl111_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl112_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl113_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl114_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl115_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl116_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl117_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl118_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl119_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl120_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl121_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl122_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl123_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl124_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl125_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl126_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl127_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl128_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl129_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl130_regs0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_enable = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_source_valid = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_source_payload_data = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_enable = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_clear = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_load = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_shift = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift = 0U;
    vlTOPp->top__DOT__mgmtsoc_crossbar_cs = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_wait = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_rxtx_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_status_status = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_enable = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_enable = 0U;
    vlTOPp->top__DOT__uart_bridge_is_ongoing = 0U;
    vlTOPp->top__DOT__la_in_status[0U] = 0U;
    vlTOPp->top__DOT__la_in_status[1U] = 0U;
    vlTOPp->top__DOT__la_in_status[2U] = 0U;
    vlTOPp->top__DOT__la_in_status[3U] = 0U;
    vlTOPp->top__DOT__rs232phy_rs232phytx_next_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2 = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2 = 0U;
    vlTOPp->top__DOT__rs232phy_rs232phyrx_next_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value_ce1 = 0U;
    vlTOPp->top__DOT__litespiphy_next_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_data = 0U;
    vlTOPp->top__DOT__litespi_next_state = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = 0U;
    vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_next_state = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0 = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0 = 0U;
    vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1 = 0U;
    vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1 = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2 = 0U;
    vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2 = 0U;
    vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_next_state = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0 = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0 = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value1 = 0U;
    vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value_ce1 = 0U;
    vlTOPp->top__DOT__uartwishbonebridge_next_state = 0U;
    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 = 0U;
    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 0U;
    vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 = 0U;
    vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = 0U;
    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2 = 0U;
    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2 = 0U;
    vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value3 = 0U;
    vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value_ce3 = 0U;
    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4 = 0U;
    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4 = 0U;
    vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5 = 0U;
    vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5 = 0U;
    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value6 = 0U;
    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6 = 0U;
    vlTOPp->top__DOT__error = 0U;
    vlTOPp->top__DOT__csrbank0_bus_errors_re = 0U;
    vlTOPp->top__DOT__csrbank1_in_re = 0U;
    vlTOPp->top__DOT__csrbank2_in0_re = 0U;
    vlTOPp->top__DOT__csrbank4_master_status_re = 0U;
    vlTOPp->top__DOT__csrbank6_value_re = 0U;
    vlTOPp->top__DOT__csrbank6_ev_status_re = 0U;
    vlTOPp->top__DOT__csrbank6_ev_pending_re = 0U;
    vlTOPp->top__DOT__csrbank7_txfull_re = 0U;
    vlTOPp->top__DOT__csrbank7_rxempty_re = 0U;
    vlTOPp->top__DOT__csrbank7_ev_status_re = 0U;
    vlTOPp->top__DOT__csrbank7_ev_pending_re = 0U;
    vlTOPp->top__DOT__csrbank7_txempty_re = 0U;
    vlTOPp->top__DOT__csrbank7_rxfull_re = 0U;
    vlTOPp->top__DOT__next_state = 0U;
    vlTOPp->top__DOT__uart_bridge_count = 0xf4240U;
    vlTOPp->top__DOT__gpio_mode1_storage = 0U;
    vlTOPp->top__DOT__gpio_mode0_storage = 0U;
    vlTOPp->top__DOT__gpio_ien_storage = 0U;
    vlTOPp->top__DOT__gpio_oe_storage = 0U;
    vlTOPp->top__DOT__gpio_out_storage = 0U;
    vlTOPp->top__DOT__la_ien_storage[0U] = 0U;
    vlTOPp->top__DOT__la_ien_storage[1U] = 0U;
    vlTOPp->top__DOT__la_ien_storage[2U] = 0U;
    vlTOPp->top__DOT__la_ien_storage[3U] = 0U;
    vlTOPp->top__DOT__la_oe_storage[0U] = 0U;
    vlTOPp->top__DOT__la_oe_storage[1U] = 0U;
    vlTOPp->top__DOT__la_oe_storage[2U] = 0U;
    vlTOPp->top__DOT__la_oe_storage[3U] = 0U;
    vlTOPp->top__DOT__la_out_storage[0U] = 0U;
    vlTOPp->top__DOT__la_out_storage[1U] = 0U;
    vlTOPp->top__DOT__la_out_storage[2U] = 0U;
    vlTOPp->top__DOT__la_out_storage[3U] = 0U;
    vlTOPp->top__DOT__mprj_wb_iena_storage = 0U;
    vlTOPp->top__DOT__user_irq_ena_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_enable_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_zero_pending = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_enable_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_count = 0x100U;
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_len = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_cs_storage = 0U;
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_width = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0 = 0U;
    vlTOPp->top__DOT__multiregimpl0_regs1 = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count = 0xbU;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid = 0U;
    vlTOPp->top__DOT__mgmtsoc_reset_storage = 0U;
    vlTOPp->top__DOT__shared_ack = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in = 0U;
    vlTOPp->top__DOT__multiregimpl1_regs1 = 0U;
    vlTOPp->top__DOT__count = 0xf4240U;
    vlTOPp->top__DOT__mgmtsoc_adr = 0U;
    vlTOPp->top__DOT__litespi_grant = 0U;
    vlTOPp->top__DOT__array_muxed4 = 0U;
    vlTOPp->top__DOT__slave_sel = 0U;
    vlTOPp->top__DOT__array_muxed3 = 0U;
    vlTOPp->top__DOT__grant = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_consume = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_load_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_reload_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_en_storage = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_update_value_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_zero_trigger_d = 0U;
    vlTOPp->top__DOT__multiregimpl0_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl1_regs0 = 0U;
    vlTOPp->top__DOT__multiregimpl2_regs0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_timer_zero_clear = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_valid = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_first = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_last = 0U;
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_payload_data = 0U;
    vlTOPp->top__DOT__csrbank0_reset0_re = 0U;
    vlTOPp->top__DOT__csrbank0_scratch0_re = 0U;
    vlTOPp->top__DOT__csrbank1_mode10_re = 0U;
    vlTOPp->top__DOT__csrbank1_mode00_re = 0U;
    vlTOPp->top__DOT__csrbank1_ien0_re = 0U;
    vlTOPp->top__DOT__csrbank1_oe0_re = 0U;
    vlTOPp->top__DOT__csrbank1_out0_re = 0U;
    vlTOPp->top__DOT__csrbank2_ien3_re = 0U;
    vlTOPp->top__DOT__csrbank2_ien2_re = 0U;
    vlTOPp->top__DOT__csrbank2_ien1_re = 0U;
    vlTOPp->top__DOT__csrbank2_ien0_re = 0U;
    vlTOPp->top__DOT__csrbank2_oe3_re = 0U;
    vlTOPp->top__DOT__csrbank2_oe2_re = 0U;
    vlTOPp->top__DOT__csrbank2_oe1_re = 0U;
    vlTOPp->top__DOT__csrbank2_oe0_re = 0U;
    vlTOPp->top__DOT__csrbank2_out3_re = 0U;
    vlTOPp->top__DOT__csrbank2_out2_re = 0U;
    vlTOPp->top__DOT__csrbank2_out1_re = 0U;
    vlTOPp->top__DOT__csrbank2_out0_re = 0U;
    vlTOPp->top__DOT__csrbank3_out0_re = 0U;
    vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_re = 0U;
    vlTOPp->top__DOT__csrbank4_master_cs0_re = 0U;
    vlTOPp->top__DOT__csrbank4_master_phyconfig0_re = 0U;
    vlTOPp->top__DOT__csrbank6_ev_enable0_re = 0U;
    vlTOPp->top__DOT__csrbank7_ev_enable0_re = 0U;
    vlTOPp->top__DOT__csrbank8_out0_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_tx_sink_ready = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0 = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_rxtx_we = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en = 0U;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage = 1U;
    vlTOPp->top__DOT__mgmtsoc_timer_value = 0U;
    vlTOPp->top__DOT__mgmtsoc_dat_w = 0U;
    vlTOPp->top__DOT__csrbank5_clk_divisor0_re = 0U;
    vlTOPp->top__DOT__csrbank6_load0_re = 0U;
    vlTOPp->top__DOT__csrbank6_reload0_re = 0U;
    vlTOPp->top__DOT__csrbank6_en0_re = 0U;
    vlTOPp->top__DOT__csrbank6_update_value0_re = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_clear = 0U;
    vlTOPp->top__DOT__int_rst = 1U;
    vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt = 0U;
    vlTOPp->top__DOT__shared_dat_r = 0U;
}

void Vtop::_settle__TOP__2(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_settle__TOP__2\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->top__DOT__array_muxed6 = 0U;
    vlTOPp->top__DOT__array_muxed7 = 0U;
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_opcode 
        = vlTOPp->top__DOT__picorv32__DOT__q_insn_opcode;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_opcode 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                ? vlTOPp->top__DOT__picorv32__DOT__cached_insn_opcode
                : ((3U == (3U & vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode))
                    ? vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode
                    : (0xffffU & vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode)));
    }
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs1 = vlTOPp->top__DOT__picorv32__DOT__q_insn_rs1;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs1 
            = (0x1fU & ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                         ? (IData)(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs1)
                         : (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1)));
    }
    vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1 = 
        ((0U != (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1))
          ? ((0x23U >= (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1))
              ? vlTOPp->top__DOT__picorv32__DOT__cpuregs
             [vlTOPp->top__DOT__picorv32__DOT__decoded_rs1]
              : 0U) : 0U);
    if ((0U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
        vlTOPp->top__DOT__mgmtsoc_picorv324 = 0xfU;
    } else {
        if ((1U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
            vlTOPp->top__DOT__mgmtsoc_picorv324 = (
                                                   (2U 
                                                    & vlTOPp->top__DOT__picorv32__DOT__reg_op1)
                                                    ? 0xcU
                                                    : 3U);
        } else {
            if ((2U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
                vlTOPp->top__DOT__mgmtsoc_picorv324 
                    = (0xfU & ((IData)(1U) << (3U & vlTOPp->top__DOT__picorv32__DOT__reg_op1)));
            }
        }
    }
    if ((0U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
        vlTOPp->top__DOT__mgmtsoc_picorv323 = vlTOPp->top__DOT__picorv32__DOT__reg_op2;
    } else {
        if ((1U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
            vlTOPp->top__DOT__mgmtsoc_picorv323 = (
                                                   (0xffff0000U 
                                                    & (vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                                       << 0x10U)) 
                                                   | (0xffffU 
                                                      & vlTOPp->top__DOT__picorv32__DOT__reg_op2));
        } else {
            if ((2U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
                vlTOPp->top__DOT__mgmtsoc_picorv323 
                    = ((0xff000000U & (vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                       << 0x18U)) | 
                       ((0xff0000U & (vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                      << 0x10U)) | 
                        ((0xff00U & (vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                     << 8U)) | (0xffU 
                                                & vlTOPp->top__DOT__picorv32__DOT__reg_op2))));
            }
        }
    }
    vlTOPp->top__DOT__picorv32__DOT__next_pc = (((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_store) 
                                                 & (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_branch))
                                                 ? 
                                                (0xfffffffeU 
                                                 & vlTOPp->top__DOT__picorv32__DOT__reg_out)
                                                 : vlTOPp->top__DOT__picorv32__DOT__reg_next_pc);
    vlTOPp->top__DOT__picorv32__DOT__cpuregs_write = 0U;
    if ((0x40U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
        if (vlTOPp->top__DOT__picorv32__DOT__latched_branch) {
            vlTOPp->top__DOT__picorv32__DOT__cpuregs_write = 1U;
        } else {
            if (((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_store) 
                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_branch)))) {
                vlTOPp->top__DOT__picorv32__DOT__cpuregs_write = 1U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) {
                    vlTOPp->top__DOT__picorv32__DOT__cpuregs_write = 1U;
                } else {
                    if ((2U & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) {
                        vlTOPp->top__DOT__picorv32__DOT__cpuregs_write = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->__Vtableidx1 = vlTOPp->top__DOT__picorv32__DOT__cpu_state;
    vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_state[0U] 
        = vlTOPp->__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state
        [vlTOPp->__Vtableidx1][0U];
    vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_state[1U] 
        = vlTOPp->__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state
        [vlTOPp->__Vtableidx1][1U];
    vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_state[2U] 
        = vlTOPp->__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state
        [vlTOPp->__Vtableidx1][2U];
    vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_state[3U] 
        = vlTOPp->__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state
        [vlTOPp->__Vtableidx1][3U];
    vlTOPp->top__DOT__picorv32__DOT__alu_eq = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                               == vlTOPp->top__DOT__picorv32__DOT__reg_op2);
    vlTOPp->top__DOT__picorv32__DOT__alu_lts = VL_LTS_III(1,32,32, vlTOPp->top__DOT__picorv32__DOT__reg_op1, vlTOPp->top__DOT__picorv32__DOT__reg_op2);
    vlTOPp->top__DOT__picorv32__DOT__alu_ltu = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                < vlTOPp->top__DOT__picorv32__DOT__reg_op2);
    vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2 = 
        ((0U != (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs2))
          ? ((0x23U >= (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs2))
              ? vlTOPp->top__DOT__picorv32__DOT__cpuregs
             [vlTOPp->top__DOT__picorv32__DOT__decoded_rs2]
              : 0U) : 0U);
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs2 = vlTOPp->top__DOT__picorv32__DOT__q_insn_rs2;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs2 
            = (0x1fU & ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                         ? (IData)(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs2)
                         : (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs2)));
    }
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rd = vlTOPp->top__DOT__picorv32__DOT__q_insn_rd;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rd 
            = (0x1fU & ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                         ? (IData)(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rd)
                         : (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rd)));
    }
    vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata = 0U;
    if ((0x40U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
        if (vlTOPp->top__DOT__picorv32__DOT__latched_branch) {
            vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata 
                = (vlTOPp->top__DOT__picorv32__DOT__reg_pc 
                   + ((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_compr)
                       ? 2U : 4U));
        } else {
            if (((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_store) 
                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_branch)))) {
                vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata 
                    = ((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_stalu)
                        ? vlTOPp->top__DOT__picorv32__DOT__alu_out_q
                        : vlTOPp->top__DOT__picorv32__DOT__reg_out);
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) {
                    vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata 
                        = (vlTOPp->top__DOT__picorv32__DOT__reg_next_pc 
                           | (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_compr));
                } else {
                    if ((2U & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) {
                        vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata 
                            = (vlTOPp->top__DOT__picorv32__DOT__irq_pending 
                               & (~ vlTOPp->top__DOT__picorv32__DOT__irq_mask));
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_imm = vlTOPp->top__DOT__picorv32__DOT__q_insn_imm;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_imm 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                ? vlTOPp->top__DOT__picorv32__DOT__cached_insn_imm
                : vlTOPp->top__DOT__picorv32__DOT__decoded_imm);
    }
    vlTOPp->top__DOT__picorv32__DOT__launch_next_insn 
        = (((0x40U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state)) 
            & (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger)) 
           & (((IData)(vlTOPp->top__DOT__picorv32__DOT__irq_delay) 
               | (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_active)) 
              | (~ (IData)((0U != (vlTOPp->top__DOT__picorv32__DOT__irq_pending 
                                   & (~ vlTOPp->top__DOT__picorv32__DOT__irq_mask)))))));
    vlTOPp->top__DOT__picorv32__DOT__instr_trap = (1U 
                                                   & (~ 
                                                      (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lui) 
                                                        | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_auipc) 
                                                           | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jal) 
                                                              | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jalr) 
                                                                 | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_beq) 
                                                                    | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_bne) 
                                                                       | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_blt) 
                                                                          | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_bge) 
                                                                             | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_bltu) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_bgeu) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lb) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lh) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lw) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lbu) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lhu) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sb) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sh) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sw) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_addi) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slti) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sltiu) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_xori) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_ori) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_andi) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slli) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srli) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srai) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_add) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sub) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sll) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slt) 
                                                                                | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sltu)))))))))))))))))))))))))))))))) 
                                                       | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_xor) 
                                                          | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srl) 
                                                             | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sra) 
                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_or) 
                                                                   | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_and) 
                                                                      | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdcycle) 
                                                                         | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdcycleh) 
                                                                            | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdinstr) 
                                                                               | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdinstrh) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_getq) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_setq) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_retirq) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_maskirq) 
                                                                                | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_waitirq) 
                                                                                | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_timer))))))))))))))))));
    vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0ULL;
    if (vlTOPp->top__DOT__picorv32__DOT__instr_lui) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6c7569ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_auipc) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6175697063ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_jal) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6a616cULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_jalr) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6a616c72ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_beq) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x626571ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_bne) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x626e65ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_blt) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x626c74ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_bge) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x626765ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_bltu) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x626c7475ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_bgeu) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x62676575ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_lb) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6c62ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_lh) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6c68ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_lw) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6c77ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_lbu) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6c6275ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_lhu) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6c6875ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sb) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x7362ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sh) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x7368ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sw) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x7377ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_addi) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x61646469ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_slti) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x736c7469ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sltiu) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x736c746975ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_xori) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x786f7269ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_ori) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6f7269ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_andi) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x616e6469ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_slli) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x736c6c69ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_srli) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x73726c69ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_srai) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x73726169ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_add) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x616464ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sub) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x737562ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sll) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x736c6cULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_slt) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x736c74ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sltu) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x736c7475ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_xor) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x786f72ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_srl) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x73726cULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_sra) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x737261ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_or) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6f72ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_and) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x616e64ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_rdcycle) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x72646379636c65ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_rdcycleh) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x72646379636c6568ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_rdinstr) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x7264696e737472ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_rdinstrh) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x7264696e73747268ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_getq) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x67657471ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_setq) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x73657471ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_retirq) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x726574697271ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_maskirq) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x6d61736b697271ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_waitirq) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x77616974697271ULL;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__instr_timer) {
        vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr = 0x74696d6572ULL;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_zero_clear = 0U;
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_timer_pending_re) 
         & (IData)(vlTOPp->top__DOT__mgmtsoc_timer_pending_r))) {
        vlTOPp->top__DOT__mgmtsoc_timer_zero_clear = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 
        ((2U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status)) 
         | (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_pending));
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 
        ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status)) 
         | ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_pending) 
            << 1U));
    vlTOPp->top__DOT__mgmtsoc_uart_tx_clear = 0U;
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_re) 
         & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_r))) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_clear = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rx_clear = 0U;
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_re) 
         & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_r) 
            >> 1U))) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_clear = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_rx_enable = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        vlTOPp->top__DOT__mgmtsoc_rx_enable = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0 = 1U;
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0 = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value_ce1 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value_ce1 = 1U;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0 
                = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_rx_count)));
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0 = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_rx_source_payload_data = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__mgmtsoc_rx_count))) {
                vlTOPp->top__DOT__mgmtsoc_rx_source_payload_data 
                    = vlTOPp->top__DOT__mgmtsoc_rx_data;
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_tx_enable = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        vlTOPp->top__DOT__mgmtsoc_tx_enable = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0 = 1U;
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0 = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0 
                = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_tx_count)));
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0 = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_tx_sink_ready = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__mgmtsoc_tx_count))) {
                vlTOPp->top__DOT__mgmtsoc_tx_sink_ready = 1U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_tx_sink_payload_data 
        = (0xffU & ((2U & (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))
                     ? ((1U & (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))
                         ? vlTOPp->top__DOT__uart_bridge_data
                         : (vlTOPp->top__DOT__uart_bridge_data 
                            >> 8U)) : ((1U & (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))
                                        ? (vlTOPp->top__DOT__uart_bridge_data 
                                           >> 0x10U)
                                        : (vlTOPp->top__DOT__uart_bridge_data 
                                           >> 0x18U))));
    vlTOPp->top__DOT__la_in_status[0U] = 0U;
    vlTOPp->top__DOT__la_in_status[1U] = 0U;
    vlTOPp->top__DOT__la_in_status[2U] = 0U;
    vlTOPp->top__DOT__la_in_status[3U] = 0U;
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffffeU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (IData)(vlTOPp->top__DOT__multiregimpl3_regs1));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffffdU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffffffeU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl4_regs1) 
                                                << 1U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffffbU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffffffcU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl5_regs1) 
                                                << 2U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffff7U 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffffff8U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl6_regs1) 
                                                << 3U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffffefU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffffff0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl7_regs1) 
                                                << 4U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffffdfU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffffffe0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl8_regs1) 
                                                << 5U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffffbfU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffffffc0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl9_regs1) 
                                                << 6U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffff7fU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffffff80U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl10_regs1) 
                                                << 7U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffeffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffffff00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl11_regs1) 
                                                << 8U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffdffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffffe00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl12_regs1) 
                                                << 9U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffffbffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffffc00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl13_regs1) 
                                                << 0xaU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffff7ffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffff800U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl14_regs1) 
                                                << 0xbU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffefffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffff000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl15_regs1) 
                                                << 0xcU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffdfffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffffe000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl16_regs1) 
                                                << 0xdU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffffbfffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffffc000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl17_regs1) 
                                                << 0xeU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffff7fffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffff8000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl18_regs1) 
                                                << 0xfU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffeffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffff0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl19_regs1) 
                                                << 0x10U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffdffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffe0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl20_regs1) 
                                                << 0x11U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfffbffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfffc0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl21_regs1) 
                                                << 0x12U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfff7ffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfff80000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl22_regs1) 
                                                << 0x13U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffefffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfff00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl23_regs1) 
                                                << 0x14U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffdfffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffe00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl24_regs1) 
                                                << 0x15U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xffbfffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xffc00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl25_regs1) 
                                                << 0x16U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xff7fffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xff800000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl26_regs1) 
                                                << 0x17U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfeffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xff000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl27_regs1) 
                                                << 0x18U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfdffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfe000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl28_regs1) 
                                                << 0x19U)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xfbffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xfc000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl29_regs1) 
                                                << 0x1aU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xf7ffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xf8000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl30_regs1) 
                                                << 0x1bU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xefffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xf0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl31_regs1) 
                                                << 0x1cU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xdfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xe0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl32_regs1) 
                                                << 0x1dU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0xbfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0xc0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl33_regs1) 
                                                << 0x1eU)));
    vlTOPp->top__DOT__la_in_status[0U] = ((0x7fffffffU 
                                           & vlTOPp->top__DOT__la_in_status[0U]) 
                                          | (0x80000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl34_regs1) 
                                                << 0x1fU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffffeU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (IData)(vlTOPp->top__DOT__multiregimpl35_regs1));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffffdU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffffffeU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl36_regs1) 
                                                << 1U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffffbU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffffffcU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl37_regs1) 
                                                << 2U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffff7U 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffffff8U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl38_regs1) 
                                                << 3U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffffefU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffffff0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl39_regs1) 
                                                << 4U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffffdfU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffffffe0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl40_regs1) 
                                                << 5U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffffbfU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffffffc0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl41_regs1) 
                                                << 6U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffff7fU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffffff80U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl42_regs1) 
                                                << 7U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffeffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffffff00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl43_regs1) 
                                                << 8U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffdffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffffe00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl44_regs1) 
                                                << 9U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffffbffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffffc00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl45_regs1) 
                                                << 0xaU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffff7ffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffff800U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl46_regs1) 
                                                << 0xbU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffefffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffff000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl47_regs1) 
                                                << 0xcU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffdfffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffffe000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl48_regs1) 
                                                << 0xdU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffffbfffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffffc000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl49_regs1) 
                                                << 0xeU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffff7fffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffff8000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl50_regs1) 
                                                << 0xfU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffeffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffff0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl51_regs1) 
                                                << 0x10U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffdffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffe0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl52_regs1) 
                                                << 0x11U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfffbffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfffc0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl53_regs1) 
                                                << 0x12U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfff7ffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfff80000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl54_regs1) 
                                                << 0x13U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffefffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfff00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl55_regs1) 
                                                << 0x14U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffdfffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffe00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl56_regs1) 
                                                << 0x15U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xffbfffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xffc00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl57_regs1) 
                                                << 0x16U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xff7fffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xff800000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl58_regs1) 
                                                << 0x17U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfeffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xff000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl59_regs1) 
                                                << 0x18U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfdffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfe000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl60_regs1) 
                                                << 0x19U)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xfbffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xfc000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl61_regs1) 
                                                << 0x1aU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xf7ffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xf8000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl62_regs1) 
                                                << 0x1bU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xefffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xf0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl63_regs1) 
                                                << 0x1cU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xdfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xe0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl64_regs1) 
                                                << 0x1dU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0xbfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0xc0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl65_regs1) 
                                                << 0x1eU)));
    vlTOPp->top__DOT__la_in_status[1U] = ((0x7fffffffU 
                                           & vlTOPp->top__DOT__la_in_status[1U]) 
                                          | (0x80000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl66_regs1) 
                                                << 0x1fU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffffeU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (IData)(vlTOPp->top__DOT__multiregimpl67_regs1));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffffdU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffffffeU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl68_regs1) 
                                                << 1U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffffbU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffffffcU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl69_regs1) 
                                                << 2U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffff7U 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffffff8U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl70_regs1) 
                                                << 3U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffffefU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffffff0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl71_regs1) 
                                                << 4U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffffdfU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffffffe0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl72_regs1) 
                                                << 5U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffffbfU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffffffc0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl73_regs1) 
                                                << 6U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffff7fU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffffff80U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl74_regs1) 
                                                << 7U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffeffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffffff00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl75_regs1) 
                                                << 8U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffdffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffffe00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl76_regs1) 
                                                << 9U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffffbffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffffc00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl77_regs1) 
                                                << 0xaU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffff7ffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffff800U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl78_regs1) 
                                                << 0xbU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffefffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffff000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl79_regs1) 
                                                << 0xcU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffdfffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffffe000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl80_regs1) 
                                                << 0xdU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffffbfffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffffc000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl81_regs1) 
                                                << 0xeU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffff7fffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffff8000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl82_regs1) 
                                                << 0xfU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffeffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffff0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl83_regs1) 
                                                << 0x10U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffdffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffe0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl84_regs1) 
                                                << 0x11U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfffbffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfffc0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl85_regs1) 
                                                << 0x12U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfff7ffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfff80000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl86_regs1) 
                                                << 0x13U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffefffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfff00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl87_regs1) 
                                                << 0x14U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffdfffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffe00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl88_regs1) 
                                                << 0x15U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xffbfffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xffc00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl89_regs1) 
                                                << 0x16U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xff7fffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xff800000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl90_regs1) 
                                                << 0x17U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfeffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xff000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl91_regs1) 
                                                << 0x18U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfdffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfe000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl92_regs1) 
                                                << 0x19U)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xfbffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xfc000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl93_regs1) 
                                                << 0x1aU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xf7ffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xf8000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl94_regs1) 
                                                << 0x1bU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xefffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xf0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl95_regs1) 
                                                << 0x1cU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xdfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xe0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl96_regs1) 
                                                << 0x1dU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0xbfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0xc0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl97_regs1) 
                                                << 0x1eU)));
    vlTOPp->top__DOT__la_in_status[2U] = ((0x7fffffffU 
                                           & vlTOPp->top__DOT__la_in_status[2U]) 
                                          | (0x80000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl98_regs1) 
                                                << 0x1fU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffffeU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (IData)(vlTOPp->top__DOT__multiregimpl99_regs1));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffffdU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffffffeU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl100_regs1) 
                                                << 1U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffffbU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffffffcU 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl101_regs1) 
                                                << 2U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffff7U 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffffff8U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl102_regs1) 
                                                << 3U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffffefU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffffff0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl103_regs1) 
                                                << 4U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffffdfU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffffffe0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl104_regs1) 
                                                << 5U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffffbfU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffffffc0U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl105_regs1) 
                                                << 6U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffff7fU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffffff80U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl106_regs1) 
                                                << 7U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffeffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffffff00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl107_regs1) 
                                                << 8U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffdffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffffe00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl108_regs1) 
                                                << 9U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffffbffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffffc00U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl109_regs1) 
                                                << 0xaU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffff7ffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffff800U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl110_regs1) 
                                                << 0xbU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffefffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffff000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl111_regs1) 
                                                << 0xcU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffdfffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffffe000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl112_regs1) 
                                                << 0xdU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffffbfffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffffc000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl113_regs1) 
                                                << 0xeU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffff7fffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffff8000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl114_regs1) 
                                                << 0xfU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffeffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffff0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl115_regs1) 
                                                << 0x10U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffdffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffe0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl116_regs1) 
                                                << 0x11U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfffbffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfffc0000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl117_regs1) 
                                                << 0x12U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfff7ffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfff80000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl118_regs1) 
                                                << 0x13U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffefffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfff00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl119_regs1) 
                                                << 0x14U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffdfffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffe00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl120_regs1) 
                                                << 0x15U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xffbfffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xffc00000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl121_regs1) 
                                                << 0x16U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xff7fffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xff800000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl122_regs1) 
                                                << 0x17U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfeffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xff000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl123_regs1) 
                                                << 0x18U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfdffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfe000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl124_regs1) 
                                                << 0x19U)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xfbffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xfc000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl125_regs1) 
                                                << 0x1aU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xf7ffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xf8000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl126_regs1) 
                                                << 0x1bU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xefffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xf0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl127_regs1) 
                                                << 0x1cU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xdfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xe0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl128_regs1) 
                                                << 0x1dU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0xbfffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0xc0000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl129_regs1) 
                                                << 0x1eU)));
    vlTOPp->top__DOT__la_in_status[3U] = ((0x7fffffffU 
                                           & vlTOPp->top__DOT__la_in_status[3U]) 
                                          | (0x80000000U 
                                             & ((IData)(vlTOPp->top__DOT__multiregimpl130_regs1) 
                                                << 0x1fU)));
    vlTOPp->top__DOT__uart_bridge_tx_enable = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        vlTOPp->top__DOT__uart_bridge_tx_enable = 1U;
    }
    vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0 = 1U;
        }
    } else {
        vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0 = 1U;
    }
    vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0 
                = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uart_bridge_tx_count)));
        }
    } else {
        vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0 = 0U;
    }
    vlTOPp->top__DOT__uart_bridge_tx_sink_ready = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__uart_bridge_tx_count))) {
                vlTOPp->top__DOT__uart_bridge_tx_sink_ready = 1U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_rx_enable = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        vlTOPp->top__DOT__uart_bridge_rx_enable = 1U;
    }
    vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value_ce1 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value_ce1 = 1U;
        }
    }
    vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0 = 1U;
        }
    } else {
        vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0 = 1U;
    }
    vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0 
                = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uart_bridge_rx_count)));
        }
    } else {
        vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0 = 0U;
    }
    vlTOPp->top__DOT__uart_bridge_rx_source_payload_data = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__uart_bridge_rx_count))) {
                vlTOPp->top__DOT__uart_bridge_rx_source_payload_data 
                    = vlTOPp->top__DOT__uart_bridge_rx_data;
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_wait = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            vlTOPp->top__DOT__mgmtsoc_litespimmap_wait = 1U;
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespimmap_wait = 1U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_wait = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_wait = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 1U;
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 1U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 1U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 1U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_last = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_last = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask = 0U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask = 1U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready = 1U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready = 1U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width = 1U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width = 1U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid = 1U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid = 1U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_wishbone_dat_r = 0U;
    if (vlTOPp->top__DOT__state) {
        vlTOPp->top__DOT__mgmtsoc_wishbone_dat_r = 
            ((((((((vlTOPp->top__DOT__interface0_bank_bus_dat_r 
                    | vlTOPp->top__DOT__interface1_bank_bus_dat_r) 
                   | vlTOPp->top__DOT__interface2_bank_bus_dat_r) 
                  | vlTOPp->top__DOT__interface3_bank_bus_dat_r) 
                 | vlTOPp->top__DOT__interface4_bank_bus_dat_r) 
                | vlTOPp->top__DOT__interface5_bank_bus_dat_r) 
               | vlTOPp->top__DOT__interface6_bank_bus_dat_r) 
              | vlTOPp->top__DOT__interface7_bank_bus_dat_r) 
             | vlTOPp->top__DOT__interface8_bank_bus_dat_r);
    }
    vlTOPp->top__DOT__mgmtsoc_wishbone_ack = 0U;
    if (vlTOPp->top__DOT__state) {
        vlTOPp->top__DOT__mgmtsoc_wishbone_ack = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_last = 0U;
    if ((1U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if ((2U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if ((3U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_last = 1U;
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_valid = 0U;
    if ((1U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if ((2U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if ((3U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_valid = 1U;
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en = 1U;
    }
    vlTOPp->top__DOT__uart_bridge_rx_source_ready = 
        (1U & ((~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                   >> 2U)) | (((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                               >> 1U) & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))));
    vlTOPp->top__DOT__uart_bridge_is_ongoing = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                vlTOPp->top__DOT__uart_bridge_is_ongoing = 1U;
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                vlTOPp->top__DOT__uart_bridge_is_ongoing = 1U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_tx_sink_valid = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                vlTOPp->top__DOT__uart_bridge_tx_sink_valid = 1U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_wishbone_we = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            vlTOPp->top__DOT__uart_bridge_wishbone_we 
                = (1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)));
        }
    }
    vlTOPp->top__DOT__uart_bridge_wishbone_stb = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            vlTOPp->top__DOT__uart_bridge_wishbone_stb = 1U;
        }
    }
    vlTOPp->top__DOT__uart_bridge_wishbone_cyc = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            vlTOPp->top__DOT__uart_bridge_wishbone_cyc = 1U;
        }
    }
    vlTOPp->top__DOT__uart_bridge_done = (0U == vlTOPp->top__DOT__uart_bridge_count);
    vlTOPp->gpio_mode1_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_mode1_storage)));
    vlTOPp->gpio_mode0_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_mode0_storage)));
    vlTOPp->gpio_inenb_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_ien_storage)));
    vlTOPp->gpio_outenb_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_oe_storage)));
    vlTOPp->gpio_out_pad = vlTOPp->top__DOT__gpio_out_storage;
    vlTOPp->la_iena[0U] = 0U;
    vlTOPp->la_iena[1U] = 0U;
    vlTOPp->la_iena[2U] = 0U;
    vlTOPp->la_iena[3U] = 0U;
    vlTOPp->la_iena[0U] = ((0xfffffffeU & vlTOPp->la_iena[0U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_ien_storage[0U])));
    vlTOPp->la_iena[0U] = ((0xfffffffdU & vlTOPp->la_iena[0U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_iena[0U] = ((0xfffffffbU & vlTOPp->la_iena[0U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_iena[0U] = ((0xfffffff7U & vlTOPp->la_iena[0U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_iena[0U] = ((0xffffffefU & vlTOPp->la_iena[0U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_iena[0U] = ((0xffffffdfU & vlTOPp->la_iena[0U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_iena[0U] = ((0xffffffbfU & vlTOPp->la_iena[0U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_iena[0U] = ((0xffffff7fU & vlTOPp->la_iena[0U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_iena[0U] = ((0xfffffeffU & vlTOPp->la_iena[0U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_iena[0U] = ((0xfffffdffU & vlTOPp->la_iena[0U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_iena[0U] = ((0xfffffbffU & vlTOPp->la_iena[0U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_iena[0U] = ((0xfffff7ffU & vlTOPp->la_iena[0U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_iena[0U] = ((0xffffefffU & vlTOPp->la_iena[0U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_iena[0U] = ((0xffffdfffU & vlTOPp->la_iena[0U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_iena[0U] = ((0xffffbfffU & vlTOPp->la_iena[0U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_iena[0U] = ((0xffff7fffU & vlTOPp->la_iena[0U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_iena[0U] = ((0xfffeffffU & vlTOPp->la_iena[0U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_iena[0U] = ((0xfffdffffU & vlTOPp->la_iena[0U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_iena[0U] = ((0xfffbffffU & vlTOPp->la_iena[0U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_iena[0U] = ((0xfff7ffffU & vlTOPp->la_iena[0U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_iena[0U] = ((0xffefffffU & vlTOPp->la_iena[0U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_iena[0U] = ((0xffdfffffU & vlTOPp->la_iena[0U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_iena[0U] = ((0xffbfffffU & vlTOPp->la_iena[0U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_iena[0U] = ((0xff7fffffU & vlTOPp->la_iena[0U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_iena[0U] = ((0xfeffffffU & vlTOPp->la_iena[0U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_iena[0U] = ((0xfdffffffU & vlTOPp->la_iena[0U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_iena[0U] = ((0xfbffffffU & vlTOPp->la_iena[0U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_iena[0U] = ((0xf7ffffffU & vlTOPp->la_iena[0U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_iena[0U] = ((0xefffffffU & vlTOPp->la_iena[0U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_iena[0U] = ((0xdfffffffU & vlTOPp->la_iena[0U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_iena[0U] = ((0xbfffffffU & vlTOPp->la_iena[0U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_iena[0U] = ((0x7fffffffU & vlTOPp->la_iena[0U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[0U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_iena[1U] = ((0xfffffffeU & vlTOPp->la_iena[1U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_ien_storage[1U])));
    vlTOPp->la_iena[1U] = ((0xfffffffdU & vlTOPp->la_iena[1U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_iena[1U] = ((0xfffffffbU & vlTOPp->la_iena[1U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_iena[1U] = ((0xfffffff7U & vlTOPp->la_iena[1U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_iena[1U] = ((0xffffffefU & vlTOPp->la_iena[1U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_iena[1U] = ((0xffffffdfU & vlTOPp->la_iena[1U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_iena[1U] = ((0xffffffbfU & vlTOPp->la_iena[1U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_iena[1U] = ((0xffffff7fU & vlTOPp->la_iena[1U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_iena[1U] = ((0xfffffeffU & vlTOPp->la_iena[1U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_iena[1U] = ((0xfffffdffU & vlTOPp->la_iena[1U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_iena[1U] = ((0xfffffbffU & vlTOPp->la_iena[1U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_iena[1U] = ((0xfffff7ffU & vlTOPp->la_iena[1U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_iena[1U] = ((0xffffefffU & vlTOPp->la_iena[1U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_iena[1U] = ((0xffffdfffU & vlTOPp->la_iena[1U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_iena[1U] = ((0xffffbfffU & vlTOPp->la_iena[1U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_iena[1U] = ((0xffff7fffU & vlTOPp->la_iena[1U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_iena[1U] = ((0xfffeffffU & vlTOPp->la_iena[1U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_iena[1U] = ((0xfffdffffU & vlTOPp->la_iena[1U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_iena[1U] = ((0xfffbffffU & vlTOPp->la_iena[1U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_iena[1U] = ((0xfff7ffffU & vlTOPp->la_iena[1U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_iena[1U] = ((0xffefffffU & vlTOPp->la_iena[1U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_iena[1U] = ((0xffdfffffU & vlTOPp->la_iena[1U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_iena[1U] = ((0xffbfffffU & vlTOPp->la_iena[1U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_iena[1U] = ((0xff7fffffU & vlTOPp->la_iena[1U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_iena[1U] = ((0xfeffffffU & vlTOPp->la_iena[1U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_iena[1U] = ((0xfdffffffU & vlTOPp->la_iena[1U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_iena[1U] = ((0xfbffffffU & vlTOPp->la_iena[1U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_iena[1U] = ((0xf7ffffffU & vlTOPp->la_iena[1U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_iena[1U] = ((0xefffffffU & vlTOPp->la_iena[1U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_iena[1U] = ((0xdfffffffU & vlTOPp->la_iena[1U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_iena[1U] = ((0xbfffffffU & vlTOPp->la_iena[1U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_iena[1U] = ((0x7fffffffU & vlTOPp->la_iena[1U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[1U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_iena[2U] = ((0xfffffffeU & vlTOPp->la_iena[2U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_ien_storage[2U])));
    vlTOPp->la_iena[2U] = ((0xfffffffdU & vlTOPp->la_iena[2U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_iena[2U] = ((0xfffffffbU & vlTOPp->la_iena[2U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_iena[2U] = ((0xfffffff7U & vlTOPp->la_iena[2U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_iena[2U] = ((0xffffffefU & vlTOPp->la_iena[2U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_iena[2U] = ((0xffffffdfU & vlTOPp->la_iena[2U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_iena[2U] = ((0xffffffbfU & vlTOPp->la_iena[2U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_iena[2U] = ((0xffffff7fU & vlTOPp->la_iena[2U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_iena[2U] = ((0xfffffeffU & vlTOPp->la_iena[2U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_iena[2U] = ((0xfffffdffU & vlTOPp->la_iena[2U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_iena[2U] = ((0xfffffbffU & vlTOPp->la_iena[2U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_iena[2U] = ((0xfffff7ffU & vlTOPp->la_iena[2U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_iena[2U] = ((0xffffefffU & vlTOPp->la_iena[2U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_iena[2U] = ((0xffffdfffU & vlTOPp->la_iena[2U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_iena[2U] = ((0xffffbfffU & vlTOPp->la_iena[2U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_iena[2U] = ((0xffff7fffU & vlTOPp->la_iena[2U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_iena[2U] = ((0xfffeffffU & vlTOPp->la_iena[2U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_iena[2U] = ((0xfffdffffU & vlTOPp->la_iena[2U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_iena[2U] = ((0xfffbffffU & vlTOPp->la_iena[2U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_iena[2U] = ((0xfff7ffffU & vlTOPp->la_iena[2U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_iena[2U] = ((0xffefffffU & vlTOPp->la_iena[2U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_iena[2U] = ((0xffdfffffU & vlTOPp->la_iena[2U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_iena[2U] = ((0xffbfffffU & vlTOPp->la_iena[2U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_iena[2U] = ((0xff7fffffU & vlTOPp->la_iena[2U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_iena[2U] = ((0xfeffffffU & vlTOPp->la_iena[2U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_iena[2U] = ((0xfdffffffU & vlTOPp->la_iena[2U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_iena[2U] = ((0xfbffffffU & vlTOPp->la_iena[2U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_iena[2U] = ((0xf7ffffffU & vlTOPp->la_iena[2U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_iena[2U] = ((0xefffffffU & vlTOPp->la_iena[2U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_iena[2U] = ((0xdfffffffU & vlTOPp->la_iena[2U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_iena[2U] = ((0xbfffffffU & vlTOPp->la_iena[2U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_iena[2U] = ((0x7fffffffU & vlTOPp->la_iena[2U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[2U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_iena[3U] = ((0xfffffffeU & vlTOPp->la_iena[3U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_ien_storage[3U])));
    vlTOPp->la_iena[3U] = ((0xfffffffdU & vlTOPp->la_iena[3U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_iena[3U] = ((0xfffffffbU & vlTOPp->la_iena[3U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_iena[3U] = ((0xfffffff7U & vlTOPp->la_iena[3U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_iena[3U] = ((0xffffffefU & vlTOPp->la_iena[3U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_iena[3U] = ((0xffffffdfU & vlTOPp->la_iena[3U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_iena[3U] = ((0xffffffbfU & vlTOPp->la_iena[3U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_iena[3U] = ((0xffffff7fU & vlTOPp->la_iena[3U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_iena[3U] = ((0xfffffeffU & vlTOPp->la_iena[3U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_iena[3U] = ((0xfffffdffU & vlTOPp->la_iena[3U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_iena[3U] = ((0xfffffbffU & vlTOPp->la_iena[3U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_iena[3U] = ((0xfffff7ffU & vlTOPp->la_iena[3U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_iena[3U] = ((0xffffefffU & vlTOPp->la_iena[3U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_iena[3U] = ((0xffffdfffU & vlTOPp->la_iena[3U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_iena[3U] = ((0xffffbfffU & vlTOPp->la_iena[3U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_iena[3U] = ((0xffff7fffU & vlTOPp->la_iena[3U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_iena[3U] = ((0xfffeffffU & vlTOPp->la_iena[3U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_iena[3U] = ((0xfffdffffU & vlTOPp->la_iena[3U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_iena[3U] = ((0xfffbffffU & vlTOPp->la_iena[3U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_iena[3U] = ((0xfff7ffffU & vlTOPp->la_iena[3U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_iena[3U] = ((0xffefffffU & vlTOPp->la_iena[3U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_iena[3U] = ((0xffdfffffU & vlTOPp->la_iena[3U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_iena[3U] = ((0xffbfffffU & vlTOPp->la_iena[3U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_iena[3U] = ((0xff7fffffU & vlTOPp->la_iena[3U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_iena[3U] = ((0xfeffffffU & vlTOPp->la_iena[3U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_iena[3U] = ((0xfdffffffU & vlTOPp->la_iena[3U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_iena[3U] = ((0xfbffffffU & vlTOPp->la_iena[3U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_iena[3U] = ((0xf7ffffffU & vlTOPp->la_iena[3U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_iena[3U] = ((0xefffffffU & vlTOPp->la_iena[3U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_iena[3U] = ((0xdfffffffU & vlTOPp->la_iena[3U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_iena[3U] = ((0xbfffffffU & vlTOPp->la_iena[3U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_iena[3U] = ((0x7fffffffU & vlTOPp->la_iena[3U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_ien_storage[3U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_oenb[0U] = 0U;
    vlTOPp->la_oenb[1U] = 0U;
    vlTOPp->la_oenb[2U] = 0U;
    vlTOPp->la_oenb[3U] = 0U;
    vlTOPp->la_oenb[0U] = ((0xfffffffeU & vlTOPp->la_oenb[0U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_oe_storage[0U])));
    vlTOPp->la_oenb[0U] = ((0xfffffffdU & vlTOPp->la_oenb[0U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_oenb[0U] = ((0xfffffffbU & vlTOPp->la_oenb[0U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_oenb[0U] = ((0xfffffff7U & vlTOPp->la_oenb[0U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_oenb[0U] = ((0xffffffefU & vlTOPp->la_oenb[0U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_oenb[0U] = ((0xffffffdfU & vlTOPp->la_oenb[0U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_oenb[0U] = ((0xffffffbfU & vlTOPp->la_oenb[0U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_oenb[0U] = ((0xffffff7fU & vlTOPp->la_oenb[0U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_oenb[0U] = ((0xfffffeffU & vlTOPp->la_oenb[0U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_oenb[0U] = ((0xfffffdffU & vlTOPp->la_oenb[0U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_oenb[0U] = ((0xfffffbffU & vlTOPp->la_oenb[0U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_oenb[0U] = ((0xfffff7ffU & vlTOPp->la_oenb[0U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_oenb[0U] = ((0xffffefffU & vlTOPp->la_oenb[0U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_oenb[0U] = ((0xffffdfffU & vlTOPp->la_oenb[0U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_oenb[0U] = ((0xffffbfffU & vlTOPp->la_oenb[0U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_oenb[0U] = ((0xffff7fffU & vlTOPp->la_oenb[0U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_oenb[0U] = ((0xfffeffffU & vlTOPp->la_oenb[0U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_oenb[0U] = ((0xfffdffffU & vlTOPp->la_oenb[0U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_oenb[0U] = ((0xfffbffffU & vlTOPp->la_oenb[0U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_oenb[0U] = ((0xfff7ffffU & vlTOPp->la_oenb[0U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_oenb[0U] = ((0xffefffffU & vlTOPp->la_oenb[0U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_oenb[0U] = ((0xffdfffffU & vlTOPp->la_oenb[0U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_oenb[0U] = ((0xffbfffffU & vlTOPp->la_oenb[0U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_oenb[0U] = ((0xff7fffffU & vlTOPp->la_oenb[0U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_oenb[0U] = ((0xfeffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_oenb[0U] = ((0xfdffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_oenb[0U] = ((0xfbffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_oenb[0U] = ((0xf7ffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_oenb[0U] = ((0xefffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_oenb[0U] = ((0xdfffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_oenb[0U] = ((0xbfffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_oenb[0U] = ((0x7fffffffU & vlTOPp->la_oenb[0U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[0U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_oenb[1U] = ((0xfffffffeU & vlTOPp->la_oenb[1U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_oe_storage[1U])));
    vlTOPp->la_oenb[1U] = ((0xfffffffdU & vlTOPp->la_oenb[1U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_oenb[1U] = ((0xfffffffbU & vlTOPp->la_oenb[1U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_oenb[1U] = ((0xfffffff7U & vlTOPp->la_oenb[1U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_oenb[1U] = ((0xffffffefU & vlTOPp->la_oenb[1U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_oenb[1U] = ((0xffffffdfU & vlTOPp->la_oenb[1U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_oenb[1U] = ((0xffffffbfU & vlTOPp->la_oenb[1U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_oenb[1U] = ((0xffffff7fU & vlTOPp->la_oenb[1U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_oenb[1U] = ((0xfffffeffU & vlTOPp->la_oenb[1U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_oenb[1U] = ((0xfffffdffU & vlTOPp->la_oenb[1U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_oenb[1U] = ((0xfffffbffU & vlTOPp->la_oenb[1U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_oenb[1U] = ((0xfffff7ffU & vlTOPp->la_oenb[1U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_oenb[1U] = ((0xffffefffU & vlTOPp->la_oenb[1U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_oenb[1U] = ((0xffffdfffU & vlTOPp->la_oenb[1U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_oenb[1U] = ((0xffffbfffU & vlTOPp->la_oenb[1U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_oenb[1U] = ((0xffff7fffU & vlTOPp->la_oenb[1U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_oenb[1U] = ((0xfffeffffU & vlTOPp->la_oenb[1U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_oenb[1U] = ((0xfffdffffU & vlTOPp->la_oenb[1U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_oenb[1U] = ((0xfffbffffU & vlTOPp->la_oenb[1U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_oenb[1U] = ((0xfff7ffffU & vlTOPp->la_oenb[1U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_oenb[1U] = ((0xffefffffU & vlTOPp->la_oenb[1U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_oenb[1U] = ((0xffdfffffU & vlTOPp->la_oenb[1U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_oenb[1U] = ((0xffbfffffU & vlTOPp->la_oenb[1U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_oenb[1U] = ((0xff7fffffU & vlTOPp->la_oenb[1U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_oenb[1U] = ((0xfeffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_oenb[1U] = ((0xfdffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_oenb[1U] = ((0xfbffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_oenb[1U] = ((0xf7ffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_oenb[1U] = ((0xefffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_oenb[1U] = ((0xdfffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_oenb[1U] = ((0xbfffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_oenb[1U] = ((0x7fffffffU & vlTOPp->la_oenb[1U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[1U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_oenb[2U] = ((0xfffffffeU & vlTOPp->la_oenb[2U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_oe_storage[2U])));
    vlTOPp->la_oenb[2U] = ((0xfffffffdU & vlTOPp->la_oenb[2U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_oenb[2U] = ((0xfffffffbU & vlTOPp->la_oenb[2U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_oenb[2U] = ((0xfffffff7U & vlTOPp->la_oenb[2U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_oenb[2U] = ((0xffffffefU & vlTOPp->la_oenb[2U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_oenb[2U] = ((0xffffffdfU & vlTOPp->la_oenb[2U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_oenb[2U] = ((0xffffffbfU & vlTOPp->la_oenb[2U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_oenb[2U] = ((0xffffff7fU & vlTOPp->la_oenb[2U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_oenb[2U] = ((0xfffffeffU & vlTOPp->la_oenb[2U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_oenb[2U] = ((0xfffffdffU & vlTOPp->la_oenb[2U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_oenb[2U] = ((0xfffffbffU & vlTOPp->la_oenb[2U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_oenb[2U] = ((0xfffff7ffU & vlTOPp->la_oenb[2U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_oenb[2U] = ((0xffffefffU & vlTOPp->la_oenb[2U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_oenb[2U] = ((0xffffdfffU & vlTOPp->la_oenb[2U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_oenb[2U] = ((0xffffbfffU & vlTOPp->la_oenb[2U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_oenb[2U] = ((0xffff7fffU & vlTOPp->la_oenb[2U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_oenb[2U] = ((0xfffeffffU & vlTOPp->la_oenb[2U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_oenb[2U] = ((0xfffdffffU & vlTOPp->la_oenb[2U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_oenb[2U] = ((0xfffbffffU & vlTOPp->la_oenb[2U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_oenb[2U] = ((0xfff7ffffU & vlTOPp->la_oenb[2U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_oenb[2U] = ((0xffefffffU & vlTOPp->la_oenb[2U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_oenb[2U] = ((0xffdfffffU & vlTOPp->la_oenb[2U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_oenb[2U] = ((0xffbfffffU & vlTOPp->la_oenb[2U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_oenb[2U] = ((0xff7fffffU & vlTOPp->la_oenb[2U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_oenb[2U] = ((0xfeffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_oenb[2U] = ((0xfdffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_oenb[2U] = ((0xfbffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_oenb[2U] = ((0xf7ffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_oenb[2U] = ((0xefffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_oenb[2U] = ((0xdfffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_oenb[2U] = ((0xbfffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_oenb[2U] = ((0x7fffffffU & vlTOPp->la_oenb[2U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[2U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_oenb[3U] = ((0xfffffffeU & vlTOPp->la_oenb[3U]) 
                           | (1U & (~ vlTOPp->top__DOT__la_oe_storage[3U])));
    vlTOPp->la_oenb[3U] = ((0xfffffffdU & vlTOPp->la_oenb[3U]) 
                           | (2U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                        >> 1U)) << 1U)));
    vlTOPp->la_oenb[3U] = ((0xfffffffbU & vlTOPp->la_oenb[3U]) 
                           | (4U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                        >> 2U)) << 2U)));
    vlTOPp->la_oenb[3U] = ((0xfffffff7U & vlTOPp->la_oenb[3U]) 
                           | (8U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                        >> 3U)) << 3U)));
    vlTOPp->la_oenb[3U] = ((0xffffffefU & vlTOPp->la_oenb[3U]) 
                           | (0x10U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                           >> 4U)) 
                                       << 4U)));
    vlTOPp->la_oenb[3U] = ((0xffffffdfU & vlTOPp->la_oenb[3U]) 
                           | (0x20U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                           >> 5U)) 
                                       << 5U)));
    vlTOPp->la_oenb[3U] = ((0xffffffbfU & vlTOPp->la_oenb[3U]) 
                           | (0x40U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                           >> 6U)) 
                                       << 6U)));
    vlTOPp->la_oenb[3U] = ((0xffffff7fU & vlTOPp->la_oenb[3U]) 
                           | (0x80U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                           >> 7U)) 
                                       << 7U)));
    vlTOPp->la_oenb[3U] = ((0xfffffeffU & vlTOPp->la_oenb[3U]) 
                           | (0x100U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                            >> 8U)) 
                                        << 8U)));
    vlTOPp->la_oenb[3U] = ((0xfffffdffU & vlTOPp->la_oenb[3U]) 
                           | (0x200U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                            >> 9U)) 
                                        << 9U)));
    vlTOPp->la_oenb[3U] = ((0xfffffbffU & vlTOPp->la_oenb[3U]) 
                           | (0x400U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                            >> 0xaU)) 
                                        << 0xaU)));
    vlTOPp->la_oenb[3U] = ((0xfffff7ffU & vlTOPp->la_oenb[3U]) 
                           | (0x800U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                            >> 0xbU)) 
                                        << 0xbU)));
    vlTOPp->la_oenb[3U] = ((0xffffefffU & vlTOPp->la_oenb[3U]) 
                           | (0x1000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                             >> 0xcU)) 
                                         << 0xcU)));
    vlTOPp->la_oenb[3U] = ((0xffffdfffU & vlTOPp->la_oenb[3U]) 
                           | (0x2000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                             >> 0xdU)) 
                                         << 0xdU)));
    vlTOPp->la_oenb[3U] = ((0xffffbfffU & vlTOPp->la_oenb[3U]) 
                           | (0x4000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                             >> 0xeU)) 
                                         << 0xeU)));
    vlTOPp->la_oenb[3U] = ((0xffff7fffU & vlTOPp->la_oenb[3U]) 
                           | (0x8000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                             >> 0xfU)) 
                                         << 0xfU)));
    vlTOPp->la_oenb[3U] = ((0xfffeffffU & vlTOPp->la_oenb[3U]) 
                           | (0x10000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                              >> 0x10U)) 
                                          << 0x10U)));
    vlTOPp->la_oenb[3U] = ((0xfffdffffU & vlTOPp->la_oenb[3U]) 
                           | (0x20000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                              >> 0x11U)) 
                                          << 0x11U)));
    vlTOPp->la_oenb[3U] = ((0xfffbffffU & vlTOPp->la_oenb[3U]) 
                           | (0x40000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                              >> 0x12U)) 
                                          << 0x12U)));
    vlTOPp->la_oenb[3U] = ((0xfff7ffffU & vlTOPp->la_oenb[3U]) 
                           | (0x80000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                              >> 0x13U)) 
                                          << 0x13U)));
    vlTOPp->la_oenb[3U] = ((0xffefffffU & vlTOPp->la_oenb[3U]) 
                           | (0x100000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                               >> 0x14U)) 
                                           << 0x14U)));
    vlTOPp->la_oenb[3U] = ((0xffdfffffU & vlTOPp->la_oenb[3U]) 
                           | (0x200000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                               >> 0x15U)) 
                                           << 0x15U)));
    vlTOPp->la_oenb[3U] = ((0xffbfffffU & vlTOPp->la_oenb[3U]) 
                           | (0x400000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                               >> 0x16U)) 
                                           << 0x16U)));
    vlTOPp->la_oenb[3U] = ((0xff7fffffU & vlTOPp->la_oenb[3U]) 
                           | (0x800000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                               >> 0x17U)) 
                                           << 0x17U)));
    vlTOPp->la_oenb[3U] = ((0xfeffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x1000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                >> 0x18U)) 
                                            << 0x18U)));
    vlTOPp->la_oenb[3U] = ((0xfdffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x2000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                >> 0x19U)) 
                                            << 0x19U)));
    vlTOPp->la_oenb[3U] = ((0xfbffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x4000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                >> 0x1aU)) 
                                            << 0x1aU)));
    vlTOPp->la_oenb[3U] = ((0xf7ffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x8000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                >> 0x1bU)) 
                                            << 0x1bU)));
    vlTOPp->la_oenb[3U] = ((0xefffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x10000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                 >> 0x1cU)) 
                                             << 0x1cU)));
    vlTOPp->la_oenb[3U] = ((0xdfffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x20000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                 >> 0x1dU)) 
                                             << 0x1dU)));
    vlTOPp->la_oenb[3U] = ((0xbfffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x40000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                 >> 0x1eU)) 
                                             << 0x1eU)));
    vlTOPp->la_oenb[3U] = ((0x7fffffffU & vlTOPp->la_oenb[3U]) 
                           | (0x80000000U & ((~ (vlTOPp->top__DOT__la_oe_storage[3U] 
                                                 >> 0x1fU)) 
                                             << 0x1fU)));
    vlTOPp->la_output[0U] = 0U;
    vlTOPp->la_output[1U] = 0U;
    vlTOPp->la_output[2U] = 0U;
    vlTOPp->la_output[3U] = 0U;
    vlTOPp->la_output[0U] = ((0xfffffffeU & vlTOPp->la_output[0U]) 
                             | (1U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffffffdU & vlTOPp->la_output[0U]) 
                             | (2U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffffffbU & vlTOPp->la_output[0U]) 
                             | (4U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffffff7U & vlTOPp->la_output[0U]) 
                             | (8U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffffefU & vlTOPp->la_output[0U]) 
                             | (0x10U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffffdfU & vlTOPp->la_output[0U]) 
                             | (0x20U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffffbfU & vlTOPp->la_output[0U]) 
                             | (0x40U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffff7fU & vlTOPp->la_output[0U]) 
                             | (0x80U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffffeffU & vlTOPp->la_output[0U]) 
                             | (0x100U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffffdffU & vlTOPp->la_output[0U]) 
                             | (0x200U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffffbffU & vlTOPp->la_output[0U]) 
                             | (0x400U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffff7ffU & vlTOPp->la_output[0U]) 
                             | (0x800U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffefffU & vlTOPp->la_output[0U]) 
                             | (0x1000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffdfffU & vlTOPp->la_output[0U]) 
                             | (0x2000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffffbfffU & vlTOPp->la_output[0U]) 
                             | (0x4000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffff7fffU & vlTOPp->la_output[0U]) 
                             | (0x8000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffeffffU & vlTOPp->la_output[0U]) 
                             | (0x10000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffdffffU & vlTOPp->la_output[0U]) 
                             | (0x20000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfffbffffU & vlTOPp->la_output[0U]) 
                             | (0x40000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfff7ffffU & vlTOPp->la_output[0U]) 
                             | (0x80000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffefffffU & vlTOPp->la_output[0U]) 
                             | (0x100000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffdfffffU & vlTOPp->la_output[0U]) 
                             | (0x200000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xffbfffffU & vlTOPp->la_output[0U]) 
                             | (0x400000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xff7fffffU & vlTOPp->la_output[0U]) 
                             | (0x800000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfeffffffU & vlTOPp->la_output[0U]) 
                             | (0x1000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfdffffffU & vlTOPp->la_output[0U]) 
                             | (0x2000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xfbffffffU & vlTOPp->la_output[0U]) 
                             | (0x4000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xf7ffffffU & vlTOPp->la_output[0U]) 
                             | (0x8000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xefffffffU & vlTOPp->la_output[0U]) 
                             | (0x10000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xdfffffffU & vlTOPp->la_output[0U]) 
                             | (0x20000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0xbfffffffU & vlTOPp->la_output[0U]) 
                             | (0x40000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[0U] = ((0x7fffffffU & vlTOPp->la_output[0U]) 
                             | (0x80000000U & vlTOPp->top__DOT__la_out_storage[0U]));
    vlTOPp->la_output[1U] = ((0xfffffffeU & vlTOPp->la_output[1U]) 
                             | (1U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffffffdU & vlTOPp->la_output[1U]) 
                             | (2U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffffffbU & vlTOPp->la_output[1U]) 
                             | (4U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffffff7U & vlTOPp->la_output[1U]) 
                             | (8U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffffefU & vlTOPp->la_output[1U]) 
                             | (0x10U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffffdfU & vlTOPp->la_output[1U]) 
                             | (0x20U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffffbfU & vlTOPp->la_output[1U]) 
                             | (0x40U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffff7fU & vlTOPp->la_output[1U]) 
                             | (0x80U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffffeffU & vlTOPp->la_output[1U]) 
                             | (0x100U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffffdffU & vlTOPp->la_output[1U]) 
                             | (0x200U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffffbffU & vlTOPp->la_output[1U]) 
                             | (0x400U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffff7ffU & vlTOPp->la_output[1U]) 
                             | (0x800U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffefffU & vlTOPp->la_output[1U]) 
                             | (0x1000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffdfffU & vlTOPp->la_output[1U]) 
                             | (0x2000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffffbfffU & vlTOPp->la_output[1U]) 
                             | (0x4000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffff7fffU & vlTOPp->la_output[1U]) 
                             | (0x8000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffeffffU & vlTOPp->la_output[1U]) 
                             | (0x10000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffdffffU & vlTOPp->la_output[1U]) 
                             | (0x20000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfffbffffU & vlTOPp->la_output[1U]) 
                             | (0x40000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfff7ffffU & vlTOPp->la_output[1U]) 
                             | (0x80000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffefffffU & vlTOPp->la_output[1U]) 
                             | (0x100000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffdfffffU & vlTOPp->la_output[1U]) 
                             | (0x200000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xffbfffffU & vlTOPp->la_output[1U]) 
                             | (0x400000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xff7fffffU & vlTOPp->la_output[1U]) 
                             | (0x800000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfeffffffU & vlTOPp->la_output[1U]) 
                             | (0x1000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfdffffffU & vlTOPp->la_output[1U]) 
                             | (0x2000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xfbffffffU & vlTOPp->la_output[1U]) 
                             | (0x4000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xf7ffffffU & vlTOPp->la_output[1U]) 
                             | (0x8000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xefffffffU & vlTOPp->la_output[1U]) 
                             | (0x10000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xdfffffffU & vlTOPp->la_output[1U]) 
                             | (0x20000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0xbfffffffU & vlTOPp->la_output[1U]) 
                             | (0x40000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[1U] = ((0x7fffffffU & vlTOPp->la_output[1U]) 
                             | (0x80000000U & vlTOPp->top__DOT__la_out_storage[1U]));
    vlTOPp->la_output[2U] = ((0xfffffffeU & vlTOPp->la_output[2U]) 
                             | (1U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffffffdU & vlTOPp->la_output[2U]) 
                             | (2U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffffffbU & vlTOPp->la_output[2U]) 
                             | (4U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffffff7U & vlTOPp->la_output[2U]) 
                             | (8U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffffefU & vlTOPp->la_output[2U]) 
                             | (0x10U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffffdfU & vlTOPp->la_output[2U]) 
                             | (0x20U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffffbfU & vlTOPp->la_output[2U]) 
                             | (0x40U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffff7fU & vlTOPp->la_output[2U]) 
                             | (0x80U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffffeffU & vlTOPp->la_output[2U]) 
                             | (0x100U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffffdffU & vlTOPp->la_output[2U]) 
                             | (0x200U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffffbffU & vlTOPp->la_output[2U]) 
                             | (0x400U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffff7ffU & vlTOPp->la_output[2U]) 
                             | (0x800U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffefffU & vlTOPp->la_output[2U]) 
                             | (0x1000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffdfffU & vlTOPp->la_output[2U]) 
                             | (0x2000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffffbfffU & vlTOPp->la_output[2U]) 
                             | (0x4000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffff7fffU & vlTOPp->la_output[2U]) 
                             | (0x8000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffeffffU & vlTOPp->la_output[2U]) 
                             | (0x10000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffdffffU & vlTOPp->la_output[2U]) 
                             | (0x20000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfffbffffU & vlTOPp->la_output[2U]) 
                             | (0x40000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfff7ffffU & vlTOPp->la_output[2U]) 
                             | (0x80000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffefffffU & vlTOPp->la_output[2U]) 
                             | (0x100000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffdfffffU & vlTOPp->la_output[2U]) 
                             | (0x200000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xffbfffffU & vlTOPp->la_output[2U]) 
                             | (0x400000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xff7fffffU & vlTOPp->la_output[2U]) 
                             | (0x800000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfeffffffU & vlTOPp->la_output[2U]) 
                             | (0x1000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfdffffffU & vlTOPp->la_output[2U]) 
                             | (0x2000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xfbffffffU & vlTOPp->la_output[2U]) 
                             | (0x4000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xf7ffffffU & vlTOPp->la_output[2U]) 
                             | (0x8000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xefffffffU & vlTOPp->la_output[2U]) 
                             | (0x10000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xdfffffffU & vlTOPp->la_output[2U]) 
                             | (0x20000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0xbfffffffU & vlTOPp->la_output[2U]) 
                             | (0x40000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[2U] = ((0x7fffffffU & vlTOPp->la_output[2U]) 
                             | (0x80000000U & vlTOPp->top__DOT__la_out_storage[2U]));
    vlTOPp->la_output[3U] = ((0xfffffffeU & vlTOPp->la_output[3U]) 
                             | (1U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffffffdU & vlTOPp->la_output[3U]) 
                             | (2U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffffffbU & vlTOPp->la_output[3U]) 
                             | (4U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffffff7U & vlTOPp->la_output[3U]) 
                             | (8U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffffefU & vlTOPp->la_output[3U]) 
                             | (0x10U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffffdfU & vlTOPp->la_output[3U]) 
                             | (0x20U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffffbfU & vlTOPp->la_output[3U]) 
                             | (0x40U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffff7fU & vlTOPp->la_output[3U]) 
                             | (0x80U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffffeffU & vlTOPp->la_output[3U]) 
                             | (0x100U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffffdffU & vlTOPp->la_output[3U]) 
                             | (0x200U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffffbffU & vlTOPp->la_output[3U]) 
                             | (0x400U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffff7ffU & vlTOPp->la_output[3U]) 
                             | (0x800U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffefffU & vlTOPp->la_output[3U]) 
                             | (0x1000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffdfffU & vlTOPp->la_output[3U]) 
                             | (0x2000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffffbfffU & vlTOPp->la_output[3U]) 
                             | (0x4000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffff7fffU & vlTOPp->la_output[3U]) 
                             | (0x8000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffeffffU & vlTOPp->la_output[3U]) 
                             | (0x10000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffdffffU & vlTOPp->la_output[3U]) 
                             | (0x20000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfffbffffU & vlTOPp->la_output[3U]) 
                             | (0x40000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfff7ffffU & vlTOPp->la_output[3U]) 
                             | (0x80000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffefffffU & vlTOPp->la_output[3U]) 
                             | (0x100000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffdfffffU & vlTOPp->la_output[3U]) 
                             | (0x200000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xffbfffffU & vlTOPp->la_output[3U]) 
                             | (0x400000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xff7fffffU & vlTOPp->la_output[3U]) 
                             | (0x800000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfeffffffU & vlTOPp->la_output[3U]) 
                             | (0x1000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfdffffffU & vlTOPp->la_output[3U]) 
                             | (0x2000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xfbffffffU & vlTOPp->la_output[3U]) 
                             | (0x4000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xf7ffffffU & vlTOPp->la_output[3U]) 
                             | (0x8000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xefffffffU & vlTOPp->la_output[3U]) 
                             | (0x10000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xdfffffffU & vlTOPp->la_output[3U]) 
                             | (0x20000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0xbfffffffU & vlTOPp->la_output[3U]) 
                             | (0x40000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->la_output[3U] = ((0x7fffffffU & vlTOPp->la_output[3U]) 
                             | (0x80000000U & vlTOPp->top__DOT__la_out_storage[3U]));
    vlTOPp->mprj_wb_iena = vlTOPp->top__DOT__mprj_wb_iena_storage;
    vlTOPp->user_irq_ena = vlTOPp->top__DOT__user_irq_ena_storage;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr 
        = vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr 
        = vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce;
    vlTOPp->top__DOT__mgmtsoc_litespimmap_done = (0U 
                                                  == (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count));
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 
                = ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                   & (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count)));
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 
                    = ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                       & (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count)));
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 
                        = ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                           & (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count)));
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 = 1U;
                }
            } else {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 
                        = ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                           & (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count)));
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_writable 
        = (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0));
    vlTOPp->top__DOT__mgmtsoc_rx_source_valid = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__mgmtsoc_rx_count))) {
                vlTOPp->top__DOT__mgmtsoc_rx_source_valid 
                    = vlTOPp->top__DOT__multiregimpl0_regs1;
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value1 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value1 
                = (((IData)(vlTOPp->top__DOT__multiregimpl0_regs1) 
                    << 7U) | (0x7fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_rx_data) 
                                       >> 1U)));
        }
    }
    vlTOPp->top__DOT__rs232phy_rs232phyrx_next_state 
        = vlTOPp->top__DOT__rs232phy_rs232phyrx_state;
    if (vlTOPp->top__DOT__rs232phy_rs232phyrx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_rx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__mgmtsoc_rx_count))) {
                vlTOPp->top__DOT__rs232phy_rs232phyrx_next_state = 0U;
            }
        }
    } else {
        if (((~ (IData)(vlTOPp->top__DOT__multiregimpl0_regs1)) 
             & (IData)(vlTOPp->top__DOT__mgmtsoc_rx_rx_d))) {
            vlTOPp->top__DOT__rs232phy_rs232phyrx_next_state = 1U;
        }
    }
    vlTOPp->spiflash_cs_n = (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count));
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_done 
        = (0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count));
    vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1 = 1U;
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1 = 1U;
        if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable) {
            vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1 = 1U;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2 = 1U;
        }
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable) {
            vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2 = 1U;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1 
                = (1U & (IData)(vlTOPp->top__DOT__mgmtsoc_tx_data));
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1 = 1U;
        if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable) {
            vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1 = 0U;
        }
    }
    vlTOPp->top__DOT__rs232phy_rs232phytx_next_state 
        = vlTOPp->top__DOT__rs232phy_rs232phytx_state;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__mgmtsoc_tx_count))) {
                vlTOPp->top__DOT__rs232phy_rs232phytx_next_state = 0U;
            }
        }
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable) {
            vlTOPp->top__DOT__rs232phy_rs232phytx_next_state = 1U;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2 = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2 
                = (0x80U | (0x7fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_tx_data) 
                                     >> 1U)));
        }
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable) {
            vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2 
                = (0xffU & (IData)(vlTOPp->top__DOT__memdat_1));
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len = 0x20U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len 
                        = (0x3fU & (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_storage));
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len = 0x18U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len = 8U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_soc_rst = 0U;
    if (vlTOPp->top__DOT__mgmtsoc_reset_re) {
        vlTOPp->top__DOT__mgmtsoc_soc_rst = (1U & (IData)(vlTOPp->top__DOT__mgmtsoc_reset_storage));
    }
    vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value1 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value1 
                = (((IData)(vlTOPp->top__DOT__multiregimpl1_regs1) 
                    << 7U) | (0x7fU & ((IData)(vlTOPp->top__DOT__uart_bridge_rx_data) 
                                       >> 1U)));
        }
    }
    vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_next_state 
        = vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__uart_bridge_rx_count))) {
                vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_next_state = 0U;
            }
        }
    } else {
        if (((~ (IData)(vlTOPp->top__DOT__multiregimpl1_regs1)) 
             & (IData)(vlTOPp->top__DOT__uart_bridge_rx_rx_d))) {
            vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_next_state = 1U;
        }
    }
    vlTOPp->top__DOT__uart_bridge_rx_source_valid = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state) {
        if (vlTOPp->top__DOT__uart_bridge_rx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__uart_bridge_rx_count))) {
                vlTOPp->top__DOT__uart_bridge_rx_source_valid 
                    = vlTOPp->top__DOT__multiregimpl1_regs1;
            }
        }
    }
    vlTOPp->top__DOT__done = (0U == vlTOPp->top__DOT__count);
    vlTOPp->top__DOT__error = 0U;
    if ((0U == vlTOPp->top__DOT__count)) {
        vlTOPp->top__DOT__error = 1U;
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_first = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_grant)))) {
        vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_first = 0U;
    }
    vlTOPp->top__DOT__litespi_tx_mux_source_first = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_first 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_first;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_first = 0U;
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_grant)))) {
        vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data 
            = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in;
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_first = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_first = 0U;
        }
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_payload_data = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_payload_data 
                = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in;
        }
    }
    if (vlTOPp->top__DOT__grant) {
        vlTOPp->top__DOT__array_muxed1 = vlTOPp->top__DOT__uart_bridge_data;
        vlTOPp->top__DOT__array_muxed0 = (0x3fffffffU 
                                          & vlTOPp->top__DOT__uart_bridge_address);
        vlTOPp->top__DOT__array_muxed2 = 0xfU;
    } else {
        vlTOPp->top__DOT__array_muxed1 = vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wdata;
        vlTOPp->top__DOT__array_muxed0 = (0x3fffffffU 
                                          & (vlTOPp->top__DOT__mgmtsoc_picorv32_mem_addr 
                                             >> 2U));
        vlTOPp->top__DOT__array_muxed2 = vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_writable 
        = (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0));
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 
        ((2U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_status_status)) 
         | (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)));
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 
        ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_status_status)) 
         | ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable) 
            << 1U));
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2) {
            vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift = 1U;
        }
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if (((0U < (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)) 
                 | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2))) {
                vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift 
                    = (0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage));
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready = 0U;
    if ((1U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if ((2U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if (((0U < (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)) 
                 | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2))) {
                vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready = 1U;
            }
        }
    }
    vlTOPp->top__DOT__picorv32__DOT__alu_out_0 = 0U;
    if (vlTOPp->top__DOT__picorv32__DOT__instr_beq) {
        vlTOPp->top__DOT__picorv32__DOT__alu_out_0 
            = vlTOPp->top__DOT__picorv32__DOT__alu_eq;
    } else {
        if (vlTOPp->top__DOT__picorv32__DOT__instr_bne) {
            vlTOPp->top__DOT__picorv32__DOT__alu_out_0 
                = (1U & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__alu_eq)));
        } else {
            if (vlTOPp->top__DOT__picorv32__DOT__instr_bge) {
                vlTOPp->top__DOT__picorv32__DOT__alu_out_0 
                    = (1U & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__alu_lts)));
            } else {
                if (vlTOPp->top__DOT__picorv32__DOT__instr_bgeu) {
                    vlTOPp->top__DOT__picorv32__DOT__alu_out_0 
                        = (1U & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__alu_ltu)));
                } else {
                    if (vlTOPp->top__DOT__picorv32__DOT__is_slti_blt_slt) {
                        vlTOPp->top__DOT__picorv32__DOT__alu_out_0 
                            = vlTOPp->top__DOT__picorv32__DOT__alu_lts;
                    } else {
                        if (vlTOPp->top__DOT__picorv32__DOT__is_sltiu_bltu_sltu) {
                            vlTOPp->top__DOT__picorv32__DOT__alu_out_0 
                                = vlTOPp->top__DOT__picorv32__DOT__alu_ltu;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__picorv32__DOT__alu_out = 0U;
    if (vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal_jalr_addi_add_sub) {
        vlTOPp->top__DOT__picorv32__DOT__alu_out = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sub)
              ? (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                 - vlTOPp->top__DOT__picorv32__DOT__reg_op2)
              : (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                 + vlTOPp->top__DOT__picorv32__DOT__reg_op2));
    } else {
        if (vlTOPp->top__DOT__picorv32__DOT__is_compare) {
            vlTOPp->top__DOT__picorv32__DOT__alu_out 
                = vlTOPp->top__DOT__picorv32__DOT__alu_out_0;
        } else {
            if (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_xori) 
                 | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_xor))) {
                vlTOPp->top__DOT__picorv32__DOT__alu_out 
                    = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                       ^ vlTOPp->top__DOT__picorv32__DOT__reg_op2);
            } else {
                if (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_ori) 
                     | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_or))) {
                    vlTOPp->top__DOT__picorv32__DOT__alu_out 
                        = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                           | vlTOPp->top__DOT__picorv32__DOT__reg_op2);
                } else {
                    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_andi) 
                         | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_and))) {
                        vlTOPp->top__DOT__picorv32__DOT__alu_out 
                            = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                               & vlTOPp->top__DOT__picorv32__DOT__reg_op2);
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_instr 
        = vlTOPp->top__DOT__picorv32__DOT__q_ascii_instr;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_instr 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                ? vlTOPp->top__DOT__picorv32__DOT__cached_ascii_instr
                : vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr);
    }
    vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt = 0U;
    vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt = 
        ((0xfffffffdU & vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt) 
         | (((IData)(vlTOPp->top__DOT__mgmtsoc_timer_zero_pending) 
             & (IData)(vlTOPp->top__DOT__mgmtsoc_timer_enable_storage)) 
            << 1U));
    vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt = 
        ((0xfffffffeU & vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt) 
         | (1U & (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status) 
                   & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage)) 
                  | (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status) 
                      & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage)) 
                     >> 1U))));
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)) 
           & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable)) 
              | (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_clear)));
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)) 
           & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable)) 
              | (IData)(vlTOPp->top__DOT__mgmtsoc_tx_sink_ready)));
    vlTOPp->top__DOT__litespi_tx_mux_source_last = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_last 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_last;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_last 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_source_last;
    }
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_mask = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_payload_mask 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_mask;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_payload_mask 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask;
    }
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_width = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_payload_width 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_width;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_payload_width 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width;
    }
    vlTOPp->top__DOT__litespi_tx_mux_source_valid = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_valid 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_valid 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid;
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_last = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_grant)))) {
        vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_last 
            = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_last;
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_last = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_last 
                = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_last;
        }
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_valid = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_valid 
                = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_valid;
        }
    }
    vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_grant)))) {
        vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid 
            = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_valid;
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge 
        = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en) 
            & (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk)) 
           & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt) 
              == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)));
    vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2 = 1U;
        }
    } else {
        if (vlTOPp->top__DOT__uart_bridge_tx_sink_valid) {
            vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2 = 1U;
        }
    }
    vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1 = 1U;
        }
    } else {
        vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1 = 1U;
        if (vlTOPp->top__DOT__uart_bridge_tx_sink_valid) {
            vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1 = 1U;
        }
    }
    vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_next_state 
        = vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__uart_bridge_tx_count))) {
                vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_next_state = 0U;
            }
        }
    } else {
        if (vlTOPp->top__DOT__uart_bridge_tx_sink_valid) {
            vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_next_state = 1U;
        }
    }
    vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1 
                = (1U & (IData)(vlTOPp->top__DOT__uart_bridge_tx_data));
        }
    } else {
        vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1 = 1U;
        if (vlTOPp->top__DOT__uart_bridge_tx_sink_valid) {
            vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1 = 0U;
        }
    }
    vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2 = 0U;
    if (vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state) {
        if (vlTOPp->top__DOT__uart_bridge_tx_tick) {
            vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2 
                = (0x80U | (0x7fU & ((IData)(vlTOPp->top__DOT__uart_bridge_tx_data) 
                                     >> 1U)));
        }
    } else {
        if (vlTOPp->top__DOT__uart_bridge_tx_sink_valid) {
            vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2 
                = vlTOPp->top__DOT__uart_bridge_tx_sink_payload_data;
        }
    }
    if (vlTOPp->top__DOT__grant) {
        vlTOPp->top__DOT__array_muxed5 = vlTOPp->top__DOT__uart_bridge_wishbone_we;
        vlTOPp->top__DOT__array_muxed4 = vlTOPp->top__DOT__uart_bridge_wishbone_stb;
    } else {
        vlTOPp->top__DOT__array_muxed5 = (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb));
        vlTOPp->top__DOT__array_muxed4 = vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid;
    }
    vlTOPp->top__DOT__request = (((IData)(vlTOPp->top__DOT__uart_bridge_wishbone_cyc) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid));
    vlTOPp->top__DOT__array_muxed3 = ((IData)(vlTOPp->top__DOT__grant)
                                       ? (IData)(vlTOPp->top__DOT__uart_bridge_wishbone_cyc)
                                       : (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid));
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_len = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_payload_len 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_len;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_payload_len 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len;
    }
    vlTOPp->top__DOT____Vcellinp__picorv32__resetn 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__int_rst) 
                    | ((IData)(vlTOPp->top__DOT__mgmtsoc_soc_rst) 
                       | ((IData)(vlTOPp->top__DOT__mgmtsoc_reset_storage) 
                          >> 1U)))));
    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2 = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2 = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value_ce3 = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value_ce3 = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value3 = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                  >> 2U)))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value3 
                        = vlTOPp->top__DOT__uart_bridge_rx_source_payload_data;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 1U;
            } else {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 1U;
                }
            } else {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 1U;
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = 1U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2 
                        = vlTOPp->top__DOT__uart_bridge_rx_source_payload_data;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2 
                        = vlTOPp->top__DOT__uart_bridge_rx_source_payload_data;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5 = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        if (((1U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)) 
                             | (3U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)))) {
                            vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5 
                                = (1U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd));
                        } else {
                            if (((2U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)) 
                                 | (4U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)))) {
                                vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5 
                                    = (2U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd));
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5 = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                  >> 2U)))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        if (((1U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)) 
                             | (3U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)))) {
                            vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5 = 1U;
                        } else {
                            if (((2U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)) 
                                 | (4U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)))) {
                                vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5 = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 = 0U;
            } else {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 
                        = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count)));
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 
                        = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count)));
                }
            } else {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 
                        = (3U & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count)));
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 = 0U;
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_dat_r = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_dat_r 
                        = ((0xff000000U & (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data 
                                           << 0x18U)) 
                           | ((0xff0000U & (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data 
                                            << 8U)) 
                              | ((0xff00U & (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data 
                                             >> 8U)) 
                                 | (0xffU & (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data 
                                             >> 0x18U)))));
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_dat_w = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__state)))) {
        vlTOPp->top__DOT__mgmtsoc_dat_w = vlTOPp->top__DOT__array_muxed1;
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data = 0U;
    if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                  >> 3U)))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data = 0xdeadU;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data 
                        = (vlTOPp->top__DOT__array_muxed0 
                           << 2U);
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data = 3U;
                }
            }
        }
    }
    vlTOPp->top__DOT__slave_sel = 0U;
    vlTOPp->top__DOT__slave_sel = ((2U & (IData)(vlTOPp->top__DOT__slave_sel)) 
                                   | (0U == (0xffU 
                                             & (vlTOPp->top__DOT__array_muxed0 
                                                >> 0x16U))));
    vlTOPp->top__DOT__slave_sel = ((1U & (IData)(vlTOPp->top__DOT__slave_sel)) 
                                   | ((0x8200U == (0xffffU 
                                                   & (vlTOPp->top__DOT__array_muxed0 
                                                      >> 0xeU))) 
                                      << 1U));
    vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready 
                = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready;
        }
    }
    vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_grant)))) {
        vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready 
            = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)) 
           & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re));
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)) 
           & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re));
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o 
            = (1U & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                     >> 0x1fU));
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
            vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o 
                = (1U & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                         >> 0x1eU));
        } else {
            if ((4U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o 
                    = (1U & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                             >> 0x1cU));
            } else {
                if ((8U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o 
                        = (1U & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                                 >> 0x18U));
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_load = 0U;
    if ((1U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if ((2U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if ((3U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
                if (((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count)) 
                     & (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_valid))) {
                    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_load = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = 1U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = 1U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = 1U;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 
                            = (0x3fffffffU & ((IData)(1U) 
                                              + vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr));
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 
                        = vlTOPp->top__DOT__array_muxed0;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 
                        = vlTOPp->top__DOT__array_muxed0;
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 
                        = vlTOPp->top__DOT__array_muxed0;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_ack = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                      >> 2U)))) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_state) 
                          >> 1U)))) {
                if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_state)))) {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_ack = 1U;
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_shift = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge) {
            vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_shift = 1U;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge) {
            vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce = 1U;
        }
    } else {
        if ((2U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if ((3U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
                if (((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count)) 
                     & (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_valid))) {
                    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge) {
            vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value 
                = (0xffU & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt) 
                            - (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width)));
        }
    } else {
        if ((2U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if ((3U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
                if (((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count)) 
                     & (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_valid))) {
                    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value 
                        = (0xffU & ((IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_len) 
                                    - (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width)));
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_picorv321 = (((IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn) 
                                            & (~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state))))) 
                                           & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata));
    vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word 
        = vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word_q;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__prefetched_high_word)))) {
        vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word = 0U;
    }
    if ((1U & (((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_branch) 
                | (0U != (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) 
               | (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn))))) {
        vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_picorv320 = ((IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn) 
                                           & ((~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state)))) 
                                              & (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
                                                  | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch)) 
                                                 | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata))));
    vlTOPp->top__DOT__shared_dat_r = (((- (IData)((1U 
                                                   & (IData)(vlTOPp->top__DOT__slave_sel_r)))) 
                                       & vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_dat_r) 
                                      | ((- (IData)(
                                                    (1U 
                                                     & ((IData)(vlTOPp->top__DOT__slave_sel_r) 
                                                        >> 1U)))) 
                                         & vlTOPp->top__DOT__mgmtsoc_wishbone_dat_r));
    if ((0U == vlTOPp->top__DOT__count)) {
        vlTOPp->top__DOT__shared_dat_r = 0xffffffffU;
    }
    vlTOPp->top__DOT__litespi_tx_mux_source_payload_data = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_tx_mux_source_payload_data 
                = vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_data;
        }
    } else {
        vlTOPp->top__DOT__litespi_tx_mux_source_payload_data 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data;
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc = 
        ((IData)(vlTOPp->top__DOT__array_muxed3) & (IData)(vlTOPp->top__DOT__slave_sel));
    vlTOPp->top__DOT__mgmtsoc_wishbone_cyc = ((IData)(vlTOPp->top__DOT__array_muxed3) 
                                              & ((IData)(vlTOPp->top__DOT__slave_sel) 
                                                 >> 1U));
    vlTOPp->top__DOT__mgmtsoc_master_status_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_status_status 
        = ((2U & (IData)(vlTOPp->top__DOT__mgmtsoc_master_status_status)) 
           | (1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid)) 
                    | (IData)(vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready))));
    vlTOPp->top__DOT__mgmtsoc_master_status_status 
        = ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_master_status_status)) 
           | ((IData)(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid) 
              << 1U));
    vlTOPp->top__DOT__shared_ack = ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_ack) 
                                    | (IData)(vlTOPp->top__DOT__mgmtsoc_wishbone_ack));
    if ((0U == vlTOPp->top__DOT__count)) {
        vlTOPp->top__DOT__shared_ack = 1U;
    }
    if ((0U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
        vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word 
            = vlTOPp->top__DOT__shared_dat_r;
    } else {
        if ((1U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
            if ((2U & vlTOPp->top__DOT__picorv32__DOT__reg_op1)) {
                if ((2U & vlTOPp->top__DOT__picorv32__DOT__reg_op1)) {
                    vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word 
                        = (0xffffU & (vlTOPp->top__DOT__shared_dat_r 
                                      >> 0x10U));
                }
            } else {
                vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word 
                    = (0xffffU & vlTOPp->top__DOT__shared_dat_r);
            }
        } else {
            if ((2U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize))) {
                vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word 
                    = ((2U & vlTOPp->top__DOT__picorv32__DOT__reg_op1)
                        ? ((1U & vlTOPp->top__DOT__picorv32__DOT__reg_op1)
                            ? (0xffU & (vlTOPp->top__DOT__shared_dat_r 
                                        >> 0x18U)) : 
                           (0xffU & (vlTOPp->top__DOT__shared_dat_r 
                                     >> 0x10U))) : 
                       ((1U & vlTOPp->top__DOT__picorv32__DOT__reg_op1)
                         ? (0xffU & (vlTOPp->top__DOT__shared_dat_r 
                                     >> 8U)) : (0xffU 
                                                & vlTOPp->top__DOT__shared_dat_r)));
            }
        }
    }
    vlTOPp->top__DOT__litespi_next_state = vlTOPp->top__DOT__litespi_state;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                  & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                 & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                vlTOPp->top__DOT__litespi_next_state 
                    = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                        & (vlTOPp->top__DOT__array_muxed0 
                           == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))
                        ? 7U : 1U);
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                      & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                     & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                    vlTOPp->top__DOT__litespi_next_state 
                        = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                            & (vlTOPp->top__DOT__array_muxed0 
                               == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))
                            ? 7U : 1U);
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                          & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                         & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                        vlTOPp->top__DOT__litespi_next_state 
                            = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                                & (vlTOPp->top__DOT__array_muxed0 
                                   == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))
                                ? 7U : 1U);
                    }
                } else {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__litespi_next_state = 0U;
                    }
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    if (vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready) {
                        vlTOPp->top__DOT__litespi_next_state = 8U;
                    }
                } else {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__litespi_next_state = 7U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    if (vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready) {
                        vlTOPp->top__DOT__litespi_next_state = 6U;
                    }
                } else {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__litespi_next_state 
                            = ((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_storage))
                                ? 7U : 5U);
                    }
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    if (vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready) {
                        vlTOPp->top__DOT__litespi_next_state = 4U;
                    }
                } else {
                    if (vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid) {
                        vlTOPp->top__DOT__litespi_next_state = 3U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    if (vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready) {
                        vlTOPp->top__DOT__litespi_next_state = 2U;
                    }
                } else {
                    if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                          & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                         & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                        vlTOPp->top__DOT__litespi_next_state 
                            = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                                & (vlTOPp->top__DOT__array_muxed0 
                                   == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))
                                ? 7U : 1U);
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 0U;
    if ((8U & (IData)(vlTOPp->top__DOT__litespi_state))) {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            vlTOPp->top__DOT__mgmtsoc_litespimmap_cs 
                = vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs;
            if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                  & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                 & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                if ((1U & (~ ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                              & (vlTOPp->top__DOT__array_muxed0 
                                 == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 0U;
                }
            }
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespimmap_cs 
                    = vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs;
                if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                      & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                     & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                    if ((1U & (~ ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                                  & (vlTOPp->top__DOT__array_muxed0 
                                     == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))))) {
                        vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 0U;
                    }
                }
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs 
                        = vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs;
                    if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                          & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                         & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                                      & (vlTOPp->top__DOT__array_muxed0 
                                         == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))))) {
                            vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 0U;
                        }
                    }
                } else {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 1U;
                }
            }
        }
    } else {
        if ((4U & (IData)(vlTOPp->top__DOT__litespi_state))) {
            vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 1U;
        } else {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 1U;
            } else {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_state))) {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 1U;
                } else {
                    vlTOPp->top__DOT__mgmtsoc_litespimmap_cs 
                        = vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs;
                    if ((((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc) 
                          & (IData)(vlTOPp->top__DOT__array_muxed4)) 
                         & (~ (IData)(vlTOPp->top__DOT__array_muxed5)))) {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs) 
                                      & (vlTOPp->top__DOT__array_muxed0 
                                         == vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr))))) {
                            vlTOPp->top__DOT__mgmtsoc_litespimmap_cs = 0U;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__next_state = vlTOPp->top__DOT__state;
    if (vlTOPp->top__DOT__state) {
        vlTOPp->top__DOT__next_state = 0U;
    } else {
        if (((IData)(vlTOPp->top__DOT__mgmtsoc_wishbone_cyc) 
             & (IData)(vlTOPp->top__DOT__array_muxed4))) {
            vlTOPp->top__DOT__next_state = 1U;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_adr = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__state)))) {
        if (((IData)(vlTOPp->top__DOT__mgmtsoc_wishbone_cyc) 
             & (IData)(vlTOPp->top__DOT__array_muxed4))) {
            vlTOPp->top__DOT__mgmtsoc_adr = (0x3fffU 
                                             & vlTOPp->top__DOT__array_muxed0);
        }
    }
    vlTOPp->top__DOT__mgmtsoc_we = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__state)))) {
        if (((IData)(vlTOPp->top__DOT__mgmtsoc_wishbone_cyc) 
             & (IData)(vlTOPp->top__DOT__array_muxed4))) {
            vlTOPp->top__DOT__mgmtsoc_we = ((IData)(vlTOPp->top__DOT__array_muxed5) 
                                            & (0U != (IData)(vlTOPp->top__DOT__array_muxed2)));
        }
    }
    vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack = 
        ((IData)(vlTOPp->top__DOT__shared_ack) & (~ (IData)(vlTOPp->top__DOT__grant)));
    vlTOPp->top__DOT__uart_bridge_wishbone_ack = ((IData)(vlTOPp->top__DOT__shared_ack) 
                                                  & (IData)(vlTOPp->top__DOT__grant));
    vlTOPp->top__DOT__litespi_request = (((IData)(vlTOPp->top__DOT__mgmtsoc_master_cs_storage) 
                                          << 1U) | (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_cs));
    vlTOPp->top__DOT__mgmtsoc_crossbar_cs = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__mgmtsoc_crossbar_cs = vlTOPp->top__DOT__mgmtsoc_master_cs_storage;
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_crossbar_cs = vlTOPp->top__DOT__mgmtsoc_litespimmap_cs;
    }
    vlTOPp->top__DOT__csrbank0_reset0_re = 0U;
    if (((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank0_reset0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank0_reset0_we = 0U;
    if (((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank0_reset0_we = (1U 
                                                & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank0_scratch0_we = 0U;
    if (((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank0_scratch0_we = (1U 
                                                  & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank0_scratch0_re = 0U;
    if (((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank0_scratch0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank0_bus_errors_re = 0U;
    if (((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank0_bus_errors_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank0_bus_errors_we = 0U;
    if (((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank0_bus_errors_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_mode10_we = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_mode10_we = (1U 
                                                & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_mode10_re = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_mode10_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank1_mode00_re = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_mode00_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank1_mode00_we = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_mode00_we = (1U 
                                                & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_ien0_we = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_ien0_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_ien0_re = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_ien0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank1_oe0_re = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_oe0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank1_oe0_we = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_oe0_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_in_re = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_in_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank1_in_we = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_in_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_out0_we = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_out0_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank1_out0_re = 0U;
    if (((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank1_out0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_ien3_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien3_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_ien3_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien3_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_ien2_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien2_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_ien2_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien2_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_ien1_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien1_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_ien1_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien1_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_ien0_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_ien0_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_ien0_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_oe3_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe3_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_oe3_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe3_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_oe2_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe2_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_oe2_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe2_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_oe1_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (6U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe1_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_oe1_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (6U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe1_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_oe0_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (7U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe0_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_oe0_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (7U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_oe0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_in3_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (8U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in3_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_in3_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (8U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in3_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_in2_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (9U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in2_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_in2_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (9U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in2_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_in1_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xaU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in1_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_in1_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xaU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in1_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_in0_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xbU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in0_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_in0_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xbU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_in0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_out3_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xcU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out3_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_out3_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xcU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out3_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_out2_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xdU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out2_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_out2_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xdU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out2_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_out1_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xeU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out1_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank2_out1_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xeU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out1_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_out0_re = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xfU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank2_out0_we = 0U;
    if (((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0xfU == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank2_out0_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank3_out0_we = 0U;
    if (((3U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank3_out0_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank3_out0_re = 0U;
    if (((3U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank3_out0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_we = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_we 
            = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_re = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_re 
            = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank4_master_cs0_re = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_master_cs0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank4_master_cs0_we = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_master_cs0_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank4_master_phyconfig0_re = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_master_phyconfig0_re 
            = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank4_master_phyconfig0_we = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_master_phyconfig0_we 
            = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__mgmtsoc_master_rxtx_re = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__mgmtsoc_master_rxtx_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank4_master_status_we = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_master_status_we 
            = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank4_master_status_re = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank4_master_status_re 
            = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank5_clk_divisor0_re = 0U;
    if (((5U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank5_clk_divisor0_re 
            = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank5_clk_divisor0_we = 0U;
    if (((5U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank5_clk_divisor0_we 
            = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_load0_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_load0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_load0_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_load0_we = (1U & 
                                               (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_reload0_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_reload0_we = (1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_reload0_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_reload0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_en0_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_en0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_en0_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_en0_we = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_update_value0_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_update_value0_we 
            = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_update_value0_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_update_value0_re 
            = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_value_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_value_we = (1U & 
                                               (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_value_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_value_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_ev_status_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_ev_status_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_ev_status_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_ev_status_we = (1U 
                                                   & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_ev_pending_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (6U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_ev_pending_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank6_ev_pending_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (6U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_ev_pending_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_ev_enable0_we = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (7U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_ev_enable0_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank6_ev_enable0_re = 0U;
    if (((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (7U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank6_ev_enable0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rxtx_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__mgmtsoc_uart_rxtx_we = (1U 
                                                  & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_txfull_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_txfull_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank7_txfull_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (1U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_txfull_we = (1U 
                                                & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_rxempty_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_rxempty_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank7_rxempty_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (2U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_rxempty_we = (1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_ev_status_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_ev_status_we = (1U 
                                                   & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_ev_status_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_ev_status_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank7_ev_pending_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_ev_pending_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_ev_pending_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (4U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_ev_pending_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank7_ev_enable0_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_ev_enable0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank7_ev_enable0_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (5U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_ev_enable0_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_txempty_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (6U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_txempty_we = (1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_txempty_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (6U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_txempty_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank7_rxfull_we = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (7U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_rxfull_we = (1U 
                                                & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank7_rxfull_re = 0U;
    if (((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (7U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank7_rxfull_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__csrbank8_out0_we = 0U;
    if (((8U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank8_out0_we = (1U & 
                                              (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__csrbank8_out0_re = 0U;
    if (((8U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (0U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__csrbank8_out0_re = vlTOPp->top__DOT__mgmtsoc_we;
    }
    vlTOPp->top__DOT__mgmtsoc_master_rxtx_we = 0U;
    if (((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                          >> 9U))) & (3U == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
        vlTOPp->top__DOT__mgmtsoc_master_rxtx_we = 
            (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_we)));
    }
    vlTOPp->top__DOT__picorv32__DOT__mem_xfer = ((IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid) 
                                                 & (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack));
    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6 = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6 = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = 1U;
            } else {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = 1U;
                    }
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = 1U;
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = 1U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4 = 1U;
                    }
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4 = 1U;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4 = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 = 0U;
            } else {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 
                            = (0xffU & ((IData)(1U) 
                                        + (IData)(vlTOPp->top__DOT__uart_bridge_words_count)));
                    }
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__uart_bridge_words_count)));
                }
            }
        }
    } else {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 = 0U;
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4 
                            = (vlTOPp->top__DOT__uart_bridge_address 
                               + (IData)(vlTOPp->top__DOT__uart_bridge_incr));
                    }
                }
            }
        } else {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4 
                        = (vlTOPp->top__DOT__uart_bridge_address 
                           + (IData)(vlTOPp->top__DOT__uart_bridge_incr));
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (~ (IData)(vlTOPp->top__DOT__uartwishbonebridge_state)))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4 
                        = ((0xffffff00U & (vlTOPp->top__DOT__uart_bridge_address 
                                           << 8U)) 
                           | (IData)(vlTOPp->top__DOT__uart_bridge_rx_source_payload_data));
                }
            }
        }
    }
    vlTOPp->top__DOT__uartwishbonebridge_next_state 
        = vlTOPp->top__DOT__uartwishbonebridge_state;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uartwishbonebridge_next_state = 1U;
                }
            } else {
                if (vlTOPp->top__DOT__uart_bridge_tx_sink_ready) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uartwishbonebridge_next_state 
                            = (((IData)(vlTOPp->top__DOT__uart_bridge_words_count) 
                                == (0xffU & ((IData)(vlTOPp->top__DOT__uart_bridge_length) 
                                             - (IData)(1U))))
                                ? 0U : 5U);
                    }
                }
            }
        } else {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uartwishbonebridge_next_state = 6U;
                }
            } else {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uartwishbonebridge_next_state 
                        = (((IData)(vlTOPp->top__DOT__uart_bridge_words_count) 
                            == (0xffU & ((IData)(vlTOPp->top__DOT__uart_bridge_length) 
                                         - (IData)(1U))))
                            ? 0U : 3U);
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uartwishbonebridge_next_state = 4U;
                    }
                }
            } else {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    if ((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count))) {
                        vlTOPp->top__DOT__uartwishbonebridge_next_state 
                            = (((1U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)) 
                                | (3U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)))
                                ? 3U : (((2U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)) 
                                         | (4U == (IData)(vlTOPp->top__DOT__uart_bridge_cmd)))
                                         ? 5U : 0U));
                    }
                }
            }
        } else {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uartwishbonebridge_next_state = 2U;
                }
            } else {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uartwishbonebridge_next_state = 1U;
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value6 = 0U;
    if ((4U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
        if ((1U & (~ ((IData)(vlTOPp->top__DOT__uartwishbonebridge_state) 
                      >> 1U)))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_wishbone_ack) {
                    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value6 
                        = vlTOPp->top__DOT__shared_dat_r;
                }
            }
        }
    } else {
        if ((2U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
            if ((1U & (IData)(vlTOPp->top__DOT__uartwishbonebridge_state))) {
                if (vlTOPp->top__DOT__uart_bridge_rx_source_valid) {
                    vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value6 
                        = ((0xffffff00U & (vlTOPp->top__DOT__uart_bridge_data 
                                           << 8U)) 
                           | (IData)(vlTOPp->top__DOT__uart_bridge_rx_source_payload_data));
                }
            }
        }
    }
    vlTOPp->top__DOT__litespi_rx_demux_sink_ready = 0U;
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            vlTOPp->top__DOT__litespi_rx_demux_sink_ready 
                = (1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid)) 
                         | (IData)(vlTOPp->top__DOT__mgmtsoc_master_rxtx_we)));
        }
    } else {
        vlTOPp->top__DOT__litespi_rx_demux_sink_ready 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready;
    }
    vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_xfer)
            ? vlTOPp->top__DOT__shared_dat_r : vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q);
    vlTOPp->top__DOT__picorv32__DOT__mem_done = ((IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn) 
                                                 & ((((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_xfer) 
                                                      & (0U 
                                                         != (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state))) 
                                                     & (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
                                                         | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata)) 
                                                        | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata))) 
                                                    | ((3U 
                                                        == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state)) 
                                                       & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst))));
    vlTOPp->top__DOT__litespiphy_next_state = vlTOPp->top__DOT__litespiphy_state;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge) {
            if ((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt))) {
                vlTOPp->top__DOT__litespiphy_next_state = 2U;
            }
        }
    } else {
        if ((2U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if (((0U < (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)) 
                 | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2))) {
                vlTOPp->top__DOT__litespiphy_next_state = 3U;
            }
        } else {
            if ((3U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
                if (vlTOPp->top__DOT__litespi_rx_demux_sink_ready) {
                    vlTOPp->top__DOT__litespiphy_next_state = 0U;
                }
            } else {
                if (((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count)) 
                     & (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_valid))) {
                    vlTOPp->top__DOT__litespiphy_next_state = 1U;
                }
            }
        }
    }
}

void Vtop::_eval_initial(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_initial\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
    vlTOPp->__Vclklast__TOP__sys_clk = vlTOPp->sys_clk;
}

void Vtop::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::final\n"); );
    // Variables
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vtop::_eval_settle(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_settle\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__2(vlSymsp);
    vlTOPp->__Vm_traceActivity[1U] = 1U;
    vlTOPp->__Vm_traceActivity[0U] = 1U;
}

void Vtop::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_ctor_var_reset\n"); );
    // Body
    sys_clk = VL_RAND_RESET_I(1);
    sys_rst = VL_RAND_RESET_I(1);
    serial_rx = VL_RAND_RESET_I(1);
    serial_tx = VL_RAND_RESET_I(1);
    spiflash_cs_n = VL_RAND_RESET_I(1);
    spiflash_clk = VL_RAND_RESET_I(1);
    spiflash_miso = VL_RAND_RESET_I(1);
    spiflash_mosi = VL_RAND_RESET_I(1);
    spiflash_wp = VL_RAND_RESET_I(1);
    spiflash_hold = VL_RAND_RESET_I(1);
    serial_dbg_rx = VL_RAND_RESET_I(1);
    serial_dbg_tx = VL_RAND_RESET_I(1);
    gpio_out_pad = VL_RAND_RESET_I(1);
    gpio_in_pad = VL_RAND_RESET_I(1);
    gpio_outenb_pad = VL_RAND_RESET_I(1);
    gpio_inenb_pad = VL_RAND_RESET_I(1);
    gpio_mode0_pad = VL_RAND_RESET_I(1);
    gpio_mode1_pad = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, la_output);
    VL_RAND_RESET_W(128, la_input);
    VL_RAND_RESET_W(128, la_oenb);
    VL_RAND_RESET_W(128, la_iena);
    mprj_wb_iena = VL_RAND_RESET_I(1);
    user_irq_ena = VL_RAND_RESET_I(3);
    top__DOT__int_rst = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_soc_rst = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_reset_storage = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_reset_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_scratch_storage = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_scratch_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_bus_errors_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_bus_errors = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_picorv32_trap = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv32_interrupt = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_picorv32_idbus_ack = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv32_mem_valid = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv32_mem_instr = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv32_mem_addr = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_picorv32_mem_wdata = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_picorv32_mem_wstrb = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_picorv320 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv321 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv323 = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_picorv324 = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_picorv325 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_picorv326 = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_picorv329 = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_tx_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_tx_data = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_tx_count = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_tx_enable = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_tx_tick = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_tx_phase = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_rx_source_valid = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_rx_source_payload_data = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_rx_data = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_rx_count = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_rx_enable = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_rx_tick = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_rx_phase = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_rx_rx_d = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rxtx_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rxtx_we = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_txfull_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rxempty_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_pending = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_clear = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_trigger_d = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_pending = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_clear = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_trigger_d = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_status_status = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_uart_status_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_pending_status = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_uart_pending_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_pending_r = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_uart_enable_storage = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_uart_enable_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_txempty_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rxfull_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_fifo_readable = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_writable = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_tx_fifo_level0 = VL_RAND_RESET_I(5);
    top__DOT__mgmtsoc_uart_tx_fifo_produce = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_uart_tx_fifo_consume = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_uart_tx_fifo_do_read = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_fifo_readable = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_writable = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_uart_rx_fifo_level0 = VL_RAND_RESET_I(5);
    top__DOT__mgmtsoc_uart_rx_fifo_produce = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_uart_rx_fifo_consume = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_uart_rx_fifo_do_read = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_load_storage = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_timer_load_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_reload_storage = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_timer_reload_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_en_storage = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_en_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_update_value_storage = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_update_value_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_value_status = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_timer_value_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_zero_pending = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_zero_clear = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_zero_trigger_d = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_status_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_pending_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_pending_r = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_enable_storage = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_enable_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_timer_value = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_litespisdrphycore_source_valid = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_source_last = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_storage = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_litespisdrphycore_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_negedge = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_en = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_cnt = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_litespisdrphycore_clk = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_posedge_reg = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_done = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_count = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_litespisdrphycore_dq_o = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_dq_i = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_litespisdrphycore_sr_cnt = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_litespisdrphycore_sr_out_load = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_sr_out_shift = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_sr_out = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespisdrphycore_sr_in = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_crossbar_cs = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_source_valid = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_source_last = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_source_payload_data = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_litespimmap_source_payload_len = VL_RAND_RESET_I(6);
    top__DOT__mgmtsoc_litespimmap_source_payload_width = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_litespimmap_source_payload_mask = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_litespimmap_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_litespimmap_bus_cyc = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_bus_ack = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_cs = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_burst_cs = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_burst_adr = VL_RAND_RESET_I(30);
    top__DOT__mgmtsoc_litespimmap_wait = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_done = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_count = VL_RAND_RESET_I(9);
    top__DOT__mgmtsoc_litespimmap_storage = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_litespimmap_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_cs_storage = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_cs_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_phyconfig_storage = VL_RAND_RESET_I(24);
    top__DOT__mgmtsoc_master_phyconfig_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_rxtx_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_rxtx_we = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_status_status = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_master_status_re = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_tx_fifo_source_valid = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_tx_fifo_source_first = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_tx_fifo_source_last = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_tx_fifo_source_payload_data = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_master_tx_fifo_source_payload_len = VL_RAND_RESET_I(6);
    top__DOT__mgmtsoc_master_tx_fifo_source_payload_width = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_master_tx_fifo_source_payload_mask = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_master_rx_fifo_source_valid = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_rx_fifo_source_first = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_rx_fifo_source_last = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_master_rx_fifo_source_payload_data = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_tx_sink_valid = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_tx_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_tx_sink_payload_data = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_tx_data = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_tx_count = VL_RAND_RESET_I(4);
    top__DOT__uart_bridge_tx_enable = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_tx_tick = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_tx_phase = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_rx_source_valid = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_rx_source_ready = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_rx_source_payload_data = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_rx_data = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_rx_count = VL_RAND_RESET_I(4);
    top__DOT__uart_bridge_rx_enable = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_rx_tick = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_rx_phase = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_rx_rx_d = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_wishbone_cyc = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_wishbone_stb = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_wishbone_ack = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_wishbone_we = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_cmd = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_incr = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_length = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_address = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_data = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_bytes_count = VL_RAND_RESET_I(2);
    top__DOT__uart_bridge_words_count = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_done = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_count = VL_RAND_RESET_I(20);
    top__DOT__uart_bridge_is_ongoing = VL_RAND_RESET_I(1);
    top__DOT__gpio_mode1_storage = VL_RAND_RESET_I(1);
    top__DOT__gpio_mode1_re = VL_RAND_RESET_I(1);
    top__DOT__gpio_mode0_storage = VL_RAND_RESET_I(1);
    top__DOT__gpio_mode0_re = VL_RAND_RESET_I(1);
    top__DOT__gpio_ien_storage = VL_RAND_RESET_I(1);
    top__DOT__gpio_ien_re = VL_RAND_RESET_I(1);
    top__DOT__gpio_oe_storage = VL_RAND_RESET_I(1);
    top__DOT__gpio_oe_re = VL_RAND_RESET_I(1);
    top__DOT__gpio_in_re = VL_RAND_RESET_I(1);
    top__DOT__gpio_out_storage = VL_RAND_RESET_I(1);
    top__DOT__gpio_out_re = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, top__DOT__la_ien_storage);
    top__DOT__la_ien_re = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, top__DOT__la_oe_storage);
    top__DOT__la_oe_re = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, top__DOT__la_in_status);
    top__DOT__la_in_re = VL_RAND_RESET_I(1);
    VL_RAND_RESET_W(128, top__DOT__la_out_storage);
    top__DOT__la_out_re = VL_RAND_RESET_I(1);
    top__DOT__mprj_wb_iena_storage = VL_RAND_RESET_I(1);
    top__DOT__mprj_wb_iena_re = VL_RAND_RESET_I(1);
    top__DOT__user_irq_ena_storage = VL_RAND_RESET_I(3);
    top__DOT__user_irq_ena_re = VL_RAND_RESET_I(1);
    top__DOT__rs232phy_rs232phytx_state = VL_RAND_RESET_I(1);
    top__DOT__rs232phy_rs232phytx_next_state = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0 = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2 = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2 = VL_RAND_RESET_I(1);
    top__DOT__rs232phy_rs232phyrx_state = VL_RAND_RESET_I(1);
    top__DOT__rs232phy_rs232phyrx_next_state = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0 = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value1 = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value_ce1 = VL_RAND_RESET_I(1);
    top__DOT__litespiphy_state = VL_RAND_RESET_I(2);
    top__DOT__litespiphy_next_state = VL_RAND_RESET_I(2);
    top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value = VL_RAND_RESET_I(8);
    top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce = VL_RAND_RESET_I(1);
    top__DOT__litespi_request = VL_RAND_RESET_I(2);
    top__DOT__litespi_grant = VL_RAND_RESET_I(1);
    top__DOT__litespi_tx_mux_source_valid = VL_RAND_RESET_I(1);
    top__DOT__litespi_tx_mux_source_first = VL_RAND_RESET_I(1);
    top__DOT__litespi_tx_mux_source_last = VL_RAND_RESET_I(1);
    top__DOT__litespi_tx_mux_source_payload_data = VL_RAND_RESET_I(32);
    top__DOT__litespi_tx_mux_source_payload_len = VL_RAND_RESET_I(6);
    top__DOT__litespi_tx_mux_source_payload_width = VL_RAND_RESET_I(4);
    top__DOT__litespi_tx_mux_source_payload_mask = VL_RAND_RESET_I(8);
    top__DOT__litespi_tx_mux_endpoint0_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__litespi_tx_mux_endpoint1_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_sink_ready = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint0_source_valid = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint0_source_first = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint0_source_last = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint0_source_payload_data = VL_RAND_RESET_I(32);
    top__DOT__litespi_rx_demux_endpoint1_source_valid = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint1_source_first = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint1_source_last = VL_RAND_RESET_I(1);
    top__DOT__litespi_rx_demux_endpoint1_source_payload_data = VL_RAND_RESET_I(32);
    top__DOT__litespi_state = VL_RAND_RESET_I(4);
    top__DOT__litespi_next_state = VL_RAND_RESET_I(4);
    top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1 = VL_RAND_RESET_I(30);
    top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1 = VL_RAND_RESET_I(1);
    top__DOT__uartwishbonebridge_rs232phytx_state = VL_RAND_RESET_I(1);
    top__DOT__uartwishbonebridge_rs232phytx_next_state = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0 = VL_RAND_RESET_I(4);
    top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0 = VL_RAND_RESET_I(1);
    top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1 = VL_RAND_RESET_I(1);
    top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2 = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2 = VL_RAND_RESET_I(1);
    top__DOT__uartwishbonebridge_rs232phyrx_state = VL_RAND_RESET_I(1);
    top__DOT__uartwishbonebridge_rs232phyrx_next_state = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0 = VL_RAND_RESET_I(4);
    top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value1 = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value_ce1 = VL_RAND_RESET_I(1);
    top__DOT__uartwishbonebridge_state = VL_RAND_RESET_I(3);
    top__DOT__uartwishbonebridge_next_state = VL_RAND_RESET_I(3);
    top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0 = VL_RAND_RESET_I(2);
    top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1 = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2 = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_length_uartwishbonebridge_next_value3 = VL_RAND_RESET_I(8);
    top__DOT__uart_bridge_length_uartwishbonebridge_next_value_ce3 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_address_uartwishbonebridge_next_value4 = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5 = VL_RAND_RESET_I(1);
    top__DOT__uart_bridge_data_uartwishbonebridge_next_value6 = VL_RAND_RESET_I(32);
    top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6 = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_adr = VL_RAND_RESET_I(14);
    top__DOT__mgmtsoc_we = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_dat_w = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_wishbone_dat_r = VL_RAND_RESET_I(32);
    top__DOT__mgmtsoc_wishbone_cyc = VL_RAND_RESET_I(1);
    top__DOT__mgmtsoc_wishbone_ack = VL_RAND_RESET_I(1);
    top__DOT__shared_dat_r = VL_RAND_RESET_I(32);
    top__DOT__shared_ack = VL_RAND_RESET_I(1);
    top__DOT__request = VL_RAND_RESET_I(2);
    top__DOT__grant = VL_RAND_RESET_I(1);
    top__DOT__slave_sel = VL_RAND_RESET_I(2);
    top__DOT__slave_sel_r = VL_RAND_RESET_I(2);
    top__DOT__error = VL_RAND_RESET_I(1);
    top__DOT__done = VL_RAND_RESET_I(1);
    top__DOT__count = VL_RAND_RESET_I(20);
    top__DOT__interface0_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank0_reset0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank0_reset0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank0_scratch0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank0_scratch0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank0_bus_errors_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank0_bus_errors_we = VL_RAND_RESET_I(1);
    top__DOT__interface1_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank1_mode10_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_mode10_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_mode00_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_mode00_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_ien0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_ien0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_oe0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_oe0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_in_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_in_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_out0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank1_out0_we = VL_RAND_RESET_I(1);
    top__DOT__interface2_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank2_ien3_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien3_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien2_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien2_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien1_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien1_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_ien0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe3_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe3_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe2_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe2_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe1_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe1_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_oe0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in3_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in3_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in2_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in2_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in1_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in1_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_in0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out3_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out3_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out2_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out2_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out1_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out1_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank2_out0_we = VL_RAND_RESET_I(1);
    top__DOT__interface3_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank3_out0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank3_out0_we = VL_RAND_RESET_I(1);
    top__DOT__interface4_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank4_mmap_dummy_bits0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_mmap_dummy_bits0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_master_cs0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_master_cs0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_master_phyconfig0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_master_phyconfig0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_master_status_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank4_master_status_we = VL_RAND_RESET_I(1);
    top__DOT__interface5_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank5_clk_divisor0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank5_clk_divisor0_we = VL_RAND_RESET_I(1);
    top__DOT__interface6_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank6_load0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_load0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_reload0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_reload0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_en0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_en0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_update_value0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_update_value0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_value_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_value_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_ev_status_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_ev_status_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_ev_pending_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_ev_pending_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_ev_enable0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank6_ev_enable0_we = VL_RAND_RESET_I(1);
    top__DOT__interface7_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank7_txfull_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_txfull_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_rxempty_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_rxempty_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_ev_status_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_ev_status_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_ev_pending_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_ev_pending_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_ev_enable0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_ev_enable0_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_txempty_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_txempty_we = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_rxfull_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank7_rxfull_we = VL_RAND_RESET_I(1);
    top__DOT__interface8_bank_bus_dat_r = VL_RAND_RESET_I(32);
    top__DOT__csrbank8_out0_re = VL_RAND_RESET_I(1);
    top__DOT__csrbank8_out0_we = VL_RAND_RESET_I(1);
    top__DOT__state = VL_RAND_RESET_I(1);
    top__DOT__next_state = VL_RAND_RESET_I(1);
    top__DOT__array_muxed0 = VL_RAND_RESET_I(30);
    top__DOT__array_muxed1 = VL_RAND_RESET_I(32);
    top__DOT__array_muxed2 = VL_RAND_RESET_I(4);
    top__DOT__array_muxed3 = VL_RAND_RESET_I(1);
    top__DOT__array_muxed4 = VL_RAND_RESET_I(1);
    top__DOT__array_muxed5 = VL_RAND_RESET_I(1);
    top__DOT__array_muxed6 = VL_RAND_RESET_I(3);
    top__DOT__array_muxed7 = VL_RAND_RESET_I(2);
    top__DOT__multiregimpl0_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl0_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl1_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl1_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl2_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl2_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl3_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl3_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl4_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl4_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl5_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl5_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl6_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl6_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl7_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl7_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl8_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl8_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl9_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl9_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl10_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl10_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl11_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl11_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl12_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl12_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl13_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl13_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl14_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl14_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl15_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl15_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl16_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl16_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl17_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl17_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl18_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl18_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl19_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl19_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl20_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl20_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl21_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl21_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl22_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl22_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl23_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl23_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl24_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl24_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl25_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl25_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl26_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl26_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl27_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl27_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl28_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl28_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl29_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl29_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl30_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl30_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl31_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl31_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl32_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl32_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl33_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl33_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl34_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl34_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl35_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl35_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl36_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl36_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl37_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl37_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl38_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl38_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl39_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl39_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl40_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl40_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl41_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl41_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl42_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl42_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl43_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl43_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl44_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl44_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl45_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl45_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl46_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl46_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl47_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl47_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl48_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl48_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl49_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl49_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl50_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl50_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl51_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl51_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl52_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl52_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl53_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl53_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl54_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl54_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl55_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl55_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl56_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl56_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl57_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl57_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl58_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl58_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl59_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl59_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl60_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl60_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl61_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl61_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl62_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl62_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl63_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl63_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl64_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl64_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl65_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl65_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl66_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl66_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl67_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl67_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl68_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl68_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl69_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl69_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl70_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl70_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl71_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl71_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl72_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl72_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl73_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl73_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl74_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl74_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl75_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl75_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl76_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl76_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl77_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl77_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl78_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl78_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl79_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl79_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl80_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl80_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl81_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl81_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl82_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl82_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl83_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl83_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl84_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl84_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl85_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl85_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl86_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl86_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl87_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl87_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl88_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl88_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl89_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl89_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl90_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl90_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl91_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl91_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl92_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl92_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl93_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl93_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl94_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl94_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl95_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl95_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl96_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl96_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl97_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl97_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl98_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl98_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl99_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl99_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl100_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl100_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl101_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl101_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl102_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl102_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl103_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl103_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl104_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl104_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl105_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl105_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl106_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl106_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl107_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl107_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl108_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl108_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl109_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl109_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl110_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl110_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl111_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl111_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl112_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl112_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl113_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl113_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl114_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl114_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl115_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl115_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl116_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl116_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl117_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl117_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl118_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl118_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl119_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl119_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl120_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl120_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl121_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl121_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl122_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl122_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl123_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl123_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl124_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl124_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl125_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl125_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl126_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl126_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl127_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl127_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl128_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl128_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl129_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl129_regs1 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl130_regs0 = VL_RAND_RESET_I(1);
    top__DOT__multiregimpl130_regs1 = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        top__DOT__storage[__Vi0] = VL_RAND_RESET_I(10);
    }
    top__DOT__memdat = VL_RAND_RESET_I(10);
    top__DOT__memdat_1 = VL_RAND_RESET_I(10);
    for (int __Vi0=0; __Vi0<16; ++__Vi0) {
        top__DOT__storage_1[__Vi0] = VL_RAND_RESET_I(10);
    }
    top__DOT__memdat_2 = VL_RAND_RESET_I(10);
    top__DOT__memdat_3 = VL_RAND_RESET_I(10);
    top__DOT____Vcellinp__picorv32__resetn = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__trace_valid = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__trace_data = VL_RAND_RESET_Q(36);
    top__DOT__picorv32__DOT__count_cycle = VL_RAND_RESET_Q(64);
    top__DOT__picorv32__DOT__count_instr = VL_RAND_RESET_Q(64);
    top__DOT__picorv32__DOT__reg_pc = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__reg_next_pc = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__reg_op1 = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__reg_op2 = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__reg_out = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__reg_sh = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__next_insn_opcode = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__dbg_insn_opcode = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__dbg_insn_addr = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__next_pc = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__irq_delay = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__irq_active = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__irq_mask = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__irq_pending = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__timer = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<36; ++__Vi0) {
        top__DOT__picorv32__DOT__cpuregs[__Vi0] = VL_RAND_RESET_I(32);
    }
    top__DOT__picorv32__DOT__i = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__mem_state = VL_RAND_RESET_I(2);
    top__DOT__picorv32__DOT__mem_wordsize = VL_RAND_RESET_I(2);
    top__DOT__picorv32__DOT__mem_rdata_word = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__mem_rdata_q = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__mem_do_prefetch = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_do_rinst = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_do_rdata = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_do_wdata = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_xfer = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_la_secondword = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_la_firstword_reg = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__last_mem_valid = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__prefetched_high_word = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__clear_prefetched_high_word = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__mem_16bit_buffer = VL_RAND_RESET_I(16);
    top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__mem_done = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_lui = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_auipc = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_jal = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_jalr = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_beq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_bne = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_blt = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_bge = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_bltu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_bgeu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_lb = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_lh = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_lw = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_lbu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_lhu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sb = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sh = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sw = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_addi = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_slti = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sltiu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_xori = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_ori = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_andi = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_slli = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_srli = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_srai = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_add = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sub = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sll = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_slt = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sltu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_xor = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_srl = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_sra = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_or = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_and = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_rdcycle = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_rdcycleh = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_rdinstr = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_rdinstrh = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_ecall_ebreak = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_getq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_setq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_retirq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_maskirq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_waitirq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_timer = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__instr_trap = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__decoded_rd = VL_RAND_RESET_I(6);
    top__DOT__picorv32__DOT__decoded_rs1 = VL_RAND_RESET_I(6);
    top__DOT__picorv32__DOT__decoded_rs2 = VL_RAND_RESET_I(6);
    top__DOT__picorv32__DOT__decoded_imm = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__decoded_imm_j = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__decoder_trigger = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__decoder_trigger_q = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__decoder_pseudo_trigger = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__decoder_pseudo_trigger_q = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__compressed_instr = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_lui_auipc_jal = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_slli_srli_srai = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_sb_sh_sw = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_sll_srl_sra = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_lui_auipc_jal_jalr_addi_add_sub = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_slti_blt_slt = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_sltiu_bltu_sltu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_lbu_lhu_lw = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_alu_reg_imm = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_alu_reg_reg = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__is_compare = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__new_ascii_instr = VL_RAND_RESET_Q(64);
    top__DOT__picorv32__DOT__dbg_ascii_instr = VL_RAND_RESET_Q(64);
    top__DOT__picorv32__DOT__dbg_insn_imm = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__dbg_insn_rs1 = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__dbg_insn_rs2 = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__dbg_insn_rd = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__dbg_rs1val = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__dbg_rs2val = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__dbg_rs1val_valid = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__dbg_rs2val_valid = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__q_ascii_instr = VL_RAND_RESET_Q(64);
    top__DOT__picorv32__DOT__q_insn_imm = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__q_insn_opcode = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__q_insn_rs1 = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__q_insn_rs2 = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__q_insn_rd = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__dbg_next = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__launch_next_insn = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__dbg_valid_insn = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__cached_ascii_instr = VL_RAND_RESET_Q(64);
    top__DOT__picorv32__DOT__cached_insn_imm = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__cached_insn_opcode = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__cached_insn_rs1 = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__cached_insn_rs2 = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__cached_insn_rd = VL_RAND_RESET_I(5);
    top__DOT__picorv32__DOT__cpu_state = VL_RAND_RESET_I(8);
    top__DOT__picorv32__DOT__irq_state = VL_RAND_RESET_I(2);
    VL_RAND_RESET_W(128, top__DOT__picorv32__DOT__dbg_ascii_state);
    top__DOT__picorv32__DOT__set_mem_do_rinst = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__set_mem_do_rdata = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__set_mem_do_wdata = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_store = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_stalu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_branch = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_compr = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_trace = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_is_lu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_is_lh = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_is_lb = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__latched_rd = VL_RAND_RESET_I(6);
    top__DOT__picorv32__DOT__current_pc = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__pcpi_timeout_counter = VL_RAND_RESET_I(4);
    top__DOT__picorv32__DOT__pcpi_timeout = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__next_irq_pending = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__do_waitirq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_out = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__alu_out_q = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__alu_out_0 = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_out_0_q = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_wait = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_wait_2 = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_eq = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_ltu = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__alu_lts = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__clear_prefetched_high_word_q = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__cpuregs_write = VL_RAND_RESET_I(1);
    top__DOT__picorv32__DOT__cpuregs_wrdata = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__cpuregs_rs1 = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT__cpuregs_rs2 = VL_RAND_RESET_I(32);
    top__DOT__picorv32__DOT____Vlvbound1 = VL_RAND_RESET_I(32);
    __Vtableidx1 = 0;
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[0],0x00000000);
    VL_CONST_W_2X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[1],0x0000006c,0x646d656d);
    VL_CONST_W_2X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[2],0x00000073,0x746d656d);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[3],0x00000000);
    VL_CONST_W_2X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[4],0x00000073,0x68696674);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[5],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[6],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[7],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[8],0x65786563);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[9],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[10],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[11],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[12],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[13],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[14],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[15],0x00000000);
    VL_CONST_W_2X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[16],0x00006c64,0x5f727332);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[17],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[18],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[19],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[20],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[21],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[22],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[23],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[24],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[25],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[26],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[27],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[28],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[29],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[30],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[31],0x00000000);
    VL_CONST_W_2X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[32],0x00006c64,0x5f727331);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[33],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[34],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[35],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[36],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[37],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[38],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[39],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[40],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[41],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[42],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[43],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[44],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[45],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[46],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[47],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[48],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[49],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[50],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[51],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[52],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[53],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[54],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[55],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[56],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[57],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[58],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[59],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[60],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[61],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[62],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[63],0x00000000);
    VL_CONST_W_2X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[64],0x00000066,0x65746368);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[65],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[66],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[67],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[68],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[69],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[70],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[71],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[72],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[73],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[74],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[75],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[76],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[77],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[78],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[79],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[80],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[81],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[82],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[83],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[84],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[85],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[86],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[87],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[88],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[89],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[90],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[91],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[92],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[93],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[94],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[95],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[96],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[97],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[98],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[99],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[100],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[101],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[102],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[103],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[104],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[105],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[106],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[107],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[108],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[109],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[110],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[111],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[112],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[113],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[114],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[115],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[116],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[117],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[118],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[119],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[120],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[121],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[122],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[123],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[124],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[125],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[126],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[127],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[128],0x74726170);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[129],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[130],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[131],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[132],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[133],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[134],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[135],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[136],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[137],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[138],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[139],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[140],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[141],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[142],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[143],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[144],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[145],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[146],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[147],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[148],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[149],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[150],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[151],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[152],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[153],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[154],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[155],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[156],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[157],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[158],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[159],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[160],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[161],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[162],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[163],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[164],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[165],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[166],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[167],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[168],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[169],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[170],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[171],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[172],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[173],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[174],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[175],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[176],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[177],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[178],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[179],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[180],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[181],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[182],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[183],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[184],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[185],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[186],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[187],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[188],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[189],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[190],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[191],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[192],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[193],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[194],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[195],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[196],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[197],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[198],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[199],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[200],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[201],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[202],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[203],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[204],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[205],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[206],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[207],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[208],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[209],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[210],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[211],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[212],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[213],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[214],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[215],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[216],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[217],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[218],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[219],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[220],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[221],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[222],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[223],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[224],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[225],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[226],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[227],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[228],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[229],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[230],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[231],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[232],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[233],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[234],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[235],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[236],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[237],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[238],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[239],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[240],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[241],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[242],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[243],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[244],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[245],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[246],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[247],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[248],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[249],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[250],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[251],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[252],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[253],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[254],0x00000000);
    VL_CONST_W_1X(128,__Vtable1_top__DOT__picorv32__DOT__dbg_ascii_state[255],0x00000000);
    __Vdly__top__DOT__mgmtsoc_timer_value = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__picorv32__DOT__mem_state = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__picorv32__DOT__reg_sh = VL_RAND_RESET_I(5);
    __Vdly__top__DOT__picorv32__DOT__reg_out = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__picorv32__DOT__decoder_trigger = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__decoder_pseudo_trigger = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__do_waitirq = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__mem_do_rinst = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__latched_is_lu = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__latched_is_lh = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__latched_is_lb = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__irq_active = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__reg_pc = VL_RAND_RESET_I(32);
    __Vdly__top__DOT__picorv32__DOT__latched_rd = VL_RAND_RESET_I(6);
    __Vdly__top__DOT__picorv32__DOT__latched_compr = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__irq_state = VL_RAND_RESET_I(2);
    __Vdly__top__DOT__picorv32__DOT__mem_do_prefetch = VL_RAND_RESET_I(1);
    __Vdly__top__DOT__picorv32__DOT__cpu_state = VL_RAND_RESET_I(8);
    __Vdly__top__DOT__picorv32__DOT__reg_op1 = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
