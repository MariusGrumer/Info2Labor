#include "CQueue.h"
CQueue::CQueue(int maxSize):mMaxSize(maxSize), mCurrentSize(0), mHeadIndex(0), mTailIndex(0)
{
	mQueueArray = new CMessage[mMaxSize];
}

CQueue::~CQueue()
{
	delete[] mQueueArray;
}

bool CQueue::enqueue(const CMessage& msg)
{
	if (mCurrentSize >= mMaxSize)				//Queue full?
		return false;

	mQueueArray[mTailIndex] = msg;				// write
	mTailIndex++;								// Index ++
	mCurrentSize++;

	if (mTailIndex >= mMaxSize)					// wrap around
		mTailIndex = 0;

	return true;
}

bool CQueue::dequeue(CMessage& msg)
{
	if (mCurrentSize == 0)						// leer?
		return false;
	msg = mQueueArray[mHeadIndex];				// read
	mHeadIndex++;								// index
	mCurrentSize--;

	mHeadIndex = mHeadIndex % mMaxSize;			// andere Moeglichkeit für wrap around
	return true;
}

int CQueue::getNumOfMessages()
{
	return mCurrentSize;
}

void CQueue::display()				
{
	CMessage tempMsg;
	char msg[MSG_MAX_LEN];
	int displayIndex = 0;							//Index, welcher die aktuell auszugebende Stelle des Array angibt
	cout << "[";
	/*
	for (int i = 0; i < mCurrentSize; i++)						//gibt es hier eine schönere Lösung???
	{													// Schleife mit der Länge der Anzahl der Element in der Warteschlange
		if (i + mHeadIndex >= mMaxSize)					//Bedingung für warp around
		{
			displayIndex = i + mHeadIndex - mMaxSize;	// wrap around --> displayIndex zurücksetzen, falls über  Arraygrenze
		}
		else
		{
			displayIndex = i + mHeadIndex;				// Beginne mit der Ausgabe am Anfang der Queue	
		}
		tempMsg = mQueueArray[displayIndex];			// Kopieren der auszugebenden msg in tempMsg
		tempMsg.getMsg(msg);							// extrahieren der msg aus CMessage
		cout << tempMsg.getID() << "-" << msg;			// entsprechende Ausgabe mit der zugewiesenen ID

		if (i < mCurrentSize - 1)						// Ausgabe des Komma, nicht am ende der jeweiligen Ausgabe
		{
			cout << ", ";
		}

	}
	*/
	
	displayIndex = mHeadIndex;							//Startindex der Queue

	for (int i = 0; i < mCurrentSize; i++)				// Anzahl der Elemente in der Queue 
	{
		tempMsg = mQueueArray[displayIndex];			// Kopieren der auszugebenden msg in tempMsg
		tempMsg.getMsg(msg);							// extrahieren der msg aus CMessage
		cout << tempMsg.getID() << "-" << msg;			// entsprechende Ausgabe mit der zugewiesenen ID

		if (i < mCurrentSize - 1)						// Ausgabe des Komma, nicht am ende der jeweiligen Ausgabe
		{
			cout << ", ";
		}
		
		displayIndex++;									// erhöhen Index
		displayIndex = displayIndex % mMaxSize;			// wrap around
	}

	cout << "]";
}