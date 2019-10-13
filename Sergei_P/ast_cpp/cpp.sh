rm -rf ./unite.so

bison -d parser.y
flex scanner.l
g++ -fPIC -c unified.cpp
gcc -fPIC -c parser.tab.c lex.yy.c -lfl
g++ -shared -fPIC -o unite.so unified.o parser.tab.o lex.yy.o unite.cpp -lfl
python3 test.py
