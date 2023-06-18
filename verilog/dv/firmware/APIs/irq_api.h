
/**
 \file
*/
#ifndef IRQ_API_C_HEADER_FILE
#define IRQ_API_C_HEADER_FILE
// IRQ 
#ifndef DOXYGEN_SHOULD_SKIP_THIS
extern unsigned int flag;
char IRQ_getFlag(){
    return flag;
}

void IRQ_clearFlag(){
    flag=0;
}
#endif /* DOXYGEN_SHOULD_SKIP_THIS */
/**
 * Enable or disable external1 interrupt GPIO[7] 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableExternal1(bool is_enable){
    if (is_enable){
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << USER_IRQ_4_INTERRUPT));
        reg_user4_irq_en =1;
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << USER_IRQ_4_INTERRUPT));
        reg_user4_irq_en =0;
        user_irq_4_ev_pending_i0_write(1); // to clear the interrupt
    }
}

/**
 * Enable or disable external2 interrupt GPIO[12] 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableExternal2(bool is_enable){
    if (is_enable){
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << USER_IRQ_5_INTERRUPT));
        reg_user5_irq_en =1;
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << USER_IRQ_5_INTERRUPT));
        reg_user5_irq_en =0;
        user_irq_5_ev_pending_i0_write(1); // to clear the interrupt
    }    
}
/**
 * Enable or disable user0 interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableUser0(bool is_enable){
    if (is_enable){
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << USER_IRQ_0_INTERRUPT));
        reg_user0_irq_en =1;
        reg_user_irq_enable |=0x1;
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(0 << USER_IRQ_0_INTERRUPT));
        reg_user0_irq_en =0;
        reg_user_irq_enable &=0x6;
        user_irq_0_ev_pending_i0_write(1); // to clear the interrupt
    }    
}
/**
 * Enable or disable user1 interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableUser1(bool is_enable){
    if (is_enable){
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << USER_IRQ_1_INTERRUPT));
        reg_user1_irq_en =1;
        reg_user_irq_enable |=0x2;
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << USER_IRQ_1_INTERRUPT));
        reg_user1_irq_en =0;
        reg_user_irq_enable &=0x5;
        user_irq_1_ev_pending_i0_write(1); // to clear the interrupt
    }    
}

/**
 * Enable or disable user1 interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableUser2(bool is_enable){
    if (is_enable){
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << USER_IRQ_2_INTERRUPT));
        reg_user2_irq_en =1;
        reg_user_irq_enable |=0x4;
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << USER_IRQ_2_INTERRUPT));
        reg_user2_irq_en =0;
        reg_user_irq_enable &=0x3;
        user_irq_2_ev_pending_i0_write(1); // to clear the interrupt
    }    
}
/**
 * Enable or disable timer0 interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableTimer(bool is_enable){
    if (is_enable){
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << TIMER0_INTERRUPT));
        reg_timer0_irq_en = 1;
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << TIMER0_INTERRUPT));
        reg_timer0_irq_en = 0;
        timer0_ev_pending_zero_write(1); // to clear the interrupt
    }
}
/**
 * Enable or disable UART tx interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableUartTx(bool is_enable){
    if (is_enable){
        reg_uart_enable = 1;
        reg_uart_irq_en =1;
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << UART_INTERRUPT));
    }else{
        reg_uart_irq_en =0;
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << UART_INTERRUPT));
        uart_ev_pending_tx_write(1);    // to clear the interrupt
    }
}
/**
 * Enable or disable UART rx interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_enableUartRx(bool is_enable){
    if (is_enable){
        reg_uart_enable = 1;
        reg_uart_irq_en =1;
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << UART_INTERRUPT));
    }else{
        reg_uart_enable = 1;
        reg_uart_irq_en =1;
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << UART_INTERRUPT));
        uart_ev_pending_rx_write(1);    // to clear the interrupt
    }
}
/**
 * Enable or disable SPI interrupt 
 * 
 *  
 * @param is_enable when 1 (true) interrupt is active and firmware would detect if happened, 0 (false) interrupt is disabled and firmware would not detect if happened
 */
void IRQ_hkSpi(bool is_enable){
    if (is_enable){
        reg_user3_irq_en =1;
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() | (1 << USER_IRQ_3_INTERRUPT));
    }else{
        irq_setmask(0);
        irq_setie(1);
        irq_setmask(irq_getmask() & ~(1 << USER_IRQ_3_INTERRUPT));
        reg_user3_irq_en =0;
        user_irq_3_ev_pending_i0_write(1); // to clear the interrupt
    }
}

#endif // IRQ_API_C_HEADER_FILE
