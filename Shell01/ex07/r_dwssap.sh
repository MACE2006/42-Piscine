#!/bin/bash

#Remove the comment # on lines 4 & 5 to test script
#FT_LINE1=7
#FT_LINE2=15

cat /etc/passwd |\
sed '/^#/d' |\
awk 'NR%2==0' |\
cut -d: -f1 |\
rev |\
sort -r |\
sed -n "${FT_LINE1},${FT_LINE2}p" |\
tr '\n' ' ' |\
sed 's+ +, +g' |\
sed 's+, $+.+g'|\
tr -d '\n' 

# cat /etc/passwd : Shows content about system logins
# sed ´/^#/d' : Removes all the lines with comments
# awk ´NR%2==0': Select only the odd lines
# cut -d: -f1 : Extracts the first column before the ´:'
# rev : reverses the order of characters
# sort -r : order in reverse alphabetical
# sed -n "${FT_LINE1},${FT_LINE2}p : prints the lines that are among the last variables
# tr ´\n' ´  : Replaces new line with space
# sed s+ +, +g : replaces all spaces with comma before a space
# sed s+, $+.+g : replaces the last comma with a point
# tr -d \n : deletes the new line at end
