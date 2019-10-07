#include "HandLexer.hpp"

namespace Ilang
{
    HandLexer::HandLexer() {
        line = 0;
        position = 0;
    }

    HandLexer::~HandLexer() {};

    bool HandLexer::doTokenisation(void) {
        
        return false;
    }

    bool HandLexer::hash(const char* key, unsigned int len, unsigned int& result) {
        
        return false;
    }
} // namespae Ilang
