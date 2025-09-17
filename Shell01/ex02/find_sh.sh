#!/bin/bash
find . -type f -name '*.sh' -execdir basename -s '.sh' {} +

#find . -tpye f : Find all files in current directory and all sub directories
#-name ´*.sh' : all files with *.sh extension
#-execdir basename -s ´.sh': removes the .sh extenstion when displaying the file
#{} +: Run the command to multiple files at once
