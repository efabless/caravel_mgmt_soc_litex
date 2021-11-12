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

#include </defs.h>

// --------------------------------------------------------

/*
	Storage area Test
	It uses GPIO to flag the success or failure of the test
*/

void main()
{
    int i;
    volatile uint32_t* ram_addr; 
    /* Upper 16 user area pins are configured to be GPIO output */

    // Test Management R/W block0
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block0 + i;
        *ram_addr = i*5000 + 10000;
    }
	
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block0 + i;
        if ((i*5000+10000) != *ram_addr) 
	    reg_mprj_datal = 0xAB400000;
    }
	
    reg_mprj_datal = 0xAB410000;
	
    // Test Management R/W block1
    reg_mprj_datal = 0xA0200000;
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block1 + i;
        *ram_addr = i*5000 + 10000;
    }
	
    for (i=0; i<10; i++){
        ram_addr = &reg_rw_block1 + i;
        if ((i*5000+10000) != *ram_addr) 
	    reg_mprj_datal = 0xAB200000;
    }
    
    reg_mprj_datal = 0xAB210000;
}

