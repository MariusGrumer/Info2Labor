
#include "CStack.h"
#include <iostream>





CStack::CStack(int stackize) :mSize(stackize),mStackIndex(0)
{
	mStackPtr= new CMessage [stackize];
	mStackPtrNext = NULL;

}



CStack::~CStack()
{
	delete mStackPtr;
}


bool CStack:: push(const CMessage& msg)		//eine Nachricht auf den Stack legen
{
	if (mStackIndex>=mSize)					//Stack voll
	{
		return false;
	}
	else
	{
		mStackPtr[mStackIndex] = msg;
		mStackIndex++;
		return true;
	}


}



bool CStack:: pop(CMessage& msg)			//eien nachricht vom Stack herunterholen
{


	return true;
}

int CStack:: getNumOfMessages(void)			//Aktuelle Anzahl der Nachrichten auf dem Stack
{										//!! eigentlich mit void
	return mStackIndex;
}


int CStack:: getNumOfByteNeedet(void)		//Anzahl der Bytes, die vom Stack insgesmat belegt werden
{			//!!!!!!!!!!!FALSCH

	return 1;
}

void CStack:: display(void)					//Gibt den gesamten aktuellen INhalt des Stacks auf dem Bildschirm aus
{



}


