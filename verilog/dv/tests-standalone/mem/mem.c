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

#include <defs.h>
#include <stdint.h>

// --------------------------------------------------------

/*
	Memory Test
	It uses GPIO to flag the success or failure of the test
*/

#define COUNT 5

// DFFRAM
//unsigned int ints[10];
//unsigned short shorts[10];
//unsigned char bytes[10];
unsigned long *ints    = (unsigned long *)  0x00000100;
unsigned short *shorts = (unsigned short *) 0x00000200;
unsigned char *bytes   = (unsigned char *)  0x0000300;

void main()
{
    int i, v;

    // SRAM
    unsigned long *sr_ints    = (unsigned long *)  0x01000000;
    unsigned short *sr_shorts = (unsigned short *) 0x01000200;
    unsigned char *sr_bytes   = (unsigned char *)  0x01000400;

    // start test
    reg_la0_oenb = 0;
    reg_la0_data = 0xA0400000;

    // Test Word R/W
    for (i=0; i<COUNT; i++) {
	     *(sr_ints+i) = i*5000 + 10000;
	     *(ints+i) = i*5000 + 10000;
     }

    for (i=0; i<COUNT; i++) {
        v = i*5000+10000;
        if ( v != *(ints+i) || v != *(sr_ints+i) )
            reg_la0_data = 0xAB400000;
    }

    reg_la0_data = 0xAB410000;

    // Test Half Word R/W
    reg_la0_data = 0xA0200000;
    for (i=0; i<COUNT; i++) {
	    *(sr_shorts+i) = i*500 + 100;
	    *(shorts+i) = i*500 + 100;
    }

    for(i=0; i<COUNT; i++) {
        v = i*500+100;
        if(v != *(shorts+i) || v != *(sr_shorts+i))
            reg_la0_data = 0xAB200000;
    }

    reg_la0_data = 0xAB210000;

    // Test byte R/W
    reg_la0_data = 0xA0100000;
    for(i=0; i<COUNT; i++) {
        *(sr_bytes+i) = i*5 + 10;
        *(bytes+i) = i*5 + 10;
    }

    for(i=0; i<COUNT; i++) {
        v = i*5+10;
        if(v != *(bytes+i) && v != *(sr_bytes+i))
            reg_la0_data = 0xAB100000;
    }

    reg_la0_data = 0xAB110000;
}