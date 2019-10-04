CC = gcc
CFLAGS = 
LEXER_DIR = lexer
LEXER_FILE = lex.l
BUILD_DIR = build


TARGETS = bdir $(BUILD_DIR)/lexer.o

all : clean $(TARGETS)

bdir:
	mkdir -p $(BUILD_DIR)

clean :
	rm -f $(BUILD_DIR)/*
	
$(BUILD_DIR)/lexer.o : $(BUILD_DIR)/lex.yy.c
	$(CC) $(CFLAGS) -lfl -Icommon -o $(BUILD_DIR)/lexer.o $(BUILD_DIR)/lex.yy.c 
	
$(BUILD_DIR)/lex.yy.c:
	flex -o $@ $(LEXER_DIR)/$(LEXER_FILE)
	