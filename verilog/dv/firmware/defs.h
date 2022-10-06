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

#ifndef _DEF_H_
#define _DEF_H_

#include <stdint.h>
#include <stdbool.h>

#include <csr.h>
#include <caravel.h>

// a pointer to this is a null pointer, but the compiler does not
// know that because "sram" is a linker symbol from sections.lds.
extern uint32_t sram;

// Pointer to firmware flash routines
extern uint32_t flashio_worker_begin;
extern uint32_t flashio_worker_end;

// Storage area (MGMT: 0x0100_0000, User: 0x0200_0000)
#define reg_rw_block0  (*(volatile uint32_t*)0x01000000)
#define reg_rw_block1  (*(volatile uint32_t*)0x01100000)
#define reg_ro_block0  (*(volatile uint32_t*)0x02000000)

// UART (0x2000_0000)
#define reg_uart_data   (*(volatile uint32_t*) CSR_UART_RXTX_ADDR)
#define reg_uart_txfull   (*(volatile uint32_t*) CSR_UART_TXFULL_ADDR)
#define reg_uart_enable (*(volatile uint32_t*) CSR_UART_ENABLED_OUT_ADDR)

// DEBUG (0x2000_0000)
#define reg_reset   (*(volatile uint32_t*) CSR_CTRL_RESET_ADDR)
#define reg_debug_data   (*(volatile uint32_t*) CSR_DEBUG_RXTX_ADDR)
#define reg_debug_txfull   (*(volatile uint32_t*) CSR_DEBUG_TXFULL_ADDR)
#define reg_debug_irq_en   (*(volatile uint32_t*) CSR_USER_IRQ_3_EV_ENABLE_ADDR)
//#define reg_debug_enable (*(volatile uint32_t*) CSR_UART_ENABLED_OUT_ADDR)

// GPIO (0x2100_0000)
#define reg_gpio_mode1  (*(volatile uint32_t*) CSR_GPIO_MODE1_ADDR)
#define reg_gpio_mode0  (*(volatile uint32_t*) CSR_GPIO_MODE0_ADDR)
#define reg_gpio_ien    (*(volatile uint32_t*) CSR_GPIO_IEN_ADDR)
#define reg_gpio_oe     (*(volatile uint32_t*) CSR_GPIO_OE_ADDR)
#define reg_gpio_in     (*(volatile uint32_t*) CSR_GPIO_IN_ADDR)
#define reg_gpio_out    (*(volatile uint32_t*) CSR_GPIO_OUT_ADDR)

// Logic Analyzer (0x2200_0000)
#define reg_la3_data (*(volatile uint32_t*) CSR_LA_OUT_ADDR)
#define reg_la2_data (*(volatile uint32_t*) (CSR_LA_OUT_ADDR + 4))
#define reg_la1_data (*(volatile uint32_t*) (CSR_LA_OUT_ADDR + 8))
#define reg_la0_data (*(volatile uint32_t*) (CSR_LA_OUT_ADDR + 12))

#define reg_la3_data_in (*(volatile uint32_t*) CSR_LA_IN_ADDR)
#define reg_la2_data_in (*(volatile uint32_t*) (CSR_LA_IN_ADDR + 4))
#define reg_la1_data_in (*(volatile uint32_t*) (CSR_LA_IN_ADDR + 8))
#define reg_la0_data_in (*(volatile uint32_t*) (CSR_LA_IN_ADDR + 12))

#define reg_la3_oenb (*(volatile uint32_t*) CSR_LA_OE_ADDR)
#define reg_la2_oenb (*(volatile uint32_t*) (CSR_LA_OE_ADDR + 4))
#define reg_la1_oenb (*(volatile uint32_t*) (CSR_LA_OE_ADDR + 8))
#define reg_la0_oenb (*(volatile uint32_t*) (CSR_LA_OE_ADDR + 12))

#define reg_la3_iena (*(volatile uint32_t*) CSR_LA_IEN_ADDR)
#define reg_la2_iena (*(volatile uint32_t*) (CSR_LA_IEN_ADDR + 4))
#define reg_la1_iena (*(volatile uint32_t*) (CSR_LA_IEN_ADDR + 8))
#define reg_la0_iena (*(volatile uint32_t*) (CSR_LA_IEN_ADDR + 12))

// User Project Slaves (0x3000_0000)
#define reg_mprj_slave (*(volatile uint32_t*)0x30000000)

#define reg_wb_enable	  	(*(volatile uint32_t*) CSR_MPRJ_WB_IENA_OUT_ADDR)
#define reg_user_irq_enable	(*(volatile uint32_t*) CSR_USER_IRQ_ENA_OUT_ADDR)

// Counter-Timer 0 Configuration
#define reg_timer0_config (*(volatile uint32_t*) CSR_TIMER0_EN_ADDR)
#define reg_timer0_update  (*(volatile uint32_t*) CSR_TIMER0_UPDATE_VALUE_ADDR)
#define reg_timer0_value  (*(volatile uint32_t*) CSR_TIMER0_VALUE_ADDR)
#define reg_timer0_data   (*(volatile uint32_t*) CSR_TIMER0_LOAD_ADDR)
#define reg_timer0_irq_en   (*(volatile uint32_t*) CSR_TIMER0_EV_ENABLE_ADDR)

// Bit fields for Counter-timer configuration
#define TIMER_ENABLE		0x01
#define TIMER_ONESHOT		0x02
#define TIMER_UPCOUNT		0x04
#define TIMER_CHAIN		0x08
#define TIMER_IRQ_ENABLE	0x10

// SPI Master Configuration
#define reg_spimaster_control (*(volatile uint32_t*) CSR_SPI_MASTER_CONTROL_ADDR)
#define reg_spimaster_status (*(volatile uint32_t*) CSR_SPI_MASTER_STATUS_ADDR)
#define reg_spimaster_wdata   (*(volatile uint32_t*) CSR_SPI_MASTER_MOSI_ADDR)
#define reg_spimaster_rdata   (*(volatile uint32_t*) CSR_SPI_MASTER_MISO_ADDR)
#define reg_spimaster_cs   (*(volatile uint32_t*) CSR_SPI_MASTER_CS_ADDR)
#define reg_spimaster_clk_divider   (*(volatile uint32_t*) CSR_SPI_MASTER_CLK_DIVIDER_ADDR)
#define reg_spi_enable (*(volatile uint32_t*) CSR_SPI_ENABLED_OUT_ADDR)

// --------------------------------------------------------
#endif
