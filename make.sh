#!/bin/bash

cd ./src/cfiles
gcc *.c -c
echo "Compiling object files in ./src/cfiles"
mv *.o ./../..
cd ../..
gcc *.o $1
echo "Linking object files with $1"
rm *.o
echo "Removing leftover object files"
echo "Compilation finished"
