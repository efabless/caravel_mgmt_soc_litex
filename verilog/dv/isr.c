// This file is Copyright (c) 2020 Florent Kermarrec <florent@enjoy-digital.fr>
// License: BSD

#include <generated/csr.h>
#include <generated/soc.h>
#include <irq_vex.h>
#include <uart.h>
#include <defs.h>

void isr(void);

#ifdef CONFIG_CPU_HAS_INTERRUPT

uint16_t flag;

void isr(void)
{
	__attribute__((unused)) unsigned int irqs;

	irqs = irq_pending() & irq_getmask();

    reg_timer0_irq_en = 0; // disable interrupt

    reg_la1_data = 0xa;
    reg_la0_data = 0x20000;
    flag = 1;

//	if(irqs & (1 << TIMER0_INTERRUPT)) {
////		uart_isr();
//        reg_la1_data = 0xa;	// Signal end of test 1st stage
//        reg_la0_data = 0x20000;
//        flag = 1;
//    }
    return;

//#ifndef UART_POLLING
//	if(irqs & (1 << UART_INTERRUPT))
//		uart_isr();
//#endif
}

#else

void isr(void){};

#endif
