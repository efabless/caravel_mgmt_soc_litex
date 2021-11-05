// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vtop::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[0U])) {
            tracep->chgCData(oldp+0,(vlTOPp->top__DOT__array_muxed6),3);
            tracep->chgCData(oldp+1,(vlTOPp->top__DOT__array_muxed7),2);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgBit(oldp+2,(vlTOPp->top__DOT__int_rst));
            tracep->chgBit(oldp+3,(vlTOPp->top__DOT__mgmtsoc_soc_rst));
            tracep->chgBit(oldp+4,((1U & ((IData)(vlTOPp->top__DOT__mgmtsoc_reset_storage) 
                                          >> 1U))));
            tracep->chgCData(oldp+5,(vlTOPp->top__DOT__mgmtsoc_reset_storage),2);
            tracep->chgBit(oldp+6,(vlTOPp->top__DOT__mgmtsoc_reset_re));
            tracep->chgIData(oldp+7,(vlTOPp->top__DOT__mgmtsoc_scratch_storage),32);
            tracep->chgBit(oldp+8,(vlTOPp->top__DOT__mgmtsoc_scratch_re));
            tracep->chgIData(oldp+9,(vlTOPp->top__DOT__mgmtsoc_bus_errors),32);
            tracep->chgBit(oldp+10,(vlTOPp->top__DOT__csrbank0_bus_errors_we));
            tracep->chgBit(oldp+11,(vlTOPp->top__DOT__mgmtsoc_bus_errors_re));
            tracep->chgBit(oldp+12,(vlTOPp->top__DOT__error));
            tracep->chgBit(oldp+13,(vlTOPp->top__DOT__mgmtsoc_picorv32_trap));
            tracep->chgBit(oldp+14,((1U & ((IData)(vlTOPp->top__DOT__mgmtsoc_soc_rst) 
                                           | ((IData)(vlTOPp->top__DOT__mgmtsoc_reset_storage) 
                                              >> 1U)))));
            tracep->chgIData(oldp+15,(vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt),32);
            tracep->chgIData(oldp+16,((0x3fffffffU 
                                       & (vlTOPp->top__DOT__mgmtsoc_picorv32_mem_addr 
                                          >> 2U))),30);
            tracep->chgIData(oldp+17,(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wdata),32);
            tracep->chgIData(oldp+18,(vlTOPp->top__DOT__shared_dat_r),32);
            tracep->chgCData(oldp+19,(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb),4);
            tracep->chgBit(oldp+20,(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid));
            tracep->chgBit(oldp+21,(vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack));
            tracep->chgBit(oldp+22,((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb))));
            tracep->chgBit(oldp+23,(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_instr));
            tracep->chgIData(oldp+24,(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_addr),32);
            tracep->chgBit(oldp+25,(vlTOPp->top__DOT__mgmtsoc_picorv320));
            tracep->chgBit(oldp+26,(vlTOPp->top__DOT__mgmtsoc_picorv321));
            tracep->chgIData(oldp+27,((((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch) 
                                        | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst))
                                        ? (0xfffffffcU 
                                           & vlTOPp->top__DOT__picorv32__DOT__next_pc)
                                        : (0xfffffffcU 
                                           & vlTOPp->top__DOT__picorv32__DOT__reg_op1))),32);
            tracep->chgIData(oldp+28,(vlTOPp->top__DOT__mgmtsoc_picorv323),32);
            tracep->chgCData(oldp+29,(vlTOPp->top__DOT__mgmtsoc_picorv324),4);
            tracep->chgBit(oldp+30,(vlTOPp->top__DOT__mgmtsoc_picorv325));
            tracep->chgIData(oldp+31,(vlTOPp->top__DOT__mgmtsoc_picorv326),32);
            tracep->chgIData(oldp+32,(vlTOPp->top__DOT__picorv32__DOT__reg_op1),32);
            tracep->chgIData(oldp+33,(vlTOPp->top__DOT__picorv32__DOT__reg_op2),32);
            tracep->chgIData(oldp+34,(vlTOPp->top__DOT__mgmtsoc_picorv329),32);
            tracep->chgBit(oldp+35,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable));
            tracep->chgBit(oldp+36,(vlTOPp->top__DOT__mgmtsoc_tx_sink_ready));
            tracep->chgBit(oldp+37,((1U & ((IData)(vlTOPp->top__DOT__memdat_1) 
                                           >> 8U))));
            tracep->chgBit(oldp+38,((1U & ((IData)(vlTOPp->top__DOT__memdat_1) 
                                           >> 9U))));
            tracep->chgCData(oldp+39,((0xffU & (IData)(vlTOPp->top__DOT__memdat_1))),8);
            tracep->chgCData(oldp+40,(vlTOPp->top__DOT__mgmtsoc_tx_data),8);
            tracep->chgCData(oldp+41,(vlTOPp->top__DOT__mgmtsoc_tx_count),4);
            tracep->chgBit(oldp+42,(vlTOPp->top__DOT__mgmtsoc_tx_enable));
            tracep->chgBit(oldp+43,(vlTOPp->top__DOT__mgmtsoc_tx_tick));
            tracep->chgIData(oldp+44,(vlTOPp->top__DOT__mgmtsoc_tx_phase),32);
            tracep->chgBit(oldp+45,(vlTOPp->top__DOT__mgmtsoc_rx_source_valid));
            tracep->chgBit(oldp+46,((0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0))));
            tracep->chgCData(oldp+47,(vlTOPp->top__DOT__mgmtsoc_rx_source_payload_data),8);
            tracep->chgCData(oldp+48,(vlTOPp->top__DOT__mgmtsoc_rx_data),8);
            tracep->chgCData(oldp+49,(vlTOPp->top__DOT__mgmtsoc_rx_count),4);
            tracep->chgBit(oldp+50,(vlTOPp->top__DOT__mgmtsoc_rx_enable));
            tracep->chgBit(oldp+51,(vlTOPp->top__DOT__mgmtsoc_rx_tick));
            tracep->chgIData(oldp+52,(vlTOPp->top__DOT__mgmtsoc_rx_phase),32);
            tracep->chgBit(oldp+53,(vlTOPp->top__DOT__multiregimpl0_regs1));
            tracep->chgBit(oldp+54,(vlTOPp->top__DOT__mgmtsoc_rx_rx_d));
            tracep->chgBit(oldp+55,(vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re));
            tracep->chgCData(oldp+56,((0xffU & vlTOPp->top__DOT__mgmtsoc_dat_w)),8);
            tracep->chgBit(oldp+57,(vlTOPp->top__DOT__mgmtsoc_uart_rxtx_we));
            tracep->chgCData(oldp+58,((0xffU & (IData)(vlTOPp->top__DOT__memdat_3))),8);
            tracep->chgBit(oldp+59,((0x10U == (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0))));
            tracep->chgBit(oldp+60,(vlTOPp->top__DOT__csrbank7_txfull_we));
            tracep->chgBit(oldp+61,(vlTOPp->top__DOT__mgmtsoc_uart_txfull_re));
            tracep->chgBit(oldp+62,((1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable)))));
            tracep->chgBit(oldp+63,(vlTOPp->top__DOT__csrbank7_rxempty_we));
            tracep->chgBit(oldp+64,(vlTOPp->top__DOT__mgmtsoc_uart_rxempty_re));
            tracep->chgBit(oldp+65,((1U & (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status) 
                                            & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage)) 
                                           | (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status) 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage)) 
                                              >> 1U)))));
            tracep->chgBit(oldp+66,((0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0))));
            tracep->chgBit(oldp+67,(vlTOPp->top__DOT__mgmtsoc_uart_tx_pending));
            tracep->chgBit(oldp+68,(vlTOPp->top__DOT__mgmtsoc_uart_tx_clear));
            tracep->chgBit(oldp+69,(vlTOPp->top__DOT__mgmtsoc_uart_tx_trigger_d));
            tracep->chgBit(oldp+70,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable));
            tracep->chgBit(oldp+71,(vlTOPp->top__DOT__mgmtsoc_uart_rx_pending));
            tracep->chgBit(oldp+72,(vlTOPp->top__DOT__mgmtsoc_uart_rx_clear));
            tracep->chgBit(oldp+73,(vlTOPp->top__DOT__mgmtsoc_uart_rx_trigger_d));
            tracep->chgCData(oldp+74,(vlTOPp->top__DOT__mgmtsoc_uart_status_status),2);
            tracep->chgBit(oldp+75,(vlTOPp->top__DOT__csrbank7_ev_status_we));
            tracep->chgBit(oldp+76,(vlTOPp->top__DOT__mgmtsoc_uart_status_re));
            tracep->chgCData(oldp+77,(vlTOPp->top__DOT__mgmtsoc_uart_pending_status),2);
            tracep->chgBit(oldp+78,(vlTOPp->top__DOT__csrbank7_ev_pending_we));
            tracep->chgBit(oldp+79,(vlTOPp->top__DOT__mgmtsoc_uart_pending_re));
            tracep->chgCData(oldp+80,(vlTOPp->top__DOT__mgmtsoc_uart_pending_r),2);
            tracep->chgBit(oldp+81,((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage))));
            tracep->chgBit(oldp+82,((1U & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage) 
                                           >> 1U))));
            tracep->chgCData(oldp+83,(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage),2);
            tracep->chgBit(oldp+84,(vlTOPp->top__DOT__mgmtsoc_uart_enable_re));
            tracep->chgBit(oldp+85,((1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable)))));
            tracep->chgBit(oldp+86,(vlTOPp->top__DOT__csrbank7_txempty_we));
            tracep->chgBit(oldp+87,(vlTOPp->top__DOT__mgmtsoc_uart_txempty_re));
            tracep->chgBit(oldp+88,((0x10U == (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0))));
            tracep->chgBit(oldp+89,(vlTOPp->top__DOT__csrbank7_rxfull_we));
            tracep->chgBit(oldp+90,(vlTOPp->top__DOT__mgmtsoc_uart_rxfull_re));
            tracep->chgBit(oldp+91,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re));
            tracep->chgBit(oldp+92,((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0))));
            tracep->chgSData(oldp+93,((0xffU & vlTOPp->top__DOT__mgmtsoc_dat_w)),10);
            tracep->chgSData(oldp+94,(vlTOPp->top__DOT__memdat_1),10);
            tracep->chgCData(oldp+95,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0),5);
            tracep->chgCData(oldp+96,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce),4);
            tracep->chgCData(oldp+97,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_consume),4);
            tracep->chgCData(oldp+98,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr),4);
            tracep->chgSData(oldp+99,(vlTOPp->top__DOT__memdat),10);
            tracep->chgBit(oldp+100,(((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re) 
                                      & (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)))));
            tracep->chgBit(oldp+101,(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read));
            tracep->chgCData(oldp+102,((0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0) 
                                                 + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable)))),5);
            tracep->chgBit(oldp+103,((1U & ((IData)(vlTOPp->top__DOT__memdat_3) 
                                            >> 8U))));
            tracep->chgBit(oldp+104,((1U & ((IData)(vlTOPp->top__DOT__memdat_3) 
                                            >> 9U))));
            tracep->chgBit(oldp+105,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re));
            tracep->chgBit(oldp+106,((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0))));
            tracep->chgSData(oldp+107,(vlTOPp->top__DOT__mgmtsoc_rx_source_payload_data),10);
            tracep->chgSData(oldp+108,(vlTOPp->top__DOT__memdat_3),10);
            tracep->chgCData(oldp+109,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0),5);
            tracep->chgCData(oldp+110,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce),4);
            tracep->chgCData(oldp+111,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_consume),4);
            tracep->chgCData(oldp+112,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr),4);
            tracep->chgSData(oldp+113,(vlTOPp->top__DOT__memdat_2),10);
            tracep->chgBit(oldp+114,(((IData)(vlTOPp->top__DOT__mgmtsoc_rx_source_valid) 
                                      & (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)))));
            tracep->chgBit(oldp+115,(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read));
            tracep->chgCData(oldp+116,((0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0) 
                                                 + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable)))),5);
            tracep->chgIData(oldp+117,(vlTOPp->top__DOT__mgmtsoc_timer_load_storage),32);
            tracep->chgBit(oldp+118,(vlTOPp->top__DOT__mgmtsoc_timer_load_re));
            tracep->chgIData(oldp+119,(vlTOPp->top__DOT__mgmtsoc_timer_reload_storage),32);
            tracep->chgBit(oldp+120,(vlTOPp->top__DOT__mgmtsoc_timer_reload_re));
            tracep->chgBit(oldp+121,(vlTOPp->top__DOT__mgmtsoc_timer_en_storage));
            tracep->chgBit(oldp+122,(vlTOPp->top__DOT__mgmtsoc_timer_en_re));
            tracep->chgBit(oldp+123,(vlTOPp->top__DOT__mgmtsoc_timer_update_value_storage));
            tracep->chgBit(oldp+124,(vlTOPp->top__DOT__mgmtsoc_timer_update_value_re));
            tracep->chgIData(oldp+125,(vlTOPp->top__DOT__mgmtsoc_timer_value_status),32);
            tracep->chgBit(oldp+126,(vlTOPp->top__DOT__csrbank6_value_we));
            tracep->chgBit(oldp+127,(vlTOPp->top__DOT__mgmtsoc_timer_value_re));
            tracep->chgBit(oldp+128,(((IData)(vlTOPp->top__DOT__mgmtsoc_timer_zero_pending) 
                                      & (IData)(vlTOPp->top__DOT__mgmtsoc_timer_enable_storage))));
            tracep->chgBit(oldp+129,((0U == vlTOPp->top__DOT__mgmtsoc_timer_value)));
            tracep->chgBit(oldp+130,(vlTOPp->top__DOT__mgmtsoc_timer_zero_pending));
            tracep->chgBit(oldp+131,(vlTOPp->top__DOT__mgmtsoc_timer_zero_clear));
            tracep->chgBit(oldp+132,(vlTOPp->top__DOT__mgmtsoc_timer_zero_trigger_d));
            tracep->chgBit(oldp+133,(vlTOPp->top__DOT__csrbank6_ev_status_we));
            tracep->chgBit(oldp+134,(vlTOPp->top__DOT__mgmtsoc_timer_status_re));
            tracep->chgBit(oldp+135,(vlTOPp->top__DOT__csrbank6_ev_pending_we));
            tracep->chgBit(oldp+136,(vlTOPp->top__DOT__mgmtsoc_timer_pending_re));
            tracep->chgBit(oldp+137,(vlTOPp->top__DOT__mgmtsoc_timer_pending_r));
            tracep->chgBit(oldp+138,(vlTOPp->top__DOT__mgmtsoc_timer_enable_storage));
            tracep->chgBit(oldp+139,(vlTOPp->top__DOT__mgmtsoc_timer_enable_re));
            tracep->chgIData(oldp+140,(vlTOPp->top__DOT__mgmtsoc_timer_value),32);
            tracep->chgBit(oldp+141,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_valid));
            tracep->chgBit(oldp+142,(vlTOPp->top__DOT__litespi_rx_demux_sink_ready));
            tracep->chgBit(oldp+143,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_source_last));
            tracep->chgIData(oldp+144,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in),32);
            tracep->chgBit(oldp+145,(vlTOPp->top__DOT__litespi_tx_mux_source_valid));
            tracep->chgBit(oldp+146,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready));
            tracep->chgBit(oldp+147,(vlTOPp->top__DOT__litespi_tx_mux_source_first));
            tracep->chgBit(oldp+148,(vlTOPp->top__DOT__litespi_tx_mux_source_last));
            tracep->chgIData(oldp+149,(vlTOPp->top__DOT__litespi_tx_mux_source_payload_data),32);
            tracep->chgCData(oldp+150,(vlTOPp->top__DOT__litespi_tx_mux_source_payload_len),6);
            tracep->chgCData(oldp+151,(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width),4);
            tracep->chgCData(oldp+152,(vlTOPp->top__DOT__litespi_tx_mux_source_payload_mask),8);
            tracep->chgBit(oldp+153,(vlTOPp->top__DOT__mgmtsoc_crossbar_cs));
            tracep->chgCData(oldp+154,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage),8);
            tracep->chgBit(oldp+155,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_re));
            tracep->chgBit(oldp+156,((((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en) 
                                       & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk))) 
                                      & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt) 
                                         == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)))));
            tracep->chgBit(oldp+157,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge));
            tracep->chgBit(oldp+158,((1U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt))));
            tracep->chgBit(oldp+159,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en));
            tracep->chgCData(oldp+160,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt),8);
            tracep->chgBit(oldp+161,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk));
            tracep->chgBit(oldp+162,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg));
            tracep->chgBit(oldp+163,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2));
            tracep->chgBit(oldp+164,((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count))));
            tracep->chgCData(oldp+165,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count),4);
            tracep->chgBit(oldp+166,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o));
            tracep->chgCData(oldp+167,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i),2);
            tracep->chgBit(oldp+168,((1U & (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_mask))));
            tracep->chgCData(oldp+169,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt),8);
            tracep->chgBit(oldp+170,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_load));
            tracep->chgBit(oldp+171,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_shift));
            tracep->chgIData(oldp+172,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out),32);
            tracep->chgBit(oldp+173,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift));
            tracep->chgBit(oldp+174,(vlTOPp->top__DOT__mgmtsoc_litespimmap_source_valid));
            tracep->chgBit(oldp+175,(vlTOPp->top__DOT__litespi_tx_mux_endpoint0_sink_ready));
            tracep->chgBit(oldp+176,(vlTOPp->top__DOT__mgmtsoc_litespimmap_source_last));
            tracep->chgIData(oldp+177,(vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_data),32);
            tracep->chgCData(oldp+178,(vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_len),6);
            tracep->chgCData(oldp+179,(vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_width),4);
            tracep->chgCData(oldp+180,(vlTOPp->top__DOT__mgmtsoc_litespimmap_source_payload_mask),8);
            tracep->chgBit(oldp+181,(vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_valid));
            tracep->chgBit(oldp+182,(vlTOPp->top__DOT__mgmtsoc_litespimmap_sink_ready));
            tracep->chgBit(oldp+183,(vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_first));
            tracep->chgBit(oldp+184,(vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_last));
            tracep->chgIData(oldp+185,(vlTOPp->top__DOT__litespi_rx_demux_endpoint0_source_payload_data),32);
            tracep->chgIData(oldp+186,(vlTOPp->top__DOT__array_muxed0),30);
            tracep->chgIData(oldp+187,(vlTOPp->top__DOT__array_muxed1),32);
            tracep->chgIData(oldp+188,(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_dat_r),32);
            tracep->chgCData(oldp+189,(vlTOPp->top__DOT__array_muxed2),4);
            tracep->chgBit(oldp+190,(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc));
            tracep->chgBit(oldp+191,(vlTOPp->top__DOT__array_muxed4));
            tracep->chgBit(oldp+192,(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_ack));
            tracep->chgBit(oldp+193,(vlTOPp->top__DOT__array_muxed5));
            tracep->chgBit(oldp+194,(vlTOPp->top__DOT__mgmtsoc_litespimmap_cs));
            tracep->chgBit(oldp+195,(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs));
            tracep->chgIData(oldp+196,(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr),30);
            tracep->chgBit(oldp+197,(vlTOPp->top__DOT__mgmtsoc_litespimmap_wait));
            tracep->chgBit(oldp+198,((0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count))));
            tracep->chgSData(oldp+199,(vlTOPp->top__DOT__mgmtsoc_litespimmap_count),9);
            tracep->chgCData(oldp+200,(vlTOPp->top__DOT__mgmtsoc_litespimmap_storage),8);
            tracep->chgBit(oldp+201,(vlTOPp->top__DOT__mgmtsoc_litespimmap_re));
            tracep->chgBit(oldp+202,(vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_valid));
            tracep->chgBit(oldp+203,((1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid)) 
                                            | (IData)(vlTOPp->top__DOT__mgmtsoc_master_rxtx_we)))));
            tracep->chgBit(oldp+204,(vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_first));
            tracep->chgBit(oldp+205,(vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_last));
            tracep->chgIData(oldp+206,(vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_payload_data),32);
            tracep->chgBit(oldp+207,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid));
            tracep->chgBit(oldp+208,(vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready));
            tracep->chgBit(oldp+209,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_first));
            tracep->chgBit(oldp+210,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_last));
            tracep->chgIData(oldp+211,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_data),32);
            tracep->chgCData(oldp+212,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_len),6);
            tracep->chgCData(oldp+213,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_width),4);
            tracep->chgCData(oldp+214,(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_mask),8);
            tracep->chgBit(oldp+215,(vlTOPp->top__DOT__mgmtsoc_master_cs_storage));
            tracep->chgBit(oldp+216,(vlTOPp->top__DOT__mgmtsoc_master_cs_re));
            tracep->chgCData(oldp+217,((0xffU & vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage)),8);
            tracep->chgCData(oldp+218,((0xfU & (vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage 
                                                >> 8U))),4);
            tracep->chgCData(oldp+219,((0xffU & (vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage 
                                                 >> 0x10U))),8);
            tracep->chgIData(oldp+220,(vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage),24);
            tracep->chgBit(oldp+221,(vlTOPp->top__DOT__mgmtsoc_master_phyconfig_re));
            tracep->chgBit(oldp+222,(vlTOPp->top__DOT__mgmtsoc_master_rxtx_re));
            tracep->chgIData(oldp+223,(vlTOPp->top__DOT__mgmtsoc_dat_w),32);
            tracep->chgBit(oldp+224,(vlTOPp->top__DOT__mgmtsoc_master_rxtx_we));
            tracep->chgIData(oldp+225,(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_payload_data),32);
            tracep->chgBit(oldp+226,((1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid)) 
                                            | (IData)(vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready)))));
            tracep->chgBit(oldp+227,(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid));
            tracep->chgCData(oldp+228,(vlTOPp->top__DOT__mgmtsoc_master_status_status),2);
            tracep->chgBit(oldp+229,(vlTOPp->top__DOT__csrbank4_master_status_we));
            tracep->chgBit(oldp+230,(vlTOPp->top__DOT__mgmtsoc_master_status_re));
            tracep->chgCData(oldp+231,((0x3fU & vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage)),6);
            tracep->chgBit(oldp+232,(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_first));
            tracep->chgBit(oldp+233,(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_last));
            tracep->chgBit(oldp+234,(vlTOPp->top__DOT__uart_bridge_tx_sink_valid));
            tracep->chgBit(oldp+235,(vlTOPp->top__DOT__uart_bridge_tx_sink_ready));
            tracep->chgBit(oldp+236,(((3U == (IData)(vlTOPp->top__DOT__uart_bridge_bytes_count)) 
                                      & ((IData)(vlTOPp->top__DOT__uart_bridge_words_count) 
                                         == (0xffU 
                                             & ((IData)(vlTOPp->top__DOT__uart_bridge_length) 
                                                - (IData)(1U)))))));
            tracep->chgCData(oldp+237,(vlTOPp->top__DOT__uart_bridge_tx_sink_payload_data),8);
            tracep->chgCData(oldp+238,(vlTOPp->top__DOT__uart_bridge_tx_data),8);
            tracep->chgCData(oldp+239,(vlTOPp->top__DOT__uart_bridge_tx_count),4);
            tracep->chgBit(oldp+240,(vlTOPp->top__DOT__uart_bridge_tx_enable));
            tracep->chgBit(oldp+241,(vlTOPp->top__DOT__uart_bridge_tx_tick));
            tracep->chgIData(oldp+242,(vlTOPp->top__DOT__uart_bridge_tx_phase),32);
            tracep->chgBit(oldp+243,(vlTOPp->top__DOT__uart_bridge_rx_source_valid));
            tracep->chgBit(oldp+244,(vlTOPp->top__DOT__uart_bridge_rx_source_ready));
            tracep->chgCData(oldp+245,(vlTOPp->top__DOT__uart_bridge_rx_source_payload_data),8);
            tracep->chgCData(oldp+246,(vlTOPp->top__DOT__uart_bridge_rx_data),8);
            tracep->chgCData(oldp+247,(vlTOPp->top__DOT__uart_bridge_rx_count),4);
            tracep->chgBit(oldp+248,(vlTOPp->top__DOT__uart_bridge_rx_enable));
            tracep->chgBit(oldp+249,(vlTOPp->top__DOT__uart_bridge_rx_tick));
            tracep->chgIData(oldp+250,(vlTOPp->top__DOT__uart_bridge_rx_phase),32);
            tracep->chgBit(oldp+251,(vlTOPp->top__DOT__multiregimpl1_regs1));
            tracep->chgBit(oldp+252,(vlTOPp->top__DOT__uart_bridge_rx_rx_d));
            tracep->chgIData(oldp+253,((0x3fffffffU 
                                        & vlTOPp->top__DOT__uart_bridge_address)),30);
            tracep->chgIData(oldp+254,(vlTOPp->top__DOT__uart_bridge_data),32);
            tracep->chgBit(oldp+255,(vlTOPp->top__DOT__uart_bridge_wishbone_cyc));
            tracep->chgBit(oldp+256,(vlTOPp->top__DOT__uart_bridge_wishbone_stb));
            tracep->chgBit(oldp+257,(vlTOPp->top__DOT__uart_bridge_wishbone_ack));
            tracep->chgBit(oldp+258,(vlTOPp->top__DOT__uart_bridge_wishbone_we));
            tracep->chgCData(oldp+259,(vlTOPp->top__DOT__uart_bridge_cmd),8);
            tracep->chgBit(oldp+260,(vlTOPp->top__DOT__uart_bridge_incr));
            tracep->chgCData(oldp+261,(vlTOPp->top__DOT__uart_bridge_length),8);
            tracep->chgIData(oldp+262,(vlTOPp->top__DOT__uart_bridge_address),32);
            tracep->chgCData(oldp+263,(vlTOPp->top__DOT__uart_bridge_bytes_count),2);
            tracep->chgCData(oldp+264,(vlTOPp->top__DOT__uart_bridge_words_count),8);
            tracep->chgBit(oldp+265,((0U == vlTOPp->top__DOT__uart_bridge_count)));
            tracep->chgBit(oldp+266,((1U & (~ (IData)(vlTOPp->top__DOT__uart_bridge_is_ongoing)))));
            tracep->chgIData(oldp+267,(vlTOPp->top__DOT__uart_bridge_count),20);
            tracep->chgBit(oldp+268,(vlTOPp->top__DOT__uart_bridge_is_ongoing));
            tracep->chgBit(oldp+269,(vlTOPp->top__DOT__gpio_mode1_storage));
            tracep->chgBit(oldp+270,(vlTOPp->top__DOT__gpio_mode1_re));
            tracep->chgBit(oldp+271,(vlTOPp->top__DOT__gpio_mode0_storage));
            tracep->chgBit(oldp+272,(vlTOPp->top__DOT__gpio_mode0_re));
            tracep->chgBit(oldp+273,(vlTOPp->top__DOT__gpio_ien_storage));
            tracep->chgBit(oldp+274,(vlTOPp->top__DOT__gpio_ien_re));
            tracep->chgBit(oldp+275,(vlTOPp->top__DOT__gpio_oe_storage));
            tracep->chgBit(oldp+276,(vlTOPp->top__DOT__gpio_oe_re));
            tracep->chgBit(oldp+277,(vlTOPp->top__DOT__multiregimpl2_regs1));
            tracep->chgBit(oldp+278,(vlTOPp->top__DOT__csrbank1_in_we));
            tracep->chgBit(oldp+279,(vlTOPp->top__DOT__gpio_in_re));
            tracep->chgBit(oldp+280,(vlTOPp->top__DOT__gpio_out_storage));
            tracep->chgBit(oldp+281,(vlTOPp->top__DOT__gpio_out_re));
            tracep->chgWData(oldp+282,(vlTOPp->top__DOT__la_ien_storage),128);
            tracep->chgBit(oldp+286,(vlTOPp->top__DOT__la_ien_re));
            tracep->chgWData(oldp+287,(vlTOPp->top__DOT__la_oe_storage),128);
            tracep->chgBit(oldp+291,(vlTOPp->top__DOT__la_oe_re));
            tracep->chgWData(oldp+292,(vlTOPp->top__DOT__la_in_status),128);
            tracep->chgBit(oldp+296,(vlTOPp->top__DOT__csrbank2_in0_we));
            tracep->chgBit(oldp+297,(vlTOPp->top__DOT__la_in_re));
            tracep->chgWData(oldp+298,(vlTOPp->top__DOT__la_out_storage),128);
            tracep->chgBit(oldp+302,(vlTOPp->top__DOT__la_out_re));
            tracep->chgBit(oldp+303,(vlTOPp->top__DOT__mprj_wb_iena_storage));
            tracep->chgBit(oldp+304,(vlTOPp->top__DOT__mprj_wb_iena_re));
            tracep->chgCData(oldp+305,(vlTOPp->top__DOT__user_irq_ena_storage),3);
            tracep->chgBit(oldp+306,(vlTOPp->top__DOT__user_irq_ena_re));
            tracep->chgBit(oldp+307,(vlTOPp->top__DOT__rs232phy_rs232phytx_state));
            tracep->chgBit(oldp+308,(vlTOPp->top__DOT__rs232phy_rs232phytx_next_state));
            tracep->chgCData(oldp+309,(vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0),4);
            tracep->chgBit(oldp+310,(vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0));
            tracep->chgBit(oldp+311,(vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1));
            tracep->chgBit(oldp+312,(vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1));
            tracep->chgCData(oldp+313,(vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2),8);
            tracep->chgBit(oldp+314,(vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2));
            tracep->chgBit(oldp+315,(vlTOPp->top__DOT__rs232phy_rs232phyrx_state));
            tracep->chgBit(oldp+316,(vlTOPp->top__DOT__rs232phy_rs232phyrx_next_state));
            tracep->chgCData(oldp+317,(vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0),4);
            tracep->chgBit(oldp+318,(vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0));
            tracep->chgCData(oldp+319,(vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value1),8);
            tracep->chgBit(oldp+320,(vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value_ce1));
            tracep->chgCData(oldp+321,(vlTOPp->top__DOT__litespiphy_state),2);
            tracep->chgCData(oldp+322,(vlTOPp->top__DOT__litespiphy_next_state),2);
            tracep->chgCData(oldp+323,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value),8);
            tracep->chgBit(oldp+324,(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce));
            tracep->chgCData(oldp+325,(vlTOPp->top__DOT__litespi_request),2);
            tracep->chgBit(oldp+326,(vlTOPp->top__DOT__litespi_grant));
            tracep->chgCData(oldp+327,(vlTOPp->top__DOT__litespi_state),4);
            tracep->chgCData(oldp+328,(vlTOPp->top__DOT__litespi_next_state),4);
            tracep->chgBit(oldp+329,(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0));
            tracep->chgBit(oldp+330,(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0));
            tracep->chgIData(oldp+331,(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1),30);
            tracep->chgBit(oldp+332,(vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1));
            tracep->chgBit(oldp+333,(vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state));
            tracep->chgBit(oldp+334,(vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_next_state));
            tracep->chgCData(oldp+335,(vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0),4);
            tracep->chgBit(oldp+336,(vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0));
            tracep->chgBit(oldp+337,(vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1));
            tracep->chgBit(oldp+338,(vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1));
            tracep->chgCData(oldp+339,(vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2),8);
            tracep->chgBit(oldp+340,(vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2));
            tracep->chgBit(oldp+341,(vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state));
            tracep->chgBit(oldp+342,(vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_next_state));
            tracep->chgCData(oldp+343,(vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0),4);
            tracep->chgBit(oldp+344,(vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0));
            tracep->chgCData(oldp+345,(vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value1),8);
            tracep->chgBit(oldp+346,(vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value_ce1));
            tracep->chgCData(oldp+347,(vlTOPp->top__DOT__uartwishbonebridge_state),3);
            tracep->chgCData(oldp+348,(vlTOPp->top__DOT__uartwishbonebridge_next_state),3);
            tracep->chgCData(oldp+349,(vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0),2);
            tracep->chgBit(oldp+350,(vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0));
            tracep->chgCData(oldp+351,(vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1),8);
            tracep->chgBit(oldp+352,(vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1));
            tracep->chgCData(oldp+353,(vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2),8);
            tracep->chgBit(oldp+354,(vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2));
            tracep->chgCData(oldp+355,(vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value3),8);
            tracep->chgBit(oldp+356,(vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value_ce3));
            tracep->chgIData(oldp+357,(vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4),32);
            tracep->chgBit(oldp+358,(vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4));
            tracep->chgBit(oldp+359,(vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5));
            tracep->chgBit(oldp+360,(vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5));
            tracep->chgIData(oldp+361,(vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value6),32);
            tracep->chgBit(oldp+362,(vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6));
            tracep->chgSData(oldp+363,(vlTOPp->top__DOT__mgmtsoc_adr),14);
            tracep->chgBit(oldp+364,(vlTOPp->top__DOT__mgmtsoc_we));
            tracep->chgIData(oldp+365,(((((((((vlTOPp->top__DOT__interface0_bank_bus_dat_r 
                                               | vlTOPp->top__DOT__interface1_bank_bus_dat_r) 
                                              | vlTOPp->top__DOT__interface2_bank_bus_dat_r) 
                                             | vlTOPp->top__DOT__interface3_bank_bus_dat_r) 
                                            | vlTOPp->top__DOT__interface4_bank_bus_dat_r) 
                                           | vlTOPp->top__DOT__interface5_bank_bus_dat_r) 
                                          | vlTOPp->top__DOT__interface6_bank_bus_dat_r) 
                                         | vlTOPp->top__DOT__interface7_bank_bus_dat_r) 
                                        | vlTOPp->top__DOT__interface8_bank_bus_dat_r)),32);
            tracep->chgIData(oldp+366,(vlTOPp->top__DOT__mgmtsoc_wishbone_dat_r),32);
            tracep->chgBit(oldp+367,(vlTOPp->top__DOT__mgmtsoc_wishbone_cyc));
            tracep->chgBit(oldp+368,(vlTOPp->top__DOT__mgmtsoc_wishbone_ack));
            tracep->chgBit(oldp+369,(vlTOPp->top__DOT__array_muxed3));
            tracep->chgBit(oldp+370,(vlTOPp->top__DOT__shared_ack));
            tracep->chgCData(oldp+371,(vlTOPp->top__DOT__request),2);
            tracep->chgBit(oldp+372,(vlTOPp->top__DOT__grant));
            tracep->chgCData(oldp+373,(vlTOPp->top__DOT__slave_sel),2);
            tracep->chgCData(oldp+374,(vlTOPp->top__DOT__slave_sel_r),2);
            tracep->chgBit(oldp+375,((((IData)(vlTOPp->top__DOT__array_muxed4) 
                                       & (IData)(vlTOPp->top__DOT__array_muxed3)) 
                                      & (~ (IData)(vlTOPp->top__DOT__shared_ack)))));
            tracep->chgBit(oldp+376,((0U == vlTOPp->top__DOT__count)));
            tracep->chgIData(oldp+377,(vlTOPp->top__DOT__count),20);
            tracep->chgIData(oldp+378,(vlTOPp->top__DOT__interface0_bank_bus_dat_r),32);
            tracep->chgBit(oldp+379,(vlTOPp->top__DOT__csrbank0_reset0_re));
            tracep->chgCData(oldp+380,((3U & vlTOPp->top__DOT__mgmtsoc_dat_w)),2);
            tracep->chgBit(oldp+381,(vlTOPp->top__DOT__csrbank0_reset0_we));
            tracep->chgBit(oldp+382,(vlTOPp->top__DOT__csrbank0_scratch0_re));
            tracep->chgBit(oldp+383,(vlTOPp->top__DOT__csrbank0_scratch0_we));
            tracep->chgBit(oldp+384,(vlTOPp->top__DOT__csrbank0_bus_errors_re));
            tracep->chgBit(oldp+385,((0U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+386,(vlTOPp->top__DOT__interface1_bank_bus_dat_r),32);
            tracep->chgBit(oldp+387,(vlTOPp->top__DOT__csrbank1_mode10_re));
            tracep->chgBit(oldp+388,((1U & vlTOPp->top__DOT__mgmtsoc_dat_w)));
            tracep->chgBit(oldp+389,(vlTOPp->top__DOT__csrbank1_mode10_we));
            tracep->chgBit(oldp+390,(vlTOPp->top__DOT__csrbank1_mode00_re));
            tracep->chgBit(oldp+391,(vlTOPp->top__DOT__csrbank1_mode00_we));
            tracep->chgBit(oldp+392,(vlTOPp->top__DOT__csrbank1_ien0_re));
            tracep->chgBit(oldp+393,(vlTOPp->top__DOT__csrbank1_ien0_we));
            tracep->chgBit(oldp+394,(vlTOPp->top__DOT__csrbank1_oe0_re));
            tracep->chgBit(oldp+395,(vlTOPp->top__DOT__csrbank1_oe0_we));
            tracep->chgBit(oldp+396,(vlTOPp->top__DOT__csrbank1_in_re));
            tracep->chgBit(oldp+397,(vlTOPp->top__DOT__csrbank1_out0_re));
            tracep->chgBit(oldp+398,(vlTOPp->top__DOT__csrbank1_out0_we));
            tracep->chgBit(oldp+399,((1U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+400,(vlTOPp->top__DOT__interface2_bank_bus_dat_r),32);
            tracep->chgBit(oldp+401,(vlTOPp->top__DOT__csrbank2_ien3_re));
            tracep->chgBit(oldp+402,(vlTOPp->top__DOT__csrbank2_ien3_we));
            tracep->chgIData(oldp+403,(vlTOPp->top__DOT__la_ien_storage[3U]),32);
            tracep->chgBit(oldp+404,(vlTOPp->top__DOT__csrbank2_ien2_re));
            tracep->chgBit(oldp+405,(vlTOPp->top__DOT__csrbank2_ien2_we));
            tracep->chgIData(oldp+406,(vlTOPp->top__DOT__la_ien_storage[2U]),32);
            tracep->chgBit(oldp+407,(vlTOPp->top__DOT__csrbank2_ien1_re));
            tracep->chgBit(oldp+408,(vlTOPp->top__DOT__csrbank2_ien1_we));
            tracep->chgIData(oldp+409,(vlTOPp->top__DOT__la_ien_storage[1U]),32);
            tracep->chgBit(oldp+410,(vlTOPp->top__DOT__csrbank2_ien0_re));
            tracep->chgBit(oldp+411,(vlTOPp->top__DOT__csrbank2_ien0_we));
            tracep->chgIData(oldp+412,(vlTOPp->top__DOT__la_ien_storage[0U]),32);
            tracep->chgBit(oldp+413,(vlTOPp->top__DOT__csrbank2_oe3_re));
            tracep->chgBit(oldp+414,(vlTOPp->top__DOT__csrbank2_oe3_we));
            tracep->chgIData(oldp+415,(vlTOPp->top__DOT__la_oe_storage[3U]),32);
            tracep->chgBit(oldp+416,(vlTOPp->top__DOT__csrbank2_oe2_re));
            tracep->chgBit(oldp+417,(vlTOPp->top__DOT__csrbank2_oe2_we));
            tracep->chgIData(oldp+418,(vlTOPp->top__DOT__la_oe_storage[2U]),32);
            tracep->chgBit(oldp+419,(vlTOPp->top__DOT__csrbank2_oe1_re));
            tracep->chgBit(oldp+420,(vlTOPp->top__DOT__csrbank2_oe1_we));
            tracep->chgIData(oldp+421,(vlTOPp->top__DOT__la_oe_storage[1U]),32);
            tracep->chgBit(oldp+422,(vlTOPp->top__DOT__csrbank2_oe0_re));
            tracep->chgBit(oldp+423,(vlTOPp->top__DOT__csrbank2_oe0_we));
            tracep->chgIData(oldp+424,(vlTOPp->top__DOT__la_oe_storage[0U]),32);
            tracep->chgBit(oldp+425,(vlTOPp->top__DOT__csrbank2_in3_re));
            tracep->chgBit(oldp+426,(vlTOPp->top__DOT__csrbank2_in3_we));
            tracep->chgIData(oldp+427,(vlTOPp->top__DOT__la_in_status[3U]),32);
            tracep->chgBit(oldp+428,(vlTOPp->top__DOT__csrbank2_in2_re));
            tracep->chgBit(oldp+429,(vlTOPp->top__DOT__csrbank2_in2_we));
            tracep->chgIData(oldp+430,(vlTOPp->top__DOT__la_in_status[2U]),32);
            tracep->chgBit(oldp+431,(vlTOPp->top__DOT__csrbank2_in1_re));
            tracep->chgBit(oldp+432,(vlTOPp->top__DOT__csrbank2_in1_we));
            tracep->chgIData(oldp+433,(vlTOPp->top__DOT__la_in_status[1U]),32);
            tracep->chgBit(oldp+434,(vlTOPp->top__DOT__csrbank2_in0_re));
            tracep->chgIData(oldp+435,(vlTOPp->top__DOT__la_in_status[0U]),32);
            tracep->chgBit(oldp+436,(vlTOPp->top__DOT__csrbank2_out3_re));
            tracep->chgBit(oldp+437,(vlTOPp->top__DOT__csrbank2_out3_we));
            tracep->chgIData(oldp+438,(vlTOPp->top__DOT__la_out_storage[3U]),32);
            tracep->chgBit(oldp+439,(vlTOPp->top__DOT__csrbank2_out2_re));
            tracep->chgBit(oldp+440,(vlTOPp->top__DOT__csrbank2_out2_we));
            tracep->chgIData(oldp+441,(vlTOPp->top__DOT__la_out_storage[2U]),32);
            tracep->chgBit(oldp+442,(vlTOPp->top__DOT__csrbank2_out1_re));
            tracep->chgBit(oldp+443,(vlTOPp->top__DOT__csrbank2_out1_we));
            tracep->chgIData(oldp+444,(vlTOPp->top__DOT__la_out_storage[1U]),32);
            tracep->chgBit(oldp+445,(vlTOPp->top__DOT__csrbank2_out0_re));
            tracep->chgBit(oldp+446,(vlTOPp->top__DOT__csrbank2_out0_we));
            tracep->chgIData(oldp+447,(vlTOPp->top__DOT__la_out_storage[0U]),32);
            tracep->chgBit(oldp+448,((2U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+449,(vlTOPp->top__DOT__interface3_bank_bus_dat_r),32);
            tracep->chgBit(oldp+450,(vlTOPp->top__DOT__csrbank3_out0_re));
            tracep->chgBit(oldp+451,(vlTOPp->top__DOT__csrbank3_out0_we));
            tracep->chgBit(oldp+452,((3U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+453,(vlTOPp->top__DOT__interface4_bank_bus_dat_r),32);
            tracep->chgBit(oldp+454,(vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_re));
            tracep->chgBit(oldp+455,(vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_we));
            tracep->chgBit(oldp+456,(vlTOPp->top__DOT__csrbank4_master_cs0_re));
            tracep->chgBit(oldp+457,(vlTOPp->top__DOT__csrbank4_master_cs0_we));
            tracep->chgBit(oldp+458,(vlTOPp->top__DOT__csrbank4_master_phyconfig0_re));
            tracep->chgIData(oldp+459,((0xffffffU & vlTOPp->top__DOT__mgmtsoc_dat_w)),24);
            tracep->chgBit(oldp+460,(vlTOPp->top__DOT__csrbank4_master_phyconfig0_we));
            tracep->chgBit(oldp+461,(vlTOPp->top__DOT__csrbank4_master_status_re));
            tracep->chgBit(oldp+462,((4U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+463,(vlTOPp->top__DOT__interface5_bank_bus_dat_r),32);
            tracep->chgBit(oldp+464,(vlTOPp->top__DOT__csrbank5_clk_divisor0_re));
            tracep->chgBit(oldp+465,(vlTOPp->top__DOT__csrbank5_clk_divisor0_we));
            tracep->chgBit(oldp+466,((5U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+467,(vlTOPp->top__DOT__interface6_bank_bus_dat_r),32);
            tracep->chgBit(oldp+468,(vlTOPp->top__DOT__csrbank6_load0_re));
            tracep->chgBit(oldp+469,(vlTOPp->top__DOT__csrbank6_load0_we));
            tracep->chgBit(oldp+470,(vlTOPp->top__DOT__csrbank6_reload0_re));
            tracep->chgBit(oldp+471,(vlTOPp->top__DOT__csrbank6_reload0_we));
            tracep->chgBit(oldp+472,(vlTOPp->top__DOT__csrbank6_en0_re));
            tracep->chgBit(oldp+473,(vlTOPp->top__DOT__csrbank6_en0_we));
            tracep->chgBit(oldp+474,(vlTOPp->top__DOT__csrbank6_update_value0_re));
            tracep->chgBit(oldp+475,(vlTOPp->top__DOT__csrbank6_update_value0_we));
            tracep->chgBit(oldp+476,(vlTOPp->top__DOT__csrbank6_value_re));
            tracep->chgBit(oldp+477,(vlTOPp->top__DOT__csrbank6_ev_status_re));
            tracep->chgBit(oldp+478,(vlTOPp->top__DOT__csrbank6_ev_pending_re));
            tracep->chgBit(oldp+479,(vlTOPp->top__DOT__csrbank6_ev_enable0_re));
            tracep->chgBit(oldp+480,(vlTOPp->top__DOT__csrbank6_ev_enable0_we));
            tracep->chgBit(oldp+481,((6U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+482,(vlTOPp->top__DOT__interface7_bank_bus_dat_r),32);
            tracep->chgBit(oldp+483,(vlTOPp->top__DOT__csrbank7_txfull_re));
            tracep->chgBit(oldp+484,(vlTOPp->top__DOT__csrbank7_rxempty_re));
            tracep->chgBit(oldp+485,(vlTOPp->top__DOT__csrbank7_ev_status_re));
            tracep->chgBit(oldp+486,(vlTOPp->top__DOT__csrbank7_ev_pending_re));
            tracep->chgBit(oldp+487,(vlTOPp->top__DOT__csrbank7_ev_enable0_re));
            tracep->chgBit(oldp+488,(vlTOPp->top__DOT__csrbank7_ev_enable0_we));
            tracep->chgBit(oldp+489,(vlTOPp->top__DOT__csrbank7_txempty_re));
            tracep->chgBit(oldp+490,(vlTOPp->top__DOT__csrbank7_rxfull_re));
            tracep->chgBit(oldp+491,((7U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgIData(oldp+492,(vlTOPp->top__DOT__interface8_bank_bus_dat_r),32);
            tracep->chgBit(oldp+493,(vlTOPp->top__DOT__csrbank8_out0_re));
            tracep->chgCData(oldp+494,((7U & vlTOPp->top__DOT__mgmtsoc_dat_w)),3);
            tracep->chgBit(oldp+495,(vlTOPp->top__DOT__csrbank8_out0_we));
            tracep->chgBit(oldp+496,((8U == (0x1fU 
                                             & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                                                >> 9U)))));
            tracep->chgBit(oldp+497,(vlTOPp->top__DOT__state));
            tracep->chgBit(oldp+498,(vlTOPp->top__DOT__next_state));
            tracep->chgBit(oldp+499,(vlTOPp->top__DOT__multiregimpl0_regs0));
            tracep->chgBit(oldp+500,(vlTOPp->top__DOT__multiregimpl1_regs0));
            tracep->chgBit(oldp+501,(vlTOPp->top__DOT__multiregimpl2_regs0));
            tracep->chgBit(oldp+502,(vlTOPp->top__DOT__multiregimpl3_regs0));
            tracep->chgBit(oldp+503,(vlTOPp->top__DOT__multiregimpl3_regs1));
            tracep->chgBit(oldp+504,(vlTOPp->top__DOT__multiregimpl4_regs0));
            tracep->chgBit(oldp+505,(vlTOPp->top__DOT__multiregimpl4_regs1));
            tracep->chgBit(oldp+506,(vlTOPp->top__DOT__multiregimpl5_regs0));
            tracep->chgBit(oldp+507,(vlTOPp->top__DOT__multiregimpl5_regs1));
            tracep->chgBit(oldp+508,(vlTOPp->top__DOT__multiregimpl6_regs0));
            tracep->chgBit(oldp+509,(vlTOPp->top__DOT__multiregimpl6_regs1));
            tracep->chgBit(oldp+510,(vlTOPp->top__DOT__multiregimpl7_regs0));
            tracep->chgBit(oldp+511,(vlTOPp->top__DOT__multiregimpl7_regs1));
            tracep->chgBit(oldp+512,(vlTOPp->top__DOT__multiregimpl8_regs0));
            tracep->chgBit(oldp+513,(vlTOPp->top__DOT__multiregimpl8_regs1));
            tracep->chgBit(oldp+514,(vlTOPp->top__DOT__multiregimpl9_regs0));
            tracep->chgBit(oldp+515,(vlTOPp->top__DOT__multiregimpl9_regs1));
            tracep->chgBit(oldp+516,(vlTOPp->top__DOT__multiregimpl10_regs0));
            tracep->chgBit(oldp+517,(vlTOPp->top__DOT__multiregimpl10_regs1));
            tracep->chgBit(oldp+518,(vlTOPp->top__DOT__multiregimpl11_regs0));
            tracep->chgBit(oldp+519,(vlTOPp->top__DOT__multiregimpl11_regs1));
            tracep->chgBit(oldp+520,(vlTOPp->top__DOT__multiregimpl12_regs0));
            tracep->chgBit(oldp+521,(vlTOPp->top__DOT__multiregimpl12_regs1));
            tracep->chgBit(oldp+522,(vlTOPp->top__DOT__multiregimpl13_regs0));
            tracep->chgBit(oldp+523,(vlTOPp->top__DOT__multiregimpl13_regs1));
            tracep->chgBit(oldp+524,(vlTOPp->top__DOT__multiregimpl14_regs0));
            tracep->chgBit(oldp+525,(vlTOPp->top__DOT__multiregimpl14_regs1));
            tracep->chgBit(oldp+526,(vlTOPp->top__DOT__multiregimpl15_regs0));
            tracep->chgBit(oldp+527,(vlTOPp->top__DOT__multiregimpl15_regs1));
            tracep->chgBit(oldp+528,(vlTOPp->top__DOT__multiregimpl16_regs0));
            tracep->chgBit(oldp+529,(vlTOPp->top__DOT__multiregimpl16_regs1));
            tracep->chgBit(oldp+530,(vlTOPp->top__DOT__multiregimpl17_regs0));
            tracep->chgBit(oldp+531,(vlTOPp->top__DOT__multiregimpl17_regs1));
            tracep->chgBit(oldp+532,(vlTOPp->top__DOT__multiregimpl18_regs0));
            tracep->chgBit(oldp+533,(vlTOPp->top__DOT__multiregimpl18_regs1));
            tracep->chgBit(oldp+534,(vlTOPp->top__DOT__multiregimpl19_regs0));
            tracep->chgBit(oldp+535,(vlTOPp->top__DOT__multiregimpl19_regs1));
            tracep->chgBit(oldp+536,(vlTOPp->top__DOT__multiregimpl20_regs0));
            tracep->chgBit(oldp+537,(vlTOPp->top__DOT__multiregimpl20_regs1));
            tracep->chgBit(oldp+538,(vlTOPp->top__DOT__multiregimpl21_regs0));
            tracep->chgBit(oldp+539,(vlTOPp->top__DOT__multiregimpl21_regs1));
            tracep->chgBit(oldp+540,(vlTOPp->top__DOT__multiregimpl22_regs0));
            tracep->chgBit(oldp+541,(vlTOPp->top__DOT__multiregimpl22_regs1));
            tracep->chgBit(oldp+542,(vlTOPp->top__DOT__multiregimpl23_regs0));
            tracep->chgBit(oldp+543,(vlTOPp->top__DOT__multiregimpl23_regs1));
            tracep->chgBit(oldp+544,(vlTOPp->top__DOT__multiregimpl24_regs0));
            tracep->chgBit(oldp+545,(vlTOPp->top__DOT__multiregimpl24_regs1));
            tracep->chgBit(oldp+546,(vlTOPp->top__DOT__multiregimpl25_regs0));
            tracep->chgBit(oldp+547,(vlTOPp->top__DOT__multiregimpl25_regs1));
            tracep->chgBit(oldp+548,(vlTOPp->top__DOT__multiregimpl26_regs0));
            tracep->chgBit(oldp+549,(vlTOPp->top__DOT__multiregimpl26_regs1));
            tracep->chgBit(oldp+550,(vlTOPp->top__DOT__multiregimpl27_regs0));
            tracep->chgBit(oldp+551,(vlTOPp->top__DOT__multiregimpl27_regs1));
            tracep->chgBit(oldp+552,(vlTOPp->top__DOT__multiregimpl28_regs0));
            tracep->chgBit(oldp+553,(vlTOPp->top__DOT__multiregimpl28_regs1));
            tracep->chgBit(oldp+554,(vlTOPp->top__DOT__multiregimpl29_regs0));
            tracep->chgBit(oldp+555,(vlTOPp->top__DOT__multiregimpl29_regs1));
            tracep->chgBit(oldp+556,(vlTOPp->top__DOT__multiregimpl30_regs0));
            tracep->chgBit(oldp+557,(vlTOPp->top__DOT__multiregimpl30_regs1));
            tracep->chgBit(oldp+558,(vlTOPp->top__DOT__multiregimpl31_regs0));
            tracep->chgBit(oldp+559,(vlTOPp->top__DOT__multiregimpl31_regs1));
            tracep->chgBit(oldp+560,(vlTOPp->top__DOT__multiregimpl32_regs0));
            tracep->chgBit(oldp+561,(vlTOPp->top__DOT__multiregimpl32_regs1));
            tracep->chgBit(oldp+562,(vlTOPp->top__DOT__multiregimpl33_regs0));
            tracep->chgBit(oldp+563,(vlTOPp->top__DOT__multiregimpl33_regs1));
            tracep->chgBit(oldp+564,(vlTOPp->top__DOT__multiregimpl34_regs0));
            tracep->chgBit(oldp+565,(vlTOPp->top__DOT__multiregimpl34_regs1));
            tracep->chgBit(oldp+566,(vlTOPp->top__DOT__multiregimpl35_regs0));
            tracep->chgBit(oldp+567,(vlTOPp->top__DOT__multiregimpl35_regs1));
            tracep->chgBit(oldp+568,(vlTOPp->top__DOT__multiregimpl36_regs0));
            tracep->chgBit(oldp+569,(vlTOPp->top__DOT__multiregimpl36_regs1));
            tracep->chgBit(oldp+570,(vlTOPp->top__DOT__multiregimpl37_regs0));
            tracep->chgBit(oldp+571,(vlTOPp->top__DOT__multiregimpl37_regs1));
            tracep->chgBit(oldp+572,(vlTOPp->top__DOT__multiregimpl38_regs0));
            tracep->chgBit(oldp+573,(vlTOPp->top__DOT__multiregimpl38_regs1));
            tracep->chgBit(oldp+574,(vlTOPp->top__DOT__multiregimpl39_regs0));
            tracep->chgBit(oldp+575,(vlTOPp->top__DOT__multiregimpl39_regs1));
            tracep->chgBit(oldp+576,(vlTOPp->top__DOT__multiregimpl40_regs0));
            tracep->chgBit(oldp+577,(vlTOPp->top__DOT__multiregimpl40_regs1));
            tracep->chgBit(oldp+578,(vlTOPp->top__DOT__multiregimpl41_regs0));
            tracep->chgBit(oldp+579,(vlTOPp->top__DOT__multiregimpl41_regs1));
            tracep->chgBit(oldp+580,(vlTOPp->top__DOT__multiregimpl42_regs0));
            tracep->chgBit(oldp+581,(vlTOPp->top__DOT__multiregimpl42_regs1));
            tracep->chgBit(oldp+582,(vlTOPp->top__DOT__multiregimpl43_regs0));
            tracep->chgBit(oldp+583,(vlTOPp->top__DOT__multiregimpl43_regs1));
            tracep->chgBit(oldp+584,(vlTOPp->top__DOT__multiregimpl44_regs0));
            tracep->chgBit(oldp+585,(vlTOPp->top__DOT__multiregimpl44_regs1));
            tracep->chgBit(oldp+586,(vlTOPp->top__DOT__multiregimpl45_regs0));
            tracep->chgBit(oldp+587,(vlTOPp->top__DOT__multiregimpl45_regs1));
            tracep->chgBit(oldp+588,(vlTOPp->top__DOT__multiregimpl46_regs0));
            tracep->chgBit(oldp+589,(vlTOPp->top__DOT__multiregimpl46_regs1));
            tracep->chgBit(oldp+590,(vlTOPp->top__DOT__multiregimpl47_regs0));
            tracep->chgBit(oldp+591,(vlTOPp->top__DOT__multiregimpl47_regs1));
            tracep->chgBit(oldp+592,(vlTOPp->top__DOT__multiregimpl48_regs0));
            tracep->chgBit(oldp+593,(vlTOPp->top__DOT__multiregimpl48_regs1));
            tracep->chgBit(oldp+594,(vlTOPp->top__DOT__multiregimpl49_regs0));
            tracep->chgBit(oldp+595,(vlTOPp->top__DOT__multiregimpl49_regs1));
            tracep->chgBit(oldp+596,(vlTOPp->top__DOT__multiregimpl50_regs0));
            tracep->chgBit(oldp+597,(vlTOPp->top__DOT__multiregimpl50_regs1));
            tracep->chgBit(oldp+598,(vlTOPp->top__DOT__multiregimpl51_regs0));
            tracep->chgBit(oldp+599,(vlTOPp->top__DOT__multiregimpl51_regs1));
            tracep->chgBit(oldp+600,(vlTOPp->top__DOT__multiregimpl52_regs0));
            tracep->chgBit(oldp+601,(vlTOPp->top__DOT__multiregimpl52_regs1));
            tracep->chgBit(oldp+602,(vlTOPp->top__DOT__multiregimpl53_regs0));
            tracep->chgBit(oldp+603,(vlTOPp->top__DOT__multiregimpl53_regs1));
            tracep->chgBit(oldp+604,(vlTOPp->top__DOT__multiregimpl54_regs0));
            tracep->chgBit(oldp+605,(vlTOPp->top__DOT__multiregimpl54_regs1));
            tracep->chgBit(oldp+606,(vlTOPp->top__DOT__multiregimpl55_regs0));
            tracep->chgBit(oldp+607,(vlTOPp->top__DOT__multiregimpl55_regs1));
            tracep->chgBit(oldp+608,(vlTOPp->top__DOT__multiregimpl56_regs0));
            tracep->chgBit(oldp+609,(vlTOPp->top__DOT__multiregimpl56_regs1));
            tracep->chgBit(oldp+610,(vlTOPp->top__DOT__multiregimpl57_regs0));
            tracep->chgBit(oldp+611,(vlTOPp->top__DOT__multiregimpl57_regs1));
            tracep->chgBit(oldp+612,(vlTOPp->top__DOT__multiregimpl58_regs0));
            tracep->chgBit(oldp+613,(vlTOPp->top__DOT__multiregimpl58_regs1));
            tracep->chgBit(oldp+614,(vlTOPp->top__DOT__multiregimpl59_regs0));
            tracep->chgBit(oldp+615,(vlTOPp->top__DOT__multiregimpl59_regs1));
            tracep->chgBit(oldp+616,(vlTOPp->top__DOT__multiregimpl60_regs0));
            tracep->chgBit(oldp+617,(vlTOPp->top__DOT__multiregimpl60_regs1));
            tracep->chgBit(oldp+618,(vlTOPp->top__DOT__multiregimpl61_regs0));
            tracep->chgBit(oldp+619,(vlTOPp->top__DOT__multiregimpl61_regs1));
            tracep->chgBit(oldp+620,(vlTOPp->top__DOT__multiregimpl62_regs0));
            tracep->chgBit(oldp+621,(vlTOPp->top__DOT__multiregimpl62_regs1));
            tracep->chgBit(oldp+622,(vlTOPp->top__DOT__multiregimpl63_regs0));
            tracep->chgBit(oldp+623,(vlTOPp->top__DOT__multiregimpl63_regs1));
            tracep->chgBit(oldp+624,(vlTOPp->top__DOT__multiregimpl64_regs0));
            tracep->chgBit(oldp+625,(vlTOPp->top__DOT__multiregimpl64_regs1));
            tracep->chgBit(oldp+626,(vlTOPp->top__DOT__multiregimpl65_regs0));
            tracep->chgBit(oldp+627,(vlTOPp->top__DOT__multiregimpl65_regs1));
            tracep->chgBit(oldp+628,(vlTOPp->top__DOT__multiregimpl66_regs0));
            tracep->chgBit(oldp+629,(vlTOPp->top__DOT__multiregimpl66_regs1));
            tracep->chgBit(oldp+630,(vlTOPp->top__DOT__multiregimpl67_regs0));
            tracep->chgBit(oldp+631,(vlTOPp->top__DOT__multiregimpl67_regs1));
            tracep->chgBit(oldp+632,(vlTOPp->top__DOT__multiregimpl68_regs0));
            tracep->chgBit(oldp+633,(vlTOPp->top__DOT__multiregimpl68_regs1));
            tracep->chgBit(oldp+634,(vlTOPp->top__DOT__multiregimpl69_regs0));
            tracep->chgBit(oldp+635,(vlTOPp->top__DOT__multiregimpl69_regs1));
            tracep->chgBit(oldp+636,(vlTOPp->top__DOT__multiregimpl70_regs0));
            tracep->chgBit(oldp+637,(vlTOPp->top__DOT__multiregimpl70_regs1));
            tracep->chgBit(oldp+638,(vlTOPp->top__DOT__multiregimpl71_regs0));
            tracep->chgBit(oldp+639,(vlTOPp->top__DOT__multiregimpl71_regs1));
            tracep->chgBit(oldp+640,(vlTOPp->top__DOT__multiregimpl72_regs0));
            tracep->chgBit(oldp+641,(vlTOPp->top__DOT__multiregimpl72_regs1));
            tracep->chgBit(oldp+642,(vlTOPp->top__DOT__multiregimpl73_regs0));
            tracep->chgBit(oldp+643,(vlTOPp->top__DOT__multiregimpl73_regs1));
            tracep->chgBit(oldp+644,(vlTOPp->top__DOT__multiregimpl74_regs0));
            tracep->chgBit(oldp+645,(vlTOPp->top__DOT__multiregimpl74_regs1));
            tracep->chgBit(oldp+646,(vlTOPp->top__DOT__multiregimpl75_regs0));
            tracep->chgBit(oldp+647,(vlTOPp->top__DOT__multiregimpl75_regs1));
            tracep->chgBit(oldp+648,(vlTOPp->top__DOT__multiregimpl76_regs0));
            tracep->chgBit(oldp+649,(vlTOPp->top__DOT__multiregimpl76_regs1));
            tracep->chgBit(oldp+650,(vlTOPp->top__DOT__multiregimpl77_regs0));
            tracep->chgBit(oldp+651,(vlTOPp->top__DOT__multiregimpl77_regs1));
            tracep->chgBit(oldp+652,(vlTOPp->top__DOT__multiregimpl78_regs0));
            tracep->chgBit(oldp+653,(vlTOPp->top__DOT__multiregimpl78_regs1));
            tracep->chgBit(oldp+654,(vlTOPp->top__DOT__multiregimpl79_regs0));
            tracep->chgBit(oldp+655,(vlTOPp->top__DOT__multiregimpl79_regs1));
            tracep->chgBit(oldp+656,(vlTOPp->top__DOT__multiregimpl80_regs0));
            tracep->chgBit(oldp+657,(vlTOPp->top__DOT__multiregimpl80_regs1));
            tracep->chgBit(oldp+658,(vlTOPp->top__DOT__multiregimpl81_regs0));
            tracep->chgBit(oldp+659,(vlTOPp->top__DOT__multiregimpl81_regs1));
            tracep->chgBit(oldp+660,(vlTOPp->top__DOT__multiregimpl82_regs0));
            tracep->chgBit(oldp+661,(vlTOPp->top__DOT__multiregimpl82_regs1));
            tracep->chgBit(oldp+662,(vlTOPp->top__DOT__multiregimpl83_regs0));
            tracep->chgBit(oldp+663,(vlTOPp->top__DOT__multiregimpl83_regs1));
            tracep->chgBit(oldp+664,(vlTOPp->top__DOT__multiregimpl84_regs0));
            tracep->chgBit(oldp+665,(vlTOPp->top__DOT__multiregimpl84_regs1));
            tracep->chgBit(oldp+666,(vlTOPp->top__DOT__multiregimpl85_regs0));
            tracep->chgBit(oldp+667,(vlTOPp->top__DOT__multiregimpl85_regs1));
            tracep->chgBit(oldp+668,(vlTOPp->top__DOT__multiregimpl86_regs0));
            tracep->chgBit(oldp+669,(vlTOPp->top__DOT__multiregimpl86_regs1));
            tracep->chgBit(oldp+670,(vlTOPp->top__DOT__multiregimpl87_regs0));
            tracep->chgBit(oldp+671,(vlTOPp->top__DOT__multiregimpl87_regs1));
            tracep->chgBit(oldp+672,(vlTOPp->top__DOT__multiregimpl88_regs0));
            tracep->chgBit(oldp+673,(vlTOPp->top__DOT__multiregimpl88_regs1));
            tracep->chgBit(oldp+674,(vlTOPp->top__DOT__multiregimpl89_regs0));
            tracep->chgBit(oldp+675,(vlTOPp->top__DOT__multiregimpl89_regs1));
            tracep->chgBit(oldp+676,(vlTOPp->top__DOT__multiregimpl90_regs0));
            tracep->chgBit(oldp+677,(vlTOPp->top__DOT__multiregimpl90_regs1));
            tracep->chgBit(oldp+678,(vlTOPp->top__DOT__multiregimpl91_regs0));
            tracep->chgBit(oldp+679,(vlTOPp->top__DOT__multiregimpl91_regs1));
            tracep->chgBit(oldp+680,(vlTOPp->top__DOT__multiregimpl92_regs0));
            tracep->chgBit(oldp+681,(vlTOPp->top__DOT__multiregimpl92_regs1));
            tracep->chgBit(oldp+682,(vlTOPp->top__DOT__multiregimpl93_regs0));
            tracep->chgBit(oldp+683,(vlTOPp->top__DOT__multiregimpl93_regs1));
            tracep->chgBit(oldp+684,(vlTOPp->top__DOT__multiregimpl94_regs0));
            tracep->chgBit(oldp+685,(vlTOPp->top__DOT__multiregimpl94_regs1));
            tracep->chgBit(oldp+686,(vlTOPp->top__DOT__multiregimpl95_regs0));
            tracep->chgBit(oldp+687,(vlTOPp->top__DOT__multiregimpl95_regs1));
            tracep->chgBit(oldp+688,(vlTOPp->top__DOT__multiregimpl96_regs0));
            tracep->chgBit(oldp+689,(vlTOPp->top__DOT__multiregimpl96_regs1));
            tracep->chgBit(oldp+690,(vlTOPp->top__DOT__multiregimpl97_regs0));
            tracep->chgBit(oldp+691,(vlTOPp->top__DOT__multiregimpl97_regs1));
            tracep->chgBit(oldp+692,(vlTOPp->top__DOT__multiregimpl98_regs0));
            tracep->chgBit(oldp+693,(vlTOPp->top__DOT__multiregimpl98_regs1));
            tracep->chgBit(oldp+694,(vlTOPp->top__DOT__multiregimpl99_regs0));
            tracep->chgBit(oldp+695,(vlTOPp->top__DOT__multiregimpl99_regs1));
            tracep->chgBit(oldp+696,(vlTOPp->top__DOT__multiregimpl100_regs0));
            tracep->chgBit(oldp+697,(vlTOPp->top__DOT__multiregimpl100_regs1));
            tracep->chgBit(oldp+698,(vlTOPp->top__DOT__multiregimpl101_regs0));
            tracep->chgBit(oldp+699,(vlTOPp->top__DOT__multiregimpl101_regs1));
            tracep->chgBit(oldp+700,(vlTOPp->top__DOT__multiregimpl102_regs0));
            tracep->chgBit(oldp+701,(vlTOPp->top__DOT__multiregimpl102_regs1));
            tracep->chgBit(oldp+702,(vlTOPp->top__DOT__multiregimpl103_regs0));
            tracep->chgBit(oldp+703,(vlTOPp->top__DOT__multiregimpl103_regs1));
            tracep->chgBit(oldp+704,(vlTOPp->top__DOT__multiregimpl104_regs0));
            tracep->chgBit(oldp+705,(vlTOPp->top__DOT__multiregimpl104_regs1));
            tracep->chgBit(oldp+706,(vlTOPp->top__DOT__multiregimpl105_regs0));
            tracep->chgBit(oldp+707,(vlTOPp->top__DOT__multiregimpl105_regs1));
            tracep->chgBit(oldp+708,(vlTOPp->top__DOT__multiregimpl106_regs0));
            tracep->chgBit(oldp+709,(vlTOPp->top__DOT__multiregimpl106_regs1));
            tracep->chgBit(oldp+710,(vlTOPp->top__DOT__multiregimpl107_regs0));
            tracep->chgBit(oldp+711,(vlTOPp->top__DOT__multiregimpl107_regs1));
            tracep->chgBit(oldp+712,(vlTOPp->top__DOT__multiregimpl108_regs0));
            tracep->chgBit(oldp+713,(vlTOPp->top__DOT__multiregimpl108_regs1));
            tracep->chgBit(oldp+714,(vlTOPp->top__DOT__multiregimpl109_regs0));
            tracep->chgBit(oldp+715,(vlTOPp->top__DOT__multiregimpl109_regs1));
            tracep->chgBit(oldp+716,(vlTOPp->top__DOT__multiregimpl110_regs0));
            tracep->chgBit(oldp+717,(vlTOPp->top__DOT__multiregimpl110_regs1));
            tracep->chgBit(oldp+718,(vlTOPp->top__DOT__multiregimpl111_regs0));
            tracep->chgBit(oldp+719,(vlTOPp->top__DOT__multiregimpl111_regs1));
            tracep->chgBit(oldp+720,(vlTOPp->top__DOT__multiregimpl112_regs0));
            tracep->chgBit(oldp+721,(vlTOPp->top__DOT__multiregimpl112_regs1));
            tracep->chgBit(oldp+722,(vlTOPp->top__DOT__multiregimpl113_regs0));
            tracep->chgBit(oldp+723,(vlTOPp->top__DOT__multiregimpl113_regs1));
            tracep->chgBit(oldp+724,(vlTOPp->top__DOT__multiregimpl114_regs0));
            tracep->chgBit(oldp+725,(vlTOPp->top__DOT__multiregimpl114_regs1));
            tracep->chgBit(oldp+726,(vlTOPp->top__DOT__multiregimpl115_regs0));
            tracep->chgBit(oldp+727,(vlTOPp->top__DOT__multiregimpl115_regs1));
            tracep->chgBit(oldp+728,(vlTOPp->top__DOT__multiregimpl116_regs0));
            tracep->chgBit(oldp+729,(vlTOPp->top__DOT__multiregimpl116_regs1));
            tracep->chgBit(oldp+730,(vlTOPp->top__DOT__multiregimpl117_regs0));
            tracep->chgBit(oldp+731,(vlTOPp->top__DOT__multiregimpl117_regs1));
            tracep->chgBit(oldp+732,(vlTOPp->top__DOT__multiregimpl118_regs0));
            tracep->chgBit(oldp+733,(vlTOPp->top__DOT__multiregimpl118_regs1));
            tracep->chgBit(oldp+734,(vlTOPp->top__DOT__multiregimpl119_regs0));
            tracep->chgBit(oldp+735,(vlTOPp->top__DOT__multiregimpl119_regs1));
            tracep->chgBit(oldp+736,(vlTOPp->top__DOT__multiregimpl120_regs0));
            tracep->chgBit(oldp+737,(vlTOPp->top__DOT__multiregimpl120_regs1));
            tracep->chgBit(oldp+738,(vlTOPp->top__DOT__multiregimpl121_regs0));
            tracep->chgBit(oldp+739,(vlTOPp->top__DOT__multiregimpl121_regs1));
            tracep->chgBit(oldp+740,(vlTOPp->top__DOT__multiregimpl122_regs0));
            tracep->chgBit(oldp+741,(vlTOPp->top__DOT__multiregimpl122_regs1));
            tracep->chgBit(oldp+742,(vlTOPp->top__DOT__multiregimpl123_regs0));
            tracep->chgBit(oldp+743,(vlTOPp->top__DOT__multiregimpl123_regs1));
            tracep->chgBit(oldp+744,(vlTOPp->top__DOT__multiregimpl124_regs0));
            tracep->chgBit(oldp+745,(vlTOPp->top__DOT__multiregimpl124_regs1));
            tracep->chgBit(oldp+746,(vlTOPp->top__DOT__multiregimpl125_regs0));
            tracep->chgBit(oldp+747,(vlTOPp->top__DOT__multiregimpl125_regs1));
            tracep->chgBit(oldp+748,(vlTOPp->top__DOT__multiregimpl126_regs0));
            tracep->chgBit(oldp+749,(vlTOPp->top__DOT__multiregimpl126_regs1));
            tracep->chgBit(oldp+750,(vlTOPp->top__DOT__multiregimpl127_regs0));
            tracep->chgBit(oldp+751,(vlTOPp->top__DOT__multiregimpl127_regs1));
            tracep->chgBit(oldp+752,(vlTOPp->top__DOT__multiregimpl128_regs0));
            tracep->chgBit(oldp+753,(vlTOPp->top__DOT__multiregimpl128_regs1));
            tracep->chgBit(oldp+754,(vlTOPp->top__DOT__multiregimpl129_regs0));
            tracep->chgBit(oldp+755,(vlTOPp->top__DOT__multiregimpl129_regs1));
            tracep->chgBit(oldp+756,(vlTOPp->top__DOT__multiregimpl130_regs0));
            tracep->chgBit(oldp+757,(vlTOPp->top__DOT__multiregimpl130_regs1));
            tracep->chgSData(oldp+758,(vlTOPp->top__DOT__storage[0]),10);
            tracep->chgSData(oldp+759,(vlTOPp->top__DOT__storage[1]),10);
            tracep->chgSData(oldp+760,(vlTOPp->top__DOT__storage[2]),10);
            tracep->chgSData(oldp+761,(vlTOPp->top__DOT__storage[3]),10);
            tracep->chgSData(oldp+762,(vlTOPp->top__DOT__storage[4]),10);
            tracep->chgSData(oldp+763,(vlTOPp->top__DOT__storage[5]),10);
            tracep->chgSData(oldp+764,(vlTOPp->top__DOT__storage[6]),10);
            tracep->chgSData(oldp+765,(vlTOPp->top__DOT__storage[7]),10);
            tracep->chgSData(oldp+766,(vlTOPp->top__DOT__storage[8]),10);
            tracep->chgSData(oldp+767,(vlTOPp->top__DOT__storage[9]),10);
            tracep->chgSData(oldp+768,(vlTOPp->top__DOT__storage[10]),10);
            tracep->chgSData(oldp+769,(vlTOPp->top__DOT__storage[11]),10);
            tracep->chgSData(oldp+770,(vlTOPp->top__DOT__storage[12]),10);
            tracep->chgSData(oldp+771,(vlTOPp->top__DOT__storage[13]),10);
            tracep->chgSData(oldp+772,(vlTOPp->top__DOT__storage[14]),10);
            tracep->chgSData(oldp+773,(vlTOPp->top__DOT__storage[15]),10);
            tracep->chgSData(oldp+774,(vlTOPp->top__DOT__storage_1[0]),10);
            tracep->chgSData(oldp+775,(vlTOPp->top__DOT__storage_1[1]),10);
            tracep->chgSData(oldp+776,(vlTOPp->top__DOT__storage_1[2]),10);
            tracep->chgSData(oldp+777,(vlTOPp->top__DOT__storage_1[3]),10);
            tracep->chgSData(oldp+778,(vlTOPp->top__DOT__storage_1[4]),10);
            tracep->chgSData(oldp+779,(vlTOPp->top__DOT__storage_1[5]),10);
            tracep->chgSData(oldp+780,(vlTOPp->top__DOT__storage_1[6]),10);
            tracep->chgSData(oldp+781,(vlTOPp->top__DOT__storage_1[7]),10);
            tracep->chgSData(oldp+782,(vlTOPp->top__DOT__storage_1[8]),10);
            tracep->chgSData(oldp+783,(vlTOPp->top__DOT__storage_1[9]),10);
            tracep->chgSData(oldp+784,(vlTOPp->top__DOT__storage_1[10]),10);
            tracep->chgSData(oldp+785,(vlTOPp->top__DOT__storage_1[11]),10);
            tracep->chgSData(oldp+786,(vlTOPp->top__DOT__storage_1[12]),10);
            tracep->chgSData(oldp+787,(vlTOPp->top__DOT__storage_1[13]),10);
            tracep->chgSData(oldp+788,(vlTOPp->top__DOT__storage_1[14]),10);
            tracep->chgSData(oldp+789,(vlTOPp->top__DOT__storage_1[15]),10);
            tracep->chgBit(oldp+790,(vlTOPp->top__DOT____Vcellinp__picorv32__resetn));
            tracep->chgBit(oldp+791,(vlTOPp->top__DOT__picorv32__DOT__trace_valid));
            tracep->chgQData(oldp+792,(vlTOPp->top__DOT__picorv32__DOT__trace_data),36);
            tracep->chgQData(oldp+794,(vlTOPp->top__DOT__picorv32__DOT__count_cycle),64);
            tracep->chgQData(oldp+796,(vlTOPp->top__DOT__picorv32__DOT__count_instr),64);
            tracep->chgIData(oldp+798,(vlTOPp->top__DOT__picorv32__DOT__reg_pc),32);
            tracep->chgIData(oldp+799,(vlTOPp->top__DOT__picorv32__DOT__reg_next_pc),32);
            tracep->chgIData(oldp+800,(vlTOPp->top__DOT__picorv32__DOT__reg_out),32);
            tracep->chgCData(oldp+801,(vlTOPp->top__DOT__picorv32__DOT__reg_sh),5);
            tracep->chgIData(oldp+802,(vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode),32);
            tracep->chgIData(oldp+803,(vlTOPp->top__DOT__picorv32__DOT__dbg_insn_opcode),32);
            tracep->chgIData(oldp+804,(vlTOPp->top__DOT__picorv32__DOT__dbg_insn_addr),32);
            tracep->chgIData(oldp+805,(vlTOPp->top__DOT__picorv32__DOT__next_pc),32);
            tracep->chgBit(oldp+806,(vlTOPp->top__DOT__picorv32__DOT__irq_delay));
            tracep->chgBit(oldp+807,(vlTOPp->top__DOT__picorv32__DOT__irq_active));
            tracep->chgIData(oldp+808,(vlTOPp->top__DOT__picorv32__DOT__irq_mask),32);
            tracep->chgIData(oldp+809,(vlTOPp->top__DOT__picorv32__DOT__irq_pending),32);
            tracep->chgIData(oldp+810,(vlTOPp->top__DOT__picorv32__DOT__timer),32);
            tracep->chgCData(oldp+811,(vlTOPp->top__DOT__picorv32__DOT__mem_state),2);
            tracep->chgCData(oldp+812,(vlTOPp->top__DOT__picorv32__DOT__mem_wordsize),2);
            tracep->chgIData(oldp+813,(vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word),32);
            tracep->chgIData(oldp+814,(vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q),32);
            tracep->chgBit(oldp+815,(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch));
            tracep->chgBit(oldp+816,(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst));
            tracep->chgBit(oldp+817,(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata));
            tracep->chgBit(oldp+818,(vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata));
            tracep->chgBit(oldp+819,(vlTOPp->top__DOT__picorv32__DOT__mem_xfer));
            tracep->chgBit(oldp+820,(vlTOPp->top__DOT__picorv32__DOT__mem_la_secondword));
            tracep->chgBit(oldp+821,(vlTOPp->top__DOT__picorv32__DOT__mem_la_firstword_reg));
            tracep->chgBit(oldp+822,(vlTOPp->top__DOT__picorv32__DOT__last_mem_valid));
            tracep->chgBit(oldp+823,(vlTOPp->top__DOT__picorv32__DOT__prefetched_high_word));
            tracep->chgBit(oldp+824,(vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word));
            tracep->chgIData(oldp+825,(vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle),32);
            tracep->chgBit(oldp+826,(((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch) 
                                      | ((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
                                         | ((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata) 
                                            | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata))))));
            tracep->chgBit(oldp+827,(vlTOPp->top__DOT__picorv32__DOT__mem_done));
            tracep->chgBit(oldp+828,(vlTOPp->top__DOT__picorv32__DOT__instr_lui));
            tracep->chgBit(oldp+829,(vlTOPp->top__DOT__picorv32__DOT__instr_auipc));
            tracep->chgBit(oldp+830,(vlTOPp->top__DOT__picorv32__DOT__instr_jal));
            tracep->chgBit(oldp+831,(vlTOPp->top__DOT__picorv32__DOT__instr_jalr));
            tracep->chgBit(oldp+832,(vlTOPp->top__DOT__picorv32__DOT__instr_beq));
            tracep->chgBit(oldp+833,(vlTOPp->top__DOT__picorv32__DOT__instr_bne));
            tracep->chgBit(oldp+834,(vlTOPp->top__DOT__picorv32__DOT__instr_blt));
            tracep->chgBit(oldp+835,(vlTOPp->top__DOT__picorv32__DOT__instr_bge));
            tracep->chgBit(oldp+836,(vlTOPp->top__DOT__picorv32__DOT__instr_bltu));
            tracep->chgBit(oldp+837,(vlTOPp->top__DOT__picorv32__DOT__instr_bgeu));
            tracep->chgBit(oldp+838,(vlTOPp->top__DOT__picorv32__DOT__instr_lb));
            tracep->chgBit(oldp+839,(vlTOPp->top__DOT__picorv32__DOT__instr_lh));
            tracep->chgBit(oldp+840,(vlTOPp->top__DOT__picorv32__DOT__instr_lw));
            tracep->chgBit(oldp+841,(vlTOPp->top__DOT__picorv32__DOT__instr_lbu));
            tracep->chgBit(oldp+842,(vlTOPp->top__DOT__picorv32__DOT__instr_lhu));
            tracep->chgBit(oldp+843,(vlTOPp->top__DOT__picorv32__DOT__instr_sb));
            tracep->chgBit(oldp+844,(vlTOPp->top__DOT__picorv32__DOT__instr_sh));
            tracep->chgBit(oldp+845,(vlTOPp->top__DOT__picorv32__DOT__instr_sw));
            tracep->chgBit(oldp+846,(vlTOPp->top__DOT__picorv32__DOT__instr_addi));
            tracep->chgBit(oldp+847,(vlTOPp->top__DOT__picorv32__DOT__instr_slti));
            tracep->chgBit(oldp+848,(vlTOPp->top__DOT__picorv32__DOT__instr_sltiu));
            tracep->chgBit(oldp+849,(vlTOPp->top__DOT__picorv32__DOT__instr_xori));
            tracep->chgBit(oldp+850,(vlTOPp->top__DOT__picorv32__DOT__instr_ori));
            tracep->chgBit(oldp+851,(vlTOPp->top__DOT__picorv32__DOT__instr_andi));
            tracep->chgBit(oldp+852,(vlTOPp->top__DOT__picorv32__DOT__instr_slli));
            tracep->chgBit(oldp+853,(vlTOPp->top__DOT__picorv32__DOT__instr_srli));
            tracep->chgBit(oldp+854,(vlTOPp->top__DOT__picorv32__DOT__instr_srai));
            tracep->chgBit(oldp+855,(vlTOPp->top__DOT__picorv32__DOT__instr_add));
            tracep->chgBit(oldp+856,(vlTOPp->top__DOT__picorv32__DOT__instr_sub));
            tracep->chgBit(oldp+857,(vlTOPp->top__DOT__picorv32__DOT__instr_sll));
            tracep->chgBit(oldp+858,(vlTOPp->top__DOT__picorv32__DOT__instr_slt));
            tracep->chgBit(oldp+859,(vlTOPp->top__DOT__picorv32__DOT__instr_sltu));
            tracep->chgBit(oldp+860,(vlTOPp->top__DOT__picorv32__DOT__instr_xor));
            tracep->chgBit(oldp+861,(vlTOPp->top__DOT__picorv32__DOT__instr_srl));
            tracep->chgBit(oldp+862,(vlTOPp->top__DOT__picorv32__DOT__instr_sra));
            tracep->chgBit(oldp+863,(vlTOPp->top__DOT__picorv32__DOT__instr_or));
            tracep->chgBit(oldp+864,(vlTOPp->top__DOT__picorv32__DOT__instr_and));
            tracep->chgBit(oldp+865,(vlTOPp->top__DOT__picorv32__DOT__instr_rdcycle));
            tracep->chgBit(oldp+866,(vlTOPp->top__DOT__picorv32__DOT__instr_rdcycleh));
            tracep->chgBit(oldp+867,(vlTOPp->top__DOT__picorv32__DOT__instr_rdinstr));
            tracep->chgBit(oldp+868,(vlTOPp->top__DOT__picorv32__DOT__instr_rdinstrh));
            tracep->chgBit(oldp+869,(vlTOPp->top__DOT__picorv32__DOT__instr_ecall_ebreak));
            tracep->chgBit(oldp+870,(vlTOPp->top__DOT__picorv32__DOT__instr_getq));
            tracep->chgBit(oldp+871,(vlTOPp->top__DOT__picorv32__DOT__instr_setq));
            tracep->chgBit(oldp+872,(vlTOPp->top__DOT__picorv32__DOT__instr_retirq));
            tracep->chgBit(oldp+873,(vlTOPp->top__DOT__picorv32__DOT__instr_maskirq));
            tracep->chgBit(oldp+874,(vlTOPp->top__DOT__picorv32__DOT__instr_waitirq));
            tracep->chgBit(oldp+875,(vlTOPp->top__DOT__picorv32__DOT__instr_timer));
            tracep->chgBit(oldp+876,(vlTOPp->top__DOT__picorv32__DOT__instr_trap));
            tracep->chgCData(oldp+877,(vlTOPp->top__DOT__picorv32__DOT__decoded_rd),6);
            tracep->chgCData(oldp+878,(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1),6);
            tracep->chgCData(oldp+879,(vlTOPp->top__DOT__picorv32__DOT__decoded_rs2),6);
            tracep->chgIData(oldp+880,(vlTOPp->top__DOT__picorv32__DOT__decoded_imm),32);
            tracep->chgIData(oldp+881,(vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j),32);
            tracep->chgBit(oldp+882,(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger));
            tracep->chgBit(oldp+883,(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q));
            tracep->chgBit(oldp+884,(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger));
            tracep->chgBit(oldp+885,(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q));
            tracep->chgBit(oldp+886,(vlTOPp->top__DOT__picorv32__DOT__compressed_instr));
            tracep->chgBit(oldp+887,(vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal));
            tracep->chgBit(oldp+888,(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu));
            tracep->chgBit(oldp+889,(vlTOPp->top__DOT__picorv32__DOT__is_slli_srli_srai));
            tracep->chgBit(oldp+890,(vlTOPp->top__DOT__picorv32__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi));
            tracep->chgBit(oldp+891,(vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw));
            tracep->chgBit(oldp+892,(vlTOPp->top__DOT__picorv32__DOT__is_sll_srl_sra));
            tracep->chgBit(oldp+893,(vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal_jalr_addi_add_sub));
            tracep->chgBit(oldp+894,(vlTOPp->top__DOT__picorv32__DOT__is_slti_blt_slt));
            tracep->chgBit(oldp+895,(vlTOPp->top__DOT__picorv32__DOT__is_sltiu_bltu_sltu));
            tracep->chgBit(oldp+896,(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu));
            tracep->chgBit(oldp+897,(vlTOPp->top__DOT__picorv32__DOT__is_lbu_lhu_lw));
            tracep->chgBit(oldp+898,(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm));
            tracep->chgBit(oldp+899,(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg));
            tracep->chgBit(oldp+900,(vlTOPp->top__DOT__picorv32__DOT__is_compare));
            tracep->chgBit(oldp+901,(((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdcycle) 
                                      | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdcycleh) 
                                         | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdinstr) 
                                            | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_rdinstrh))))));
            tracep->chgQData(oldp+902,(vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr),64);
            tracep->chgQData(oldp+904,(vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_instr),64);
            tracep->chgIData(oldp+906,(vlTOPp->top__DOT__picorv32__DOT__dbg_insn_imm),32);
            tracep->chgCData(oldp+907,(vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs1),5);
            tracep->chgCData(oldp+908,(vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs2),5);
            tracep->chgCData(oldp+909,(vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rd),5);
            tracep->chgIData(oldp+910,(vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val),32);
            tracep->chgIData(oldp+911,(vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val),32);
            tracep->chgBit(oldp+912,(vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid));
            tracep->chgBit(oldp+913,(vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val_valid));
            tracep->chgQData(oldp+914,(vlTOPp->top__DOT__picorv32__DOT__q_ascii_instr),64);
            tracep->chgIData(oldp+916,(vlTOPp->top__DOT__picorv32__DOT__q_insn_imm),32);
            tracep->chgIData(oldp+917,(vlTOPp->top__DOT__picorv32__DOT__q_insn_opcode),32);
            tracep->chgCData(oldp+918,(vlTOPp->top__DOT__picorv32__DOT__q_insn_rs1),5);
            tracep->chgCData(oldp+919,(vlTOPp->top__DOT__picorv32__DOT__q_insn_rs2),5);
            tracep->chgCData(oldp+920,(vlTOPp->top__DOT__picorv32__DOT__q_insn_rd),5);
            tracep->chgBit(oldp+921,(vlTOPp->top__DOT__picorv32__DOT__dbg_next));
            tracep->chgBit(oldp+922,(vlTOPp->top__DOT__picorv32__DOT__launch_next_insn));
            tracep->chgBit(oldp+923,(vlTOPp->top__DOT__picorv32__DOT__dbg_valid_insn));
            tracep->chgQData(oldp+924,(vlTOPp->top__DOT__picorv32__DOT__cached_ascii_instr),64);
            tracep->chgIData(oldp+926,(vlTOPp->top__DOT__picorv32__DOT__cached_insn_imm),32);
            tracep->chgIData(oldp+927,(vlTOPp->top__DOT__picorv32__DOT__cached_insn_opcode),32);
            tracep->chgCData(oldp+928,(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs1),5);
            tracep->chgCData(oldp+929,(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs2),5);
            tracep->chgCData(oldp+930,(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rd),5);
            tracep->chgCData(oldp+931,(vlTOPp->top__DOT__picorv32__DOT__cpu_state),8);
            tracep->chgCData(oldp+932,(vlTOPp->top__DOT__picorv32__DOT__irq_state),2);
            tracep->chgWData(oldp+933,(vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_state),128);
            tracep->chgBit(oldp+937,(vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rinst));
            tracep->chgBit(oldp+938,(vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rdata));
            tracep->chgBit(oldp+939,(vlTOPp->top__DOT__picorv32__DOT__set_mem_do_wdata));
            tracep->chgBit(oldp+940,(vlTOPp->top__DOT__picorv32__DOT__latched_store));
            tracep->chgBit(oldp+941,(vlTOPp->top__DOT__picorv32__DOT__latched_stalu));
            tracep->chgBit(oldp+942,(vlTOPp->top__DOT__picorv32__DOT__latched_branch));
            tracep->chgBit(oldp+943,(vlTOPp->top__DOT__picorv32__DOT__latched_compr));
            tracep->chgBit(oldp+944,(vlTOPp->top__DOT__picorv32__DOT__latched_trace));
            tracep->chgBit(oldp+945,(vlTOPp->top__DOT__picorv32__DOT__latched_is_lu));
            tracep->chgBit(oldp+946,(vlTOPp->top__DOT__picorv32__DOT__latched_is_lh));
            tracep->chgBit(oldp+947,(vlTOPp->top__DOT__picorv32__DOT__latched_is_lb));
            tracep->chgCData(oldp+948,(vlTOPp->top__DOT__picorv32__DOT__latched_rd),6);
            tracep->chgIData(oldp+949,(vlTOPp->top__DOT__picorv32__DOT__current_pc),32);
            tracep->chgBit(oldp+950,(vlTOPp->top__DOT__picorv32__DOT__pcpi_timeout));
            tracep->chgIData(oldp+951,(vlTOPp->top__DOT__picorv32__DOT__next_irq_pending),32);
            tracep->chgBit(oldp+952,(vlTOPp->top__DOT__picorv32__DOT__do_waitirq));
            tracep->chgIData(oldp+953,(vlTOPp->top__DOT__picorv32__DOT__alu_out),32);
            tracep->chgIData(oldp+954,(vlTOPp->top__DOT__picorv32__DOT__alu_out_q),32);
            tracep->chgBit(oldp+955,(vlTOPp->top__DOT__picorv32__DOT__alu_out_0));
            tracep->chgBit(oldp+956,(vlTOPp->top__DOT__picorv32__DOT__alu_out_0_q));
            tracep->chgBit(oldp+957,(vlTOPp->top__DOT__picorv32__DOT__alu_wait));
            tracep->chgBit(oldp+958,(vlTOPp->top__DOT__picorv32__DOT__alu_wait_2));
            tracep->chgIData(oldp+959,(((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sub)
                                         ? (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                            - vlTOPp->top__DOT__picorv32__DOT__reg_op2)
                                         : (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                            + vlTOPp->top__DOT__picorv32__DOT__reg_op2))),32);
            tracep->chgIData(oldp+960,((vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                        << (0x1fU & vlTOPp->top__DOT__picorv32__DOT__reg_op2))),32);
            tracep->chgIData(oldp+961,((IData)((0x1ffffffffULL 
                                                & VL_SHIFTRS_QQI(33,33,5, 
                                                                 (((QData)((IData)(
                                                                                (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sra) 
                                                                                | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srai)) 
                                                                                & (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                                                >> 0x1fU)))) 
                                                                   << 0x20U) 
                                                                  | (QData)((IData)(vlTOPp->top__DOT__picorv32__DOT__reg_op1))), 
                                                                 (0x1fU 
                                                                  & vlTOPp->top__DOT__picorv32__DOT__reg_op2))))),32);
            tracep->chgBit(oldp+962,(vlTOPp->top__DOT__picorv32__DOT__alu_eq));
            tracep->chgBit(oldp+963,(vlTOPp->top__DOT__picorv32__DOT__alu_ltu));
            tracep->chgBit(oldp+964,(vlTOPp->top__DOT__picorv32__DOT__alu_lts));
            tracep->chgBit(oldp+965,(vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word_q));
            tracep->chgBit(oldp+966,(vlTOPp->top__DOT__picorv32__DOT__cpuregs_write));
            tracep->chgIData(oldp+967,(vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata),32);
            tracep->chgIData(oldp+968,(vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1),32);
            tracep->chgIData(oldp+969,(vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2),32);
        }
        tracep->chgBit(oldp+970,(vlTOPp->sys_clk));
        tracep->chgBit(oldp+971,(vlTOPp->sys_rst));
        tracep->chgBit(oldp+972,(vlTOPp->serial_rx));
        tracep->chgBit(oldp+973,(vlTOPp->serial_tx));
        tracep->chgBit(oldp+974,(vlTOPp->spiflash_cs_n));
        tracep->chgBit(oldp+975,(vlTOPp->spiflash_clk));
        tracep->chgBit(oldp+976,(vlTOPp->spiflash_miso));
        tracep->chgBit(oldp+977,(vlTOPp->spiflash_mosi));
        tracep->chgBit(oldp+978,(vlTOPp->spiflash_wp));
        tracep->chgBit(oldp+979,(vlTOPp->spiflash_hold));
        tracep->chgBit(oldp+980,(vlTOPp->serial_dbg_rx));
        tracep->chgBit(oldp+981,(vlTOPp->serial_dbg_tx));
        tracep->chgBit(oldp+982,(vlTOPp->gpio_out_pad));
        tracep->chgBit(oldp+983,(vlTOPp->gpio_in_pad));
        tracep->chgBit(oldp+984,(vlTOPp->gpio_outenb_pad));
        tracep->chgBit(oldp+985,(vlTOPp->gpio_inenb_pad));
        tracep->chgBit(oldp+986,(vlTOPp->gpio_mode0_pad));
        tracep->chgBit(oldp+987,(vlTOPp->gpio_mode1_pad));
        tracep->chgWData(oldp+988,(vlTOPp->la_output),128);
        tracep->chgWData(oldp+992,(vlTOPp->la_input),128);
        tracep->chgWData(oldp+996,(vlTOPp->la_oenb),128);
        tracep->chgWData(oldp+1000,(vlTOPp->la_iena),128);
        tracep->chgBit(oldp+1004,(vlTOPp->mprj_wb_iena));
        tracep->chgCData(oldp+1005,(vlTOPp->user_irq_ena),3);
    }
}

void Vtop::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vtop__Syms* __restrict vlSymsp = static_cast<Vtop__Syms*>(userp);
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
    }
}
