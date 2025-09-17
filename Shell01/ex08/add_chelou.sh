#!/bin/bash

#Test 1:
#str1="\'?"
#str2='"\"'
#str3="'"
#str4='\'
#FT_NBR1=$str1$str2$str3$str4
#FT_NBR2=rcrdmddd

#Test 2:
#l="!"
#s='\"\"'
#FT_NBR1=$s$l$s$l$s$l$s$l$s$l$s
#FT_NBR2=dcrcmcmooododmrrrmorcmcrmomo

echo $FT_NBR1 + $FT_NBR2 | sed "s/'/0/g" | tr '\\"?!' 1234 | tr "mrdoc" 01234 |\
xargs echo 'obase=13; ibase=5;' | bc | tr 0123456789ABC 'gtaio luSnemf'
