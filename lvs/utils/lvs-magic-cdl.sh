#!/bin/bash
#

if [ -f  ./reports/${MAGTYPE}-vs-spice-${1%.mag}l.out ]; then
\mv ./reports/${MAGTYPE}-vs-spice-${1%.mag} ./reports/${MAGTYPE}-vs-spice-${1%.mag}.last
fi
if [ -f  ../netlists/${1%.mag}-$MAGTYPE-extracted.spice ]; then
\mv ./netlists/${1%.mag}-$MAGTYPE-extracted.spice ./netlists/${1%.mag}-$MAGTYPE-extracted.spice.last
fi
if [ -f  core ]; then
\rm core
fi


########################################################
###### Magic netlist extraction
########################################################

export MAGIC=magic
export PDKPATH=$PDK_ROOT/$PDK ; 
export MAGTYPE=$2

$MAGIC -dnull -noconsole -rcfile $PDKPATH/libs.tech/magic/$PDK.magicrc  << EOF

path search [concat "../$MAGTYPE" [path search]]
addpath ${PDKPATH}/libs.ref/sky130_ml_xx_hd/mag
addpath ../mag/hexdigits
###addpath ../mag/
path
drc off
load $1  
cellname list filepath ${1%.mag} ../mag 
flush ${1%.mag}		
select top cell
expand
extract do local
extract all			    
ext2spice lvs			    
ext2spice -o ./netlists/${MAGTYPE}-extracted-${1%.gds}.spice

#########
EOF

\rm ../${MAGTYPE}/*.ext

#cat ./sky130_fd_pr__base.spice >> ./${1%.mag}-$MAGTYPE-extracted.spice

########################################################
####### convert vlog to gate-level and include 
########################################################

./utils/vlog2Spice ../verilog/gl/${1%.mag}.v -o 		./netlists/cdl-source-${1%.mag}.spice \
-l ./pdk/sky130_fd_sc_hd.spice   -l ./pdk/sky130_fd_sc_hvl.spice -i 

### -l ./sky130_fd_pr__base.spice

########################################################
####### convert lines starting with +into a single line 
####### (netgen doesn't seem to like multiple spice lines 
####### starting with +)
########################################################

./utils/unfold ./netlists/cdl-source-${1%.mag}.spice > 		./netlists/cdl-source-${1%.mag}.spice.unfolded
           \mv ./netlists/cdl-source-${1%.mag}.spice 		./netlists/${1%.mag}-source.spice.folded
           \mv ./netlists/cdl-source-${1%.mag}.spice.unfolded 	./netlists/cdl-source-${1%.mag}.spice
           \rm ./netlists/cdl-source-${1%.mag}.spice.folded 
#
########################################################
####### running netgen
########################################################

export NETGEN_COLUMNS=60

netgen -batch lvs \
        "./netlists/${MAGTYPE}-extracted-${1%.gds}.spice ${1%.mag}" \
		"./netlists/cdl-source-${1%.mag}.spice ${1%.mag}" \
			     ./pdk/$PDK_VARIENT_setup.tcl \
			         ./reports/${MAGTYPE}-vs-cdl-${1%.mag}.out
				 
########################################################

########################################################
####### create another file with .cdl extention for Cal runs (netgen doesn't like .cdl input file ext)
########################################################

\cp ./netlists/${1%.mag}-source.spice ./netlists/${1%.mag}.cdl

