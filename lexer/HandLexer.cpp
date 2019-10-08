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
        fileSize = 0;

        std::ifstream in(filename);
        std::stringstream ss;

        if(in.is_open()) {
            ss << in.rdbuf();
			//for(int i = 0;;i++) {

                // Перенос строки - пропускает!!!
			//	in.getline(&file[i], maxFileSize);
			//	in << "";
//                in >> file[i];
//                std::cout << file[i];
             //   if(in.eof()) break;
			//}
	        file = ss.str();
        }
        in.close();
    }

    HandLexer::~HandLexer() {};

    bool HandLexer::doTokenisation(void) {
//    	for file.length() //последний \n тоже входит в размер
    	/*
        for (unsigned int i = 0; i < fileSize;) {
            if(isSingleSign(file[i])) {
                std::cout << "Token " << file[i] << "\n";
                wordSize = 0;
                i++;
            } else if (isAmbigousSign(file[i])) {
                if(isEqualSign(file[i])) {
                    std::cout << "Token " << file[i] << file[i+1] << "\n";
                    i+=2;
                } else {
            		std::cout << "Token " << file[i] << "\n";
            		i++;
                }
                wordSize = 0;
            } else if (isKeyWord(&file[i], wordSize)) { //to do
        		std::cout << "Keyword ";
        		for (unsigned j = 0; j < wordSize; j++) {
            		std::cout << file[i+j];
        		}
            }
        }*/
        
        return false;
    }

    bool HandLexer::hash(const char* key, unsigned int len, unsigned int& result) {
        
        return false;
    }
    
    bool HandLexer::isSingleSign(const char sign) {
        if ( sign == '(' || sign == ')' ||
             sign == '[' || sign == ']' ||
             sign == ':' || sign == '.' ||
             sign == '*' || sign == '%' ||
             sign == '+' || sign == '-' ||
             sign == ',' || sign == ';' ||
             sign == '=') {
            return true;
        }
        return false;
    }
    
    bool HandLexer::isAmbigousSign(const char sign) {
        if ( sign == '/' || sign == '<' ||
             sign == '>' || sign == ':') {
            return true;
        }
        return false;
    }
    
    bool HandLexer::isEqualSign(const char sign) {
        if (sign == '=') return true;
        return false;
    }
    
    bool HandLexer::isKeyWord(const char* word, unsigned int len) {
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
} // namespae Ilang
