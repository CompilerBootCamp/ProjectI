#ifndef _TOKEN_HPP_
#define _TOKEN_HPP_

namespace Ilang
{
    class Token {
    public:
        Token();
        ~Token();
    private:
    static const unsigned int ID_SIZE_MAX = 32;

    enum TokenType {
        // Base
        TERMINAL = 0x0101,
        ASSIGNMENT,
        IDENTIFIER,
        WHITESPACE,
        DELIMETER,
        COMMA,
        POINT,
        // Operators
        OPERATOR_PLUS,
        OPERATOR_MINUS,
        OPERATOR_MULT,
        OPERATOR_DIV,
        OPERATOR_MOD,
        // Logical operators
        LOGICAL_OPERATOR_OR,
        LOGICAL_OPERATOR_AND,
        LOGICAL_OPERATOR_XOR,
        // Relations
        RELATION_LESS,
        RELATION_LESS_OR_EQUAL,
        RELATION_GREAT,
        RELATION_GREAT_OR_EQUAL,
        RELATION_EQUAL,
        RELATION_NOT_EQUAL,
        // Brackets
        BRACKET_CIRCLE_LEFT,
        BRACKET_CIRCLE_RIGHT,
        BRACKET_SQUARE_LEFT,
        BRACKET_SQUARE_RIGHT,
        BRACKET_CURLY_LEFT,
        BRACKET_CURLY_RIGHT,
        // Keywords
        KEYWORD_VAR,
        KEYWORD_IS,
        KEYWORD_TYPE,
        KEYWORD_ROUTINE,
        KEYWORD_END,
        KEYWORD_INTEGER,
        KEYWORD_REAL,
        KEYWORD_BOOLEAN,
        KEYWORD_RECORD,
        KEYWORD_ARRAY,
        KEYWORD_WHILE,
        KEYWORD_LOOP,
        KEYWORD_FOR,
        KEYWORD_IN,
        KEYWORD_REVERSE,
        KEYWORD_FOREACH,
        KEYWORD_FROM,
        KEYWORD_IF,
        KEYWORD_THEN,
        KEYWORD_ELSE,
        KEYWORD_TRUE,
        KEYWORD_FALSE
    };

        enum TokenType type;
        char identifier[ID_SIZE_MAX];
        unsigned int line;
        unsigned int position;
    }; // class Token
} // namespace Ilang

#endif // _TOKEN_HPP_
