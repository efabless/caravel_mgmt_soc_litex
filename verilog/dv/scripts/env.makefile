# SPDX-FileCopyrightText: 2020 Efabless Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with he License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# SPDX-License-Identifier: Apache-2.0

# ---- Environment Variables ----

export PDK_PATH = $(PDK_ROOT)/sky130A
export VERILOG_PATH = ../../..

VIP_PATH = $(VERILOG_PATH)/dv/vip
FIRMWARE_PATH = $(VERILOG_PATH)/dv/firmware

# ---- Compiler Information ----

GCC_PATH?=$(TOOLS)/bin
GCC_PREFIX?=riscv32-unknown-linux-gnu



