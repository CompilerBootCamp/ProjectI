#ifndef _COMPILER_HPP_
#define _COMPILER_HPP_

#include "HandLexer.hpp"
#include "Token.hpp"

namespace Ilang
{
    class Compiler {
    public:
        Compiler(const std::string& filename);
        ~Compiler();

    bool compile(void);
    
    private:
        static const unsigned int maxTokenNum = 0xFFFF;

        HandLexer* lexer;
        Token token[maxTokenNum];
    }; // class Compiler
} // namespae Lexer

#endif // COMPILER
