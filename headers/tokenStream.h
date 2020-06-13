#pragma once
#include "token.h"
#define _CRTDBG_MAP_ALLOC
#define DEBUG
#ifdef DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // DEBUG

class TokenStream {

	struct NODE
	{
		token_T* data;
		NODE* next;
		NODE(token_T* t)
			:data(t), next(nullptr)
		{}
		NODE()
			:data(nullptr), next(nullptr)
		{}
	} node;

	struct TOKEN_STREAM
	{
		NODE* front, * back;
	} tokenStream;

public:
	TokenStream();
	~TokenStream();
	void addToStream(token_T* token);
	token_T* nextToken();
private:
	TOKEN_STREAM* m_tokenStream;

};