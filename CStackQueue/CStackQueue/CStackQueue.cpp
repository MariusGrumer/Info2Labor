#include "CStackQueue.h"

CStackQueue::CStackQueue(int pSize):mStack(pSize), mQueue(pSize)
{}

CStackQueue::~CStackQueue()
{
}

bool CStackQueue::add(CMessage& pMsg)
{
	switch (pMsg.BufferType)
	{
	case 'Q':
		return mQueue.add(pMsg);
		break;
	case 'S':
		return mStack.add(pMsg);
		break;
	default:
		return false;
		break;
	}
}

bool CStackQueue::get(CMessage& pMsg)
{
	if (mStack.get(pMsg))
		return true;
	else
		return mQueue.get(pMsg);
}