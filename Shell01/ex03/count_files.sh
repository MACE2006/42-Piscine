#!/bin/bash
find . | wc -l
# find . : finds all files in current directory and all its subdirectories
# | : pipelin (Uses output from last command as input for next command)
# wc -l : counts the number of lines from the input
