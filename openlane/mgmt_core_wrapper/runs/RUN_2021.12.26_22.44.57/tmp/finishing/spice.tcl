
if { [info exist ::env(MAGIC_EXT_USE_GDS)] && $::env(MAGIC_EXT_USE_GDS) } {
	gds read $::env(CURRENT_GDS)
} else {
	lef read /ciic/pdks/openlane/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd.tlef
	if {  [info exist ::env(EXTRA_LEFS)] } {
		set lefs_in $::env(EXTRA_LEFS)
		foreach lef_file $lefs_in {
			lef read $lef_file
		}
	}
	def read /project/openlane/mgmt_core_wrapper/runs/RUN_2021.12.26_22.44.57/results/routing/mgmt_core_wrapper.def
}
load mgmt_core_wrapper -dereference
cd /project/openlane/mgmt_core_wrapper/runs/RUN_2021.12.26_22.44.57/results/finishing/
extract do local
extract no capacitance
extract no coupling
extract no resistance
extract no adjust
if { ! 0 } {
	extract unique
}
# extract warn all
extract

ext2spice lvs
ext2spice -o /project/openlane/mgmt_core_wrapper/runs/RUN_2021.12.26_22.44.57/results/finishing/mgmt_core_wrapper.spice mgmt_core_wrapper.ext
feedback save /project/openlane/mgmt_core_wrapper/runs/RUN_2021.12.26_22.44.57/logs/finishing/23-ext2spice.feedback.txt
# exec cp mgmt_core_wrapper.spice /project/openlane/mgmt_core_wrapper/runs/RUN_2021.12.26_22.44.57/results/finishing/mgmt_core_wrapper.spice

