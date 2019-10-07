#include <cstring>
#include "HandLexer.hpp"

namespace Ilang
{
    HandLexer::HandLexer() {
        line = 0;
        position = 0;
    }

    HandLexer::~HandLexer() {};

    bool HandLexer::doTokenisation(void) {
        for (unsigned int i = 0; i < fileSize; i++) {
            if(isSingleSign(file[i])) {
                // Print token
            } else if (isAmbigousSign(file[i])) {
                if(isEqualSign(file[i])) {
                    // >= /= <=
                } else {
                    // < > /
                }
            } else if (false) { //to do
                return false;
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
             sign == '>') {
            return true;
        }
        return false;
    }
    
    bool HandLexer::isEqualSign(const char sign) {
        if (sign == '=') return true;
        return false;
    }
    
    bool HandLexer::isKeyWord(const char* word, unsigned int len) {
        if (strcmp(word, "if")      == 0 || 
            strcmp(word, "is")      == 0 || 
            strcmp(word, "in")      == 0 ||
            strcmp(word, "end")     == 0 || 
            strcmp(word, "for")     == 0 || 
            strcmp(word, "var")     == 0 || 
            strcmp(word, "real")    == 0 || 
            strcmp(word, "type")    == 0 || 
            strcmp(word, "routine") == 0 || 
            strcmp(word, "integer") == 0 || 
            strcmp(word, "boolean") == 0 || 
            strcmp(word, "record")  == 0 || 
            strcmp(word, "array")   == 0 || 
            strcmp(word, "while")   == 0 ||
            strcmp(word, "reverse") == 0 || 
            strcmp(word, "foreach") == 0 || 
            strcmp(word, "from")    == 0 || 
            strcmp(word, "loop")    == 0 || 
            strcmp(word, "then")    == 0 || 
            strcmp(word, "else")    == 0 || 
            strcmp(word, "and")     == 0 || 
            strcmp(word, "or")      == 0 || 
            strcmp(word, "xor")     == 0 || 
            strcmp(word, "true")    == 0 || 
            strcmp(word, "false")   == 0) {
            return true;
        }
          return false;
    }
} // namespae Ilang
