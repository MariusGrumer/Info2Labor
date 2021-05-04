#pragma once
#include"CMessage.h"

class CStack					// LIFO w‰chst nach oben, zeigt auf Leerelement
{
public:
	CStack(int pSize);						// ctor mit param, Groeﬂe bei Aufruf
	~CStack();

	bool add(CMessage& pMsg);
	bool get(CMessage& pMsg);

private:
	int mSize;						// store Size
	unsigned int mIndex;			// Stackpointer
	CMessage* mStackPtr;			// zeigt auf dynamisches Array

};

