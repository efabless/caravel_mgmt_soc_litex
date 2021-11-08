#include <csr.h>
main() {

    #define reg_gpio_test (*(volatile uint32_t*)0x82000800)

    reg_gpio_test = 1;
    reg_gpio_test = 0;

//	gpio_ien_write(1);
//	gpio_mode0_write(1);
//	gpio_mode1_write(1);
//	gpio_ien_write(1);
//	gpio_oe_write(1);
//
//	gpio_ien_write(0);
//	gpio_mode0_write(0);
//    gpio_mode1_write(0);
//	gpio_ien_write(0);
//	gpio_oe_write(0);
}
