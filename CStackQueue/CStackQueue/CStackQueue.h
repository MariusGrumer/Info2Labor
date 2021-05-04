#pragma once
#include "CQueue.h"
#include "CStack.h"

class CStackQueue
{
public:
	CStackQueue(int pSize);
	~CStackQueue();

	bool add(CMessage& pMsg);
	bool get(CMessage& pMsg);

private:
	CQueue mQueue;
	CStack mStack;
};
