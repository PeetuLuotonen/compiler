#pragma once
#include "../headers/lexer.h"
#include "../headers/token.h"
#include <string>
#include <cctype>
#define _CRTDBG_MAP_ALLOC
#define DEBUG
#ifdef DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // DEBUG


#define T TOKEN_STRUCT::tokenType


using namespace std;

Lexer::Lexer(std::string ppSourceCode)
{
	m_lexer = lexerInit(ppSourceCode);
}

Lexer::~Lexer()
{
	delete (m_lexer);
}

void Lexer::tokenize() {
	token_T* token = nullptr;
	TokenStream tStream;
	while ((token = getNextToken()) != nullptr)
	{
		tStream.addToStream(token);
	}
}

lexer_T *Lexer::lexerInit(std::string sourceCode)
{
	m_lexer = new LEXER_STRUCT();
	m_lexer->sourceCode = sourceCode;
	m_lexer->i = 0;
	m_lexer->c = sourceCode[0];
	return m_lexer;
}

token_T* Lexer::getNextToken()
{
	
	while (m_lexer->c != '\0' && (m_lexer->sourceCode).length() > m_lexer->i)
	{
		if (m_lexer->c == ' ' || m_lexer->c == '\n')
			lexerSkipWhitespace();

		if (m_lexer->c == '"')
			return lexerGetString();

		if (isdigit(m_lexer->c))
			return lexerGetValue();

		if (isalpha(m_lexer->c))
			return lexerParseString();

		switch (m_lexer->c)
		{
		case '=': return lexerAdvanceWithToken(Token::initToken(T::TOKEN_EQUALS   , "=")); break;
		case '(': return lexerAdvanceWithToken(Token::initToken(T::TOKEN_LBRACKET , "(")); break;
		case ')': return lexerAdvanceWithToken(Token::initToken(T::TOKEN_RBRACKET , ")")); break;
		case '{': return lexerAdvanceWithToken(Token::initToken(T::TOKEN_LCBRACKET, "{")); break;
		case '}': return lexerAdvanceWithToken(Token::initToken(T::TOKEN_RCBRACKET, "}")); break;
		case ';': return lexerAdvanceWithToken(Token::initToken(T::TOKEN_SEMICOLON, ";")); break;
		}
		// lexerAdvance();
	}
	return nullptr;
}

token_T* Lexer::lexerAdvanceWithToken(token_T* token)
{
	lexerAdvance();
	return token;
}

token_T* Lexer::lexerGetString()
{
	lexerAdvance();
	std::string string = "";

	while (m_lexer->c != '"')
	{
		string = string + m_lexer->c;
		lexerAdvance();
	}

	lexerAdvance();

	return Token::initToken(T::TOKEN_STRING, string);
}


token_T* Lexer::lexerGetValue()
{
	std::string value = "";
	while (isdigit(m_lexer->c))
	{
		value = value + m_lexer->c;
		lexerAdvance();
	}
	return Token::initToken(T::TOKEN_INTEGER, value);
}


token_T* Lexer::lexerParseString()
{
	string str = "";
	while (isalnum(m_lexer->c))
	{
		str = str + m_lexer->c;
		lexerAdvance();
	}
	if (str.compare("int") == 0)
		return Token::initToken(T::TOKEN_TYPE, "int");
	else if (str.compare("return") == 0)
		return Token::initToken(T::TOKEN_KEY_WORD, "return");
	else
		return Token::initToken(T::TOKEN_IDENTIFIER, str);
}

void Lexer::lexerAdvance()
{
	if (m_lexer->c != '\0' && (m_lexer->sourceCode).length() > m_lexer->i)
	{
		m_lexer->i += 1;
		m_lexer->c = m_lexer->sourceCode[m_lexer->i];
	}
}

void Lexer::lexerSkipWhitespace()
{
	while (m_lexer->c == ' ' || m_lexer->c == '\n')
	{
		lexerAdvance();
	}
}
