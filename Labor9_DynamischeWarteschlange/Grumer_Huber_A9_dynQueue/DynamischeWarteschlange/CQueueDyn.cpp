//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.19
//
//Sinn, Zweck der Datei:
//Implementierung der Klasse CQueueDyn

#include "CQueueDyn.h"
#include <iostream>
using namespace std;

CQueueDyn::CQueueDyn()
{
	mHeadPtr = NULL;
	mTailPtr = NULL;

}

CQueueDyn::~CQueueDyn()
{
	string dummyString;
	while (this->dequeue(dummyString))	//leerlesen
	{

	}
}

bool CQueueDyn::enqueue(string& pElement)
{
	if (mTailPtr == NULL)										//Wenn warteschlange leer ist
	{
		mHeadPtr = new CElement(pElement);
		mTailPtr = mHeadPtr;
		return true;
	}															//Ende und Anfang der Schlange sind gleich --> beide Pointer zeigen auf neues Element
	mTailPtr->mPtrNext = new CElement(pElement);				//Element erzeugen und an Liste anhängen
	mTailPtr = mTailPtr->mPtrNext;								//TailPtr umhängen
	return true;
}

bool CQueueDyn::dequeue(string& pElement)
{
	if (mHeadPtr == NULL)										// wenn Queue leer ist
		return false;

	pElement = mHeadPtr->mData;									// Auslesen von Daten
	CElement* tmpPtr = mHeadPtr;
	mHeadPtr = mHeadPtr->mPtrNext;								// HeadPtr umhängen
	tmpPtr->mPtrNext = NULL;									// zum löschen Ptr entkoppeln
	delete tmpPtr;												// löschen von Element

	if (mHeadPtr == NULL)										//Wenn Queue geleert wurde, auch TailPtr zurücksetzen
	{
		mTailPtr = NULL;
	}

	return true;
}

void CQueueDyn::display(void)
{
	cout << "Queue [";
	CElement* tmpPtr = mHeadPtr;			//Ptr wandert zum auslesen nach unten

	while (tmpPtr != NULL)					//am Ende angekommen
	{
		cout << tmpPtr->mData;				//Data ausgeben
		if (tmpPtr->mPtrNext != NULL)		//Abfrage wegen Formatierung; ob Komma dazwischen muss
		{
			cout << ", ";
		}
		tmpPtr = tmpPtr->mPtrNext;			//durchhangeln
	}


	cout << "]" << endl;
}