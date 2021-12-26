#!/bin/bash
#

if [ -f  lvs-compare-${1%.gds}-gds-vs-verilog.out ]; then
\mv lvs-compare-${1%.gds}-gds-vs-verilog.out lvs-compare-${1%.gds}-gds-vs-verilog.out.last
fi
if [ -f  ${1%.gds}-source.spice ]; then
\mv ${1%.gds}-source.spice ${1%.gds}-source.spice.last
fi
if [ -f  ${1%.gds}-gds-extracted.spice ]; then
\mv ${1%.gds}-gds-extracted.spice ${1%.gds}-gds-extracted.spice.last
fi
if [ -f  core ]; then
\rm core
fi

########################################################
###### Magic netlist extraction
########################################################

export MAGIC=magic
export PDKPATH=$PDK_ROOT/sky130A ; 
export MAGTYPE=$2

MAGTYPE=$MAGTYPE $MAGIC -dnull -noconsole -rcfile $PDKPATH/libs.tech/magic/sky130A.magicrc  << EOF

path search [concat "../$MAGTYPE" [path search]]
crashbackups stop
drc off
gds readonly true
gds flatten true
gds rescale false
tech unlock *
cif istyle sky130(vendor)
gds read $1
load ${1%.gds} -dereference
select top cell
#lef read  $PDK_ROOT/openlane/sky130A/libs.ref/sky130_fd_sc_hd/lef/sky130_fd_sc_hd.lef
#readspice $PDK_ROOT/openlane/sky130A/libs.ref/sky130_fd_sc_hd/cdl/sky130_fd_sc_hd.cdl}
#extract no all
extract do local
extract all
ext2spice lvs
ext2spice -o ${1%.gds}-gds-extracted.spice
EOF

\rm ./*.ext

#
########################################################
####### running netgen
########################################################

export NETGEN_COLUMNS=60
export MAGIC_EXT_USE_GDS=1

netgen -batch lvs \
        "${1%.gds}-gds-extracted.spice ${1%.gds}" \
		"./${1%.gds}.v ${1%.gds}" \
			     ./sky130A_setup.tcl \
			         lvs-compare-${1%.gds}-gds-vs-verilog.out
				 
########################################################

				 
				 
