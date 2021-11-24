
if { [info exist ::env(MAGIC_EXT_USE_GDS)] && $::env(MAGIC_EXT_USE_GDS) } {
	gds read $::env(CURRENT_GDS)
} else {
	lef read /ciic/pdks/sky130A/libs.ref/sky130_fd_sc_hd/techlef/sky130_fd_sc_hd.tlef
	if {  [info exist ::env(EXTRA_LEFS)] } {
		set lefs_in $::env(EXTRA_LEFS)
		foreach lef_file $lefs_in {
			lef read $lef_file
		}
	}
	def read /project/openlane/mgmt_core/runs/RUN_2021.11.23_18.34.59/results/routing/21-mgmt_core.def
}
load mgmt_core -dereference
cd /project/openlane/mgmt_core/runs/RUN_2021.11.23_18.34.59/results/magic/
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
ext2spice -o /project/openlane/mgmt_core/runs/RUN_2021.11.23_18.34.59/results/magic/mgmt_core.spice mgmt_core.ext
feedback save /project/openlane/mgmt_core/runs/RUN_2021.11.23_18.34.59/logs/magic/37-magic_ext2spice.feedback.txt
# exec cp mgmt_core.spice /project/openlane/mgmt_core/runs/RUN_2021.11.23_18.34.59/results/magic/mgmt_core.spice

