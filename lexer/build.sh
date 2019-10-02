#!/bin/bash

rm -R ./bin
rm -R ./output

mkdir bin
mkdir output

flex myGrammar.l 

mv lex.yy.c ./output

gcc ./output/lex.yy.c -lfl -o ./bin/analyzer

./bin/analyzer <input.txt >./output/output.txt
