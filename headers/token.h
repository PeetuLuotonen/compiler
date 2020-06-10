#pragma once
#include <string>

typedef struct TOKEN_STRUCT
{
	enum class tokenType
	{
		TOKEN_IDENTIFIER,
		TOKEN_KEY_WORD,
		TOKEN_STRING,
		TOKEN_EQUALS,
		TOKEN_LBRACKET,
		TOKEN_RBRACKET,
		TOKEN_LCBRACKET,
		TOKEN_RCBRACKET,
		TOKEN_INTEGER,
		TOKEN_SEMICOLON,
		TOKEN_TYPE,
	} type;
	std::string m_tokenValue;
} token_T;

namespace Token {
	token_T* initToken(TOKEN_STRUCT::tokenType tokenType, std::string value);
}

