#include <defs.h>

main() {

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
