// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop.h"
#include "Vtop__Syms.h"

void Vtop::_eval(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->sys_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__sys_clk)))) {
        vlTOPp->_sequent__TOP__3(vlSymsp);
        vlTOPp->__Vm_traceActivity[1U] = 1U;
        vlTOPp->_sequent__TOP__4(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__sys_clk = vlTOPp->sys_clk;
}

VL_INLINE_OPT QData Vtop::_change_request(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vtop::_change_request_1(Vtop__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_change_request_1\n"); );
    Vtop* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vtop::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((sys_clk & 0xfeU))) {
        Verilated::overWidthError("sys_clk");}
    if (VL_UNLIKELY((sys_rst & 0xfeU))) {
        Verilated::overWidthError("sys_rst");}
    if (VL_UNLIKELY((serial_rx & 0xfeU))) {
        Verilated::overWidthError("serial_rx");}
    if (VL_UNLIKELY((spiflash_miso & 0xfeU))) {
        Verilated::overWidthError("spiflash_miso");}
    if (VL_UNLIKELY((spiflash_wp & 0xfeU))) {
        Verilated::overWidthError("spiflash_wp");}
    if (VL_UNLIKELY((spiflash_hold & 0xfeU))) {
        Verilated::overWidthError("spiflash_hold");}
    if (VL_UNLIKELY((serial_dbg_rx & 0xfeU))) {
        Verilated::overWidthError("serial_dbg_rx");}
    if (VL_UNLIKELY((gpio_in_pad & 0xfeU))) {
        Verilated::overWidthError("gpio_in_pad");}
}
#endif  // VL_DEBUG
