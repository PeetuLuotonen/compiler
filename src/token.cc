#include "../headers/token.h"
#include <iostream>

using namespace std;
namespace Token
{
	token_T* initToken(TOKEN_STRUCT::tokenType tokenType, std::string value)
	{
		token_T* token = new TOKEN_STRUCT();
		token->type = tokenType;
		token->m_tokenValue = value;
		return token;
	}
}
