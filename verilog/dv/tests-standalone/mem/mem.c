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
//unsigned int ints[10];
unsigned short shorts[10];
unsigned char bytes[10];

void main()
{
    int i;

    int *ints = (volatile int*) 0x01000000;

    // start test
    reg_la0_oenb = 0;
    reg_la0_data = 0xA0400000;

//    #define mem_loc (*(volatile uint32_t*) 0x10000104)
//    #define mem_loc (*(volatile uint32_t*) 0x11000104)
//    mem_loc = 0xab;
//
//    reg_la0_data = mem_loc;

    // Test Word R/W
    for (i=0; i<10; i++)
	    ints[i] = i*5000 + 10000;

    for (i=0; i<10; i++)
        if ((i*5000+10000) != ints[i])
            reg_la0_data = 0xAB400000;

    reg_la0_data = 0xAB410000;

    // Test Half Word R/W
    reg_la0_data = 0xA0200000;
    for (i=0; i<10; i++)
	    shorts[i] = i*500 + 100;

    for(i=0; i<10; i++)
        if((i*500+100) != shorts[i])
            reg_la0_data = 0xAB200000;

    reg_la0_data = 0xAB210000;

    // Test byte R/W
    reg_la0_data = 0xA0100000;
    for(i=0; i<10; i++)
        bytes[i] = i*5 + 10;

    for(i=0; i<10; i++)
        if((i*5+10) != bytes[i])
            reg_la0_data = 0xAB100000;

    reg_la0_data = 0xAB110000;
}