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
IN_ENV  = if [ -e env/bin/activate ]; then . env/bin/activate; fi;

all: mgmt_soc

mgmt_soc: caravel.py
	@$(IN_ENV) python caravel.py
	@$(IN_ENV) python modify_verilog.py
	cp build/caravel_platform/gateware/mgmt_core_modified.v ../verilog/rtl/mgmt_core.v
	cp -R build/caravel_platform/software/include/generated ../verilog/dv/.

setup:
	@$(PYTHON) -mvenv env
	@$(IN_ENV) pip3 install -r requirements.txt

.PHONY: clean hex all
