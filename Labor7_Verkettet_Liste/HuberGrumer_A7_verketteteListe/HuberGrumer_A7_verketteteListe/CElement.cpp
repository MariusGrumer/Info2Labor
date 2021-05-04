#include "CElement.h"


CElement::CElement()				
{
	mText = "";
	mNextPtr = NULL;

}

CElement::CElement(string& pText)
{
	mText = pText;
	mNextPtr = NULL;

}


CElement::~CElement()
{
	if (mNextPtr!=NULL)
	{
		delete mNextPtr;			//durchhangeln und von Rückwärts löschen
	}
}


bool CElement::einfuegen(string& pText)		//sortiertes Einfügen
{
	if (mNextPtr==NULL)						// bisher kein Element vorhanden
	{
		mNextPtr = new CElement(pText);
	}
	else if (pText<=mNextPtr->mText)		//richtige Stelle -> element einfügen
	{
		CElement* newElementPtr = new CElement(pText);		//neuer Knoten
		newElementPtr->mNextPtr = mNextPtr;					//verketten des neuen Knoten mit nachfolgendem Element
		mNextPtr = newElementPtr;							//verbinden von element von vor dem neuen Knoten
		
	}
	else
	{
		mNextPtr->einfuegen(pText);				//delegieren
	}

	return true;
}


bool CElement::ausgabe()
{
	cout << mText << endl;
	if (mNextPtr!=NULL)
	{
		mNextPtr->ausgabe();
	}
	return true;

}

