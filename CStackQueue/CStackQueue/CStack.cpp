#include "CStack.h"


CStack::CStack(int pSize) : mIndex(0), mSize(pSize)		// ctor mit param
{
	mStackPtr = new CMessage[pSize];

}

CStack::~CStack()								//dtor
{
	delete[] mStackPtr;						// lösche das Array --> nicht optional da new verwendet wurde muss hier ein delete erfolgen, [] sind nötig, da ein Array
}

bool CStack::add(CMessage& pMsg)
{
	if (mIndex >= mSize)						//Stack voll?
		return false;

	mStackPtr[mIndex] = pMsg;					//schreiben
	mIndex++;									//inkrementieren

	return true;
}

bool CStack::get(CMessage& pMsg)
{
	if (mIndex <= 0)							//Stack leer?
		return false;

	mIndex--;									//Stackpointer richtig stellen
	pMsg = mStackPtr[mIndex];					//schreiben


	return true;
}