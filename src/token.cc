#include "../headers/token.h"
#include <iostream>
#define _CRTDBG_MAP_ALLOC
#define DEBUG
#ifdef DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // DEBUG


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
