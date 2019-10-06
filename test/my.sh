#!/bin/bash
bison -d parser.y
flex scanner.l
gcc -o unite parser.tab.c lex.yy.c -lfl
./unite < test.i
