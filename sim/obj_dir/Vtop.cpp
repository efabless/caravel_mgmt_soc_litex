// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

//==========

VerilatedContext* Vtop::contextp() {
    return __VlSymsp->_vm_contextp__;
}

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval\n"); );
    Vtop__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mgmt_soc.v", 4, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vtop::_eval_initial_loop(Vtop__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("mgmt_soc.v", 4, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vtop::_sequent__TOP__3(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__3\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*4:0*/ __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_level0;
    CData/*4:0*/ __Vdly__top__DOT__mgmtsoc_uart_tx_fifo_level0;
    CData/*3:0*/ __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_consume;
    CData/*7:0*/ __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt;
    CData/*0:0*/ __Vdly__top__DOT__mgmtsoc_litespisdrphycore_clk;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__storage__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__storage__v0;
    CData/*3:0*/ __Vdlyvdim0__top__DOT__storage_1__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__storage_1__v0;
    CData/*5:0*/ __Vdlyvdim0__top__DOT__picorv32__DOT__cpuregs__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__picorv32__DOT__cpuregs__v0;
    SData/*9:0*/ __Vdlyvval__top__DOT__storage__v0;
    SData/*9:0*/ __Vdlyvval__top__DOT__storage_1__v0;
    IData/*31:0*/ __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out;
    IData/*31:0*/ __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in;
    IData/*31:0*/ __Vdly__top__DOT__mgmtsoc_tx_phase;
    IData/*31:0*/ __Vdly__top__DOT__mgmtsoc_bus_errors;
    IData/*31:0*/ __Vdly__top__DOT__mgmtsoc_rx_phase;
    IData/*31:0*/ __Vdly__top__DOT__uart_bridge_tx_phase;
    IData/*31:0*/ __Vdly__top__DOT__uart_bridge_rx_phase;
    IData/*19:0*/ __Vdly__top__DOT__uart_bridge_count;
    IData/*31:0*/ __Vdlyvval__top__DOT__picorv32__DOT__cpuregs__v0;
    // Body
    __Vdlyvset__top__DOT__storage_1__v0 = 0U;
    __Vdlyvset__top__DOT__storage__v0 = 0U;
    __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out 
        = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out;
    __Vdlyvset__top__DOT__picorv32__DOT__cpuregs__v0 = 0U;
    __Vdly__top__DOT__mgmtsoc_bus_errors = vlTOPp->top__DOT__mgmtsoc_bus_errors;
    __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_consume 
        = vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_consume;
    __Vdly__top__DOT__uart_bridge_count = vlTOPp->top__DOT__uart_bridge_count;
    __Vdly__top__DOT__mgmtsoc_rx_phase = vlTOPp->top__DOT__mgmtsoc_rx_phase;
    __Vdly__top__DOT__mgmtsoc_tx_phase = vlTOPp->top__DOT__mgmtsoc_tx_phase;
    __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_level0 = vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0;
    __Vdly__top__DOT__mgmtsoc_uart_tx_fifo_level0 = vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0;
    __Vdly__top__DOT__uart_bridge_tx_phase = vlTOPp->top__DOT__uart_bridge_tx_phase;
    __Vdly__top__DOT__uart_bridge_rx_phase = vlTOPp->top__DOT__uart_bridge_rx_phase;
    __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in 
        = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in;
    vlTOPp->__Vdly__top__DOT__mgmtsoc_timer_value = vlTOPp->top__DOT__mgmtsoc_timer_value;
    __Vdly__top__DOT__mgmtsoc_litespisdrphycore_clk 
        = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk;
    __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt 
        = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_rd 
        = vlTOPp->top__DOT__picorv32__DOT__latched_rd;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lb 
        = vlTOPp->top__DOT__picorv32__DOT__latched_is_lb;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lh 
        = vlTOPp->top__DOT__picorv32__DOT__latched_is_lh;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lu 
        = vlTOPp->top__DOT__picorv32__DOT__latched_is_lu;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__do_waitirq 
        = vlTOPp->top__DOT__picorv32__DOT__do_waitirq;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_pseudo_trigger 
        = vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh 
        = vlTOPp->top__DOT__picorv32__DOT__reg_sh;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_prefetch 
        = vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_active 
        = vlTOPp->top__DOT__picorv32__DOT__irq_active;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_trigger 
        = vlTOPp->top__DOT__picorv32__DOT__decoder_trigger;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_compr 
        = vlTOPp->top__DOT__picorv32__DOT__latched_compr;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_pc 
        = vlTOPp->top__DOT__picorv32__DOT__reg_pc;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
        = vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
        = vlTOPp->top__DOT__picorv32__DOT__reg_out;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_state 
        = vlTOPp->top__DOT__picorv32__DOT__irq_state;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state 
        = vlTOPp->top__DOT__picorv32__DOT__cpu_state;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
        = vlTOPp->top__DOT__picorv32__DOT__reg_op1;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state 
        = vlTOPp->top__DOT__picorv32__DOT__mem_state;
    vlTOPp->top__DOT__picorv32__DOT__alu_wait = 0U;
    vlTOPp->top__DOT__picorv32__DOT__count_instr = 0ULL;
    vlTOPp->top__DOT__picorv32__DOT__trace_valid = 0U;
    vlTOPp->top__DOT__picorv32__DOT__alu_wait_2 = 0U;
    vlTOPp->top__DOT__picorv32__DOT__trace_data = 0ULL;
    vlTOPp->top__DOT__picorv32__DOT__count_cycle = 0ULL;
    vlTOPp->spiflash_mosi = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_o;
    vlTOPp->top__DOT__memdat_2 = vlTOPp->top__DOT__storage_1
        [vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr];
    vlTOPp->top__DOT__memdat = vlTOPp->top__DOT__storage
        [vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr];
    if (vlTOPp->top__DOT__picorv32__DOT__launch_next_insn) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_addr 
            = vlTOPp->top__DOT__picorv32__DOT__next_pc;
    }
    vlTOPp->top__DOT__picorv32__DOT__alu_out_0_q = vlTOPp->top__DOT__picorv32__DOT__alu_out_0;
    vlTOPp->top__DOT__picorv32__DOT__q_insn_opcode 
        = vlTOPp->top__DOT__picorv32__DOT__dbg_insn_opcode;
    vlTOPp->top__DOT__picorv32__DOT__q_insn_rd = vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rd;
    vlTOPp->top__DOT__picorv32__DOT__q_insn_rs2 = vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs2;
    vlTOPp->top__DOT__picorv32__DOT__q_insn_rs1 = vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs1;
    vlTOPp->top__DOT__picorv32__DOT__q_insn_imm = vlTOPp->top__DOT__picorv32__DOT__dbg_insn_imm;
    vlTOPp->top__DOT__picorv32__DOT__q_ascii_instr 
        = vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_instr;
    vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word_q 
        = vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word;
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__mgmtsoc_picorv326 = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read) {
        vlTOPp->top__DOT__memdat_1 = vlTOPp->top__DOT__storage
            [vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_consume];
    }
    if (vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value_ce3) {
        vlTOPp->top__DOT__uart_bridge_length = vlTOPp->top__DOT__uart_bridge_length_uartwishbonebridge_next_value3;
    }
    if (vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value_ce1) {
        vlTOPp->top__DOT__mgmtsoc_rx_data = vlTOPp->top__DOT__mgmtsoc_rx_data_rs232phy_rs232phyrx_next_value1;
    }
    if (vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value_ce2) {
        vlTOPp->top__DOT__mgmtsoc_tx_data = vlTOPp->top__DOT__mgmtsoc_tx_data_rs232phy_rs232phytx_next_value2;
    }
    if (vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value_ce2) {
        vlTOPp->top__DOT__uart_bridge_tx_data = vlTOPp->top__DOT__uart_bridge_tx_data_uartwishbonebridge_rs232phytx_next_value2;
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
        vlTOPp->top__DOT__picorv32__DOT__pcpi_timeout = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
        vlTOPp->top__DOT__mgmtsoc_picorv325 = 0U;
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
        vlTOPp->top__DOT__picorv32__DOT__latched_trace = 0U;
    }
    if (vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value_ce1) {
        vlTOPp->top__DOT__uart_bridge_words_count = vlTOPp->top__DOT__uart_bridge_words_count_uartwishbonebridge_next_value1;
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value_ce) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt 
            = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_cnt_litespiphy_next_value;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_rx_source_valid) 
         & (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)))) {
        __Vdlyvval__top__DOT__storage_1__v0 = vlTOPp->top__DOT__mgmtsoc_rx_source_payload_data;
        __Vdlyvset__top__DOT__storage_1__v0 = 1U;
        __Vdlyvdim0__top__DOT__storage_1__v0 = vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr;
    }
    if (vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value_ce2) {
        vlTOPp->top__DOT__uart_bridge_cmd = vlTOPp->top__DOT__uart_bridge_cmd_uartwishbonebridge_next_value2;
    }
    if (vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value_ce0) {
        vlTOPp->top__DOT__mgmtsoc_rx_count = vlTOPp->top__DOT__mgmtsoc_rx_count_rs232phy_rs232phyrx_next_value0;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re) 
         & (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)))) {
        __Vdlyvval__top__DOT__storage__v0 = (0xffU 
                                             & vlTOPp->top__DOT__mgmtsoc_dat_w);
        __Vdlyvset__top__DOT__storage__v0 = 1U;
        __Vdlyvdim0__top__DOT__storage__v0 = vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr;
    }
    vlTOPp->top__DOT__picorv32__DOT__dbg_next = vlTOPp->top__DOT__picorv32__DOT__launch_next_insn;
    vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q 
        = vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger;
    vlTOPp->spiflash_clk = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk;
    if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_load) {
        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out 
            = ((0x1fU >= (0x3fU & ((IData)(0x20U) - (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_len))))
                ? (vlTOPp->top__DOT__litespi_tx_mux_source_payload_data 
                   << (0x3fU & ((IData)(0x20U) - (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_len))))
                : 0U);
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out_shift) {
        if ((1U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
            __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                = (0xfffffffeU & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                                  << 1U));
        } else {
            if ((2U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                    = (0xfffffffcU & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                                      << 2U));
            } else {
                if ((4U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                    __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                        = (0xfffffff0U & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                                          << 4U));
                } else {
                    if ((8U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                            = (0xffffff00U & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
                                              << 8U));
                    }
                }
            }
        }
    }
    if ((((IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn) 
          & (IData)(vlTOPp->top__DOT__picorv32__DOT__cpuregs_write)) 
         & (0U != (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_rd)))) {
        vlTOPp->top__DOT__picorv32__DOT____Vlvbound1 
            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_wrdata;
        if ((0x23U >= (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_rd))) {
            __Vdlyvval__top__DOT__picorv32__DOT__cpuregs__v0 
                = vlTOPp->top__DOT__picorv32__DOT____Vlvbound1;
            __Vdlyvset__top__DOT__picorv32__DOT__cpuregs__v0 = 1U;
            __Vdlyvdim0__top__DOT__picorv32__DOT__cpuregs__v0 
                = vlTOPp->top__DOT__picorv32__DOT__latched_rd;
        }
    }
    if (vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value_ce0) {
        vlTOPp->top__DOT__mgmtsoc_tx_count = vlTOPp->top__DOT__mgmtsoc_tx_count_rs232phy_rs232phytx_next_value0;
    }
    if (vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value_ce6) {
        vlTOPp->top__DOT__uart_bridge_data = vlTOPp->top__DOT__uart_bridge_data_uartwishbonebridge_next_value6;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_ecall_ebreak 
            = (((0x73U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q)) 
                & (~ (IData)((0U != (0x7ffU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                               >> 0x15U)))))) 
               & (~ (IData)((0U != (0x1fffU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                               >> 7U))))));
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value_ce1) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_adr_litespi_next_value1;
    }
    if (vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value_ce1) {
        vlTOPp->top__DOT__uart_bridge_rx_data = vlTOPp->top__DOT__uart_bridge_rx_data_uartwishbonebridge_rs232phyrx_next_value1;
    }
    if (vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value_ce0) {
        vlTOPp->top__DOT__uart_bridge_bytes_count = vlTOPp->top__DOT__uart_bridge_bytes_count_uartwishbonebridge_next_value0;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_rdinstrh = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_rdinstr = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_rdcycle = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_timer = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_rdcycleh = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_txempty_re = vlTOPp->top__DOT__csrbank7_txempty_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_txempty_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_status_re = vlTOPp->top__DOT__csrbank6_ev_status_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_status_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_value_re = vlTOPp->top__DOT__csrbank6_value_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_value_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_master_status_re = vlTOPp->top__DOT__csrbank4_master_status_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_status_re = 0U;
    }
    vlTOPp->top__DOT__gpio_in_re = vlTOPp->top__DOT__csrbank1_in_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_in_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_bus_errors_re = vlTOPp->top__DOT__csrbank0_bus_errors_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_bus_errors_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_status_re = vlTOPp->top__DOT__csrbank7_ev_status_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_status_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rxempty_re = vlTOPp->top__DOT__csrbank7_rxempty_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_rxempty_re = 0U;
    }
    vlTOPp->top__DOT__la_in_re = vlTOPp->top__DOT__csrbank2_in0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_in_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_txfull_re = vlTOPp->top__DOT__csrbank7_txfull_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_txfull_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rxfull_re = vlTOPp->top__DOT__csrbank7_rxfull_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_rxfull_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_enable_re = vlTOPp->top__DOT__csrbank7_ev_enable0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_enable_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_reload_re = vlTOPp->top__DOT__csrbank6_reload0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_reload_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_re 
        = vlTOPp->top__DOT__csrbank5_clk_divisor0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_master_cs_re = vlTOPp->top__DOT__csrbank4_master_cs0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_cs_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_litespimmap_re = vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_re = 0U;
    }
    vlTOPp->top__DOT__mprj_wb_iena_re = vlTOPp->top__DOT__csrbank3_out0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mprj_wb_iena_re = 0U;
    }
    vlTOPp->top__DOT__la_oe_re = vlTOPp->top__DOT__csrbank2_oe0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_oe_re = 0U;
    }
    vlTOPp->top__DOT__gpio_oe_re = vlTOPp->top__DOT__csrbank1_oe0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_oe_re = 0U;
    }
    vlTOPp->top__DOT__gpio_mode0_re = vlTOPp->top__DOT__csrbank1_mode00_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_mode0_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_enable_re = vlTOPp->top__DOT__csrbank6_ev_enable0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_enable_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_load_re = vlTOPp->top__DOT__csrbank6_load0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_load_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_en_re = vlTOPp->top__DOT__csrbank6_en0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_en_re = 0U;
    }
    vlTOPp->top__DOT__gpio_out_re = vlTOPp->top__DOT__csrbank1_out0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_out_re = 0U;
    }
    vlTOPp->top__DOT__gpio_ien_re = vlTOPp->top__DOT__csrbank1_ien0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_ien_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_master_phyconfig_re = vlTOPp->top__DOT__csrbank4_master_phyconfig0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_phyconfig_re = 0U;
    }
    vlTOPp->top__DOT__la_ien_re = vlTOPp->top__DOT__csrbank2_ien0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_ien_re = 0U;
    }
    vlTOPp->top__DOT__user_irq_ena_re = vlTOPp->top__DOT__csrbank8_out0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__user_irq_ena_re = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_scratch_re = vlTOPp->top__DOT__csrbank0_scratch0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_scratch_re = 0U;
    }
    vlTOPp->top__DOT__gpio_mode1_re = vlTOPp->top__DOT__csrbank1_mode10_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_mode1_re = 0U;
    }
    vlTOPp->top__DOT__la_out_re = vlTOPp->top__DOT__csrbank2_out0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_out_re = 0U;
    }
    if ((0xffffffffU != vlTOPp->top__DOT__mgmtsoc_bus_errors)) {
        if (vlTOPp->top__DOT__error) {
            __Vdly__top__DOT__mgmtsoc_bus_errors = 
                ((IData)(1U) + vlTOPp->top__DOT__mgmtsoc_bus_errors);
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        __Vdly__top__DOT__mgmtsoc_bus_errors = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read) {
        __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_consume 
            = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_consume)));
    }
    if (vlTOPp->top__DOT__int_rst) {
        __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_consume = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_consume 
            = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_consume)));
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_consume = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value_ce1) {
        vlTOPp->serial_tx = vlTOPp->top__DOT__mgmtsoc_serial_tx_rs232phy_rs232phytx_next_value1;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->serial_tx = 1U;
    }
    if (vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value_ce1) {
        vlTOPp->serial_dbg_tx = vlTOPp->top__DOT__obj_serial_dbg_tx_uartwishbonebridge_rs232phytx_next_value1;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->serial_dbg_tx = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_pending_re = vlTOPp->top__DOT__csrbank6_ev_pending_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_pending_re = 0U;
    }
    if (vlTOPp->top__DOT__uart_bridge_is_ongoing) {
        __Vdly__top__DOT__uart_bridge_count = 0xf4240U;
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__uart_bridge_done)))) {
            __Vdly__top__DOT__uart_bridge_count = (0xfffffU 
                                                   & (vlTOPp->top__DOT__uart_bridge_count 
                                                      - (IData)(1U)));
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        __Vdly__top__DOT__uart_bridge_count = 0xf4240U;
    }
    if (vlTOPp->top__DOT__csrbank6_ev_pending_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_pending_r = 
            (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_pending_r = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespimmap_wait) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_done)))) {
            vlTOPp->top__DOT__mgmtsoc_litespimmap_count 
                = (0x1ffU & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count) 
                             - (IData)(1U)));
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_count = 0x100U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_count = 0x100U;
    }
    if (vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value_ce5) {
        vlTOPp->top__DOT__uart_bridge_incr = vlTOPp->top__DOT__uart_bridge_incr_uartwishbonebridge_next_value5;
    }
    if ((0U == vlTOPp->top__DOT__uart_bridge_count)) {
        vlTOPp->top__DOT__uart_bridge_incr = 0U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uart_bridge_incr = 0U;
    }
    if (vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value_ce0) {
        vlTOPp->top__DOT__uart_bridge_tx_count = vlTOPp->top__DOT__uart_bridge_tx_count_uartwishbonebridge_rs232phytx_next_value0;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_rx_source_valid) 
         & (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)))) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce 
            = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce)));
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re) 
         & (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)))) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce 
            = (0xfU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce)));
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_pending_re = vlTOPp->top__DOT__csrbank7_ev_pending_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_pending_re = 0U;
    }
    vlTOPp->top__DOT__multiregimpl129_regs1 = vlTOPp->top__DOT__multiregimpl129_regs0;
    vlTOPp->top__DOT__multiregimpl127_regs1 = vlTOPp->top__DOT__multiregimpl127_regs0;
    vlTOPp->top__DOT__multiregimpl126_regs1 = vlTOPp->top__DOT__multiregimpl126_regs0;
    vlTOPp->top__DOT__multiregimpl125_regs1 = vlTOPp->top__DOT__multiregimpl125_regs0;
    vlTOPp->top__DOT__multiregimpl123_regs1 = vlTOPp->top__DOT__multiregimpl123_regs0;
    vlTOPp->top__DOT__multiregimpl122_regs1 = vlTOPp->top__DOT__multiregimpl122_regs0;
    vlTOPp->top__DOT__multiregimpl120_regs1 = vlTOPp->top__DOT__multiregimpl120_regs0;
    vlTOPp->top__DOT__multiregimpl119_regs1 = vlTOPp->top__DOT__multiregimpl119_regs0;
    vlTOPp->top__DOT__multiregimpl117_regs1 = vlTOPp->top__DOT__multiregimpl117_regs0;
    vlTOPp->top__DOT__multiregimpl116_regs1 = vlTOPp->top__DOT__multiregimpl116_regs0;
    vlTOPp->top__DOT__multiregimpl115_regs1 = vlTOPp->top__DOT__multiregimpl115_regs0;
    vlTOPp->top__DOT__multiregimpl112_regs1 = vlTOPp->top__DOT__multiregimpl112_regs0;
    vlTOPp->top__DOT__multiregimpl111_regs1 = vlTOPp->top__DOT__multiregimpl111_regs0;
    vlTOPp->top__DOT__multiregimpl109_regs1 = vlTOPp->top__DOT__multiregimpl109_regs0;
    vlTOPp->top__DOT__multiregimpl104_regs1 = vlTOPp->top__DOT__multiregimpl104_regs0;
    vlTOPp->top__DOT__multiregimpl103_regs1 = vlTOPp->top__DOT__multiregimpl103_regs0;
    vlTOPp->top__DOT__multiregimpl102_regs1 = vlTOPp->top__DOT__multiregimpl102_regs0;
    vlTOPp->top__DOT__multiregimpl100_regs1 = vlTOPp->top__DOT__multiregimpl100_regs0;
    vlTOPp->top__DOT__multiregimpl97_regs1 = vlTOPp->top__DOT__multiregimpl97_regs0;
    vlTOPp->top__DOT__multiregimpl96_regs1 = vlTOPp->top__DOT__multiregimpl96_regs0;
    vlTOPp->top__DOT__multiregimpl95_regs1 = vlTOPp->top__DOT__multiregimpl95_regs0;
    vlTOPp->top__DOT__multiregimpl92_regs1 = vlTOPp->top__DOT__multiregimpl92_regs0;
    vlTOPp->top__DOT__multiregimpl91_regs1 = vlTOPp->top__DOT__multiregimpl91_regs0;
    vlTOPp->top__DOT__multiregimpl90_regs1 = vlTOPp->top__DOT__multiregimpl90_regs0;
    vlTOPp->top__DOT__multiregimpl89_regs1 = vlTOPp->top__DOT__multiregimpl89_regs0;
    vlTOPp->top__DOT__multiregimpl88_regs1 = vlTOPp->top__DOT__multiregimpl88_regs0;
    vlTOPp->top__DOT__multiregimpl87_regs1 = vlTOPp->top__DOT__multiregimpl87_regs0;
    vlTOPp->top__DOT__multiregimpl86_regs1 = vlTOPp->top__DOT__multiregimpl86_regs0;
    vlTOPp->top__DOT__multiregimpl84_regs1 = vlTOPp->top__DOT__multiregimpl84_regs0;
    vlTOPp->top__DOT__multiregimpl81_regs1 = vlTOPp->top__DOT__multiregimpl81_regs0;
    vlTOPp->top__DOT__multiregimpl78_regs1 = vlTOPp->top__DOT__multiregimpl78_regs0;
    vlTOPp->top__DOT__multiregimpl76_regs1 = vlTOPp->top__DOT__multiregimpl76_regs0;
    vlTOPp->top__DOT__multiregimpl75_regs1 = vlTOPp->top__DOT__multiregimpl75_regs0;
    vlTOPp->top__DOT__multiregimpl73_regs1 = vlTOPp->top__DOT__multiregimpl73_regs0;
    vlTOPp->top__DOT__multiregimpl72_regs1 = vlTOPp->top__DOT__multiregimpl72_regs0;
    vlTOPp->top__DOT__multiregimpl71_regs1 = vlTOPp->top__DOT__multiregimpl71_regs0;
    vlTOPp->top__DOT__multiregimpl70_regs1 = vlTOPp->top__DOT__multiregimpl70_regs0;
    vlTOPp->top__DOT__multiregimpl69_regs1 = vlTOPp->top__DOT__multiregimpl69_regs0;
    vlTOPp->top__DOT__multiregimpl67_regs1 = vlTOPp->top__DOT__multiregimpl67_regs0;
    vlTOPp->top__DOT__multiregimpl66_regs1 = vlTOPp->top__DOT__multiregimpl66_regs0;
    vlTOPp->top__DOT__multiregimpl65_regs1 = vlTOPp->top__DOT__multiregimpl65_regs0;
    vlTOPp->top__DOT__multiregimpl63_regs1 = vlTOPp->top__DOT__multiregimpl63_regs0;
    vlTOPp->top__DOT__multiregimpl62_regs1 = vlTOPp->top__DOT__multiregimpl62_regs0;
    vlTOPp->top__DOT__multiregimpl61_regs1 = vlTOPp->top__DOT__multiregimpl61_regs0;
    vlTOPp->top__DOT__multiregimpl60_regs1 = vlTOPp->top__DOT__multiregimpl60_regs0;
    vlTOPp->top__DOT__multiregimpl57_regs1 = vlTOPp->top__DOT__multiregimpl57_regs0;
    vlTOPp->top__DOT__multiregimpl56_regs1 = vlTOPp->top__DOT__multiregimpl56_regs0;
    vlTOPp->top__DOT__multiregimpl55_regs1 = vlTOPp->top__DOT__multiregimpl55_regs0;
    vlTOPp->top__DOT__multiregimpl54_regs1 = vlTOPp->top__DOT__multiregimpl54_regs0;
    vlTOPp->top__DOT__multiregimpl53_regs1 = vlTOPp->top__DOT__multiregimpl53_regs0;
    vlTOPp->top__DOT__multiregimpl52_regs1 = vlTOPp->top__DOT__multiregimpl52_regs0;
    vlTOPp->top__DOT__multiregimpl51_regs1 = vlTOPp->top__DOT__multiregimpl51_regs0;
    vlTOPp->top__DOT__multiregimpl49_regs1 = vlTOPp->top__DOT__multiregimpl49_regs0;
    vlTOPp->top__DOT__multiregimpl47_regs1 = vlTOPp->top__DOT__multiregimpl47_regs0;
    vlTOPp->top__DOT__multiregimpl45_regs1 = vlTOPp->top__DOT__multiregimpl45_regs0;
    vlTOPp->top__DOT__multiregimpl41_regs1 = vlTOPp->top__DOT__multiregimpl41_regs0;
    vlTOPp->top__DOT__multiregimpl36_regs1 = vlTOPp->top__DOT__multiregimpl36_regs0;
    vlTOPp->top__DOT__multiregimpl35_regs1 = vlTOPp->top__DOT__multiregimpl35_regs0;
    vlTOPp->top__DOT__multiregimpl27_regs1 = vlTOPp->top__DOT__multiregimpl27_regs0;
    vlTOPp->top__DOT__multiregimpl24_regs1 = vlTOPp->top__DOT__multiregimpl24_regs0;
    vlTOPp->top__DOT__multiregimpl23_regs1 = vlTOPp->top__DOT__multiregimpl23_regs0;
    vlTOPp->top__DOT__multiregimpl21_regs1 = vlTOPp->top__DOT__multiregimpl21_regs0;
    vlTOPp->top__DOT__multiregimpl20_regs1 = vlTOPp->top__DOT__multiregimpl20_regs0;
    vlTOPp->top__DOT__multiregimpl18_regs1 = vlTOPp->top__DOT__multiregimpl18_regs0;
    vlTOPp->top__DOT__multiregimpl17_regs1 = vlTOPp->top__DOT__multiregimpl17_regs0;
    vlTOPp->top__DOT__multiregimpl16_regs1 = vlTOPp->top__DOT__multiregimpl16_regs0;
    vlTOPp->top__DOT__multiregimpl15_regs1 = vlTOPp->top__DOT__multiregimpl15_regs0;
    vlTOPp->top__DOT__multiregimpl14_regs1 = vlTOPp->top__DOT__multiregimpl14_regs0;
    vlTOPp->top__DOT__multiregimpl13_regs1 = vlTOPp->top__DOT__multiregimpl13_regs0;
    vlTOPp->top__DOT__multiregimpl12_regs1 = vlTOPp->top__DOT__multiregimpl12_regs0;
    vlTOPp->top__DOT__multiregimpl11_regs1 = vlTOPp->top__DOT__multiregimpl11_regs0;
    vlTOPp->top__DOT__multiregimpl10_regs1 = vlTOPp->top__DOT__multiregimpl10_regs0;
    vlTOPp->top__DOT__multiregimpl9_regs1 = vlTOPp->top__DOT__multiregimpl9_regs0;
    vlTOPp->top__DOT__multiregimpl8_regs1 = vlTOPp->top__DOT__multiregimpl8_regs0;
    vlTOPp->top__DOT__multiregimpl7_regs1 = vlTOPp->top__DOT__multiregimpl7_regs0;
    vlTOPp->top__DOT__multiregimpl6_regs1 = vlTOPp->top__DOT__multiregimpl6_regs0;
    vlTOPp->top__DOT__multiregimpl5_regs1 = vlTOPp->top__DOT__multiregimpl5_regs0;
    vlTOPp->top__DOT__multiregimpl110_regs1 = vlTOPp->top__DOT__multiregimpl110_regs0;
    vlTOPp->top__DOT__multiregimpl42_regs1 = vlTOPp->top__DOT__multiregimpl42_regs0;
    vlTOPp->top__DOT__multiregimpl40_regs1 = vlTOPp->top__DOT__multiregimpl40_regs0;
    vlTOPp->top__DOT__multiregimpl101_regs1 = vlTOPp->top__DOT__multiregimpl101_regs0;
    vlTOPp->top__DOT__multiregimpl30_regs1 = vlTOPp->top__DOT__multiregimpl30_regs0;
    vlTOPp->top__DOT__multiregimpl29_regs1 = vlTOPp->top__DOT__multiregimpl29_regs0;
    vlTOPp->top__DOT__multiregimpl94_regs1 = vlTOPp->top__DOT__multiregimpl94_regs0;
    vlTOPp->top__DOT__multiregimpl93_regs1 = vlTOPp->top__DOT__multiregimpl93_regs0;
    vlTOPp->top__DOT__multiregimpl26_regs1 = vlTOPp->top__DOT__multiregimpl26_regs0;
    vlTOPp->top__DOT__multiregimpl25_regs1 = vlTOPp->top__DOT__multiregimpl25_regs0;
    vlTOPp->top__DOT__multiregimpl22_regs1 = vlTOPp->top__DOT__multiregimpl22_regs0;
    vlTOPp->top__DOT__multiregimpl19_regs1 = vlTOPp->top__DOT__multiregimpl19_regs0;
    vlTOPp->top__DOT__multiregimpl85_regs1 = vlTOPp->top__DOT__multiregimpl85_regs0;
    vlTOPp->top__DOT__multiregimpl83_regs1 = vlTOPp->top__DOT__multiregimpl83_regs0;
    vlTOPp->top__DOT__multiregimpl82_regs1 = vlTOPp->top__DOT__multiregimpl82_regs0;
    vlTOPp->top__DOT__multiregimpl80_regs1 = vlTOPp->top__DOT__multiregimpl80_regs0;
    vlTOPp->top__DOT__multiregimpl79_regs1 = vlTOPp->top__DOT__multiregimpl79_regs0;
    vlTOPp->top__DOT__multiregimpl77_regs1 = vlTOPp->top__DOT__multiregimpl77_regs0;
    vlTOPp->top__DOT__multiregimpl68_regs1 = vlTOPp->top__DOT__multiregimpl68_regs0;
    vlTOPp->top__DOT__multiregimpl124_regs1 = vlTOPp->top__DOT__multiregimpl124_regs0;
    vlTOPp->top__DOT__multiregimpl44_regs1 = vlTOPp->top__DOT__multiregimpl44_regs0;
    vlTOPp->top__DOT__multiregimpl39_regs1 = vlTOPp->top__DOT__multiregimpl39_regs0;
    vlTOPp->top__DOT__multiregimpl105_regs1 = vlTOPp->top__DOT__multiregimpl105_regs0;
    vlTOPp->top__DOT__multiregimpl64_regs1 = vlTOPp->top__DOT__multiregimpl64_regs0;
    vlTOPp->top__DOT__multiregimpl38_regs1 = vlTOPp->top__DOT__multiregimpl38_regs0;
    vlTOPp->top__DOT__multiregimpl4_regs1 = vlTOPp->top__DOT__multiregimpl4_regs0;
    vlTOPp->top__DOT__multiregimpl37_regs1 = vlTOPp->top__DOT__multiregimpl37_regs0;
    vlTOPp->top__DOT__multiregimpl3_regs1 = vlTOPp->top__DOT__multiregimpl3_regs0;
    vlTOPp->top__DOT__multiregimpl130_regs1 = vlTOPp->top__DOT__multiregimpl130_regs0;
    vlTOPp->top__DOT__multiregimpl59_regs1 = vlTOPp->top__DOT__multiregimpl59_regs0;
    vlTOPp->top__DOT__multiregimpl58_regs1 = vlTOPp->top__DOT__multiregimpl58_regs0;
    vlTOPp->top__DOT__multiregimpl121_regs1 = vlTOPp->top__DOT__multiregimpl121_regs0;
    vlTOPp->top__DOT__multiregimpl50_regs1 = vlTOPp->top__DOT__multiregimpl50_regs0;
    vlTOPp->top__DOT__multiregimpl33_regs1 = vlTOPp->top__DOT__multiregimpl33_regs0;
    vlTOPp->top__DOT__multiregimpl99_regs1 = vlTOPp->top__DOT__multiregimpl99_regs0;
    vlTOPp->top__DOT__multiregimpl98_regs1 = vlTOPp->top__DOT__multiregimpl98_regs0;
    vlTOPp->top__DOT__multiregimpl113_regs1 = vlTOPp->top__DOT__multiregimpl113_regs0;
    vlTOPp->top__DOT__multiregimpl28_regs1 = vlTOPp->top__DOT__multiregimpl28_regs0;
    vlTOPp->top__DOT__multiregimpl128_regs1 = vlTOPp->top__DOT__multiregimpl128_regs0;
    vlTOPp->top__DOT__multiregimpl118_regs1 = vlTOPp->top__DOT__multiregimpl118_regs0;
    vlTOPp->top__DOT__multiregimpl43_regs1 = vlTOPp->top__DOT__multiregimpl43_regs0;
    vlTOPp->top__DOT__multiregimpl32_regs1 = vlTOPp->top__DOT__multiregimpl32_regs0;
    vlTOPp->top__DOT__multiregimpl107_regs1 = vlTOPp->top__DOT__multiregimpl107_regs0;
    vlTOPp->top__DOT__multiregimpl31_regs1 = vlTOPp->top__DOT__multiregimpl31_regs0;
    vlTOPp->top__DOT__multiregimpl106_regs1 = vlTOPp->top__DOT__multiregimpl106_regs0;
    vlTOPp->top__DOT__multiregimpl108_regs1 = vlTOPp->top__DOT__multiregimpl108_regs0;
    vlTOPp->top__DOT__multiregimpl34_regs1 = vlTOPp->top__DOT__multiregimpl34_regs0;
    vlTOPp->top__DOT__multiregimpl46_regs1 = vlTOPp->top__DOT__multiregimpl46_regs0;
    vlTOPp->top__DOT__multiregimpl48_regs1 = vlTOPp->top__DOT__multiregimpl48_regs0;
    vlTOPp->top__DOT__multiregimpl74_regs1 = vlTOPp->top__DOT__multiregimpl74_regs0;
    vlTOPp->top__DOT__multiregimpl114_regs1 = vlTOPp->top__DOT__multiregimpl114_regs0;
    vlTOPp->top__DOT__mgmtsoc_rx_rx_d = vlTOPp->top__DOT__multiregimpl0_regs1;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_rx_rx_d = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_rx_source_valid) 
         & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_writable))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read)))) {
            __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_level0 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)));
        }
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read) {
            __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_level0 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0) 
                            - (IData)(1U)));
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_level0 = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_rx_tick = 0U;
    __Vdly__top__DOT__mgmtsoc_rx_phase = 0x80000000U;
    if (vlTOPp->top__DOT__mgmtsoc_rx_enable) {
        vlTOPp->top__DOT__mgmtsoc_rx_tick = (1U & (IData)(
                                                          (1ULL 
                                                           & ((0x2f2f987ULL 
                                                               + (QData)((IData)(vlTOPp->top__DOT__mgmtsoc_rx_phase))) 
                                                              >> 0x20U))));
        __Vdly__top__DOT__mgmtsoc_rx_phase = ((IData)(0x2f2f987U) 
                                              + vlTOPp->top__DOT__mgmtsoc_rx_phase);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_rx_tick = 0U;
    }
    if (vlTOPp->top__DOT__csrbank7_ev_pending_re) {
        vlTOPp->top__DOT__mgmtsoc_uart_pending_r = 
            (3U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_pending_r = 0U;
    }
    vlTOPp->top__DOT__rs232phy_rs232phyrx_state = vlTOPp->top__DOT__rs232phy_rs232phyrx_next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__rs232phy_rs232phyrx_state = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value_ce0) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs 
            = vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs_litespi_next_value0;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_burst_cs = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rxtx_re) 
         & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_writable))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read)))) {
            __Vdly__top__DOT__mgmtsoc_uart_tx_fifo_level0 
                = (0x1fU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)));
        }
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read) {
            __Vdly__top__DOT__mgmtsoc_uart_tx_fifo_level0 
                = (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0) 
                            - (IData)(1U)));
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        __Vdly__top__DOT__mgmtsoc_uart_tx_fifo_level0 = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_crossbar_cs) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_done)))) {
            vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count 
                = (0xfU & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count) 
                           - (IData)(1U)));
        }
    } else {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count = 0xbU;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count = 0xbU;
    }
    vlTOPp->top__DOT__mgmtsoc_tx_tick = 0U;
    __Vdly__top__DOT__mgmtsoc_tx_phase = 0x2f2f987U;
    if (vlTOPp->top__DOT__mgmtsoc_tx_enable) {
        vlTOPp->top__DOT__mgmtsoc_tx_tick = (1U & (IData)(
                                                          (1ULL 
                                                           & ((0x2f2f987ULL 
                                                               + (QData)((IData)(vlTOPp->top__DOT__mgmtsoc_tx_phase))) 
                                                              >> 0x20U))));
        __Vdly__top__DOT__mgmtsoc_tx_phase = ((IData)(0x2f2f987U) 
                                              + vlTOPp->top__DOT__mgmtsoc_tx_phase);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_tx_tick = 0U;
    }
    vlTOPp->top__DOT__rs232phy_rs232phytx_state = vlTOPp->top__DOT__rs232phy_rs232phytx_next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__rs232phy_rs232phytx_state = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_reset_re = vlTOPp->top__DOT__csrbank0_reset0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_reset_re = 0U;
    }
    if (vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value_ce0) {
        vlTOPp->top__DOT__uart_bridge_rx_count = vlTOPp->top__DOT__uart_bridge_rx_count_uartwishbonebridge_rs232phyrx_next_value0;
    }
    vlTOPp->top__DOT__uart_bridge_tx_tick = 0U;
    __Vdly__top__DOT__uart_bridge_tx_phase = 0x2f2f987U;
    if (vlTOPp->top__DOT__uart_bridge_tx_enable) {
        vlTOPp->top__DOT__uart_bridge_tx_tick = (1U 
                                                 & (IData)(
                                                           (1ULL 
                                                            & ((0x2f2f987ULL 
                                                                + (QData)((IData)(vlTOPp->top__DOT__uart_bridge_tx_phase))) 
                                                               >> 0x20U))));
        __Vdly__top__DOT__uart_bridge_tx_phase = ((IData)(0x2f2f987U) 
                                                  + vlTOPp->top__DOT__uart_bridge_tx_phase);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uart_bridge_tx_tick = 0U;
    }
    vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state 
        = vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uartwishbonebridge_rs232phytx_state = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_tx_clear) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_pending = 0U;
    }
    if (((0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)) 
         & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_trigger_d)))) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_pending = 1U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_pending = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in_shift) {
        if ((1U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
            __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                = ((0xfffffffeU & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                                   << 1U)) | (1U & 
                                              ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i) 
                                               >> 1U)));
        } else {
            if ((2U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                    = ((0xfffffffcU & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                                       << 2U)) | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i));
            } else {
                if ((4U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                    __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                        = ((0xfffffffcU & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                                           << 2U)) 
                           | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i));
                } else {
                    if ((8U == (IData)(vlTOPp->top__DOT__litespi_tx_mux_source_payload_width))) {
                        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                            = ((0xfffffffcU & (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in 
                                               << 2U)) 
                               | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i));
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__uart_bridge_rx_rx_d = vlTOPp->top__DOT__multiregimpl1_regs1;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uart_bridge_rx_rx_d = 0U;
    }
    vlTOPp->top__DOT__uart_bridge_rx_tick = 0U;
    __Vdly__top__DOT__uart_bridge_rx_phase = 0x80000000U;
    if (vlTOPp->top__DOT__uart_bridge_rx_enable) {
        vlTOPp->top__DOT__uart_bridge_rx_tick = (1U 
                                                 & (IData)(
                                                           (1ULL 
                                                            & ((0x2f2f987ULL 
                                                                + (QData)((IData)(vlTOPp->top__DOT__uart_bridge_rx_phase))) 
                                                               >> 0x20U))));
        __Vdly__top__DOT__uart_bridge_rx_phase = ((IData)(0x2f2f987U) 
                                                  + vlTOPp->top__DOT__uart_bridge_rx_phase);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uart_bridge_rx_tick = 0U;
    }
    vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state 
        = vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uartwishbonebridge_rs232phyrx_state = 0U;
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid)) 
               | (IData)(vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready)))) {
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid 
            = vlTOPp->top__DOT__mgmtsoc_master_rxtx_re;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_first = 0U;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_last = 1U;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_data 
            = vlTOPp->top__DOT__mgmtsoc_dat_w;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_len 
            = (0x3fU & vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage);
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_width 
            = (0xfU & (vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage 
                       >> 8U));
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_mask 
            = (0xffU & (vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage 
                        >> 0x10U));
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid = 0U;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_data = 0U;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_len = 0U;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_width = 0U;
        vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_payload_mask = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_rx_clear) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_pending = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable) 
         & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_trigger_d)))) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_pending = 1U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_pending = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en) {
        if (((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt) 
             < (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage))) {
            __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt 
                = (0xffU & ((IData)(1U) + (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt)));
        } else {
            __Vdly__top__DOT__mgmtsoc_litespisdrphycore_clk 
                = (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk)));
            __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt = 0U;
        }
    } else {
        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_clk = 0U;
        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt = 0U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_clk = 0U;
        __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt = 0U;
    }
    vlTOPp->top__DOT__interface8_bank_bus_dat_r = 0U;
    if ((8U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
            vlTOPp->top__DOT__interface8_bank_bus_dat_r 
                = vlTOPp->top__DOT__user_irq_ena_storage;
        }
    }
    vlTOPp->top__DOT__interface3_bank_bus_dat_r = 0U;
    if ((3U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
            vlTOPp->top__DOT__interface3_bank_bus_dat_r 
                = vlTOPp->top__DOT__mprj_wb_iena_storage;
        }
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2 
        = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2 = 0U;
    }
    vlTOPp->top__DOT__interface5_bank_bus_dat_r = 0U;
    if ((5U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
            vlTOPp->top__DOT__interface5_bank_bus_dat_r 
                = vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage;
        }
    }
    vlTOPp->top__DOT__interface2_bank_bus_dat_r = 0U;
    if ((2U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if (((((((((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))) 
                   | (1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                  | (2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                 | (3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                | (4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
               | (5U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
              | (6U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
             | (7U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
            vlTOPp->top__DOT__interface2_bank_bus_dat_r 
                = ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                    ? vlTOPp->top__DOT__la_ien_storage[3U]
                    : ((1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                        ? vlTOPp->top__DOT__la_ien_storage[2U]
                        : ((2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                            ? vlTOPp->top__DOT__la_ien_storage[1U]
                            : ((3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                ? vlTOPp->top__DOT__la_ien_storage[0U]
                                : ((4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                    ? vlTOPp->top__DOT__la_oe_storage[3U]
                                    : ((5U == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                        ? vlTOPp->top__DOT__la_oe_storage[2U]
                                        : ((6U == (0x1ffU 
                                                   & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                            ? vlTOPp->top__DOT__la_oe_storage[1U]
                                            : vlTOPp->top__DOT__la_oe_storage[0U])))))));
        } else {
            if (((((((((8U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))) 
                       | (9U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                      | (0xaU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                     | (0xbU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                    | (0xcU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                   | (0xdU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                  | (0xeU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                 | (0xfU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
                vlTOPp->top__DOT__interface2_bank_bus_dat_r 
                    = ((8U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                        ? vlTOPp->top__DOT__la_in_status[3U]
                        : ((9U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                            ? vlTOPp->top__DOT__la_in_status[2U]
                            : ((0xaU == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                ? vlTOPp->top__DOT__la_in_status[1U]
                                : ((0xbU == (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                    ? vlTOPp->top__DOT__la_in_status[0U]
                                    : ((0xcU == (0x1ffU 
                                                 & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                        ? vlTOPp->top__DOT__la_out_storage[3U]
                                        : ((0xdU == 
                                            (0x1ffU 
                                             & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                            ? vlTOPp->top__DOT__la_out_storage[2U]
                                            : ((0xeU 
                                                == 
                                                (0x1ffU 
                                                 & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                                ? vlTOPp->top__DOT__la_out_storage[1U]
                                                : vlTOPp->top__DOT__la_out_storage[0U])))))));
            }
        }
    }
    vlTOPp->top__DOT__interface0_bank_bus_dat_r = 0U;
    if ((0U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
            vlTOPp->top__DOT__interface0_bank_bus_dat_r 
                = vlTOPp->top__DOT__mgmtsoc_reset_storage;
        } else {
            if ((1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                vlTOPp->top__DOT__interface0_bank_bus_dat_r 
                    = vlTOPp->top__DOT__mgmtsoc_scratch_storage;
            } else {
                if ((2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                    vlTOPp->top__DOT__interface0_bank_bus_dat_r 
                        = vlTOPp->top__DOT__mgmtsoc_bus_errors;
                }
            }
        }
    }
    vlTOPp->top__DOT__interface7_bank_bus_dat_r = 0U;
    if ((7U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if (((((((((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))) 
                   | (1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                  | (2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                 | (3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                | (4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
               | (5U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
              | (6U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
             | (7U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
            vlTOPp->top__DOT__interface7_bank_bus_dat_r 
                = ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                    ? (0xffU & (IData)(vlTOPp->top__DOT__memdat_3))
                    : ((1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                        ? (0x10U == (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0))
                        : ((2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                            ? (1U & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable)))
                            : ((3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                ? (IData)(vlTOPp->top__DOT__mgmtsoc_uart_status_status)
                                : ((4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                    ? (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status)
                                    : ((5U == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                        ? (IData)(vlTOPp->top__DOT__mgmtsoc_uart_enable_storage)
                                        : ((6U == (0x1ffU 
                                                   & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                            ? (1U & 
                                               (~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable)))
                                            : (0x10U 
                                               == (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)))))))));
        }
    }
    vlTOPp->top__DOT__interface1_bank_bus_dat_r = 0U;
    if ((1U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
            vlTOPp->top__DOT__interface1_bank_bus_dat_r 
                = vlTOPp->top__DOT__gpio_mode1_storage;
        } else {
            if ((1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                vlTOPp->top__DOT__interface1_bank_bus_dat_r 
                    = vlTOPp->top__DOT__gpio_mode0_storage;
            } else {
                if ((2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                    vlTOPp->top__DOT__interface1_bank_bus_dat_r 
                        = vlTOPp->top__DOT__gpio_ien_storage;
                } else {
                    if ((3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                        vlTOPp->top__DOT__interface1_bank_bus_dat_r 
                            = vlTOPp->top__DOT__gpio_oe_storage;
                    } else {
                        if ((4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                            vlTOPp->top__DOT__interface1_bank_bus_dat_r 
                                = vlTOPp->top__DOT__multiregimpl2_regs1;
                        } else {
                            if ((5U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                                vlTOPp->top__DOT__interface1_bank_bus_dat_r 
                                    = vlTOPp->top__DOT__gpio_out_storage;
                            }
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__interface4_bank_bus_dat_r = 0U;
    if ((4U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
            vlTOPp->top__DOT__interface4_bank_bus_dat_r 
                = vlTOPp->top__DOT__mgmtsoc_litespimmap_storage;
        } else {
            if ((1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                vlTOPp->top__DOT__interface4_bank_bus_dat_r 
                    = vlTOPp->top__DOT__mgmtsoc_master_cs_storage;
            } else {
                if ((2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                    vlTOPp->top__DOT__interface4_bank_bus_dat_r 
                        = vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage;
                } else {
                    if ((3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                        vlTOPp->top__DOT__interface4_bank_bus_dat_r 
                            = vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_payload_data;
                    } else {
                        if ((4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) {
                            vlTOPp->top__DOT__interface4_bank_bus_dat_r 
                                = vlTOPp->top__DOT__mgmtsoc_master_status_status;
                        }
                    }
                }
            }
        }
    }
    vlTOPp->top__DOT__litespi_state = vlTOPp->top__DOT__litespi_next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__litespi_state = 0U;
    }
    vlTOPp->top__DOT__interface6_bank_bus_dat_r = 0U;
    if ((6U == (0x1fU & ((IData)(vlTOPp->top__DOT__mgmtsoc_adr) 
                         >> 9U)))) {
        if (((((((((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))) 
                   | (1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                  | (2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                 | (3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
                | (4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
               | (5U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
              | (6U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))) 
             | (7U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr))))) {
            vlTOPp->top__DOT__interface6_bank_bus_dat_r 
                = ((0U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                    ? vlTOPp->top__DOT__mgmtsoc_timer_load_storage
                    : ((1U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                        ? vlTOPp->top__DOT__mgmtsoc_timer_reload_storage
                        : ((2U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                            ? (IData)(vlTOPp->top__DOT__mgmtsoc_timer_en_storage)
                            : ((3U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                ? (IData)(vlTOPp->top__DOT__mgmtsoc_timer_update_value_storage)
                                : ((4U == (0x1ffU & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                    ? vlTOPp->top__DOT__mgmtsoc_timer_value_status
                                    : ((5U == (0x1ffU 
                                               & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                        ? (0U == vlTOPp->top__DOT__mgmtsoc_timer_value)
                                        : ((6U == (0x1ffU 
                                                   & (IData)(vlTOPp->top__DOT__mgmtsoc_adr)))
                                            ? (IData)(vlTOPp->top__DOT__mgmtsoc_timer_zero_pending)
                                            : (IData)(vlTOPp->top__DOT__mgmtsoc_timer_enable_storage))))))));
        }
    }
    vlTOPp->top__DOT__state = vlTOPp->top__DOT__next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__state = 0U;
    }
    if (vlTOPp->top__DOT__litespi_grant) {
        if (vlTOPp->top__DOT__litespi_grant) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__litespi_request) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__litespi_request))) {
                    vlTOPp->top__DOT__litespi_grant = 0U;
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__litespi_request)))) {
            if ((2U & (IData)(vlTOPp->top__DOT__litespi_request))) {
                vlTOPp->top__DOT__litespi_grant = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__litespi_grant = 0U;
    }
    vlTOPp->top__DOT__litespiphy_state = vlTOPp->top__DOT__litespiphy_next_state;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__litespiphy_state = 0U;
    }
    vlTOPp->top__DOT__slave_sel_r = vlTOPp->top__DOT__slave_sel;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__slave_sel_r = 0U;
    }
    if ((((IData)(vlTOPp->top__DOT__array_muxed4) & (IData)(vlTOPp->top__DOT__array_muxed3)) 
         & (~ (IData)(vlTOPp->top__DOT__shared_ack)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__done)))) {
            vlTOPp->top__DOT__count = (0xfffffU & (vlTOPp->top__DOT__count 
                                                   - (IData)(1U)));
        }
    } else {
        vlTOPp->top__DOT__count = 0xf4240U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__count = 0xf4240U;
    }
    if (vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value_ce4) {
        vlTOPp->top__DOT__uart_bridge_address = vlTOPp->top__DOT__uart_bridge_address_uartwishbonebridge_next_value4;
    }
    vlTOPp->top__DOT__uartwishbonebridge_state = vlTOPp->top__DOT__uartwishbonebridge_next_state;
    if ((0U == vlTOPp->top__DOT__uart_bridge_count)) {
        vlTOPp->top__DOT__uartwishbonebridge_state = 0U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__uartwishbonebridge_state = 0U;
    }
    if (vlTOPp->top__DOT__grant) {
        if (vlTOPp->top__DOT__grant) {
            if ((1U & (~ ((IData)(vlTOPp->top__DOT__request) 
                          >> 1U)))) {
                if ((1U & (IData)(vlTOPp->top__DOT__request))) {
                    vlTOPp->top__DOT__grant = 0U;
                }
            }
        }
    } else {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__request)))) {
            if ((2U & (IData)(vlTOPp->top__DOT__request))) {
                vlTOPp->top__DOT__grant = 1U;
            }
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__grant = 0U;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q) {
        vlTOPp->top__DOT__picorv32__DOT__cached_ascii_instr 
            = vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr;
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
               | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_trap)))) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_valid_insn = 0U;
    } else {
        if (vlTOPp->top__DOT__picorv32__DOT__launch_next_insn) {
            vlTOPp->top__DOT__picorv32__DOT__dbg_valid_insn = 1U;
        }
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
               | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_trap)))) {
        vlTOPp->top__DOT__picorv32__DOT__prefetched_high_word = 0U;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__clear_prefetched_high_word) {
        vlTOPp->top__DOT__picorv32__DOT__prefetched_high_word = 0U;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q) {
        vlTOPp->top__DOT__picorv32__DOT__cached_insn_rd 
            = (0x1fU & (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rd));
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
                  | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_trap))))) {
        if (vlTOPp->top__DOT__mgmtsoc_picorv321) {
            vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wdata 
                = vlTOPp->top__DOT__mgmtsoc_picorv323;
        }
    }
    if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q) {
        vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs1 
            = (0x1fU & (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1));
    }
    if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q) {
        vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs2 
            = (0x1fU & (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs2));
    }
    if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q) {
        vlTOPp->top__DOT__picorv32__DOT__cached_insn_opcode 
            = ((3U == (3U & vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode))
                ? vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode
                : (0xffffU & vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode));
    }
    if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q) {
        vlTOPp->top__DOT__picorv32__DOT__cached_insn_imm 
            = vlTOPp->top__DOT__picorv32__DOT__decoded_imm;
    }
    if (vlTOPp->top__DOT____Vcellinp__picorv32__resetn) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__last_mem_valid)))) {
            vlTOPp->top__DOT__picorv32__DOT__mem_la_firstword_reg = 0U;
        }
    } else {
        vlTOPp->top__DOT__picorv32__DOT__mem_la_firstword_reg = 0U;
    }
    if ((1U & (~ ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
                  | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_trap))))) {
        if (((IData)(vlTOPp->top__DOT__mgmtsoc_picorv320) 
             | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv321))) {
            vlTOPp->top__DOT__mgmtsoc_picorv32_mem_addr 
                = (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch) 
                    | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst))
                    ? (0xfffffffcU & vlTOPp->top__DOT__picorv32__DOT__next_pc)
                    : (0xfffffffcU & vlTOPp->top__DOT__picorv32__DOT__reg_op1));
        }
    }
    if (__Vdlyvset__top__DOT__storage__v0) {
        vlTOPp->top__DOT__storage[__Vdlyvdim0__top__DOT__storage__v0] 
            = __Vdlyvval__top__DOT__storage__v0;
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_out 
        = __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_out;
    if (__Vdlyvset__top__DOT__picorv32__DOT__cpuregs__v0) {
        vlTOPp->top__DOT__picorv32__DOT__cpuregs[__Vdlyvdim0__top__DOT__picorv32__DOT__cpuregs__v0] 
            = __Vdlyvval__top__DOT__picorv32__DOT__cpuregs__v0;
    }
    vlTOPp->top__DOT__mgmtsoc_rx_phase = __Vdly__top__DOT__mgmtsoc_rx_phase;
    vlTOPp->top__DOT__mgmtsoc_tx_phase = __Vdly__top__DOT__mgmtsoc_tx_phase;
    vlTOPp->top__DOT__uart_bridge_tx_phase = __Vdly__top__DOT__uart_bridge_tx_phase;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sr_in 
        = __Vdly__top__DOT__mgmtsoc_litespisdrphycore_sr_in;
    vlTOPp->top__DOT__uart_bridge_rx_phase = __Vdly__top__DOT__uart_bridge_rx_phase;
    vlTOPp->top__DOT__mgmtsoc_bus_errors = __Vdly__top__DOT__mgmtsoc_bus_errors;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0 = __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_level0;
    vlTOPp->top__DOT__uart_bridge_count = __Vdly__top__DOT__uart_bridge_count;
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
    vlTOPp->top__DOT__mgmtsoc_litespimmap_done = (0U 
                                                  == (IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_count));
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_wrport_adr 
        = vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_produce;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_wrport_adr 
        = vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_produce;
    vlTOPp->top__DOT__multiregimpl129_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x1eU));
    vlTOPp->top__DOT__multiregimpl127_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x1cU));
    vlTOPp->top__DOT__multiregimpl126_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x1bU));
    vlTOPp->top__DOT__multiregimpl125_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x1aU));
    vlTOPp->top__DOT__multiregimpl123_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x18U));
    vlTOPp->top__DOT__multiregimpl122_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x17U));
    vlTOPp->top__DOT__multiregimpl120_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x15U));
    vlTOPp->top__DOT__multiregimpl119_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x14U));
    vlTOPp->top__DOT__multiregimpl117_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x12U));
    vlTOPp->top__DOT__multiregimpl116_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x11U));
    vlTOPp->top__DOT__multiregimpl115_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x10U));
    vlTOPp->top__DOT__multiregimpl112_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0xdU));
    vlTOPp->top__DOT__multiregimpl111_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0xcU));
    vlTOPp->top__DOT__multiregimpl109_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0xaU));
    vlTOPp->top__DOT__multiregimpl104_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 5U));
    vlTOPp->top__DOT__multiregimpl103_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 4U));
    vlTOPp->top__DOT__multiregimpl102_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 3U));
    vlTOPp->top__DOT__multiregimpl100_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 1U));
    vlTOPp->top__DOT__multiregimpl97_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x1eU));
    vlTOPp->top__DOT__multiregimpl96_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x1dU));
    vlTOPp->top__DOT__multiregimpl95_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x1cU));
    vlTOPp->top__DOT__multiregimpl92_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x19U));
    vlTOPp->top__DOT__multiregimpl91_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x18U));
    vlTOPp->top__DOT__multiregimpl90_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x17U));
    vlTOPp->top__DOT__multiregimpl89_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x16U));
    vlTOPp->top__DOT__multiregimpl88_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x15U));
    vlTOPp->top__DOT__multiregimpl87_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x14U));
    vlTOPp->top__DOT__multiregimpl86_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x13U));
    vlTOPp->top__DOT__multiregimpl84_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x11U));
    vlTOPp->top__DOT__multiregimpl81_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0xeU));
    vlTOPp->top__DOT__multiregimpl78_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0xbU));
    vlTOPp->top__DOT__multiregimpl76_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 9U));
    vlTOPp->top__DOT__multiregimpl75_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 8U));
    vlTOPp->top__DOT__multiregimpl73_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 6U));
    vlTOPp->top__DOT__multiregimpl72_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 5U));
    vlTOPp->top__DOT__multiregimpl71_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 4U));
    vlTOPp->top__DOT__multiregimpl70_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 3U));
    vlTOPp->top__DOT__multiregimpl69_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 2U));
    vlTOPp->top__DOT__multiregimpl67_regs0 = (1U & 
                                              vlTOPp->la_input[2U]);
    vlTOPp->top__DOT__multiregimpl66_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x1fU));
    vlTOPp->top__DOT__multiregimpl65_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x1eU));
    vlTOPp->top__DOT__multiregimpl63_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x1cU));
    vlTOPp->top__DOT__multiregimpl62_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x1bU));
    vlTOPp->top__DOT__multiregimpl61_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x1aU));
    vlTOPp->top__DOT__multiregimpl60_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x19U));
    vlTOPp->top__DOT__multiregimpl57_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x16U));
    vlTOPp->top__DOT__multiregimpl56_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x15U));
    vlTOPp->top__DOT__multiregimpl55_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x14U));
    vlTOPp->top__DOT__multiregimpl54_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x13U));
    vlTOPp->top__DOT__multiregimpl53_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x12U));
    vlTOPp->top__DOT__multiregimpl52_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x11U));
    vlTOPp->top__DOT__multiregimpl51_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x10U));
    vlTOPp->top__DOT__multiregimpl49_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0xeU));
    vlTOPp->top__DOT__multiregimpl47_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0xcU));
    vlTOPp->top__DOT__multiregimpl45_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0xaU));
    vlTOPp->top__DOT__multiregimpl41_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 6U));
    vlTOPp->top__DOT__multiregimpl36_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 1U));
    vlTOPp->top__DOT__multiregimpl35_regs0 = (1U & 
                                              vlTOPp->la_input[1U]);
    vlTOPp->top__DOT__multiregimpl27_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x18U));
    vlTOPp->top__DOT__multiregimpl24_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x15U));
    vlTOPp->top__DOT__multiregimpl23_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x14U));
    vlTOPp->top__DOT__multiregimpl21_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x12U));
    vlTOPp->top__DOT__multiregimpl20_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x11U));
    vlTOPp->top__DOT__multiregimpl18_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0xfU));
    vlTOPp->top__DOT__multiregimpl17_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0xeU));
    vlTOPp->top__DOT__multiregimpl16_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0xdU));
    vlTOPp->top__DOT__multiregimpl15_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0xcU));
    vlTOPp->top__DOT__multiregimpl14_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0xbU));
    vlTOPp->top__DOT__multiregimpl13_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0xaU));
    vlTOPp->top__DOT__multiregimpl12_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 9U));
    vlTOPp->top__DOT__multiregimpl11_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 8U));
    vlTOPp->top__DOT__multiregimpl10_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 7U));
    vlTOPp->top__DOT__multiregimpl9_regs0 = (1U & (
                                                   vlTOPp->la_input[0U] 
                                                   >> 6U));
    vlTOPp->top__DOT__multiregimpl8_regs0 = (1U & (
                                                   vlTOPp->la_input[0U] 
                                                   >> 5U));
    vlTOPp->top__DOT__multiregimpl7_regs0 = (1U & (
                                                   vlTOPp->la_input[0U] 
                                                   >> 4U));
    vlTOPp->top__DOT__multiregimpl6_regs0 = (1U & (
                                                   vlTOPp->la_input[0U] 
                                                   >> 3U));
    vlTOPp->top__DOT__multiregimpl5_regs0 = (1U & (
                                                   vlTOPp->la_input[0U] 
                                                   >> 2U));
    vlTOPp->top__DOT__multiregimpl110_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0xbU));
    vlTOPp->top__DOT__multiregimpl42_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 7U));
    vlTOPp->top__DOT__multiregimpl40_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 5U));
    vlTOPp->top__DOT__multiregimpl101_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 2U));
    vlTOPp->top__DOT__multiregimpl30_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x1bU));
    vlTOPp->top__DOT__multiregimpl29_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x1aU));
    vlTOPp->top__DOT__multiregimpl94_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x1bU));
    vlTOPp->top__DOT__multiregimpl93_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x1aU));
    vlTOPp->top__DOT__multiregimpl26_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x17U));
    vlTOPp->top__DOT__multiregimpl25_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x16U));
    vlTOPp->top__DOT__multiregimpl22_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x13U));
    vlTOPp->top__DOT__multiregimpl19_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x10U));
    vlTOPp->top__DOT__multiregimpl85_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x12U));
    vlTOPp->top__DOT__multiregimpl83_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x10U));
    vlTOPp->top__DOT__multiregimpl82_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0xfU));
    vlTOPp->top__DOT__multiregimpl80_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0xdU));
    vlTOPp->top__DOT__multiregimpl79_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0xcU));
    vlTOPp->top__DOT__multiregimpl77_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0xaU));
    vlTOPp->top__DOT__multiregimpl68_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 1U));
    vlTOPp->top__DOT__multiregimpl124_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x19U));
    vlTOPp->top__DOT__multiregimpl44_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 9U));
    vlTOPp->top__DOT__multiregimpl39_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 4U));
    vlTOPp->top__DOT__multiregimpl105_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 6U));
    vlTOPp->top__DOT__multiregimpl64_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x1dU));
    vlTOPp->top__DOT__multiregimpl38_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 3U));
    vlTOPp->top__DOT__multiregimpl4_regs0 = (1U & (
                                                   vlTOPp->la_input[0U] 
                                                   >> 1U));
    vlTOPp->top__DOT__multiregimpl37_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 2U));
    vlTOPp->top__DOT__multiregimpl3_regs0 = (1U & vlTOPp->la_input[0U]);
    vlTOPp->top__DOT__multiregimpl130_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x1fU));
    vlTOPp->top__DOT__multiregimpl59_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x18U));
    vlTOPp->top__DOT__multiregimpl58_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0x17U));
    vlTOPp->top__DOT__multiregimpl121_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x16U));
    vlTOPp->top__DOT__multiregimpl50_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0xfU));
    vlTOPp->top__DOT__multiregimpl33_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x1eU));
    vlTOPp->top__DOT__multiregimpl99_regs0 = (1U & 
                                              vlTOPp->la_input[3U]);
    vlTOPp->top__DOT__multiregimpl98_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 0x1fU));
    vlTOPp->top__DOT__multiregimpl113_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0xeU));
    vlTOPp->top__DOT__multiregimpl28_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x19U));
    vlTOPp->top__DOT__multiregimpl128_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x1dU));
    vlTOPp->top__DOT__multiregimpl118_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0x13U));
    vlTOPp->top__DOT__multiregimpl43_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 8U));
    vlTOPp->top__DOT__multiregimpl32_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x1dU));
    vlTOPp->top__DOT__multiregimpl107_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 8U));
    vlTOPp->top__DOT__multiregimpl31_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x1cU));
    vlTOPp->top__DOT__multiregimpl106_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 7U));
    vlTOPp->top__DOT__multiregimpl108_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 9U));
    vlTOPp->top__DOT__multiregimpl34_regs0 = (1U & 
                                              (vlTOPp->la_input[0U] 
                                               >> 0x1fU));
    vlTOPp->top__DOT__multiregimpl46_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0xbU));
    vlTOPp->top__DOT__multiregimpl48_regs0 = (1U & 
                                              (vlTOPp->la_input[1U] 
                                               >> 0xdU));
    vlTOPp->top__DOT__multiregimpl74_regs0 = (1U & 
                                              (vlTOPp->la_input[2U] 
                                               >> 7U));
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
    vlTOPp->top__DOT__multiregimpl114_regs0 = (1U & 
                                               (vlTOPp->la_input[3U] 
                                                >> 0xfU));
    vlTOPp->top__DOT__multiregimpl0_regs1 = vlTOPp->top__DOT__multiregimpl0_regs0;
    vlTOPp->top__DOT__mgmtsoc_uart_tx_clear = 0U;
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_re) 
         & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_r))) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_clear = 1U;
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
    vlTOPp->spiflash_cs_n = (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count));
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_done 
        = (0U == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_count));
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
    vlTOPp->top__DOT__mgmtsoc_uart_tx_trigger_d = (0x10U 
                                                   != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0));
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_trigger_d = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i 
        = ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_dq_i)) 
           | ((IData)(vlTOPp->spiflash_miso) << 1U));
    vlTOPp->top__DOT__multiregimpl1_regs1 = vlTOPp->top__DOT__multiregimpl1_regs0;
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
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 
        ((2U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status)) 
         | (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_pending));
    vlTOPp->top__DOT__mgmtsoc_uart_pending_status = 
        ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_status)) 
         | ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_pending) 
            << 1U));
    vlTOPp->top__DOT__mgmtsoc_uart_rx_trigger_d = vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_trigger_d = 0U;
    }
    if (vlTOPp->top__DOT__csrbank8_out0_re) {
        vlTOPp->top__DOT__user_irq_ena_storage = (7U 
                                                  & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__user_irq_ena_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank3_out0_re) {
        vlTOPp->top__DOT__mprj_wb_iena_storage = (1U 
                                                  & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mprj_wb_iena_storage = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg 
        = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en) 
            & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk))) 
           & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt) 
              == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)));
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg = 0U;
    }
    if (vlTOPp->top__DOT__csrbank2_ien3_re) {
        vlTOPp->top__DOT__la_ien_storage[3U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_ien2_re) {
        vlTOPp->top__DOT__la_ien_storage[2U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_ien1_re) {
        vlTOPp->top__DOT__la_ien_storage[1U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_ien0_re) {
        vlTOPp->top__DOT__la_ien_storage[0U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_ien_storage[0U] = 0U;
        vlTOPp->top__DOT__la_ien_storage[1U] = 0U;
        vlTOPp->top__DOT__la_ien_storage[2U] = 0U;
        vlTOPp->top__DOT__la_ien_storage[3U] = 0U;
    }
    if (vlTOPp->top__DOT__csrbank2_oe3_re) {
        vlTOPp->top__DOT__la_oe_storage[3U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_oe2_re) {
        vlTOPp->top__DOT__la_oe_storage[2U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_oe1_re) {
        vlTOPp->top__DOT__la_oe_storage[1U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_oe0_re) {
        vlTOPp->top__DOT__la_oe_storage[0U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_oe_storage[0U] = 0U;
        vlTOPp->top__DOT__la_oe_storage[1U] = 0U;
        vlTOPp->top__DOT__la_oe_storage[2U] = 0U;
        vlTOPp->top__DOT__la_oe_storage[3U] = 0U;
    }
    if (vlTOPp->top__DOT__csrbank2_out3_re) {
        vlTOPp->top__DOT__la_out_storage[3U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_out2_re) {
        vlTOPp->top__DOT__la_out_storage[2U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_out1_re) {
        vlTOPp->top__DOT__la_out_storage[1U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__csrbank2_out0_re) {
        vlTOPp->top__DOT__la_out_storage[0U] = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__la_out_storage[0U] = 0U;
        vlTOPp->top__DOT__la_out_storage[1U] = 0U;
        vlTOPp->top__DOT__la_out_storage[2U] = 0U;
        vlTOPp->top__DOT__la_out_storage[3U] = 0U;
    }
    if (vlTOPp->top__DOT__csrbank0_scratch0_re) {
        vlTOPp->top__DOT__mgmtsoc_scratch_storage = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_scratch_storage = 0x12345678U;
    }
    if (vlTOPp->top__DOT__csrbank0_reset0_re) {
        vlTOPp->top__DOT__mgmtsoc_reset_storage = (3U 
                                                   & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_reset_storage = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read) {
        vlTOPp->top__DOT__memdat_3 = vlTOPp->top__DOT__storage_1
            [vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_consume];
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_writable 
        = (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0));
    if (vlTOPp->top__DOT__csrbank7_ev_enable0_re) {
        vlTOPp->top__DOT__mgmtsoc_uart_enable_storage 
            = (3U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_enable_storage = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable = 1U;
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_tx_sink_ready) {
            vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable = 0U;
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable = 0U;
    }
    vlTOPp->top__DOT__multiregimpl2_regs1 = vlTOPp->top__DOT__multiregimpl2_regs0;
    if (vlTOPp->top__DOT__csrbank1_mode10_re) {
        vlTOPp->top__DOT__gpio_mode1_storage = (1U 
                                                & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_mode1_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank1_mode00_re) {
        vlTOPp->top__DOT__gpio_mode0_storage = (1U 
                                                & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_mode0_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank1_ien0_re) {
        vlTOPp->top__DOT__gpio_ien_storage = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_ien_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank1_oe0_re) {
        vlTOPp->top__DOT__gpio_oe_storage = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_oe_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank1_out0_re) {
        vlTOPp->top__DOT__gpio_out_storage = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__gpio_out_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank4_master_phyconfig0_re) {
        vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage 
            = (0xffffffU & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_phyconfig_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank4_master_cs0_re) {
        vlTOPp->top__DOT__mgmtsoc_master_cs_storage 
            = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_cs_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank4_mmap_dummy_bits0_re) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_storage 
            = (0xffU & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespimmap_storage = 0U;
    }
    if ((1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid)) 
               | (IData)(vlTOPp->top__DOT__mgmtsoc_master_rxtx_we)))) {
        vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid 
            = vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_valid;
        vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_first 
            = vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_first;
        vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_last 
            = vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_last;
        vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_payload_data 
            = vlTOPp->top__DOT__litespi_rx_demux_endpoint1_source_payload_data;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid = 0U;
        vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_payload_data = 0U;
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
    if (vlTOPp->top__DOT__csrbank6_update_value0_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_update_value_storage 
            = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_update_value_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank6_ev_enable0_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_enable_storage 
            = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_enable_storage = 0U;
    }
    if (vlTOPp->top__DOT__mgmtsoc_timer_zero_clear) {
        vlTOPp->top__DOT__mgmtsoc_timer_zero_pending = 0U;
    }
    if (((0U == vlTOPp->top__DOT__mgmtsoc_timer_value) 
         & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_timer_zero_trigger_d)))) {
        vlTOPp->top__DOT__mgmtsoc_timer_zero_pending = 1U;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_zero_pending = 0U;
    }
    vlTOPp->__Vdly__top__DOT__mgmtsoc_timer_value = 
        ((IData)(vlTOPp->top__DOT__mgmtsoc_timer_en_storage)
          ? ((0U == vlTOPp->top__DOT__mgmtsoc_timer_value)
              ? vlTOPp->top__DOT__mgmtsoc_timer_reload_storage
              : (vlTOPp->top__DOT__mgmtsoc_timer_value 
                 - (IData)(1U))) : vlTOPp->top__DOT__mgmtsoc_timer_load_storage);
    if (vlTOPp->top__DOT__mgmtsoc_timer_update_value_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_value_status 
            = vlTOPp->top__DOT__mgmtsoc_timer_value;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_value_status = 0U;
        vlTOPp->__Vdly__top__DOT__mgmtsoc_timer_value = 0U;
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
    vlTOPp->top__DOT__done = (0U == vlTOPp->top__DOT__count);
    vlTOPp->top__DOT__error = 0U;
    if ((0U == vlTOPp->top__DOT__count)) {
        vlTOPp->top__DOT__error = 1U;
    }
    vlTOPp->top__DOT__uart_bridge_done = (0U == vlTOPp->top__DOT__uart_bridge_count);
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
    vlTOPp->top__DOT__array_muxed1 = ((IData)(vlTOPp->top__DOT__grant)
                                       ? vlTOPp->top__DOT__uart_bridge_data
                                       : vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wdata);
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__decoded_rs1 
            = (0x1fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                        >> 0xfU));
        if (((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle)) 
             & (0U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                >> 0x19U))))) {
            vlTOPp->top__DOT__picorv32__DOT__decoded_rs1 
                = (0x20U | (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1));
        }
        if (((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle)) 
             & (2U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                >> 0x19U))))) {
            vlTOPp->top__DOT__picorv32__DOT__decoded_rs1 = 0x20U;
        }
    }
    if (vlTOPp->top__DOT__picorv32__DOT__mem_xfer) {
        vlTOPp->top__DOT__picorv32__DOT__next_insn_opcode 
            = vlTOPp->top__DOT__shared_dat_r;
    }
    vlTOPp->top__DOT__picorv32__DOT__last_mem_valid 
        = ((IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn) 
           & ((IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid) 
              & (~ (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack))));
    vlTOPp->top__DOT__array_muxed0 = (0x3fffffffU & 
                                      ((IData)(vlTOPp->top__DOT__grant)
                                        ? vlTOPp->top__DOT__uart_bridge_address
                                        : (vlTOPp->top__DOT__mgmtsoc_picorv32_mem_addr 
                                           >> 2U)));
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0 = __Vdly__top__DOT__mgmtsoc_uart_tx_fifo_level0;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt 
        = __Vdly__top__DOT__mgmtsoc_litespisdrphycore_cnt;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk 
        = __Vdly__top__DOT__mgmtsoc_litespisdrphycore_clk;
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en = 0U;
    if ((1U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en = 1U;
    }
    if (__Vdlyvset__top__DOT__storage_1__v0) {
        vlTOPp->top__DOT__storage_1[__Vdlyvdim0__top__DOT__storage_1__v0] 
            = __Vdlyvval__top__DOT__storage_1__v0;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_consume 
        = __Vdly__top__DOT__mgmtsoc_uart_rx_fifo_consume;
    vlTOPp->top__DOT__mgmtsoc_tx_sink_ready = 0U;
    if (vlTOPp->top__DOT__rs232phy_rs232phytx_state) {
        if (vlTOPp->top__DOT__mgmtsoc_tx_tick) {
            if ((9U == (IData)(vlTOPp->top__DOT__mgmtsoc_tx_count))) {
                vlTOPp->top__DOT__mgmtsoc_tx_sink_ready = 1U;
            }
        }
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
    vlTOPp->top__DOT__mgmtsoc_timer_zero_clear = 0U;
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_timer_pending_re) 
         & (IData)(vlTOPp->top__DOT__mgmtsoc_timer_pending_r))) {
        vlTOPp->top__DOT__mgmtsoc_timer_zero_clear = 1U;
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
}

VL_INLINE_OPT void Vtop::_sequent__TOP__4(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_sequent__TOP__4\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
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
    vlTOPp->top__DOT__multiregimpl0_regs0 = vlTOPp->serial_rx;
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
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_writable 
        = (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0));
    vlTOPp->top__DOT__multiregimpl1_regs0 = vlTOPp->serial_dbg_rx;
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
    if (vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable = 1U;
    } else {
        if (vlTOPp->top__DOT__mgmtsoc_uart_rx_clear) {
            vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable = 0U;
        }
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable = 0U;
    }
    vlTOPp->user_irq_ena = vlTOPp->top__DOT__user_irq_ena_storage;
    vlTOPp->mprj_wb_iena = vlTOPp->top__DOT__mprj_wb_iena_storage;
    if (vlTOPp->top__DOT__csrbank5_clk_divisor0_re) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage 
            = (0xffU & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage = 1U;
    }
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
    vlTOPp->top__DOT__mgmtsoc_soc_rst = 0U;
    if (vlTOPp->top__DOT__mgmtsoc_reset_re) {
        vlTOPp->top__DOT__mgmtsoc_soc_rst = (1U & (IData)(vlTOPp->top__DOT__mgmtsoc_reset_storage));
    }
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
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)) 
           & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_readable)) 
              | (IData)(vlTOPp->top__DOT__mgmtsoc_tx_sink_ready)));
    vlTOPp->top__DOT__multiregimpl2_regs0 = vlTOPp->gpio_in_pad;
    vlTOPp->gpio_mode1_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_mode1_storage)));
    vlTOPp->gpio_mode0_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_mode0_storage)));
    vlTOPp->gpio_inenb_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_ien_storage)));
    vlTOPp->gpio_outenb_pad = (1U & (~ (IData)(vlTOPp->top__DOT__gpio_oe_storage)));
    vlTOPp->gpio_out_pad = vlTOPp->top__DOT__gpio_out_storage;
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
    vlTOPp->top__DOT__mgmtsoc_timer_zero_trigger_d 
        = (0U == vlTOPp->top__DOT__mgmtsoc_timer_value);
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_zero_trigger_d = 0U;
    }
    vlTOPp->top__DOT__mgmtsoc_timer_update_value_re 
        = vlTOPp->top__DOT__csrbank6_update_value0_re;
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_update_value_re = 0U;
    }
    if (vlTOPp->top__DOT__csrbank6_en0_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_en_storage 
            = (1U & vlTOPp->top__DOT__mgmtsoc_dat_w);
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_en_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank6_reload0_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_reload_storage 
            = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_reload_storage = 0U;
    }
    if (vlTOPp->top__DOT__csrbank6_load0_re) {
        vlTOPp->top__DOT__mgmtsoc_timer_load_storage 
            = vlTOPp->top__DOT__mgmtsoc_dat_w;
    }
    if (vlTOPp->top__DOT__int_rst) {
        vlTOPp->top__DOT__mgmtsoc_timer_load_storage = 0U;
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
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs1 = vlTOPp->top__DOT__picorv32__DOT__q_insn_rs1;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rs1 
            = (0x1fU & ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                         ? (IData)(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rs1)
                         : (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1)));
    }
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
    if ((1U & ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
               | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_trap)))) {
        if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
            vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state = 0U;
        }
        if ((1U & ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
                   | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack)))) {
            vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid = 0U;
        }
        vlTOPp->top__DOT__picorv32__DOT__mem_la_secondword = 0U;
    } else {
        if (((IData)(vlTOPp->top__DOT__mgmtsoc_picorv320) 
             | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv321))) {
            vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb 
                = ((IData)(vlTOPp->top__DOT__mgmtsoc_picorv324) 
                   & (- (IData)((IData)(vlTOPp->top__DOT__mgmtsoc_picorv321))));
        }
        if ((0U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state))) {
            if ((((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch) 
                  | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst)) 
                 | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata))) {
                vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid = 1U;
                vlTOPp->top__DOT__mgmtsoc_picorv32_mem_instr 
                    = ((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch) 
                       | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst));
                vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb = 0U;
                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state = 1U;
            }
            if (vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata) {
                vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid = 1U;
                vlTOPp->top__DOT__mgmtsoc_picorv32_mem_instr = 0U;
                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state = 2U;
            }
        } else {
            if ((1U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state))) {
                if (vlTOPp->top__DOT__picorv32__DOT__mem_xfer) {
                    vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid = 0U;
                    vlTOPp->top__DOT__picorv32__DOT__mem_la_secondword = 0U;
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state 
                        = (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
                            | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata))
                            ? 0U : 3U);
                }
            } else {
                if ((2U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state))) {
                    if (vlTOPp->top__DOT__picorv32__DOT__mem_xfer) {
                        vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid = 0U;
                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state = 0U;
                    }
                } else {
                    if ((3U == (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state))) {
                        if (vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) {
                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state = 0U;
                        }
                    }
                }
            }
        }
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
    vlTOPp->top__DOT__mgmtsoc_uart_rx_clear = 0U;
    if (((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_re) 
         & ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_pending_r) 
            >> 1U))) {
        vlTOPp->top__DOT__mgmtsoc_uart_rx_clear = 1U;
    }
    vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_do_read 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)) 
           & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_syncfifo_re));
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
    vlTOPp->top__DOT__mgmtsoc_timer_value = vlTOPp->__Vdly__top__DOT__mgmtsoc_timer_value;
    vlTOPp->top__DOT__mgmtsoc_dat_w = 0U;
    if ((1U & (~ (IData)(vlTOPp->top__DOT__state)))) {
        vlTOPp->top__DOT__mgmtsoc_dat_w = vlTOPp->top__DOT__array_muxed1;
    }
    vlTOPp->top__DOT__shared_ack = ((IData)(vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_ack) 
                                    | (IData)(vlTOPp->top__DOT__mgmtsoc_wishbone_ack));
    if ((0U == vlTOPp->top__DOT__count)) {
        vlTOPp->top__DOT__shared_ack = 1U;
    }
    vlTOPp->top__DOT__picorv32__DOT__mem_state = vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_state;
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 
        ((2U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_status_status)) 
         | (0x10U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_tx_fifo_level0)));
    vlTOPp->top__DOT__mgmtsoc_uart_status_status = 
        ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_status_status)) 
         | ((IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable) 
            << 1U));
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)) 
           & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_readable)) 
              | (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_clear)));
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
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_negedge 
        = (((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_en) 
            & (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_clk)) 
           & ((IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_cnt) 
              == (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)));
    vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready = 0U;
    if ((1U != (IData)(vlTOPp->top__DOT__litespiphy_state))) {
        if ((2U == (IData)(vlTOPp->top__DOT__litespiphy_state))) {
            if (((0U < (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_storage)) 
                 | (IData)(vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_posedge_reg2))) {
                vlTOPp->top__DOT__mgmtsoc_litespisdrphycore_sink_ready = 1U;
            }
        }
    }
    vlTOPp->top__DOT__int_rst = vlTOPp->sys_rst;
    vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack = 
        ((IData)(vlTOPp->top__DOT__shared_ack) & (~ (IData)(vlTOPp->top__DOT__grant)));
    vlTOPp->top__DOT__uart_bridge_wishbone_ack = ((IData)(vlTOPp->top__DOT__shared_ack) 
                                                  & (IData)(vlTOPp->top__DOT__grant));
    if (vlTOPp->top__DOT__grant) {
        vlTOPp->top__DOT__array_muxed2 = 0xfU;
        vlTOPp->top__DOT__array_muxed5 = vlTOPp->top__DOT__uart_bridge_wishbone_we;
    } else {
        vlTOPp->top__DOT__array_muxed2 = vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb;
        vlTOPp->top__DOT__array_muxed5 = (0U != (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_wstrb));
    }
    vlTOPp->top__DOT__request = (((IData)(vlTOPp->top__DOT__uart_bridge_wishbone_cyc) 
                                  << 1U) | (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid));
    if (vlTOPp->top__DOT__grant) {
        vlTOPp->top__DOT__array_muxed4 = vlTOPp->top__DOT__uart_bridge_wishbone_stb;
        vlTOPp->top__DOT__array_muxed3 = vlTOPp->top__DOT__uart_bridge_wishbone_cyc;
    } else {
        vlTOPp->top__DOT__array_muxed4 = vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid;
        vlTOPp->top__DOT__array_muxed3 = vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid;
    }
    vlTOPp->top__DOT__mgmtsoc_picorv32_trap = 0U;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh = 0U;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out = 0U;
    vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rinst = 0U;
    vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rdata = 0U;
    vlTOPp->top__DOT__picorv32__DOT__set_mem_do_wdata = 0U;
    if (vlTOPp->top__DOT__picorv32__DOT__launch_next_insn) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val = 0U;
        vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val = 0U;
        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 0U;
        vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val_valid = 0U;
    }
    vlTOPp->top__DOT__picorv32__DOT__next_irq_pending 
        = vlTOPp->top__DOT__picorv32__DOT__irq_pending;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_trigger 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
           & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done));
    vlTOPp->top__DOT__picorv32__DOT__decoder_trigger_q 
        = vlTOPp->top__DOT__picorv32__DOT__decoder_trigger;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_pseudo_trigger = 0U;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__do_waitirq = 0U;
    if (vlTOPp->top__DOT____Vcellinp__picorv32__resetn) {
        if (((((((((0x80U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state)) 
                   | (0x40U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) 
                  | (0x20U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) 
                 | (0x10U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) 
                | (8U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) 
               | (4U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) 
              | (2U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) 
             | (1U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state)))) {
            if ((0x80U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                vlTOPp->top__DOT__mgmtsoc_picorv32_trap = 1U;
            } else {
                if ((0x40U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
                        = (1U & ((~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger)) 
                                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__do_waitirq))));
                    vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 0U;
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lu = 0U;
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lh = 0U;
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lb = 0U;
                    vlTOPp->top__DOT__picorv32__DOT__current_pc 
                        = vlTOPp->top__DOT__picorv32__DOT__reg_next_pc;
                    if (vlTOPp->top__DOT__picorv32__DOT__latched_branch) {
                        vlTOPp->top__DOT__picorv32__DOT__current_pc 
                            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_store)
                                ? (0xfffffffeU & ((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_stalu)
                                                   ? vlTOPp->top__DOT__picorv32__DOT__alu_out_q
                                                   : vlTOPp->top__DOT__picorv32__DOT__reg_out))
                                : vlTOPp->top__DOT__picorv32__DOT__reg_next_pc);
                    } else {
                        if ((1U & (~ ((IData)(vlTOPp->top__DOT__picorv32__DOT__latched_store) 
                                      & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_branch)))))) {
                            if ((1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) {
                                vlTOPp->top__DOT__picorv32__DOT__current_pc = 0x10U;
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_active = 1U;
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
                            } else {
                                if ((2U & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))) {
                                    vlTOPp->top__DOT__picorv32__DOT__next_irq_pending 
                                        = (vlTOPp->top__DOT__picorv32__DOT__next_irq_pending 
                                           & vlTOPp->top__DOT__picorv32__DOT__irq_mask);
                                    vlTOPp->top__DOT__mgmtsoc_picorv329 
                                        = (vlTOPp->top__DOT__picorv32__DOT__irq_pending 
                                           & (~ vlTOPp->top__DOT__picorv32__DOT__irq_mask));
                                }
                            }
                        }
                    }
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_pc 
                        = vlTOPp->top__DOT__picorv32__DOT__current_pc;
                    vlTOPp->top__DOT__picorv32__DOT__reg_next_pc 
                        = vlTOPp->top__DOT__picorv32__DOT__current_pc;
                    vlTOPp->top__DOT__picorv32__DOT__latched_stalu = 0U;
                    vlTOPp->top__DOT__picorv32__DOT__latched_store = 0U;
                    vlTOPp->top__DOT__picorv32__DOT__latched_branch = 0U;
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_rd 
                        = vlTOPp->top__DOT__picorv32__DOT__decoded_rd;
                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_compr 
                        = vlTOPp->top__DOT__picorv32__DOT__compressed_instr;
                    if ((((((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
                            & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_active))) 
                           & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_delay))) 
                          & (0U != (vlTOPp->top__DOT__picorv32__DOT__irq_pending 
                                    & (~ vlTOPp->top__DOT__picorv32__DOT__irq_mask)))) 
                         | (0U != (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state)))) {
                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_state 
                            = ((0U == (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))
                                ? 1U : ((1U == (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))
                                         ? 2U : 0U));
                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_compr 
                            = vlTOPp->top__DOT__picorv32__DOT__latched_compr;
                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_rd 
                            = (0x3fU & (0x20U | (1U 
                                                 & (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_state))));
                    } else {
                        if ((((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
                              | (IData)(vlTOPp->top__DOT__picorv32__DOT__do_waitirq)) 
                             & (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_waitirq))) {
                            if ((0U != vlTOPp->top__DOT__picorv32__DOT__irq_pending)) {
                                vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                    = vlTOPp->top__DOT__picorv32__DOT__irq_pending;
                                vlTOPp->top__DOT__picorv32__DOT__reg_next_pc 
                                    = (vlTOPp->top__DOT__picorv32__DOT__current_pc 
                                       + ((IData)(vlTOPp->top__DOT__picorv32__DOT__compressed_instr)
                                           ? 2U : 4U));
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
                            } else {
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__do_waitirq = 1U;
                            }
                        } else {
                            if (vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) {
                                vlTOPp->top__DOT__picorv32__DOT__irq_delay 
                                    = vlTOPp->top__DOT__picorv32__DOT__irq_active;
                                vlTOPp->top__DOT__picorv32__DOT__reg_next_pc 
                                    = (vlTOPp->top__DOT__picorv32__DOT__current_pc 
                                       + ((IData)(vlTOPp->top__DOT__picorv32__DOT__compressed_instr)
                                           ? 2U : 4U));
                                if (vlTOPp->top__DOT__picorv32__DOT__instr_jal) {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
                                    vlTOPp->top__DOT__picorv32__DOT__reg_next_pc 
                                        = (vlTOPp->top__DOT__picorv32__DOT__current_pc 
                                           + vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j);
                                    vlTOPp->top__DOT__picorv32__DOT__latched_branch = 1U;
                                } else {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 0U;
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_prefetch 
                                        = (1U & ((~ (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jalr)) 
                                                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_retirq))));
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x20U;
                                }
                            }
                        }
                    }
                } else {
                    if ((0x20U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 = 0U;
                        vlTOPp->top__DOT__picorv32__DOT__reg_op2 = 0U;
                        if (((((((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_trap) 
                                 | (IData)(vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal)) 
                                | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_getq)) 
                               | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_setq)) 
                              | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_retirq)) 
                             | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_maskirq))) {
                            if (vlTOPp->top__DOT__picorv32__DOT__instr_trap) {
                                if ((1U & ((~ (vlTOPp->top__DOT__picorv32__DOT__irq_mask 
                                               >> 1U)) 
                                           & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_active))))) {
                                    vlTOPp->top__DOT__picorv32__DOT__next_irq_pending 
                                        = (2U | vlTOPp->top__DOT__picorv32__DOT__next_irq_pending);
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                } else {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x80U;
                                }
                            } else {
                                if (vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal) {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lui)
                                            ? 0U : vlTOPp->top__DOT__picorv32__DOT__reg_pc);
                                    vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                        = vlTOPp->top__DOT__picorv32__DOT__decoded_imm;
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
                                        = vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch;
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 8U;
                                } else {
                                    if (vlTOPp->top__DOT__picorv32__DOT__instr_getq) {
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                        vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                    } else {
                                        if (vlTOPp->top__DOT__picorv32__DOT__instr_setq) {
                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_rd 
                                                = (0x20U 
                                                   | (IData)(vlTOPp->top__DOT__picorv32__DOT__latched_rd));
                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                            vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                                = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                            vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                            vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                        } else {
                                            if (vlTOPp->top__DOT__picorv32__DOT__instr_retirq) {
                                                vlTOPp->top__DOT__mgmtsoc_picorv329 = 0U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_active = 0U;
                                                vlTOPp->top__DOT__picorv32__DOT__latched_branch = 1U;
                                                vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                    = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                                vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                                    = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                                vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                            } else {
                                                if (vlTOPp->top__DOT__picorv32__DOT__instr_maskirq) {
                                                    vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                        = vlTOPp->top__DOT__picorv32__DOT__irq_mask;
                                                    vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                                        = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                                    vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                                    vlTOPp->top__DOT__picorv32__DOT__irq_mask 
                                                        = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                                } else {
                                                    vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                        = vlTOPp->top__DOT__picorv32__DOT__timer;
                                                    vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                                        = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                                    vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                                    vlTOPp->top__DOT__picorv32__DOT__timer 
                                                        = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        } else {
                            if (((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
                                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_trap)))) {
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                    = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                    = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 1U;
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
                            } else {
                                if (vlTOPp->top__DOT__picorv32__DOT__is_slli_srli_srai) {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                        = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                    vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                        = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                    vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh 
                                        = (0x1fU & (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs2));
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 4U;
                                } else {
                                    if (vlTOPp->top__DOT__picorv32__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi) {
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                        vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                            = vlTOPp->top__DOT__picorv32__DOT__decoded_imm;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
                                            = vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 8U;
                                    } else {
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs1val_valid = 1U;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh 
                                            = (0x1fU 
                                               & vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2);
                                        vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val 
                                            = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2;
                                        vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val_valid = 1U;
                                        if (vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw) {
                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 2U;
                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
                                        } else {
                                            if (vlTOPp->top__DOT__picorv32__DOT__is_sll_srl_sra) {
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 4U;
                                            } else {
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
                                                    = vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 8U;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else {
                        if ((0x10U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh 
                                = (0x1fU & vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2);
                            vlTOPp->top__DOT__picorv32__DOT__reg_op2 
                                = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2;
                            vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val 
                                = vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs2;
                            vlTOPp->top__DOT__picorv32__DOT__dbg_rs2val_valid = 1U;
                            if (vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw) {
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 2U;
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
                            } else {
                                if (vlTOPp->top__DOT__picorv32__DOT__is_sll_srl_sra) {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 4U;
                                } else {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
                                        = vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch;
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 8U;
                                }
                            }
                        } else {
                            if ((8U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                    = (vlTOPp->top__DOT__picorv32__DOT__reg_pc 
                                       + vlTOPp->top__DOT__picorv32__DOT__decoded_imm);
                                if (vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) {
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_rd = 0U;
                                    vlTOPp->top__DOT__picorv32__DOT__latched_store 
                                        = vlTOPp->top__DOT__picorv32__DOT__alu_out_0;
                                    vlTOPp->top__DOT__picorv32__DOT__latched_branch 
                                        = vlTOPp->top__DOT__picorv32__DOT__alu_out_0;
                                    if (vlTOPp->top__DOT__picorv32__DOT__mem_done) {
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                    }
                                    if (vlTOPp->top__DOT__picorv32__DOT__alu_out_0) {
                                        vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rinst = 1U;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_trigger = 0U;
                                    }
                                } else {
                                    vlTOPp->top__DOT__picorv32__DOT__latched_branch 
                                        = vlTOPp->top__DOT__picorv32__DOT__instr_jalr;
                                    vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                    vlTOPp->top__DOT__picorv32__DOT__latched_stalu = 1U;
                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                }
                            } else {
                                if ((4U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                                    vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                    if ((0U == (IData)(vlTOPp->top__DOT__picorv32__DOT__reg_sh))) {
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                            = vlTOPp->top__DOT__picorv32__DOT__reg_op1;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst 
                                            = vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch;
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                    } else {
                                        if (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slli) 
                                             | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sll))) {
                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                                = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                   << 1U);
                                        } else {
                                            if (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srli) 
                                                 | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srl))) {
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                                    = 
                                                    (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                     >> 1U);
                                            } else {
                                                if (
                                                    ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_srai) 
                                                     | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sra))) {
                                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                                        = 
                                                        VL_SHIFTRS_III(32,32,32, vlTOPp->top__DOT__picorv32__DOT__reg_op1, 1U);
                                                }
                                            }
                                        }
                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh 
                                            = (0x1fU 
                                               & ((IData)(vlTOPp->top__DOT__picorv32__DOT__reg_sh) 
                                                  - (IData)(1U)));
                                    }
                                } else {
                                    if ((2U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state))) {
                                        if ((1U & (
                                                   (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch)) 
                                                   | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done)))) {
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata)))) {
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                                    = 
                                                    (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                     + vlTOPp->top__DOT__picorv32__DOT__decoded_imm);
                                                vlTOPp->top__DOT__picorv32__DOT__set_mem_do_wdata = 1U;
                                                if (vlTOPp->top__DOT__picorv32__DOT__instr_sb) {
                                                    vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 2U;
                                                } else {
                                                    if (vlTOPp->top__DOT__picorv32__DOT__instr_sh) {
                                                        vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 1U;
                                                    } else {
                                                        if (vlTOPp->top__DOT__picorv32__DOT__instr_sw) {
                                                            vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 0U;
                                                        }
                                                    }
                                                }
                                            }
                                            if (((~ (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch)) 
                                                 & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_trigger = 1U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_pseudo_trigger = 1U;
                                            }
                                        }
                                    } else {
                                        vlTOPp->top__DOT__picorv32__DOT__latched_store = 1U;
                                        if ((1U & (
                                                   (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch)) 
                                                   | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done)))) {
                                            if (((~ (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch)) 
                                                 & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
                                                if (vlTOPp->top__DOT__picorv32__DOT__latched_is_lu) {
                                                    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                        = vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word;
                                                } else {
                                                    if (vlTOPp->top__DOT__picorv32__DOT__latched_is_lh) {
                                                        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                            = 
                                                            VL_EXTENDS_II(32,16, 
                                                                          (0xffffU 
                                                                           & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word));
                                                    } else {
                                                        if (vlTOPp->top__DOT__picorv32__DOT__latched_is_lb) {
                                                            vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out 
                                                                = 
                                                                VL_EXTENDS_II(32,8, 
                                                                              (0xffU 
                                                                               & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_word));
                                                        }
                                                    }
                                                }
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_trigger = 1U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_pseudo_trigger = 1U;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
                                            }
                                            if ((1U 
                                                 & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata)))) {
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1 
                                                    = 
                                                    (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                     + vlTOPp->top__DOT__picorv32__DOT__decoded_imm);
                                                vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rdata = 1U;
                                                if (
                                                    ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lb) 
                                                     | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lbu))) {
                                                    vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 2U;
                                                } else {
                                                    if (
                                                        ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lh) 
                                                         | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lhu))) {
                                                        vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 1U;
                                                    } else {
                                                        if (vlTOPp->top__DOT__picorv32__DOT__instr_lw) {
                                                            vlTOPp->top__DOT__picorv32__DOT__mem_wordsize = 0U;
                                                        }
                                                    }
                                                }
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lu 
                                                    = vlTOPp->top__DOT__picorv32__DOT__is_lbu_lhu_lw;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lh 
                                                    = vlTOPp->top__DOT__picorv32__DOT__instr_lh;
                                                vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lb 
                                                    = vlTOPp->top__DOT__picorv32__DOT__instr_lb;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    } else {
        vlTOPp->top__DOT__picorv32__DOT__next_irq_pending = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_pc = 0U;
        vlTOPp->top__DOT__picorv32__DOT__reg_next_pc = 0U;
        vlTOPp->top__DOT__picorv32__DOT__latched_store = 0U;
        vlTOPp->top__DOT__picorv32__DOT__latched_stalu = 0U;
        vlTOPp->top__DOT__picorv32__DOT__latched_branch = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lu = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lh = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lb = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_active = 0U;
        vlTOPp->top__DOT__picorv32__DOT__irq_delay = 0U;
        vlTOPp->top__DOT__picorv32__DOT__irq_mask = 0xffffffffU;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_state = 0U;
        vlTOPp->top__DOT__mgmtsoc_picorv329 = 0U;
        vlTOPp->top__DOT__picorv32__DOT__timer = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state = 0x40U;
    }
    vlTOPp->top__DOT__picorv32__DOT__next_irq_pending 
        = (vlTOPp->top__DOT__picorv32__DOT__next_irq_pending 
           | vlTOPp->top__DOT__mgmtsoc_picorv32_interrupt);
    if ((1U & ((~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)) 
               | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done)))) {
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_prefetch = 0U;
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 0U;
        vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata = 0U;
        vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata = 0U;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rinst) {
        vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst = 1U;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__set_mem_do_rdata) {
        vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata = 1U;
    }
    if (vlTOPp->top__DOT__picorv32__DOT__set_mem_do_wdata) {
        vlTOPp->top__DOT__picorv32__DOT__mem_do_wdata = 1U;
    }
    vlTOPp->top__DOT__picorv32__DOT__irq_pending = vlTOPp->top__DOT__picorv32__DOT__next_irq_pending;
    vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_pc 
        = (0xfffffffcU & vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_pc);
    vlTOPp->top__DOT__picorv32__DOT__reg_next_pc = 
        (0xfffffffcU & vlTOPp->top__DOT__picorv32__DOT__reg_next_pc);
    vlTOPp->top__DOT__picorv32__DOT__current_pc = 0U;
    vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_do_read 
        = ((0U != (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_level0)) 
           & (IData)(vlTOPp->top__DOT__mgmtsoc_uart_rx_fifo_syncfifo_re));
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
    vlTOPp->top__DOT__mgmtsoc_litespimmap_bus_cyc = 
        ((IData)(vlTOPp->top__DOT__array_muxed3) & (IData)(vlTOPp->top__DOT__slave_sel));
    vlTOPp->top__DOT__mgmtsoc_wishbone_cyc = ((IData)(vlTOPp->top__DOT__array_muxed3) 
                                              & ((IData)(vlTOPp->top__DOT__slave_sel) 
                                                 >> 1U));
    vlTOPp->top__DOT__picorv32__DOT__reg_sh = vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_sh;
    vlTOPp->top__DOT__picorv32__DOT__do_waitirq = vlTOPp->__Vdly__top__DOT__picorv32__DOT__do_waitirq;
    vlTOPp->top__DOT__picorv32__DOT__latched_is_lu 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lu;
    vlTOPp->top__DOT__picorv32__DOT__latched_is_lh 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lh;
    vlTOPp->top__DOT__picorv32__DOT__latched_is_lb 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_is_lb;
    vlTOPp->top__DOT__picorv32__DOT__latched_rd = vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_rd;
    vlTOPp->top__DOT__picorv32__DOT__cpuregs_rs1 = 
        ((0U != (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1))
          ? ((0x23U >= (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rs1))
              ? vlTOPp->top__DOT__picorv32__DOT__cpuregs
             [vlTOPp->top__DOT__picorv32__DOT__decoded_rs1]
              : 0U) : 0U);
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
    vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_prefetch;
    vlTOPp->top__DOT__picorv32__DOT__irq_active = vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_active;
    vlTOPp->top__DOT__picorv32__DOT__reg_pc = vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_pc;
    vlTOPp->top__DOT__picorv32__DOT__latched_compr 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__latched_compr;
    vlTOPp->top__DOT__picorv32__DOT__reg_out = vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_out;
    vlTOPp->top__DOT__picorv32__DOT__irq_state = vlTOPp->__Vdly__top__DOT__picorv32__DOT__irq_state;
    vlTOPp->top__DOT__picorv32__DOT__cpu_state = vlTOPp->__Vdly__top__DOT__picorv32__DOT__cpu_state;
    vlTOPp->top__DOT__picorv32__DOT__reg_op1 = vlTOPp->__Vdly__top__DOT__picorv32__DOT__reg_op1;
    vlTOPp->top__DOT__mgmtsoc_master_status_status = 0U;
    vlTOPp->top__DOT__mgmtsoc_master_status_status 
        = ((2U & (IData)(vlTOPp->top__DOT__mgmtsoc_master_status_status)) 
           | (1U & ((~ (IData)(vlTOPp->top__DOT__mgmtsoc_master_tx_fifo_source_valid)) 
                    | (IData)(vlTOPp->top__DOT__litespi_tx_mux_endpoint1_sink_ready))));
    vlTOPp->top__DOT__mgmtsoc_master_status_status 
        = ((1U & (IData)(vlTOPp->top__DOT__mgmtsoc_master_status_status)) 
           | ((IData)(vlTOPp->top__DOT__mgmtsoc_master_rx_fifo_source_valid) 
              << 1U));
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
    vlTOPp->top__DOT__picorv32__DOT__alu_out_q = vlTOPp->top__DOT__picorv32__DOT__alu_out;
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__compressed_instr = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__decoded_rd 
            = (0x1fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                        >> 7U));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__decoded_rs2 
            = (0x1fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                        >> 0x14U));
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
    vlTOPp->top__DOT__picorv32__DOT__alu_eq = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                               == vlTOPp->top__DOT__picorv32__DOT__reg_op2);
    vlTOPp->top__DOT__picorv32__DOT__alu_lts = VL_LTS_III(1,32,32, vlTOPp->top__DOT__picorv32__DOT__reg_op1, vlTOPp->top__DOT__picorv32__DOT__reg_op2);
    vlTOPp->top__DOT__picorv32__DOT__alu_ltu = (vlTOPp->top__DOT__picorv32__DOT__reg_op1 
                                                < vlTOPp->top__DOT__picorv32__DOT__reg_op2);
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_waitirq 
            = ((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle)) 
               & (4U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                  >> 0x19U))));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_retirq 
            = ((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle)) 
               & (2U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                  >> 0x19U))));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_getq 
            = ((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q)) 
               & (0U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                  >> 0x19U))));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_setq 
            = ((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q)) 
               & (1U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                  >> 0x19U))));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_maskirq 
            = ((0xbU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q)) 
               & (3U == (0x7fU & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                  >> 0x19U))));
    }
    vlTOPp->top__DOT__picorv32__DOT__is_lbu_lhu_lw 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lbu) 
           | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lhu) 
              | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lw)));
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
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rd = vlTOPp->top__DOT__picorv32__DOT__q_insn_rd;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_rd 
            = (0x1fU & ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                         ? (IData)(vlTOPp->top__DOT__picorv32__DOT__cached_insn_rd)
                         : (IData)(vlTOPp->top__DOT__picorv32__DOT__decoded_rd)));
    }
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
    vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lui) 
           | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_auipc) 
              | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jal)));
    vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal_jalr_addi_add_sub 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lui) 
           | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_auipc) 
              | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jal) 
                 | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jalr) 
                    | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_addi) 
                       | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_add) 
                          | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sub)))))));
    vlTOPp->top__DOT__picorv32__DOT__is_slti_blt_slt 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slti) 
           | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_blt) 
              | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slt)));
    vlTOPp->top__DOT__picorv32__DOT__is_sltiu_bltu_sltu 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sltiu) 
           | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_bltu) 
              | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sltu)));
    vlTOPp->top__DOT__picorv32__DOT__is_compare = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
                                                   | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slti) 
                                                      | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_slt) 
                                                         | ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sltiu) 
                                                            | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_sltu)))));
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_beq 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (0U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_bne 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (1U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_blt 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (4U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_bge 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (5U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_bltu 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (6U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_bgeu 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu) 
               & (7U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_lb = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
             & (0U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                             >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_lh = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
             & (1U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                             >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_lw = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
             & (2U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                             >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_lbu 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
               & (4U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_lhu 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
               & (5U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sb = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw) 
             & (0U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                             >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sh = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw) 
             & (1U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                             >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sw = 
            ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw) 
             & (2U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                             >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_addi 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & (0U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_slti 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & (2U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sltiu 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & (3U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_xori 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & (4U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_ori 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & (6U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_andi 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & (7U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                               >> 0xcU))));
        vlTOPp->top__DOT__picorv32__DOT__instr_slli 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm))) 
                       & (0x1000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_srli 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm))) 
                       & (0x5000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_srai 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm))) 
                       & (0x40005000U == (0xfe007000U 
                                          & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__is_slli_srli_srai 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
               & ((IData)((0x1000U == (0xfe007000U 
                                       & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))) 
                  | ((IData)((0x5000U == (0xfe007000U 
                                          & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))) 
                     | (IData)((0x40005000U == (0xfe007000U 
                                                & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))))));
        vlTOPp->top__DOT__picorv32__DOT__is_jalr_addi_slti_sltiu_xori_ori_andi 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jalr) 
               | ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm) 
                  & ((0U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                   >> 0xcU))) | ((2U 
                                                  == 
                                                  (7U 
                                                   & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                      >> 0xcU))) 
                                                 | ((3U 
                                                     == 
                                                     (7U 
                                                      & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                         >> 0xcU))) 
                                                    | ((4U 
                                                        == 
                                                        (7U 
                                                         & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                            >> 0xcU))) 
                                                       | ((6U 
                                                           == 
                                                           (7U 
                                                            & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                               >> 0xcU))) 
                                                          | (7U 
                                                             == 
                                                             (7U 
                                                              & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                                 >> 0xcU))))))))));
        vlTOPp->top__DOT__picorv32__DOT__is_lui_auipc_jal_jalr_addi_add_sub = 0U;
        vlTOPp->top__DOT__picorv32__DOT__is_compare = 0U;
        vlTOPp->top__DOT__picorv32__DOT__decoded_imm 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jal)
                ? vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j
                : (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_lui) 
                    | (IData)(vlTOPp->top__DOT__picorv32__DOT__instr_auipc))
                    ? (0xfffff000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q)
                    : (((IData)(vlTOPp->top__DOT__picorv32__DOT__instr_jalr) 
                        | ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu) 
                           | (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm)))
                        ? VL_EXTENDS_II(32,12, (0xfffU 
                                                & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                   >> 0x14U)))
                        : ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu)
                            ? VL_EXTENDS_II(32,13, 
                                            ((0x1000U 
                                              & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                 >> 0x13U)) 
                                             | ((0x800U 
                                                 & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                    << 4U)) 
                                                | ((0x7e0U 
                                                    & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                       >> 0x14U)) 
                                                   | (0x1eU 
                                                      & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                         >> 7U))))))
                            : ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw)
                                ? VL_EXTENDS_II(32,12, 
                                                ((0xfe0U 
                                                  & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
                                                       >> 7U))))
                                : 0U)))));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
        vlTOPp->top__DOT__picorv32__DOT__is_compare = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_beq = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_bne = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_blt = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_bge = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_bltu = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_bgeu = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_addi = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_slti = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_sltiu = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_xori = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_ori = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_andi = 0U;
    }
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
    vlTOPp->top__DOT__picorv32__DOT__dbg_insn_imm = vlTOPp->top__DOT__picorv32__DOT__q_insn_imm;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_insn_imm 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                ? vlTOPp->top__DOT__picorv32__DOT__cached_insn_imm
                : vlTOPp->top__DOT__picorv32__DOT__decoded_imm);
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_imm 
            = (0x13U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__is_lb_lh_lw_lbu_lhu 
            = (3U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__is_sb_sh_sw 
            = (0x23U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j 
            = ((0xfffffU & vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j) 
               | (0xfff00000U & VL_EXTENDS_II(32,21, 
                                              (0x1ffffeU 
                                               & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                                  >> 0xbU)))));
        vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j 
            = ((0xfffff801U & vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j) 
               | (0x7feU & (VL_EXTENDS_II(32,21, (0x1ffffeU 
                                                  & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                                     >> 0xbU))) 
                            >> 9U)));
        vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j 
            = ((0xfffff7ffU & vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j) 
               | (0x800U & (VL_EXTENDS_II(32,21, (0x1ffffeU 
                                                  & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                                     >> 0xbU))) 
                            << 2U)));
        vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j 
            = ((0xfff00fffU & vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j) 
               | (0xff000U & (VL_EXTENDS_II(32,21, 
                                            (0x1ffffeU 
                                             & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                                >> 0xbU))) 
                              << 0xbU)));
        vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j 
            = ((0xfffffffeU & vlTOPp->top__DOT__picorv32__DOT__decoded_imm_j) 
               | (1U & VL_EXTENDS_II(1,21, (0x1ffffeU 
                                            & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                                               >> 0xbU)))));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu 
            = (0x63U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
        vlTOPp->top__DOT__picorv32__DOT__is_beq_bne_blt_bge_bltu_bgeu = 0U;
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_auipc 
            = (0x17U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_lui 
            = (0x37U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_jal 
            = (0x6fU == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_jalr 
            = ((0x67U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle)) 
               & (0U == (7U & (vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
                               >> 0xcU))));
    }
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger) 
         & (~ (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_add 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sub 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x40000000U == (0xfe007000U 
                                          & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sll 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x1000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_slt 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x2000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sltu 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x3000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_xor 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x4000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_srl 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x5000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_sra 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x40005000U == (0xfe007000U 
                                          & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_or = (IData)(
                                                            ((1U 
                                                              == 
                                                              (1U 
                                                               & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                                                             & (0x6000U 
                                                                == 
                                                                (0xfe007000U 
                                                                 & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__instr_and 
            = (IData)(((1U == (1U & (IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg))) 
                       & (0x7000U == (0xfe007000U & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))));
        vlTOPp->top__DOT__picorv32__DOT__is_sll_srl_sra 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg) 
               & ((IData)((0x1000U == (0xfe007000U 
                                       & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))) 
                  | ((IData)((0x5000U == (0xfe007000U 
                                          & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))) 
                     | (IData)((0x40005000U == (0xfe007000U 
                                                & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q))))));
    }
    if ((1U & (~ (IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn)))) {
        vlTOPp->top__DOT__picorv32__DOT__instr_add = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_sub = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_sll = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_slt = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_sltu = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_xor = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_srl = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_sra = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_or = 0U;
        vlTOPp->top__DOT__picorv32__DOT__instr_and = 0U;
    }
    vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_pseudo_trigger;
    vlTOPp->top__DOT__picorv32__DOT__decoder_trigger 
        = vlTOPp->__Vdly__top__DOT__picorv32__DOT__decoder_trigger;
    vlTOPp->top__DOT____Vcellinp__picorv32__resetn 
        = (1U & (~ ((IData)(vlTOPp->top__DOT__int_rst) 
                    | ((IData)(vlTOPp->top__DOT__mgmtsoc_soc_rst) 
                       | ((IData)(vlTOPp->top__DOT__mgmtsoc_reset_storage) 
                          >> 1U)))));
    vlTOPp->top__DOT__picorv32__DOT__launch_next_insn 
        = (((0x40U == (IData)(vlTOPp->top__DOT__picorv32__DOT__cpu_state)) 
            & (IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_trigger)) 
           & (((IData)(vlTOPp->top__DOT__picorv32__DOT__irq_delay) 
               | (IData)(vlTOPp->top__DOT__picorv32__DOT__irq_active)) 
              | (~ (IData)((0U != (vlTOPp->top__DOT__picorv32__DOT__irq_pending 
                                   & (~ vlTOPp->top__DOT__picorv32__DOT__irq_mask)))))));
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
    if (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
         & (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_done))) {
        vlTOPp->top__DOT__picorv32__DOT__is_alu_reg_reg 
            = (0x33U == (0x7fU & vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle));
    }
    if (vlTOPp->top__DOT__picorv32__DOT__mem_xfer) {
        vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q 
            = vlTOPp->top__DOT__shared_dat_r;
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
    vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst = vlTOPp->__Vdly__top__DOT__picorv32__DOT__mem_do_rinst;
    vlTOPp->top__DOT__picorv32__DOT__mem_xfer = ((IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_mem_valid) 
                                                 & (IData)(vlTOPp->top__DOT__mgmtsoc_picorv32_idbus_ack));
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
    vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_instr 
        = vlTOPp->top__DOT__picorv32__DOT__q_ascii_instr;
    if (vlTOPp->top__DOT__picorv32__DOT__dbg_next) {
        vlTOPp->top__DOT__picorv32__DOT__dbg_ascii_instr 
            = ((IData)(vlTOPp->top__DOT__picorv32__DOT__decoder_pseudo_trigger_q)
                ? vlTOPp->top__DOT__picorv32__DOT__cached_ascii_instr
                : vlTOPp->top__DOT__picorv32__DOT__new_ascii_instr);
    }
    vlTOPp->top__DOT__mgmtsoc_picorv320 = ((IData)(vlTOPp->top__DOT____Vcellinp__picorv32__resetn) 
                                           & ((~ (IData)(
                                                         (0U 
                                                          != (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_state)))) 
                                              & (((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rinst) 
                                                  | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_prefetch)) 
                                                 | (IData)(vlTOPp->top__DOT__picorv32__DOT__mem_do_rdata))));
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
    vlTOPp->top__DOT__picorv32__DOT__mem_rdata_latched_noshuffle 
        = ((IData)(vlTOPp->top__DOT__picorv32__DOT__mem_xfer)
            ? vlTOPp->top__DOT__shared_dat_r : vlTOPp->top__DOT__picorv32__DOT__mem_rdata_q);
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
}
