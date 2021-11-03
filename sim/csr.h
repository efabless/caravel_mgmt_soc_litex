//--------------------------------------------------------------------------------
// Auto-generated by Migen (7507a2b) & LiteX (57002cf3) on 2021-11-03 11:25:25
//--------------------------------------------------------------------------------
//#include <generated/soc.h>
#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H
#include <stdint.h>
//#include <system.h>
#ifndef CSR_ACCESSORS_DEFINED
#include "common.h"
#endif /* ! CSR_ACCESSORS_DEFINED */
#ifndef CSR_BASE
#define CSR_BASE 0xf0000000L
#endif

/* ctrl */
#define CSR_CTRL_BASE (CSR_BASE + 0x0L)
#define CSR_CTRL_RESET_ADDR (CSR_BASE + 0x0L)
#define CSR_CTRL_RESET_SIZE 1
static inline uint32_t ctrl_reset_read(void) {
	return csr_read_simple(CSR_BASE + 0x0L);
}
static inline void ctrl_reset_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x0L);
}
#define CSR_CTRL_RESET_SOC_RST_OFFSET 0
#define CSR_CTRL_RESET_SOC_RST_SIZE 1
static inline uint32_t ctrl_reset_soc_rst_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t ctrl_reset_soc_rst_read(void) {
	uint32_t word = ctrl_reset_read();
	return ctrl_reset_soc_rst_extract(word);
}
static inline uint32_t ctrl_reset_soc_rst_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void ctrl_reset_soc_rst_write(uint32_t plain_value) {
	uint32_t oldword = ctrl_reset_read();
	uint32_t newword = ctrl_reset_soc_rst_replace(oldword, plain_value);
	ctrl_reset_write(newword);
}
#define CSR_CTRL_RESET_CPU_RST_OFFSET 1
#define CSR_CTRL_RESET_CPU_RST_SIZE 1
static inline uint32_t ctrl_reset_cpu_rst_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 1) & mask );
}
static inline uint32_t ctrl_reset_cpu_rst_read(void) {
	uint32_t word = ctrl_reset_read();
	return ctrl_reset_cpu_rst_extract(word);
}
static inline uint32_t ctrl_reset_cpu_rst_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 1))) | (mask & plain_value)<< 1 ;
}
static inline void ctrl_reset_cpu_rst_write(uint32_t plain_value) {
	uint32_t oldword = ctrl_reset_read();
	uint32_t newword = ctrl_reset_cpu_rst_replace(oldword, plain_value);
	ctrl_reset_write(newword);
}
#define CSR_CTRL_SCRATCH_ADDR (CSR_BASE + 0x4L)
#define CSR_CTRL_SCRATCH_SIZE 1
static inline uint32_t ctrl_scratch_read(void) {
	return csr_read_simple(CSR_BASE + 0x4L);
}
static inline void ctrl_scratch_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4L);
}
#define CSR_CTRL_BUS_ERRORS_ADDR (CSR_BASE + 0x8L)
#define CSR_CTRL_BUS_ERRORS_SIZE 1
static inline uint32_t ctrl_bus_errors_read(void) {
	return csr_read_simple(CSR_BASE + 0x8L);
}

/* gpio */
#define CSR_GPIO_BASE (CSR_BASE + 0x800L)
#define CSR_GPIO_MODE1_ADDR (CSR_BASE + 0x800L)
#define CSR_GPIO_MODE1_SIZE 1
static inline uint32_t gpio_mode1_read(void) {
	return csr_read_simple(CSR_BASE + 0x800L);
}
static inline void gpio_mode1_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x800L);
}
#define CSR_GPIO_MODE0_ADDR (CSR_BASE + 0x804L)
#define CSR_GPIO_MODE0_SIZE 1
static inline uint32_t gpio_mode0_read(void) {
	return csr_read_simple(CSR_BASE + 0x804L);
}
static inline void gpio_mode0_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x804L);
}
#define CSR_GPIO_IEN_ADDR (CSR_BASE + 0x808L)
#define CSR_GPIO_IEN_SIZE 1
static inline uint32_t gpio_ien_read(void) {
	return csr_read_simple(CSR_BASE + 0x808L);
}
static inline void gpio_ien_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x808L);
}
#define CSR_GPIO_OE_ADDR (CSR_BASE + 0x80cL)
#define CSR_GPIO_OE_SIZE 1
static inline uint32_t gpio_oe_read(void) {
	return csr_read_simple(CSR_BASE + 0x80cL);
}
static inline void gpio_oe_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x80cL);
}
#define CSR_GPIO_IN_ADDR (CSR_BASE + 0x810L)
#define CSR_GPIO_IN_SIZE 1
static inline uint32_t gpio_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x810L);
}
#define CSR_GPIO_OUT_ADDR (CSR_BASE + 0x814L)
#define CSR_GPIO_OUT_SIZE 1
static inline uint32_t gpio_out_read(void) {
	return csr_read_simple(CSR_BASE + 0x814L);
}
static inline void gpio_out_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x814L);
}

/* la */
#define CSR_LA_BASE (CSR_BASE + 0x1000L)
#define CSR_LA_IEN_ADDR (CSR_BASE + 0x1000L)
#define CSR_LA_IEN_SIZE 4
#define CSR_LA_OE_ADDR (CSR_BASE + 0x1010L)
#define CSR_LA_OE_SIZE 4
#define CSR_LA_IN_ADDR (CSR_BASE + 0x1020L)
#define CSR_LA_IN_SIZE 4
#define CSR_LA_OUT_ADDR (CSR_BASE + 0x1030L)
#define CSR_LA_OUT_SIZE 4

/* mprj_wb_iena */
#define CSR_MPRJ_WB_IENA_BASE (CSR_BASE + 0x1800L)
#define CSR_MPRJ_WB_IENA_OUT_ADDR (CSR_BASE + 0x1800L)
#define CSR_MPRJ_WB_IENA_OUT_SIZE 1
static inline uint32_t mprj_wb_iena_out_read(void) {
	return csr_read_simple(CSR_BASE + 0x1800L);
}
static inline void mprj_wb_iena_out_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x1800L);
}

/* spi_master */
#define CSR_SPI_MASTER_BASE (CSR_BASE + 0x2000L)
#define CSR_SPI_MASTER_CONTROL_ADDR (CSR_BASE + 0x2000L)
#define CSR_SPI_MASTER_CONTROL_SIZE 1
static inline uint32_t spi_master_control_read(void) {
	return csr_read_simple(CSR_BASE + 0x2000L);
}
static inline void spi_master_control_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2000L);
}
#define CSR_SPI_MASTER_CONTROL_START_OFFSET 0
#define CSR_SPI_MASTER_CONTROL_START_SIZE 1
static inline uint32_t spi_master_control_start_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t spi_master_control_start_read(void) {
	uint32_t word = spi_master_control_read();
	return spi_master_control_start_extract(word);
}
static inline uint32_t spi_master_control_start_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void spi_master_control_start_write(uint32_t plain_value) {
	uint32_t oldword = spi_master_control_read();
	uint32_t newword = spi_master_control_start_replace(oldword, plain_value);
	spi_master_control_write(newword);
}
#define CSR_SPI_MASTER_CONTROL_LENGTH_OFFSET 8
#define CSR_SPI_MASTER_CONTROL_LENGTH_SIZE 8
static inline uint32_t spi_master_control_length_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 8)-1);
	return ( (oldword >> 8) & mask );
}
static inline uint32_t spi_master_control_length_read(void) {
	uint32_t word = spi_master_control_read();
	return spi_master_control_length_extract(word);
}
static inline uint32_t spi_master_control_length_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 8)-1);
	return (oldword & (~(mask << 8))) | (mask & plain_value)<< 8 ;
}
static inline void spi_master_control_length_write(uint32_t plain_value) {
	uint32_t oldword = spi_master_control_read();
	uint32_t newword = spi_master_control_length_replace(oldword, plain_value);
	spi_master_control_write(newword);
}
#define CSR_SPI_MASTER_STATUS_ADDR (CSR_BASE + 0x2004L)
#define CSR_SPI_MASTER_STATUS_SIZE 1
static inline uint32_t spi_master_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x2004L);
}
#define CSR_SPI_MASTER_STATUS_DONE_OFFSET 0
#define CSR_SPI_MASTER_STATUS_DONE_SIZE 1
static inline uint32_t spi_master_status_done_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t spi_master_status_done_read(void) {
	uint32_t word = spi_master_status_read();
	return spi_master_status_done_extract(word);
}
#define CSR_SPI_MASTER_MOSI_ADDR (CSR_BASE + 0x2008L)
#define CSR_SPI_MASTER_MOSI_SIZE 1
static inline uint32_t spi_master_mosi_read(void) {
	return csr_read_simple(CSR_BASE + 0x2008L);
}
static inline void spi_master_mosi_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2008L);
}
#define CSR_SPI_MASTER_MISO_ADDR (CSR_BASE + 0x200cL)
#define CSR_SPI_MASTER_MISO_SIZE 1
static inline uint32_t spi_master_miso_read(void) {
	return csr_read_simple(CSR_BASE + 0x200cL);
}
#define CSR_SPI_MASTER_CS_ADDR (CSR_BASE + 0x2010L)
#define CSR_SPI_MASTER_CS_SIZE 1
static inline uint32_t spi_master_cs_read(void) {
	return csr_read_simple(CSR_BASE + 0x2010L);
}
static inline void spi_master_cs_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2010L);
}
#define CSR_SPI_MASTER_CS_SEL_OFFSET 0
#define CSR_SPI_MASTER_CS_SEL_SIZE 1
static inline uint32_t spi_master_cs_sel_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t spi_master_cs_sel_read(void) {
	uint32_t word = spi_master_cs_read();
	return spi_master_cs_sel_extract(word);
}
static inline uint32_t spi_master_cs_sel_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void spi_master_cs_sel_write(uint32_t plain_value) {
	uint32_t oldword = spi_master_cs_read();
	uint32_t newword = spi_master_cs_sel_replace(oldword, plain_value);
	spi_master_cs_write(newword);
}
#define CSR_SPI_MASTER_CS_MODE_OFFSET 16
#define CSR_SPI_MASTER_CS_MODE_SIZE 1
static inline uint32_t spi_master_cs_mode_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 16) & mask );
}
static inline uint32_t spi_master_cs_mode_read(void) {
	uint32_t word = spi_master_cs_read();
	return spi_master_cs_mode_extract(word);
}
static inline uint32_t spi_master_cs_mode_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 16))) | (mask & plain_value)<< 16 ;
}
static inline void spi_master_cs_mode_write(uint32_t plain_value) {
	uint32_t oldword = spi_master_cs_read();
	uint32_t newword = spi_master_cs_mode_replace(oldword, plain_value);
	spi_master_cs_write(newword);
}
#define CSR_SPI_MASTER_LOOPBACK_ADDR (CSR_BASE + 0x2014L)
#define CSR_SPI_MASTER_LOOPBACK_SIZE 1
static inline uint32_t spi_master_loopback_read(void) {
	return csr_read_simple(CSR_BASE + 0x2014L);
}
static inline void spi_master_loopback_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2014L);
}
#define CSR_SPI_MASTER_LOOPBACK_MODE_OFFSET 0
#define CSR_SPI_MASTER_LOOPBACK_MODE_SIZE 1
static inline uint32_t spi_master_loopback_mode_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t spi_master_loopback_mode_read(void) {
	uint32_t word = spi_master_loopback_read();
	return spi_master_loopback_mode_extract(word);
}
static inline uint32_t spi_master_loopback_mode_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void spi_master_loopback_mode_write(uint32_t plain_value) {
	uint32_t oldword = spi_master_loopback_read();
	uint32_t newword = spi_master_loopback_mode_replace(oldword, plain_value);
	spi_master_loopback_write(newword);
}
#define CSR_SPI_MASTER_CLK_DIVIDER_ADDR (CSR_BASE + 0x2018L)
#define CSR_SPI_MASTER_CLK_DIVIDER_SIZE 1
static inline uint32_t spi_master_clk_divider_read(void) {
	return csr_read_simple(CSR_BASE + 0x2018L);
}
static inline void spi_master_clk_divider_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2018L);
}

/* spiflash_core */
#define CSR_SPIFLASH_CORE_BASE (CSR_BASE + 0x2800L)
#define CSR_SPIFLASH_CORE_MMAP_DUMMY_BITS_ADDR (CSR_BASE + 0x2800L)
#define CSR_SPIFLASH_CORE_MMAP_DUMMY_BITS_SIZE 1
static inline uint32_t spiflash_core_mmap_dummy_bits_read(void) {
	return csr_read_simple(CSR_BASE + 0x2800L);
}
static inline void spiflash_core_mmap_dummy_bits_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2800L);
}

/* spiflash_phy */
#define CSR_SPIFLASH_PHY_BASE (CSR_BASE + 0x3000L)
#define CSR_SPIFLASH_PHY_CLK_DIVISOR_ADDR (CSR_BASE + 0x3000L)
#define CSR_SPIFLASH_PHY_CLK_DIVISOR_SIZE 1
static inline uint32_t spiflash_phy_clk_divisor_read(void) {
	return csr_read_simple(CSR_BASE + 0x3000L);
}
static inline void spiflash_phy_clk_divisor_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3000L);
}

/* timer0 */
#define CSR_TIMER0_BASE (CSR_BASE + 0x3800L)
#define CSR_TIMER0_LOAD_ADDR (CSR_BASE + 0x3800L)
#define CSR_TIMER0_LOAD_SIZE 1
static inline uint32_t timer0_load_read(void) {
	return csr_read_simple(CSR_BASE + 0x3800L);
}
static inline void timer0_load_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3800L);
}
#define CSR_TIMER0_RELOAD_ADDR (CSR_BASE + 0x3804L)
#define CSR_TIMER0_RELOAD_SIZE 1
static inline uint32_t timer0_reload_read(void) {
	return csr_read_simple(CSR_BASE + 0x3804L);
}
static inline void timer0_reload_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3804L);
}
#define CSR_TIMER0_EN_ADDR (CSR_BASE + 0x3808L)
#define CSR_TIMER0_EN_SIZE 1
static inline uint32_t timer0_en_read(void) {
	return csr_read_simple(CSR_BASE + 0x3808L);
}
static inline void timer0_en_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3808L);
}
#define CSR_TIMER0_UPDATE_VALUE_ADDR (CSR_BASE + 0x380cL)
#define CSR_TIMER0_UPDATE_VALUE_SIZE 1
static inline uint32_t timer0_update_value_read(void) {
	return csr_read_simple(CSR_BASE + 0x380cL);
}
static inline void timer0_update_value_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x380cL);
}
#define CSR_TIMER0_VALUE_ADDR (CSR_BASE + 0x3810L)
#define CSR_TIMER0_VALUE_SIZE 1
static inline uint32_t timer0_value_read(void) {
	return csr_read_simple(CSR_BASE + 0x3810L);
}
#define CSR_TIMER0_EV_STATUS_ADDR (CSR_BASE + 0x3814L)
#define CSR_TIMER0_EV_STATUS_SIZE 1
static inline uint32_t timer0_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x3814L);
}
#define CSR_TIMER0_EV_STATUS_ZERO_OFFSET 0
#define CSR_TIMER0_EV_STATUS_ZERO_SIZE 1
static inline uint32_t timer0_ev_status_zero_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t timer0_ev_status_zero_read(void) {
	uint32_t word = timer0_ev_status_read();
	return timer0_ev_status_zero_extract(word);
}
#define CSR_TIMER0_EV_PENDING_ADDR (CSR_BASE + 0x3818L)
#define CSR_TIMER0_EV_PENDING_SIZE 1
static inline uint32_t timer0_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x3818L);
}
static inline void timer0_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3818L);
}
#define CSR_TIMER0_EV_PENDING_ZERO_OFFSET 0
#define CSR_TIMER0_EV_PENDING_ZERO_SIZE 1
static inline uint32_t timer0_ev_pending_zero_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t timer0_ev_pending_zero_read(void) {
	uint32_t word = timer0_ev_pending_read();
	return timer0_ev_pending_zero_extract(word);
}
static inline uint32_t timer0_ev_pending_zero_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void timer0_ev_pending_zero_write(uint32_t plain_value) {
	uint32_t oldword = timer0_ev_pending_read();
	uint32_t newword = timer0_ev_pending_zero_replace(oldword, plain_value);
	timer0_ev_pending_write(newword);
}
#define CSR_TIMER0_EV_ENABLE_ADDR (CSR_BASE + 0x381cL)
#define CSR_TIMER0_EV_ENABLE_SIZE 1
static inline uint32_t timer0_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x381cL);
}
static inline void timer0_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x381cL);
}
#define CSR_TIMER0_EV_ENABLE_ZERO_OFFSET 0
#define CSR_TIMER0_EV_ENABLE_ZERO_SIZE 1
static inline uint32_t timer0_ev_enable_zero_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t timer0_ev_enable_zero_read(void) {
	uint32_t word = timer0_ev_enable_read();
	return timer0_ev_enable_zero_extract(word);
}
static inline uint32_t timer0_ev_enable_zero_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void timer0_ev_enable_zero_write(uint32_t plain_value) {
	uint32_t oldword = timer0_ev_enable_read();
	uint32_t newword = timer0_ev_enable_zero_replace(oldword, plain_value);
	timer0_ev_enable_write(newword);
}

/* uart */
#define CSR_UART_BASE (CSR_BASE + 0x4000L)
#define CSR_UART_RXTX_ADDR (CSR_BASE + 0x4000L)
#define CSR_UART_RXTX_SIZE 1
static inline uint32_t uart_rxtx_read(void) {
	return csr_read_simple(CSR_BASE + 0x4000L);
}
static inline void uart_rxtx_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4000L);
}
#define CSR_UART_TXFULL_ADDR (CSR_BASE + 0x4004L)
#define CSR_UART_TXFULL_SIZE 1
static inline uint32_t uart_txfull_read(void) {
	return csr_read_simple(CSR_BASE + 0x4004L);
}
#define CSR_UART_RXEMPTY_ADDR (CSR_BASE + 0x4008L)
#define CSR_UART_RXEMPTY_SIZE 1
static inline uint32_t uart_rxempty_read(void) {
	return csr_read_simple(CSR_BASE + 0x4008L);
}
#define CSR_UART_EV_STATUS_ADDR (CSR_BASE + 0x400cL)
#define CSR_UART_EV_STATUS_SIZE 1
static inline uint32_t uart_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x400cL);
}
#define CSR_UART_EV_STATUS_TX_OFFSET 0
#define CSR_UART_EV_STATUS_TX_SIZE 1
static inline uint32_t uart_ev_status_tx_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t uart_ev_status_tx_read(void) {
	uint32_t word = uart_ev_status_read();
	return uart_ev_status_tx_extract(word);
}
#define CSR_UART_EV_STATUS_RX_OFFSET 1
#define CSR_UART_EV_STATUS_RX_SIZE 1
static inline uint32_t uart_ev_status_rx_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 1) & mask );
}
static inline uint32_t uart_ev_status_rx_read(void) {
	uint32_t word = uart_ev_status_read();
	return uart_ev_status_rx_extract(word);
}
#define CSR_UART_EV_PENDING_ADDR (CSR_BASE + 0x4010L)
#define CSR_UART_EV_PENDING_SIZE 1
static inline uint32_t uart_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x4010L);
}
static inline void uart_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4010L);
}
#define CSR_UART_EV_PENDING_TX_OFFSET 0
#define CSR_UART_EV_PENDING_TX_SIZE 1
static inline uint32_t uart_ev_pending_tx_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t uart_ev_pending_tx_read(void) {
	uint32_t word = uart_ev_pending_read();
	return uart_ev_pending_tx_extract(word);
}
static inline uint32_t uart_ev_pending_tx_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void uart_ev_pending_tx_write(uint32_t plain_value) {
	uint32_t oldword = uart_ev_pending_read();
	uint32_t newword = uart_ev_pending_tx_replace(oldword, plain_value);
	uart_ev_pending_write(newword);
}
#define CSR_UART_EV_PENDING_RX_OFFSET 1
#define CSR_UART_EV_PENDING_RX_SIZE 1
static inline uint32_t uart_ev_pending_rx_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 1) & mask );
}
static inline uint32_t uart_ev_pending_rx_read(void) {
	uint32_t word = uart_ev_pending_read();
	return uart_ev_pending_rx_extract(word);
}
static inline uint32_t uart_ev_pending_rx_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 1))) | (mask & plain_value)<< 1 ;
}
static inline void uart_ev_pending_rx_write(uint32_t plain_value) {
	uint32_t oldword = uart_ev_pending_read();
	uint32_t newword = uart_ev_pending_rx_replace(oldword, plain_value);
	uart_ev_pending_write(newword);
}
#define CSR_UART_EV_ENABLE_ADDR (CSR_BASE + 0x4014L)
#define CSR_UART_EV_ENABLE_SIZE 1
static inline uint32_t uart_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x4014L);
}
static inline void uart_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4014L);
}
#define CSR_UART_EV_ENABLE_TX_OFFSET 0
#define CSR_UART_EV_ENABLE_TX_SIZE 1
static inline uint32_t uart_ev_enable_tx_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t uart_ev_enable_tx_read(void) {
	uint32_t word = uart_ev_enable_read();
	return uart_ev_enable_tx_extract(word);
}
static inline uint32_t uart_ev_enable_tx_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void uart_ev_enable_tx_write(uint32_t plain_value) {
	uint32_t oldword = uart_ev_enable_read();
	uint32_t newword = uart_ev_enable_tx_replace(oldword, plain_value);
	uart_ev_enable_write(newword);
}
#define CSR_UART_EV_ENABLE_RX_OFFSET 1
#define CSR_UART_EV_ENABLE_RX_SIZE 1
static inline uint32_t uart_ev_enable_rx_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 1) & mask );
}
static inline uint32_t uart_ev_enable_rx_read(void) {
	uint32_t word = uart_ev_enable_read();
	return uart_ev_enable_rx_extract(word);
}
static inline uint32_t uart_ev_enable_rx_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 1))) | (mask & plain_value)<< 1 ;
}
static inline void uart_ev_enable_rx_write(uint32_t plain_value) {
	uint32_t oldword = uart_ev_enable_read();
	uint32_t newword = uart_ev_enable_rx_replace(oldword, plain_value);
	uart_ev_enable_write(newword);
}
#define CSR_UART_TXEMPTY_ADDR (CSR_BASE + 0x4018L)
#define CSR_UART_TXEMPTY_SIZE 1
static inline uint32_t uart_txempty_read(void) {
	return csr_read_simple(CSR_BASE + 0x4018L);
}
#define CSR_UART_RXFULL_ADDR (CSR_BASE + 0x401cL)
#define CSR_UART_RXFULL_SIZE 1
static inline uint32_t uart_rxfull_read(void) {
	return csr_read_simple(CSR_BASE + 0x401cL);
}

/* user_irq_ena */
#define CSR_USER_IRQ_ENA_BASE (CSR_BASE + 0x4800L)
#define CSR_USER_IRQ_ENA_OUT_ADDR (CSR_BASE + 0x4800L)
#define CSR_USER_IRQ_ENA_OUT_SIZE 1
static inline uint32_t user_irq_ena_out_read(void) {
	return csr_read_simple(CSR_BASE + 0x4800L);
}
static inline void user_irq_ena_out_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4800L);
}

#endif
