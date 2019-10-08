#ifndef _COMPILER_HPP_
#define _COMPILER_HPP_

#include "HandLexer.hpp"

namespace Ilang
{
    class Compiler {
    public:
        Compiler(const std::string& filename);
        ~Compiler();

    bool compile(void);
    
    private:
        HandLexer* lexer;
    }; // class Compiler
} // namespae Lexer

#endif // COMPILER
