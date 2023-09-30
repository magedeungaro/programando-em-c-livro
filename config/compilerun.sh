#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Please provide a file name as an argument."
    exit 1
fi

filename="$1"
binaryname="game-${filename%.*}"

gcc -g "$filename" -o "$binaryname" -lm
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running $binaryname..."
    "./$binaryname"
else
    echo "Compilation failed."
fi