#!/bin/bash
ifconfig | grep -o -E '([[:xdigit:]]{1,2}:){5}[[:xdigit:]]{1,2}'
# ifconfig : Prints System Network settings
# grep -o -E : Search text by pattern
# ([[:xdigit:]]{1,2}:) : search two hexadceimal digits with two points at the end
# {5} : Repeat previous 5 times
# [[:xdigit:]]{1,2}: search pattern of hexadecimal digits without two points after
