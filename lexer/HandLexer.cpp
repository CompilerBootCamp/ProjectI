#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include "HandLexer.hpp"

namespace Ilang
{
    HandLexer::HandLexer(const std::string& filename) {
        line = 0;
        position = 0;
        wordSize = 0;

        std::ifstream in(filename);
        std::stringstream ss;

        if(in.is_open()) {
            ss << in.rdbuf();
	        file = ss.str();
        }
        in.close();
    }

    HandLexer::~HandLexer() {};

    bool HandLexer::doTokenisation(void) {
        for (unsigned int i = 0; i < file.length();i++) {
            if(isSingleSign(file[i])) {
                if(wordSize) {
                	printToken(word, wordSize);
                    wordSize = 0;
                }
                printToken(&file[i], 1);
            } else if (isAmbigousSign(file[i])) {
                if(wordSize && !(isdigit(file[i+1]) && isdigit(file[i-1]))) {
                	printToken(word, wordSize);
                    wordSize = 0;
                }
                if(isEqualSign(file[i+1]) || isDotSign(file[i+1])) {
                	printToken(&file[i], 2);
                    i++;
                } else if (isdigit(file[i+1]) && isdigit(file[i-1])) {
                	word[wordSize] = file[i];
                	wordSize++;
                } else {
                	printToken(&file[i], 1);
                }
            } else if (isWhitespace(file[i])) {
                if(wordSize) {
                	printToken(word, wordSize);
                    wordSize = 0;
                }
            } else {// add sign to word
            	word[wordSize] = file[i];
            	wordSize++;
            }
        }
        
        return false;
    }

    bool HandLexer::hash(const char* key, unsigned int len, unsigned int& result) {
        
        return false;
    }
    
    bool HandLexer::isSingleSign(const char sign) {
        if ( sign == '(' || sign == ')' ||
             sign == '[' || sign == ']' ||
             sign == ';' || sign == '=' ||
             sign == '*' || sign == '%' ||
             sign == '+' || sign == '-' ||
             sign == ',') {
            return true;
        }
        return false;
    }
    
    bool HandLexer::isAmbigousSign(const char sign) {
        if ( sign == '/' || sign == '<' ||
             sign == '>' || sign == ':' ||
			 sign == '.') {
            return true;
        }
        return false;
    }
    
    bool HandLexer::isEqualSign(const char sign) {
        if (sign == '=') return true;
        return false;
    }
    
    bool HandLexer::isDotSign(const char sign) {
        if (sign == '.') return true;
        return false;
    }

    bool HandLexer::isWhitespace(const char sign) {
        if (sign == ' ' || sign == '\t' || sign == '\n') return true;
        return false;
    }

    bool HandLexer::wordIsNumber(void) {
    	for(unsigned i = 0; i < wordSize; i++) {
    		if(isdigit(word[i])) return false;
    	}
    	return false;
    }

    bool HandLexer::isKeyWord(const char* word, unsigned int len) {
    	if(len == 0) return false;
        if (strncmp(word, "if", len)      == 0 ||
            strncmp(word, "is", len)      == 0 ||
            strncmp(word, "in", len)      == 0 ||
            strncmp(word, "end", len)     == 0 ||
            strncmp(word, "for", len)     == 0 ||
            strncmp(word, "var", len)     == 0 ||
            strncmp(word, "real", len)    == 0 ||
            strncmp(word, "type", len)    == 0 ||
            strncmp(word, "routine", len) == 0 ||
            strncmp(word, "integer", len) == 0 ||
            strncmp(word, "boolean", len) == 0 ||
            strncmp(word, "record", len)  == 0 ||
            strncmp(word, "array", len)   == 0 ||
            strncmp(word, "while", len)   == 0 ||
            strncmp(word, "reverse", len) == 0 ||
            strncmp(word, "foreach", len) == 0 ||
            strncmp(word, "from", len)    == 0 ||
            strncmp(word, "loop", len)    == 0 ||
            strncmp(word, "then", len)    == 0 ||
            strncmp(word, "else", len)    == 0 ||
            strncmp(word, "and", len)     == 0 ||
            strncmp(word, "or", len)      == 0 ||
            strncmp(word, "xor", len)     == 0 ||
            strncmp(word, "true", len)    == 0 ||
            strncmp(word, "false", len)   == 0) {
            return true;
        }
          return false;
    }

    void HandLexer::printToken(const char* word, unsigned int len) {
    	if(isKeyWord(word, len)) {
    		std::cout << "Keyword ";
    	} else {
    	    std::cout << "Token ";
    	}
        for (unsigned j = 0; j < len; j++) {
		    std::cout << word[j];
	    }
    	std::cout << "\n";
        return;
    }
} // namespae Ilang
