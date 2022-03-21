/*
 * SPDX-FileCopyrightText: 2020 Efabless Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <csr.h>
#include <soc.h>
#include <irq_vex.h>
#include <uart.h>

#include <defs.h>

#include <stub.c>

// -------------------------------------------------------------------------
// Test IRQ callback
// -------------------------------------------------------------------------

extern uint16_t flag;

void main()
{
    uint16_t data;
    int i;

    uint32_t error = 0;

    reg_la1_data = 0x5;	// Signal start of test
    reg_la0_data = 0;
    flag = 0;

    irq_setmask(0);
	irq_setie(1);

    // Timer IRQ

    // unmask the timer irq
    irq_setmask(1 << TIMER0_INTERRUPT);

    /* Configure timer for a single-shot countdown */
	reg_timer0_config = 0;
	reg_timer0_data = 3000;
    reg_timer0_irq_en = 1;
    reg_timer0_config = 1;

    // Loop, waiting for the interrupt to change reg_mprj_datah
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    reg_la0_data = 0x40000;

    // UART IRQ

    // reset the flag (set by the ISR)
    flag = 0;
    uart_ev_enable_write(0);

    // clear pending irqs
    uart_ev_pending_write(0x3);
    uart_ev_pending_write(0);
    // unmask the UART irq
    irq_setmask(1 << UART_INTERRUPT);

    // enable UART's TX interrupt
    // this irq is set when there is a full->not-full transaction in the TX-FIFO state
    uart_ev_enable_tx_write(1);

    // send a message - force the TX-FIFO in full state
    print("0123456789abcdef0123456789abcdef0123456789abcdef0123456789abcdef");
    reg_uart_enable = 1;

    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    reg_la0_data = 0x50000;

    // clear pending irqs
    uart_ev_pending_write(0x3);
    uart_ev_pending_write(0);

    // USER IRQ

    user_irq_ena_out_write(0);
    if (user_irq_0_in_read())
        error = 1;
    if (user_irq_1_in_read())
        error = 1;
    if (user_irq_2_in_read())
        error = 1;
    if (user_irq_3_in_read())
        error = 1;
    if (user_irq_4_in_read())
        error = 1;
    if (user_irq_5_in_read())
        error = 1;

    reg_la0_data = 0x60000;

    // irq0
    flag = 0;
    user_irq_0_ev_enable_write(1);
    user_irq_ena_out_write(1);
    irq_setmask(1 << USER_IRQ_0_INTERRUPT);
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    if (user_irq_0_in_read() == 0)
        error = 2;
    if (flag == 0)
        error = 3;
    user_irq_0_ev_enable_write(0);
    user_irq_ena_out_write(0);
    reg_la0_data = 0x70000;

    // irq1
    flag = 0;
    user_irq_1_ev_enable_write(1);
    user_irq_ena_out_write(2);
    irq_setmask(1 << USER_IRQ_1_INTERRUPT);
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    if (user_irq_1_in_read() == 0)
        error = 2;
    user_irq_1_ev_enable_write(0);
    if (flag == 0)
        error = 3;
    user_irq_ena_out_write(0);
    reg_la0_data = 0x80000;

    // irq2
    flag = 0;
    user_irq_2_ev_enable_write(1);
    user_irq_ena_out_write(3);
    irq_setmask(1 << USER_IRQ_2_INTERRUPT);
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    if (user_irq_2_in_read() == 0)
        error = 2;
    if (flag == 0)
        error = 3;
    user_irq_2_ev_enable_write(0);
    user_irq_ena_out_write(0);
    reg_la0_data = 0x90000;

    // irq3
    flag = 0;
    user_irq_3_ev_enable_write(1);
    user_irq_ena_out_write(4);
    irq_setmask(1 << USER_IRQ_3_INTERRUPT);
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    if (user_irq_3_in_read() == 0)
        error = 2;
    if (flag == 0)
        error = 3;
    user_irq_3_ev_enable_write(0);
    user_irq_ena_out_write(0);
    reg_la0_data = 0xA0000;

    // irq4
    flag = 0;
    user_irq_4_ev_enable_write(1);
    user_irq_ena_out_write(5);
    irq_setmask(1 << USER_IRQ_4_INTERRUPT);
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    if (user_irq_4_in_read() == 0)
        error = 2;
    if (flag == 0)
        error = 3;
    user_irq_4_ev_enable_write(0);
    user_irq_ena_out_write(0);
    reg_la0_data = 0xB0000;

    // irq5
    flag = 0;
    user_irq_5_ev_enable_write(1);
    user_irq_ena_out_write(6);
    irq_setmask(1 << USER_IRQ_5_INTERRUPT);
    while (flag == 0) {
        reg_la0_data = 0x10000;
    }
    if (user_irq_5_in_read() == 0)
        error = 2;
    if (flag == 0)
        error = 3;
    user_irq_5_ev_enable_write(0);
    user_irq_ena_out_write(0);
    reg_la0_data = 0xC0000;

    reg_la1_data = 0xc;	// Signal end of test
}

