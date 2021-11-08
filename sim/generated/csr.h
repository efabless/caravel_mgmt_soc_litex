//--------------------------------------------------------------------------------
// Auto-generated by Migen (7507a2b) & LiteX (3b1d1f0) on 2021-11-07 20:55:58
//--------------------------------------------------------------------------------
#include <generated/soc.h>
#ifndef __GENERATED_CSR_H
#define __GENERATED_CSR_H
#include <stdint.h>
#include <system.h>
#ifndef CSR_ACCESSORS_DEFINED
#include <hw/common.h>
#endif /* ! CSR_ACCESSORS_DEFINED */
#ifndef CSR_BASE
#define CSR_BASE 0x82000000L
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

/* mprj_wb_iena */
#define CSR_MPRJ_WB_IENA_BASE (CSR_BASE + 0x1000L)
#define CSR_MPRJ_WB_IENA_OUT_ADDR (CSR_BASE + 0x1000L)
#define CSR_MPRJ_WB_IENA_OUT_SIZE 1
static inline uint32_t mprj_wb_iena_out_read(void) {
	return csr_read_simple(CSR_BASE + 0x1000L);
}
static inline void mprj_wb_iena_out_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x1000L);
}

/* spiflash_core */
#define CSR_SPIFLASH_CORE_BASE (CSR_BASE + 0x1800L)
#define CSR_SPIFLASH_CORE_MMAP_DUMMY_BITS_ADDR (CSR_BASE + 0x1800L)
#define CSR_SPIFLASH_CORE_MMAP_DUMMY_BITS_SIZE 1
static inline uint32_t spiflash_core_mmap_dummy_bits_read(void) {
	return csr_read_simple(CSR_BASE + 0x1800L);
}
static inline void spiflash_core_mmap_dummy_bits_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x1800L);
}
#define CSR_SPIFLASH_CORE_MASTER_CS_ADDR (CSR_BASE + 0x1804L)
#define CSR_SPIFLASH_CORE_MASTER_CS_SIZE 1
static inline uint32_t spiflash_core_master_cs_read(void) {
	return csr_read_simple(CSR_BASE + 0x1804L);
}
static inline void spiflash_core_master_cs_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x1804L);
}
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_ADDR (CSR_BASE + 0x1808L)
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_SIZE 1
static inline uint32_t spiflash_core_master_phyconfig_read(void) {
	return csr_read_simple(CSR_BASE + 0x1808L);
}
static inline void spiflash_core_master_phyconfig_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x1808L);
}
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_LEN_OFFSET 0
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_LEN_SIZE 8
static inline uint32_t spiflash_core_master_phyconfig_len_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 8)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t spiflash_core_master_phyconfig_len_read(void) {
	uint32_t word = spiflash_core_master_phyconfig_read();
	return spiflash_core_master_phyconfig_len_extract(word);
}
static inline uint32_t spiflash_core_master_phyconfig_len_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 8)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void spiflash_core_master_phyconfig_len_write(uint32_t plain_value) {
	uint32_t oldword = spiflash_core_master_phyconfig_read();
	uint32_t newword = spiflash_core_master_phyconfig_len_replace(oldword, plain_value);
	spiflash_core_master_phyconfig_write(newword);
}
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_WIDTH_OFFSET 8
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_WIDTH_SIZE 4
static inline uint32_t spiflash_core_master_phyconfig_width_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 4)-1);
	return ( (oldword >> 8) & mask );
}
static inline uint32_t spiflash_core_master_phyconfig_width_read(void) {
	uint32_t word = spiflash_core_master_phyconfig_read();
	return spiflash_core_master_phyconfig_width_extract(word);
}
static inline uint32_t spiflash_core_master_phyconfig_width_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 4)-1);
	return (oldword & (~(mask << 8))) | (mask & plain_value)<< 8 ;
}
static inline void spiflash_core_master_phyconfig_width_write(uint32_t plain_value) {
	uint32_t oldword = spiflash_core_master_phyconfig_read();
	uint32_t newword = spiflash_core_master_phyconfig_width_replace(oldword, plain_value);
	spiflash_core_master_phyconfig_write(newword);
}
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_MASK_OFFSET 16
#define CSR_SPIFLASH_CORE_MASTER_PHYCONFIG_MASK_SIZE 8
static inline uint32_t spiflash_core_master_phyconfig_mask_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 8)-1);
	return ( (oldword >> 16) & mask );
}
static inline uint32_t spiflash_core_master_phyconfig_mask_read(void) {
	uint32_t word = spiflash_core_master_phyconfig_read();
	return spiflash_core_master_phyconfig_mask_extract(word);
}
static inline uint32_t spiflash_core_master_phyconfig_mask_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 8)-1);
	return (oldword & (~(mask << 16))) | (mask & plain_value)<< 16 ;
}
static inline void spiflash_core_master_phyconfig_mask_write(uint32_t plain_value) {
	uint32_t oldword = spiflash_core_master_phyconfig_read();
	uint32_t newword = spiflash_core_master_phyconfig_mask_replace(oldword, plain_value);
	spiflash_core_master_phyconfig_write(newword);
}
#define CSR_SPIFLASH_CORE_MASTER_RXTX_ADDR (CSR_BASE + 0x180cL)
#define CSR_SPIFLASH_CORE_MASTER_RXTX_SIZE 1
static inline uint32_t spiflash_core_master_rxtx_read(void) {
	return csr_read_simple(CSR_BASE + 0x180cL);
}
static inline void spiflash_core_master_rxtx_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x180cL);
}
#define CSR_SPIFLASH_CORE_MASTER_STATUS_ADDR (CSR_BASE + 0x1810L)
#define CSR_SPIFLASH_CORE_MASTER_STATUS_SIZE 1
static inline uint32_t spiflash_core_master_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x1810L);
}
#define CSR_SPIFLASH_CORE_MASTER_STATUS_TX_READY_OFFSET 0
#define CSR_SPIFLASH_CORE_MASTER_STATUS_TX_READY_SIZE 1
static inline uint32_t spiflash_core_master_status_tx_ready_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t spiflash_core_master_status_tx_ready_read(void) {
	uint32_t word = spiflash_core_master_status_read();
	return spiflash_core_master_status_tx_ready_extract(word);
}
#define CSR_SPIFLASH_CORE_MASTER_STATUS_RX_READY_OFFSET 1
#define CSR_SPIFLASH_CORE_MASTER_STATUS_RX_READY_SIZE 1
static inline uint32_t spiflash_core_master_status_rx_ready_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 1) & mask );
}
static inline uint32_t spiflash_core_master_status_rx_ready_read(void) {
	uint32_t word = spiflash_core_master_status_read();
	return spiflash_core_master_status_rx_ready_extract(word);
}

/* spiflash_phy */
#define CSR_SPIFLASH_PHY_BASE (CSR_BASE + 0x2000L)
#define CSR_SPIFLASH_PHY_CLK_DIVISOR_ADDR (CSR_BASE + 0x2000L)
#define CSR_SPIFLASH_PHY_CLK_DIVISOR_SIZE 1
static inline uint32_t spiflash_phy_clk_divisor_read(void) {
	return csr_read_simple(CSR_BASE + 0x2000L);
}
static inline void spiflash_phy_clk_divisor_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2000L);
}

/* user_irq_0 */
#define CSR_USER_IRQ_0_BASE (CSR_BASE + 0x2800L)
#define CSR_USER_IRQ_0_IN_ADDR (CSR_BASE + 0x2800L)
#define CSR_USER_IRQ_0_IN_SIZE 1
static inline uint32_t user_irq_0_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x2800L);
}
#define CSR_USER_IRQ_0_MODE_ADDR (CSR_BASE + 0x2804L)
#define CSR_USER_IRQ_0_MODE_SIZE 1
static inline uint32_t user_irq_0_mode_read(void) {
	return csr_read_simple(CSR_BASE + 0x2804L);
}
static inline void user_irq_0_mode_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2804L);
}
#define CSR_USER_IRQ_0_EDGE_ADDR (CSR_BASE + 0x2808L)
#define CSR_USER_IRQ_0_EDGE_SIZE 1
static inline uint32_t user_irq_0_edge_read(void) {
	return csr_read_simple(CSR_BASE + 0x2808L);
}
static inline void user_irq_0_edge_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2808L);
}
#define CSR_USER_IRQ_0_EV_STATUS_ADDR (CSR_BASE + 0x280cL)
#define CSR_USER_IRQ_0_EV_STATUS_SIZE 1
static inline uint32_t user_irq_0_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x280cL);
}
#define CSR_USER_IRQ_0_EV_STATUS_I0_OFFSET 0
#define CSR_USER_IRQ_0_EV_STATUS_I0_SIZE 1
static inline uint32_t user_irq_0_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_0_ev_status_i0_read(void) {
	uint32_t word = user_irq_0_ev_status_read();
	return user_irq_0_ev_status_i0_extract(word);
}
#define CSR_USER_IRQ_0_EV_PENDING_ADDR (CSR_BASE + 0x2810L)
#define CSR_USER_IRQ_0_EV_PENDING_SIZE 1
static inline uint32_t user_irq_0_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x2810L);
}
static inline void user_irq_0_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2810L);
}
#define CSR_USER_IRQ_0_EV_PENDING_I0_OFFSET 0
#define CSR_USER_IRQ_0_EV_PENDING_I0_SIZE 1
static inline uint32_t user_irq_0_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_0_ev_pending_i0_read(void) {
	uint32_t word = user_irq_0_ev_pending_read();
	return user_irq_0_ev_pending_i0_extract(word);
}
static inline uint32_t user_irq_0_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_0_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_0_ev_pending_read();
	uint32_t newword = user_irq_0_ev_pending_i0_replace(oldword, plain_value);
	user_irq_0_ev_pending_write(newword);
}
#define CSR_USER_IRQ_0_EV_ENABLE_ADDR (CSR_BASE + 0x2814L)
#define CSR_USER_IRQ_0_EV_ENABLE_SIZE 1
static inline uint32_t user_irq_0_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x2814L);
}
static inline void user_irq_0_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x2814L);
}
#define CSR_USER_IRQ_0_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_IRQ_0_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_irq_0_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_0_ev_enable_i0_read(void) {
	uint32_t word = user_irq_0_ev_enable_read();
	return user_irq_0_ev_enable_i0_extract(word);
}
static inline uint32_t user_irq_0_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_0_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_0_ev_enable_read();
	uint32_t newword = user_irq_0_ev_enable_i0_replace(oldword, plain_value);
	user_irq_0_ev_enable_write(newword);
}

/* user_irq_1 */
#define CSR_USER_IRQ_1_BASE (CSR_BASE + 0x3000L)
#define CSR_USER_IRQ_1_IN_ADDR (CSR_BASE + 0x3000L)
#define CSR_USER_IRQ_1_IN_SIZE 1
static inline uint32_t user_irq_1_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x3000L);
}
#define CSR_USER_IRQ_1_MODE_ADDR (CSR_BASE + 0x3004L)
#define CSR_USER_IRQ_1_MODE_SIZE 1
static inline uint32_t user_irq_1_mode_read(void) {
	return csr_read_simple(CSR_BASE + 0x3004L);
}
static inline void user_irq_1_mode_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3004L);
}
#define CSR_USER_IRQ_1_EDGE_ADDR (CSR_BASE + 0x3008L)
#define CSR_USER_IRQ_1_EDGE_SIZE 1
static inline uint32_t user_irq_1_edge_read(void) {
	return csr_read_simple(CSR_BASE + 0x3008L);
}
static inline void user_irq_1_edge_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3008L);
}
#define CSR_USER_IRQ_1_EV_STATUS_ADDR (CSR_BASE + 0x300cL)
#define CSR_USER_IRQ_1_EV_STATUS_SIZE 1
static inline uint32_t user_irq_1_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x300cL);
}
#define CSR_USER_IRQ_1_EV_STATUS_I0_OFFSET 0
#define CSR_USER_IRQ_1_EV_STATUS_I0_SIZE 1
static inline uint32_t user_irq_1_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_1_ev_status_i0_read(void) {
	uint32_t word = user_irq_1_ev_status_read();
	return user_irq_1_ev_status_i0_extract(word);
}
#define CSR_USER_IRQ_1_EV_PENDING_ADDR (CSR_BASE + 0x3010L)
#define CSR_USER_IRQ_1_EV_PENDING_SIZE 1
static inline uint32_t user_irq_1_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x3010L);
}
static inline void user_irq_1_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3010L);
}
#define CSR_USER_IRQ_1_EV_PENDING_I0_OFFSET 0
#define CSR_USER_IRQ_1_EV_PENDING_I0_SIZE 1
static inline uint32_t user_irq_1_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_1_ev_pending_i0_read(void) {
	uint32_t word = user_irq_1_ev_pending_read();
	return user_irq_1_ev_pending_i0_extract(word);
}
static inline uint32_t user_irq_1_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_1_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_1_ev_pending_read();
	uint32_t newword = user_irq_1_ev_pending_i0_replace(oldword, plain_value);
	user_irq_1_ev_pending_write(newword);
}
#define CSR_USER_IRQ_1_EV_ENABLE_ADDR (CSR_BASE + 0x3014L)
#define CSR_USER_IRQ_1_EV_ENABLE_SIZE 1
static inline uint32_t user_irq_1_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x3014L);
}
static inline void user_irq_1_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3014L);
}
#define CSR_USER_IRQ_1_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_IRQ_1_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_irq_1_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_1_ev_enable_i0_read(void) {
	uint32_t word = user_irq_1_ev_enable_read();
	return user_irq_1_ev_enable_i0_extract(word);
}
static inline uint32_t user_irq_1_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_1_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_1_ev_enable_read();
	uint32_t newword = user_irq_1_ev_enable_i0_replace(oldword, plain_value);
	user_irq_1_ev_enable_write(newword);
}

/* user_irq_2 */
#define CSR_USER_IRQ_2_BASE (CSR_BASE + 0x3800L)
#define CSR_USER_IRQ_2_IN_ADDR (CSR_BASE + 0x3800L)
#define CSR_USER_IRQ_2_IN_SIZE 1
static inline uint32_t user_irq_2_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x3800L);
}
#define CSR_USER_IRQ_2_MODE_ADDR (CSR_BASE + 0x3804L)
#define CSR_USER_IRQ_2_MODE_SIZE 1
static inline uint32_t user_irq_2_mode_read(void) {
	return csr_read_simple(CSR_BASE + 0x3804L);
}
static inline void user_irq_2_mode_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3804L);
}
#define CSR_USER_IRQ_2_EDGE_ADDR (CSR_BASE + 0x3808L)
#define CSR_USER_IRQ_2_EDGE_SIZE 1
static inline uint32_t user_irq_2_edge_read(void) {
	return csr_read_simple(CSR_BASE + 0x3808L);
}
static inline void user_irq_2_edge_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3808L);
}
#define CSR_USER_IRQ_2_EV_STATUS_ADDR (CSR_BASE + 0x380cL)
#define CSR_USER_IRQ_2_EV_STATUS_SIZE 1
static inline uint32_t user_irq_2_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x380cL);
}
#define CSR_USER_IRQ_2_EV_STATUS_I0_OFFSET 0
#define CSR_USER_IRQ_2_EV_STATUS_I0_SIZE 1
static inline uint32_t user_irq_2_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_2_ev_status_i0_read(void) {
	uint32_t word = user_irq_2_ev_status_read();
	return user_irq_2_ev_status_i0_extract(word);
}
#define CSR_USER_IRQ_2_EV_PENDING_ADDR (CSR_BASE + 0x3810L)
#define CSR_USER_IRQ_2_EV_PENDING_SIZE 1
static inline uint32_t user_irq_2_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x3810L);
}
static inline void user_irq_2_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3810L);
}
#define CSR_USER_IRQ_2_EV_PENDING_I0_OFFSET 0
#define CSR_USER_IRQ_2_EV_PENDING_I0_SIZE 1
static inline uint32_t user_irq_2_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_2_ev_pending_i0_read(void) {
	uint32_t word = user_irq_2_ev_pending_read();
	return user_irq_2_ev_pending_i0_extract(word);
}
static inline uint32_t user_irq_2_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_2_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_2_ev_pending_read();
	uint32_t newword = user_irq_2_ev_pending_i0_replace(oldword, plain_value);
	user_irq_2_ev_pending_write(newword);
}
#define CSR_USER_IRQ_2_EV_ENABLE_ADDR (CSR_BASE + 0x3814L)
#define CSR_USER_IRQ_2_EV_ENABLE_SIZE 1
static inline uint32_t user_irq_2_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x3814L);
}
static inline void user_irq_2_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x3814L);
}
#define CSR_USER_IRQ_2_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_IRQ_2_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_irq_2_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_2_ev_enable_i0_read(void) {
	uint32_t word = user_irq_2_ev_enable_read();
	return user_irq_2_ev_enable_i0_extract(word);
}
static inline uint32_t user_irq_2_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_2_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_2_ev_enable_read();
	uint32_t newword = user_irq_2_ev_enable_i0_replace(oldword, plain_value);
	user_irq_2_ev_enable_write(newword);
}

/* user_irq_3 */
#define CSR_USER_IRQ_3_BASE (CSR_BASE + 0x4000L)
#define CSR_USER_IRQ_3_IN_ADDR (CSR_BASE + 0x4000L)
#define CSR_USER_IRQ_3_IN_SIZE 1
static inline uint32_t user_irq_3_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x4000L);
}
#define CSR_USER_IRQ_3_MODE_ADDR (CSR_BASE + 0x4004L)
#define CSR_USER_IRQ_3_MODE_SIZE 1
static inline uint32_t user_irq_3_mode_read(void) {
	return csr_read_simple(CSR_BASE + 0x4004L);
}
static inline void user_irq_3_mode_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4004L);
}
#define CSR_USER_IRQ_3_EDGE_ADDR (CSR_BASE + 0x4008L)
#define CSR_USER_IRQ_3_EDGE_SIZE 1
static inline uint32_t user_irq_3_edge_read(void) {
	return csr_read_simple(CSR_BASE + 0x4008L);
}
static inline void user_irq_3_edge_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4008L);
}
#define CSR_USER_IRQ_3_EV_STATUS_ADDR (CSR_BASE + 0x400cL)
#define CSR_USER_IRQ_3_EV_STATUS_SIZE 1
static inline uint32_t user_irq_3_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x400cL);
}
#define CSR_USER_IRQ_3_EV_STATUS_I0_OFFSET 0
#define CSR_USER_IRQ_3_EV_STATUS_I0_SIZE 1
static inline uint32_t user_irq_3_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_3_ev_status_i0_read(void) {
	uint32_t word = user_irq_3_ev_status_read();
	return user_irq_3_ev_status_i0_extract(word);
}
#define CSR_USER_IRQ_3_EV_PENDING_ADDR (CSR_BASE + 0x4010L)
#define CSR_USER_IRQ_3_EV_PENDING_SIZE 1
static inline uint32_t user_irq_3_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x4010L);
}
static inline void user_irq_3_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4010L);
}
#define CSR_USER_IRQ_3_EV_PENDING_I0_OFFSET 0
#define CSR_USER_IRQ_3_EV_PENDING_I0_SIZE 1
static inline uint32_t user_irq_3_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_3_ev_pending_i0_read(void) {
	uint32_t word = user_irq_3_ev_pending_read();
	return user_irq_3_ev_pending_i0_extract(word);
}
static inline uint32_t user_irq_3_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_3_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_3_ev_pending_read();
	uint32_t newword = user_irq_3_ev_pending_i0_replace(oldword, plain_value);
	user_irq_3_ev_pending_write(newword);
}
#define CSR_USER_IRQ_3_EV_ENABLE_ADDR (CSR_BASE + 0x4014L)
#define CSR_USER_IRQ_3_EV_ENABLE_SIZE 1
static inline uint32_t user_irq_3_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x4014L);
}
static inline void user_irq_3_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4014L);
}
#define CSR_USER_IRQ_3_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_IRQ_3_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_irq_3_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_3_ev_enable_i0_read(void) {
	uint32_t word = user_irq_3_ev_enable_read();
	return user_irq_3_ev_enable_i0_extract(word);
}
static inline uint32_t user_irq_3_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_3_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_3_ev_enable_read();
	uint32_t newword = user_irq_3_ev_enable_i0_replace(oldword, plain_value);
	user_irq_3_ev_enable_write(newword);
}

/* user_irq_4 */
#define CSR_USER_IRQ_4_BASE (CSR_BASE + 0x4800L)
#define CSR_USER_IRQ_4_IN_ADDR (CSR_BASE + 0x4800L)
#define CSR_USER_IRQ_4_IN_SIZE 1
static inline uint32_t user_irq_4_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x4800L);
}
#define CSR_USER_IRQ_4_MODE_ADDR (CSR_BASE + 0x4804L)
#define CSR_USER_IRQ_4_MODE_SIZE 1
static inline uint32_t user_irq_4_mode_read(void) {
	return csr_read_simple(CSR_BASE + 0x4804L);
}
static inline void user_irq_4_mode_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4804L);
}
#define CSR_USER_IRQ_4_EDGE_ADDR (CSR_BASE + 0x4808L)
#define CSR_USER_IRQ_4_EDGE_SIZE 1
static inline uint32_t user_irq_4_edge_read(void) {
	return csr_read_simple(CSR_BASE + 0x4808L);
}
static inline void user_irq_4_edge_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4808L);
}
#define CSR_USER_IRQ_4_EV_STATUS_ADDR (CSR_BASE + 0x480cL)
#define CSR_USER_IRQ_4_EV_STATUS_SIZE 1
static inline uint32_t user_irq_4_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x480cL);
}
#define CSR_USER_IRQ_4_EV_STATUS_I0_OFFSET 0
#define CSR_USER_IRQ_4_EV_STATUS_I0_SIZE 1
static inline uint32_t user_irq_4_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_4_ev_status_i0_read(void) {
	uint32_t word = user_irq_4_ev_status_read();
	return user_irq_4_ev_status_i0_extract(word);
}
#define CSR_USER_IRQ_4_EV_PENDING_ADDR (CSR_BASE + 0x4810L)
#define CSR_USER_IRQ_4_EV_PENDING_SIZE 1
static inline uint32_t user_irq_4_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x4810L);
}
static inline void user_irq_4_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4810L);
}
#define CSR_USER_IRQ_4_EV_PENDING_I0_OFFSET 0
#define CSR_USER_IRQ_4_EV_PENDING_I0_SIZE 1
static inline uint32_t user_irq_4_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_4_ev_pending_i0_read(void) {
	uint32_t word = user_irq_4_ev_pending_read();
	return user_irq_4_ev_pending_i0_extract(word);
}
static inline uint32_t user_irq_4_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_4_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_4_ev_pending_read();
	uint32_t newword = user_irq_4_ev_pending_i0_replace(oldword, plain_value);
	user_irq_4_ev_pending_write(newword);
}
#define CSR_USER_IRQ_4_EV_ENABLE_ADDR (CSR_BASE + 0x4814L)
#define CSR_USER_IRQ_4_EV_ENABLE_SIZE 1
static inline uint32_t user_irq_4_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x4814L);
}
static inline void user_irq_4_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x4814L);
}
#define CSR_USER_IRQ_4_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_IRQ_4_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_irq_4_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_4_ev_enable_i0_read(void) {
	uint32_t word = user_irq_4_ev_enable_read();
	return user_irq_4_ev_enable_i0_extract(word);
}
static inline uint32_t user_irq_4_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_4_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_4_ev_enable_read();
	uint32_t newword = user_irq_4_ev_enable_i0_replace(oldword, plain_value);
	user_irq_4_ev_enable_write(newword);
}

/* user_irq_5 */
#define CSR_USER_IRQ_5_BASE (CSR_BASE + 0x5000L)
#define CSR_USER_IRQ_5_IN_ADDR (CSR_BASE + 0x5000L)
#define CSR_USER_IRQ_5_IN_SIZE 1
static inline uint32_t user_irq_5_in_read(void) {
	return csr_read_simple(CSR_BASE + 0x5000L);
}
#define CSR_USER_IRQ_5_MODE_ADDR (CSR_BASE + 0x5004L)
#define CSR_USER_IRQ_5_MODE_SIZE 1
static inline uint32_t user_irq_5_mode_read(void) {
	return csr_read_simple(CSR_BASE + 0x5004L);
}
static inline void user_irq_5_mode_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x5004L);
}
#define CSR_USER_IRQ_5_EDGE_ADDR (CSR_BASE + 0x5008L)
#define CSR_USER_IRQ_5_EDGE_SIZE 1
static inline uint32_t user_irq_5_edge_read(void) {
	return csr_read_simple(CSR_BASE + 0x5008L);
}
static inline void user_irq_5_edge_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x5008L);
}
#define CSR_USER_IRQ_5_EV_STATUS_ADDR (CSR_BASE + 0x500cL)
#define CSR_USER_IRQ_5_EV_STATUS_SIZE 1
static inline uint32_t user_irq_5_ev_status_read(void) {
	return csr_read_simple(CSR_BASE + 0x500cL);
}
#define CSR_USER_IRQ_5_EV_STATUS_I0_OFFSET 0
#define CSR_USER_IRQ_5_EV_STATUS_I0_SIZE 1
static inline uint32_t user_irq_5_ev_status_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_5_ev_status_i0_read(void) {
	uint32_t word = user_irq_5_ev_status_read();
	return user_irq_5_ev_status_i0_extract(word);
}
#define CSR_USER_IRQ_5_EV_PENDING_ADDR (CSR_BASE + 0x5010L)
#define CSR_USER_IRQ_5_EV_PENDING_SIZE 1
static inline uint32_t user_irq_5_ev_pending_read(void) {
	return csr_read_simple(CSR_BASE + 0x5010L);
}
static inline void user_irq_5_ev_pending_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x5010L);
}
#define CSR_USER_IRQ_5_EV_PENDING_I0_OFFSET 0
#define CSR_USER_IRQ_5_EV_PENDING_I0_SIZE 1
static inline uint32_t user_irq_5_ev_pending_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_5_ev_pending_i0_read(void) {
	uint32_t word = user_irq_5_ev_pending_read();
	return user_irq_5_ev_pending_i0_extract(word);
}
static inline uint32_t user_irq_5_ev_pending_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_5_ev_pending_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_5_ev_pending_read();
	uint32_t newword = user_irq_5_ev_pending_i0_replace(oldword, plain_value);
	user_irq_5_ev_pending_write(newword);
}
#define CSR_USER_IRQ_5_EV_ENABLE_ADDR (CSR_BASE + 0x5014L)
#define CSR_USER_IRQ_5_EV_ENABLE_SIZE 1
static inline uint32_t user_irq_5_ev_enable_read(void) {
	return csr_read_simple(CSR_BASE + 0x5014L);
}
static inline void user_irq_5_ev_enable_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x5014L);
}
#define CSR_USER_IRQ_5_EV_ENABLE_I0_OFFSET 0
#define CSR_USER_IRQ_5_EV_ENABLE_I0_SIZE 1
static inline uint32_t user_irq_5_ev_enable_i0_extract(uint32_t oldword) {
	uint32_t mask = ((1 << 1)-1);
	return ( (oldword >> 0) & mask );
}
static inline uint32_t user_irq_5_ev_enable_i0_read(void) {
	uint32_t word = user_irq_5_ev_enable_read();
	return user_irq_5_ev_enable_i0_extract(word);
}
static inline uint32_t user_irq_5_ev_enable_i0_replace(uint32_t oldword, uint32_t plain_value) {
	uint32_t mask = ((1 << 1)-1);
	return (oldword & (~(mask << 0))) | (mask & plain_value)<< 0 ;
}
static inline void user_irq_5_ev_enable_i0_write(uint32_t plain_value) {
	uint32_t oldword = user_irq_5_ev_enable_read();
	uint32_t newword = user_irq_5_ev_enable_i0_replace(oldword, plain_value);
	user_irq_5_ev_enable_write(newword);
}

/* user_irq_ena */
#define CSR_USER_IRQ_ENA_BASE (CSR_BASE + 0x5800L)
#define CSR_USER_IRQ_ENA_OUT_ADDR (CSR_BASE + 0x5800L)
#define CSR_USER_IRQ_ENA_OUT_SIZE 1
static inline uint32_t user_irq_ena_out_read(void) {
	return csr_read_simple(CSR_BASE + 0x5800L);
}
static inline void user_irq_ena_out_write(uint32_t v) {
	csr_write_simple(v, CSR_BASE + 0x5800L);
}

#endif
