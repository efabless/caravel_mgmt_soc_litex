
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
	def read /project/openlane/DFFRAM/runs/RUN_2021.12.26_22.11.38/results/routing/DFFRAM.def
}
load DFFRAM -dereference
cd /project/openlane/DFFRAM/runs/RUN_2021.12.26_22.11.38/results/finishing/
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
ext2spice -o /project/openlane/DFFRAM/runs/RUN_2021.12.26_22.11.38/results/finishing/DFFRAM.spice DFFRAM.ext
feedback save /project/openlane/DFFRAM/runs/RUN_2021.12.26_22.11.38/logs/finishing/30-ext2spice.feedback.txt
# exec cp DFFRAM.spice /project/openlane/DFFRAM/runs/RUN_2021.12.26_22.11.38/results/finishing/DFFRAM.spice

