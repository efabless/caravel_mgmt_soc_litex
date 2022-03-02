##
set ::env(PL_RESIZER_SETUP_MAX_BUFFER_PERCENT) "50"

##
set ::env(PL_RESIZER_HOLD_SLACK_MARGIN) "0.15"
set ::env(GLB_RESIZER_HOLD_SLACK_MARGIN) "0.3"

##
set ::env(PL_TARGET_DENSITY) 0.3

##
set ::env(PL_LIB) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__tt_025C_1v80.lib"

##
set ::env(LIB_CTS) "/project/openlane/mgmt_core/runs/mgmt_core/tmp/cts/cts.lib"

##
set ::env(LIB_FASTEST) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"

## Extraction and STA Analysis
set ::env(LIB_RCX) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"

##
set ::env(LIB_RESIZER_OPT) "/project/openlane/mgmt_core/runs/mgmt_core/tmp/synthesis/resizer_sky130_fd_sc_hd__ff_n40C_1v95.lib"

##
set ::env(LIB_SLOWEST) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ss_100C_1v60.lib"
set ::env(LIB_SLOWEST_OPT) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ss_100C_1v60.lib"

##
set ::env(LIB_SYNTH) "/project/openlane/mgmt_core/runs/mgmt_core/tmp/synthesis/trimmed.lib"
set ::env(LIB_SYNTH_COMPLETE) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"
set ::env(LIB_SYNTH_COMPLETE_NO_PG) "/project/openlane/mgmt_core/runs/mgmt_core/tmp/synthesis/1-sky130_fd_sc_hd__ff_n40C_1v95.no_pg.lib"

##
set ::env(LIB_TYPICAL) "$::env(PDK_ROOT)/$::env(PDK)/libs.ref/sky130_fd_sc_hd/lib/sky130_fd_sc_hd__ff_n40C_1v95.lib"


