#include"CElement.h"
#include"CStackDyn.h"
#include <iostream>
using namespace std;


CStackDyn::CStackDyn()
{
	mPtrHead = NULL;
}

CStackDyn::~CStackDyn()
{
	/*string dummy;
	while (pop(dummy))
	{
	
	}*/
}

bool CStackDyn::push(const string& data)
{
	CElement* tmpPtr = new CElement(data);
	tmpPtr->mPtrNext = mPtrHead;
	mPtrHead = tmpPtr;

	return true;
}



bool CStackDyn::pop(string& data)
{
	if (NULL==mPtrHead)
	{
		return false;
	}
	else
	{
		data = mPtrHead->mData;			//lesen	
		CElement* tmpPtr;				//tmpptr
		tmpPtr = mPtrHead;				//tempptr zeigt auf zu lesendes Element	
		mPtrHead = tmpPtr->mPtrNext;	//mPtrHead zeigt auf das Element eins darunter
		tmpPtr->mPtrNext = NULL;
		delete tmpPtr;					//loeschen des Elementes

	}


}



void CStackDyn::display(void)
{
	cout << "Stack [";
	CElement* tmpPtr = mPtrHead;

	while (tmpPtr!=NULL)
	{
		cout << tmpPtr->mData << " ";
		tmpPtr = tmpPtr->mPtrNext;
	}


	cout << "]" << endl;
}