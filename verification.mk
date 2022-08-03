verification_image = efabless/dv:latest

logs_dir = logs
project_root      = $(realpath $(pwd))
caravel_core_dir  = $(MCW_ROOT)
standalone_dir    = $(MCW_ROOT)/verilog/dv/tests-standalone
caravel_test_dir  = $(MCW_ROOT)/verilog/dv/tests-caravel

threads ?= 1
SIM ?= RTL

ifeq ($(wildcard $(MCW_ROOT)/.),)
$(error $(MCW_ROOT) not found)
endif
ifeq ($(wildcard $(CARAVEL_ROOT)/.),)
$(error $(CARAVEL_ROOT) not found)
endif
ifeq ($(wildcard $(caravel_core_dir)/.),)
$(error $(caravel_core_dir) not found)
endif

standalone = $(shell cd $(standalone_dir) && find * -maxdepth 0 -type d)
caravel_test = $(shell cd $(caravel_test_dir) && find * -maxdepth 0 -type d)
standalone_targets := $(foreach i, $(standalone), standalone-$(i))
caravel_test_targets := $(foreach i, $(caravel_test), caravel-$(i))

docker_env =  -e CARAVEL_VERILOG_PATH=$(CARAVEL_ROOT)/verilog
docker_env += -e CORE_VERILOG_PATH=$(caravel_core_dir)/verilog
docker_env += -e PDK_ROOT=$(PDK_ROOT)
docker_env += -e PDK=$(PDK)

check_defined = \
		    $(strip $(foreach 1,$1, \
		            $(call __check_defined,$1,$(strip $(value 2)))))
__check_defined = \
		      $(if $(value $1),, \
		            $(error undefined $1$(if $2, ($2))))

$(call check_defined, PDK_ROOT CARAVEL_ROOT PDK MCW_ROOT, please define missing variables)

docker_runner_cmd = docker run -t \
			    -v $(MCW_ROOT):$(MCW_ROOT) \
			    -v $(CARAVEL_ROOT):$(CARAVEL_ROOT) \
			    -v $(PDK_ROOT):$(PDK_ROOT) \
			    $(docker_env) \
			    -u $(shell id -u $(user)):$(shell id -g $(user)) \
			    $(verification_image) \


.phony: $(caravel_test_targets)
.phony: $(caravel_test)
.phony: $(standalone_targets)
.phony: $(standalone)
.phony: $(standalone_targets)
.phony: list-standalone
.phony: list-caravel
.phony: list

all: $(standalone_targets) $(caravel_test_targets)

list: list-standalone list-caravel

list-standalone:
	# standalone $(standalone_targets)

list-caravel:
	# caravel $(caravel_test_targets)

$(logs_dir):
	@mkdir -p logs

$(standalone_targets): standalone-% : $(logs_dir)
	@echo "time: $$(date) --------------------------------------------------------"
	# target: $(standalone_dir)/$*
	# caravel: $(CARAVEL_ROOT)
	# sim: $(SIM)
	# running $@
	@$(docker_runner_cmd) \
		bash -c "source /.bashrc && env && cd $(standalone_dir)/$* && make $(SIM) -j$(threads)" 2>&1 > $(logs_dir)/$@.log
	@echo "time: $$(date) +++++++++++++++++++++++++++++++++++++++++ done $@"

$(caravel_test_targets): caravel-% : $(logs_dir)
	@echo "time: $$(date) --------------------------------------------------------"
	# target: $(caravel_test_dir)/$*
	# caravel: $(CARAVEL_ROOT)
	# sim: $(SIM)
	# running $@
	@$(docker_runner_cmd) \
		bash -c "source /.bashrc && env && cd $(caravel_test_dir)/$* && make $(SIM) -j$(threads)" 2>&1 > $(logs_dir)/$@.log
	@echo "time: $$(date) +++++++++++++++++++++++++++++++++++++++++ done $@"
