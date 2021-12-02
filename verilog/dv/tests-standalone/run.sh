#!/bin/sh

#x=`basename $(pwd)` ; SIM=RTL	  make  2>&1 | tee -a verify-rtl.log     ; grep Monitor verify-rtl.log	  ; mv $x.vcd $x-rtl.vcd
#x=`basename $(pwd)` ; SIM=GL	  make  2>&1 | tee -a verify-gl.log      ; grep Monitor verify-gl.log     ; mv $x.vcd $x-gl.vcd
#x=`basename $(pwd)` ; SIM=GL_SDF  make  2>&1 | tee -a verify-gl-sdf.log  ; grep Monitor verify-gl-sdf.log ; mv $x.vcd $x-gl-sdf.vcd


#for x in `ls -d */` ; do cd $x ; SIM=GL  make  2>&1 | tee -a verify-rtl.log	; grep Monitor verify-rtl.log	 ; mv $x.vcd $x-rtl.vcd     ; done
#for x in `ls -d */` ; do cd $x ; SIM=GL  make  2>&1 | tee -a verify-gl.log	; grep Monitor verify-gl.log	 ; mv $x.vcd $x-gl.vcd	    ; done
#for x in `ls -d */` ; do cd $x ; SIM=GL  make  2>&1 | tee -a verify-gl-sdf.log  ; grep Monitor verify-gl-sdf.log ; mv $x.vcd $x-gl-sdf.vcd  ; done

make clean
SIM=$1 make  2>&1 | tee -a verify-$1.log  ; grep Monitor verify-$1.log 

