#pragma once
#include "CMessage.h"

class CQueue
{
public:
	CQueue(int pSize);
	~CQueue();					// optional
	bool add(CMessage& pMsg);
	bool get(CMessage& pMsg);

private:
	int mSize;
	CMessage* mQueuePtr;
	int mCurrentSize;			// Füllstand
	int mHeadIndex;				// readIndex
	int mTailIndex;				// writeIndex

};

