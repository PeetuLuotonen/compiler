#pragma once
#include <iostream>
#include <string>
#include "token.h"
#include "tokenStream.h"


typedef struct LEXER_STRUCT
{
	char c; // current char
	uint32_t i;
	std::string sourceCode;
} lexer_T;

class Lexer {

public:
	Lexer(std::string ppSourceCode);
	~Lexer();
	void tokenize();
private:
	lexer_T* lexerInit(std::string sourceCode);
	token_T* getNextToken();
	token_T* lexerAdvanceWithToken(token_T* token);
	token_T* lexerGetString();
	token_T* lexerGetValue();
	token_T* lexerParseString(); // differenciates between ID, key word and type
	void	 lexerAdvance();
	void	 lexerSkipWhitespace();


	lexer_T* m_lexer;
};

