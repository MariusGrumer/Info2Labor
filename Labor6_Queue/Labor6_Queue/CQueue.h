#pragma once
#include <iostream>
#include "CMessage.h"
using namespace std;

class CQueue
{
public:
	CQueue(int maxSize);
	~CQueue();
	bool enqueue(const CMessage& msg);
	bool dequeue(CMessage& msg);
	int getNumOfMessages();
	void display();

private:
	int mMaxSize;						// Max. Größe der Warteschlange
	CMessage* mQueueArray;				// Warteschlange (Array/ Ringspeicher)

	int mCurrentSize;					// Füllstand
	int mHeadIndex;						// readIndex
	int mTailIndex;						// writeIndex
};
