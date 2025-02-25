#!/bin/bash

#CHECK FOR TWO ARGUMENTS
if [ $# -ne 2 ]
then
	echo "Usage: ./make c_file output_name"
	exit 1
fi

#MAIN PROGRAM
gcc "$1" ./src/*.c -o "$2"
