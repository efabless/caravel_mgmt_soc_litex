#include "csr.h"
main() {
	gpio_ien_write(1);
	gpio_mode0_write(1);
	gpio_mode1_write(1);
	gpio_ien_write(1);
	gpio_oe_write(1);
	
	gpio_ien_write(0);
	gpio_mode0_write(0);
    gpio_mode1_write(0);
	gpio_ien_write(0);
	gpio_oe_write(0);
}
