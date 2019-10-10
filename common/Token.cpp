#include "Token.hpp"

namespace Ilang
{
    Token::Token() {
        type = UNKNOWN;
        identifier = std::string();
        line = 0;
        position = 0;
    };
    Token::Token(Token::Type tp, const std::string& id,unsigned int ln,unsigned int pos) {
        type = tp;
        identifier = id;
        line = ln;
        position = pos;
    };

    Token::~Token() {};

    Token::Type Token::getType () {return type;}
    std::string Token::getId () {return identifier;}
    unsigned int Token::getLine() {return line;}
    unsigned int Token::getPosition () {return position;}

} // namespace Ilang
