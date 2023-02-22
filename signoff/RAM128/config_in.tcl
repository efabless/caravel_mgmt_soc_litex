
            set ::env(DESIGN_NAME) "RAM128"

            set ::env(CLOCK_PORT) "CLK"
            set ::env(CLOCK_PERIOD) "15"

            set ::env(LEC_ENABLE) "0"
            set ::env(FP_WELLTAP_CELL) "gf180mcu_fd_sc_mcu7t5v0__filltie*"

            set ::env(GPL_CELL_PADDING) "0"
            set ::env(DPL_CELL_PADDING) "0"
            set ::env(RUN_FILL_INSERTION) "0"
            set ::env(PL_RESIZER_DESIGN_OPTIMIZATIONS) "0"
            set ::env(PL_RESIZER_TIMING_OPTIMIZATIONS) "0"
            set ::env(GLB_RESIZER_DESIGN_OPTIMIZATIONS) "0"
            set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) "0"

            set ::env(RT_MAX_LAYER) "met4"
            set ::env(GRT_ALLOW_CONGESTION) "1"

            set ::env(CELLS_LEF) "$::env(DESIGN_DIR)/cells.lef"

            set ::env(DIE_AREA) "0 0 402.5 470.56"

            set ::env(DIODE_INSERTION_STRATEGY) "0"

            set ::env(ROUTING_CORES) 1

            set ::env(DESIGN_IS_CORE) "0"
            set ::env(FP_PDN_CORE_RING) "0"

            set ::env(PRODUCTS_PATH) "./build/128x32_DEFAULT/products"

            set ::env(INITIAL_NETLIST) "$::env(DESIGN_DIR)/RAM128.nl.v"
            set ::env(INITIAL_ODB) "$::env(DESIGN_DIR)/RAM128.placed.odb"
            set ::env(INITIAL_SDC) "$::env(BASE_SDC_FILE)"

            set ::env(LVS_CONNECT_BY_LABEL) "1"

            set ::env(SYNTH_DRIVING_CELL) "sky130_fd_sc_hd__inv_8"
            set ::env(SYNTH_DRIVING_CELL_PIN) "Y"
            set ::env(IO_PCT) "0.25"

            