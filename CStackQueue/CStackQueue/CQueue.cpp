#include "CQueue.h"

CQueue::CQueue(int pSize) : mCurrentSize(0), mHeadIndex(0), mTailIndex(0), mSize(pSize)
{
	mQueuePtr = new CMessage[pSize];
}

CQueue::~CQueue()
{

}

bool CQueue::add(CMessage& pMsg)
{
	if (mCurrentSize >= mSize)				//Queue full?
		return false;

	mQueuePtr[mTailIndex] = pMsg;				// write
	mTailIndex++;							// Index ++
	mCurrentSize++;

	if (mTailIndex >= mSize)				// wrap around
		mTailIndex = 0;

	return true;
}

bool CQueue::get(CMessage& pMsg)
{
	if (mCurrentSize == 0)					// leer?
		return false;
	pMsg = mQueuePtr[mHeadIndex];				// read
	mHeadIndex++;							// index
	mCurrentSize--;

	//if (mHeadIndex == QSIZE)				// wrap around
	//	mHeadIndex = 0;

	mHeadIndex = mHeadIndex % mSize;		// andere Moeglichkeit für wrap around
	return true;
}
