//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Implementierung der Klasse Cqueue


#include "CQueue.h"


CQueue::CQueue(int pSize)//:mCurrenSize, ...
{
	mCurrentSize = 0;					//Füllstand;
	mHeadIndex = 0;						//readIndex
	mTailIndex = 0;						//writeIndex
	mQueuePtr = new CMessage[pSize];
	mSize = pSize;

};

CQueue::~CQueue()
{
	delete[] mQueuePtr;

}

bool CQueue::add(CMessage& pMsg)
{
	//if (mCurrentSize<QSIZE)				//voll?
	//{
	//	if (mTailIndex<QSIZE)
	//	{
	//		mQueue[mTailIndex] = pMsg;	//write
	//		mTailIndex++;				//index++
	//	}
	//	else
	//	{
	//		mQueue[mTailIndex] = pMsg;
	//		mTailIndex = 0;				//wrap around
	//	}
	//	mCurrentSize++;
	//	return true;
	//}
	//return false;

	if (mCurrentSize == mSize)
	{
		return false;
	}
	mQueuePtr[mTailIndex] = pMsg;
	mTailIndex++;
	mCurrentSize++;

	if (mTailIndex == mSize)				//wrap around
	{
		mTailIndex = 0;
	}

	return true;
}

bool CQueue::get(CMessage& pMsg)
{

	if (mCurrentSize == 0)				//leer?
	{
		return false;
	}
	pMsg = mQueuePtr[mHeadIndex];			//read
	mHeadIndex++;						//index++
	mCurrentSize--;

	mHeadIndex = mHeadIndex % mSize;	//wrap around


	return true;
}
