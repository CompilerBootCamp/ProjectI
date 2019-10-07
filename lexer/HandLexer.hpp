#ifndef _HAND_LEXER_HPP_
#define _HAND_LEXER_HPP_

namespace Ilang
{
    class HandLexer {
    public:
        HandLexer();
        ~HandLexer();

        bool doTokenisation(void);

    private:
        bool hash(const char* key, unsigned int len, unsigned int& result);


        unsigned int line;
        unsigned int position;
    }; // class HandLexer
} // namespae Ilang

#endif // _HAND_LEXER_HPP_
