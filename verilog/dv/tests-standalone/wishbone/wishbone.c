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
#include <stub.c>
#include "mem.h"

// --------------------------------------------------------

// The wishbone slave simply registers the last written value

void main()
{
    volatile unsigned int *wb_start_addr = (volatile unsigned int *) MPRJ_BASE;
    unsigned int exp_size = 0x10000000;
    unsigned int error = 0;
    int i;

    // Start test
    reg_la0_oenb = 0;
    reg_la0_data = 0x1;

    // check reset value - 1st address
    if (*(wb_start_addr) != 0xDEADBEEF) {
        reg_la0_data = 0xE0000000;
    }
    // test the whole WB address space - walking "1"
    reg_la0_data = 0x2;
    for (i = 1; i < exp_size; i = i << 1) {
        *(wb_start_addr+i) = i;
        if (*(wb_start_addr+i) != i) {
            reg_la0_data = 0xE0000001;
        }
    }
    // check reset value - last address
    reg_la0_data = 0x3;
    if (*(wb_start_addr+exp_size-1) != 0xDEADBEEF) {
        reg_la0_data = 0xE0000002;
    }

    // End test
    reg_la0_data = 0x10000000;
}
