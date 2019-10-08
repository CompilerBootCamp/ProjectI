#include <iostream>
#include <fstream>
#include <string>
#include "Compiler.hpp"

namespace Ilang
{
    Compiler::Compiler(const std::string& filename){
        lexer = new HandLexer(filename);
    };

    Compiler::~Compiler() {
    	delete lexer;
    };

    bool Compiler::compile(void) {
        return false;	
    }
} // namespace Ilang
