#!/bin/bash

rm -R output
mkdir output
../build/lexer.o <input.txt >./output/output.txt
