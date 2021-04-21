
#include "CStack.h"
#include <iostream>
using namespace std;





CStack::CStack(int stackize) :mSize(stackize),mStackIndex(0)
{
	mStackPtr= new CMessage [stackize];
	mStackPtrNext = mStackPtr;

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
		mStackPtrNext++;
		return true;
	}


}



bool CStack:: pop(CMessage& msg)			//eien nachricht vom Stack herunterholen
{
	if (mStackIndex <=0 )					//Stack leer
	{
		return false;
	}
	else
	{
		mStackIndex--;
		mStackPtrNext--;
		msg = mStackPtr[mStackIndex];
		
	
	}

	return true;
}

int CStack:: getNumOfMessages(void)			//Aktuelle Anzahl der Nachrichten auf dem Stack
{											
	return mStackIndex-1;
}


int CStack:: getNumOfByteNeedet(void)		//Anzahl der Bytes, die vom Stack insgesmat belegt werden
{			//!!!!!!!!!!!FALSCH

	return 1;
}

void CStack:: display(void)					//Gibt den gesamten aktuellen INhalt des Stacks auf dem Bildschirm aus
{
	cout << "Stack = [";


	for (int i = 0; i < mStackIndex; i++)
	{
		char  msgtemp[MSG_MAX_LEN];
		
		mStackPtr[i].getMsg(msgtemp);


		cout << "(" << i << ", " << msgtemp << "), ";
	}
	
	cout << "]" << endl;

}


