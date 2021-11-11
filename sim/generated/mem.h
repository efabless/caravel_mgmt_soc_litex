//--------------------------------------------------------------------------------
// Auto-generated by Migen (7507a2b) & LiteX (8ff6cd0) on 2021-11-11 07:02:06
//--------------------------------------------------------------------------------
#ifndef __GENERATED_MEM_H
#define __GENERATED_MEM_H

#ifndef SRAM_BASE
#define SRAM_BASE 0x10000000L
#define SRAM_SIZE 0x00000800
#endif

#ifndef FLASH_BASE
#define FLASH_BASE 0x00000000L
#define FLASH_SIZE 0x01000000
#endif

#ifndef CSR_BASE
#define CSR_BASE 0x82000000L
#define CSR_SIZE 0x00010000
#endif

#ifndef MEM_REGIONS
#define MEM_REGIONS "SRAM      0x10000000 0x800 \nFLASH     0x00000000 0x1000000 \nCSR       0x82000000 0x10000 "
#endif
#endif
