#include <csr.h>
main() {

    #define reg_gpio_mode1  (*(volatile uint32_t*)0x82000800)
    #define reg_gpio_mode0  (*(volatile uint32_t*)0x82000804)
    #define reg_gpio_ien    (*(volatile uint32_t*)0x82000808)
    #define reg_gpio_oe     (*(volatile uint32_t*)0x8200080c)
    #define reg_gpio_in     (*(volatile uint32_t*)0x82000810)
    #define reg_gpio_out    (*(volatile uint32_t*)0x82000814)

    reg_gpio_mode1 = 1;
    reg_gpio_mode0 = 1;
    reg_gpio_mode1 = 0;
    reg_gpio_mode0 = 0;

    reg_gpio_ien = 1;
    reg_gpio_oe = 1;

    reg_gpio_out = 1;
    reg_gpio_out = 0;

//	gpio_ien_write(1);
//	gpio_ien_write(0);
//	gpio_mode0_write(1);
	gpio_mode1_write(1);
//	gpio_ien_write(1);
//	gpio_oe_write(1);
//
//	gpio_ien_write(0);
//	gpio_mode0_write(0);
//    gpio_mode1_write(0);
//	gpio_ien_write(0);
//	gpio_oe_write(0);
}
