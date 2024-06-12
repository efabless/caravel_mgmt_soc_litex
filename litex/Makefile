# SPDX-FileCopyrightText: 2020 Efabless Corporation
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
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
PYTHON ?= python3
IN_ENV = if [ -e env/bin/activate ]; then . env/bin/activate; fi;
ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
LITEX_BUILD_DIR = $(ROOT_DIR)/build/caravel_platform
MGMT_SOC_DIR = $(ROOT_DIR)/../verilog

all: update_mgmt_soc_gateware generate_mgmt_soc_headers

update_mgmt_soc_gateware: $(MGMT_SOC_DIR)/rtl/mgmt_core.v
generate_mgmt_soc_headers: $(MGMT_SOC_DIR)/dv/generated/variables.mak

$(MGMT_SOC_DIR)/rtl/mgmt_core.v: $(LITEX_BUILD_DIR)/gateware/mgmt_core.v
	$(IN_ENV) python modify_verilog.py $< $@

$(MGMT_SOC_DIR)/dv/generated/variables.mak: $(LITEX_BUILD_DIR)/software/include/generated/variables.mak
	cp -R $(LITEX_BUILD_DIR)/software/include/generated $(MGMT_SOC_DIR)/dv/.

$(LITEX_BUILD_DIR)/gateware/mgmt_core.v $(LITEX_BUILD_DIR)/software/include/generated/variables.mak: caravel.py | env
	$(IN_ENV) python caravel.py

setup: env

env:
	@$(PYTHON) -mvenv env
	@$(IN_ENV) pip3 install -r requirements.txt

clean:
	rm -rf build env __pycache__

.PHONY: clean all
