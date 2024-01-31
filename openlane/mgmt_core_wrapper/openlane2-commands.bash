export RUN_TAG=RUN_12
rm -rf openlane/mgmt_core_wrapper/runs/$RUN_TAG
export MODE=NA   ; openlane openlane/mgmt_core_wrapper/config.json --run-tag $RUN_TAG --to OpenROAD.CTS
export MODE=TEST ; openlane openlane/mgmt_core_wrapper/config.json --run-tag $RUN_TAG --from OpenROAD.CTS-1 --to OpenROAD.ResizerTimingPostCTS
export MODE=NA   ; openlane openlane/mgmt_core_wrapper/config.json --run-tag $RUN_TAG --from OpenROAD.ResizerTimingPostCTS-1 --to OpenROAD.RepairDesignPostGRT
export MODE=TEST ; openlane openlane/mgmt_core_wrapper/config.json --run-tag $RUN_TAG --only OpenROAD.ResizerTimingPostGRT
export MODE=NA   ; openlane openlane/mgmt_core_wrapper/config.json --run-tag $RUN_TAG --from OpenROAD.ResizerTimingPostGRT-1 --to OpenROAD.STAPostPNR
export MODE=TEST ; openlane openlane/mgmt_core_wrapper/config.json --run-tag $RUN_TAG --from OpenROAD.STAPostPNR-1