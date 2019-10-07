CC = g++
CFLAGS = -g -Wall -std=c++11
LEXER_DIR = lexer
COMMON_DIR = common
LEXER_FILE = lex.l
BUILD_DIR = build

TARGETS = bdir $(BUILD_DIR)/main.o #$(BUILD_DIR)/lexer.o

all : clean $(TARGETS)

bdir:
	mkdir -p $(BUILD_DIR)

clean :
	rm -f $(BUILD_DIR)/*

#$(BUILD_DIR)/lexer.o : $(BUILD_DIR)/lex.yy.c
#	$(CC) $(CFLAGS) -lfl -Icommon -o $(BUILD_DIR)/lexer.o $(BUILD_DIR)/lex.yy.c 

#$(BUILD_DIR)/lex.yy.c:
#	flex -o $@ $(LEXER_DIR)/$(LEXER_FILE)

$(BUILD_DIR)/main.o : $(BUILD_DIR)/Compiler.o
	$(CC) $(CFLAGS) -I$(COMMON_DIR) -I$(LEXER_DIR) $(BUILD_DIR)/Compiler.o $(BUILD_DIR)/HandLexer.o -o $@ $(COMMON_DIR)/main.cpp

$(BUILD_DIR)/Compiler.o : $(BUILD_DIR)/HandLexer.o
	$(CC) $(CFLAGS) -I$(COMMON_DIR) -c -I$(LEXER_DIR) -o $@ $(COMMON_DIR)/Compiler.cpp

$(BUILD_DIR)/HandLexer.o:
	$(CC) $(CFLAGS) -I$(LEXER_DIR) -c -o $@ $(LEXER_DIR)/HandLexer.cpp
