include ../generated/variables.mak

ifeq ($(CPU),picorv32)
	LINK_SCRIPT=$(FIRMWARE_PATH)/sections.lds
	SOURCE_FILES=$(FIRMWARE_PATH)/start.S $(FIRMWARE_PATH)/isr.c
	VERILOG_FILES=
endif

ifeq ($(CPU),ibex)
	LINK_SCRIPT=$(FIRMWARE_PATH)/link_ibex.ld
	SOURCE_FILES=$(FIRMWARE_PATH)/crt0_ibex.S $(FIRMWARE_PATH)/simple_system_common.c
	VERILOG_FILES=../ibex/*
endif

ifeq ($(CPU),vexriscv)
	LINK_SCRIPT=$(FIRMWARE_PATH)/sections_vexriscv.lds
	SOURCE_FILES=$(FIRMWARE_PATH)/start_caravel_vexriscv.s
	VERILOG_FILES=
endif

