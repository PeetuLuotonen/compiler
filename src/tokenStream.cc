#include "../headers/tokenStream.h"
#define _CRTDBG_MAP_ALLOC
#define DEBUG
#ifdef DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // DEBUG

TokenStream::TokenStream()
{
	m_tokenStream = new TOKEN_STREAM();
	m_tokenStream->back  = nullptr;
	m_tokenStream->front = nullptr;
}

TokenStream::~TokenStream()
{
	while (m_tokenStream->front != nullptr)
	{
		token_T* temp = nextToken();
		delete(temp);
	}
	delete m_tokenStream;
}

void TokenStream::addToStream(token_T* token)
{
	NODE* temp = new NODE(token);

	// empty stream
	if (m_tokenStream->back == nullptr)
	{
		m_tokenStream->back  = temp;
		m_tokenStream->front = temp;
		return;
	}

	(m_tokenStream->back)->next = temp;
	m_tokenStream->back = temp;
}

token_T* TokenStream::nextToken()
{
	// empty stream
	if (m_tokenStream->front == nullptr)
	{
		return nullptr;
	}
	NODE* temp = m_tokenStream->front;
	m_tokenStream->front = m_tokenStream->front->next;

	if (m_tokenStream->front == nullptr)
		m_tokenStream->back = nullptr;

	token_T* token = temp->data;
	delete (temp);
	return token;

}
