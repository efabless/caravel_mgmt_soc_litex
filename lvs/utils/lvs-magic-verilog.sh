#!/bin/bash
#



if [ -f  ./reports/${1%.gds}-magic-verilog.out ]; then
\mv ./reports/${1%.gds}-magic-verilog.out ./reports/${1%.gds}-magic-verilog.out.last
fi
if [ -f  ../netlists/${1%.mag}-$MAGTYPE-extracted.spice ]; then
\mv ./netlists/${1%.mag}-$MAGTYPE-extracted.spice ./netlists/${1%.mag}-$MAGTYPE-extracted.spice.last
fi
if [ -f  core ]; then
\rm core
fi


export MAGIC=magic
export PDKPATH=$PDK_ROOT/sky130A ; 
export MAGTYPE=$2

$MAGIC -dnull -noconsole -rcfile $PDKPATH/libs.tech/magic/sky130A.magicrc  << EOF


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
ext2spice -o ./netlists/${1%.mag}-$MAGTYPE-extracted.spice

#########
EOF

\rm ../${MAGTYPE}/*.ext

export NETGEN_COLUMNS=60
export MAGIC_EXT_USE_GDS=1

netgen -batch lvs \
"./netlists/${1%.mag}-${MAGTYPE}-extracted.spice  ${1%.mag}" \
 "../verilog/gl/${1%.mag}.v ${1%.mag}" \
./pdk/sky130A_setup.tcl \
./reports/${1%.mag}.${MAGTYPE}-vs-verilog.out


