#/bin/bash

# Checks if bin exists before compiling
if [ -d bin ]
    then
        make clean
fi

# Creates bin and then checks for errors
mkdir bin
make
