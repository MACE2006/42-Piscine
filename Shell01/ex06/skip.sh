#!/bin/bash
ls -l | sed -n 'p;n'
# ls -l : list files and directories in more detail
# sed : edits the test flow output
# -n : Supresses all information normally written to standard output
# p : prints the current line of input
# n : skip next line
