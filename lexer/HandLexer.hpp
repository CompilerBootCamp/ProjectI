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
        
        static bool isSingleSign(const char sign); 
        static bool isAmbigousSign(const char sign);
        static bool isEqualSign(const char sign);
        static bool isKeyWord(const char* word, unsigned int len);
        
        static const unsigned int maxIdentifierSize = 32;
        static const unsigned int maxFileSize = 0xFFFF;
        
        unsigned int line;
        unsigned int position;
        unsigned int wordSize;
        char word[maxIdentifierSize];
        unsigned int fileSize;
        char file[maxIdentifierSize];
    }; // class HandLexer
} // namespae Ilang

#endif // _HAND_LEXER_HPP_
