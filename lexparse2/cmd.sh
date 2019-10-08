

rm -rf ./unite
bison -vd parser.y
flex scanner.l
gcc -o unite parser.tab.c lex.yy.c -lfl 2> gcc.txt
./unite < test.i > result.txt
cat result.txt

