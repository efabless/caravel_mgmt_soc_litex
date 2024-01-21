rm -rf openlane/mgmt_core_wrapper/runs/NEW_4
export MODE=NA   ; openlane openlane/mgmt_core_wrapper/config.json --run-tag NEW_4 --to OpenROAD.CTS
export MODE=TEST ; openlane openlane/mgmt_core_wrapper/config.json --run-tag NEW_4 --from OpenROAD.CTS-1 --to OpenROAD.ResizerTimingPostCTS
export MODE=NA   ; openlane openlane/mgmt_core_wrapper/config.json --run-tag NEW_4 --from OpenROAD.ResizerTimingPostCTS-1 --to OpenROAD.RepairDesignPostGRT
export MODE=TEST ; openlane openlane/mgmt_core_wrapper/config.json --run-tag NEW_4 --only OpenROAD.ResizerTimingPostGRT
export MODE=NA   ; openlane openlane/mgmt_core_wrapper/config.json --run-tag NEW_4 --from OpenROAD.ResizerTimingPostGRT-1 --to OpenROAD.STAPostPNR
export MODE=TEST ; openlane openlane/mgmt_core_wrapper/config.json --run-tag NEW_4 --from OpenROAD.STAPostPNR-1