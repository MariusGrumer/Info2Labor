//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.05
//
//Sinn, Zweck der Datei:
//Implementierung der Methoden der Klasse CElement

#include "CElement.h"


CElement::CElement()						//Ctor ohne Param für Root Element			
{
	mText = "";
	mNextPtr = NULL;

}

CElement::CElement(string& pText)			//Ctor mit Param
{
	mText = pText;
	mNextPtr = NULL;

}


CElement::~CElement()
{
	if (mNextPtr!=NULL)
	{
		delete mNextPtr;					//durchhangeln und von Rückwärts löschen
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
		mNextPtr->einfuegen(pText);			//delegieren
	}

	return true;
}


bool CElement::ausgabe()					//Ausgabe Methode
{
	cout << mText << endl;					//Ausgabe				
	if (mNextPtr!=NULL)						//Wenn noch nicht am Ende angelangt wird nicht weiter delegiert
	{
		mNextPtr->ausgabe();				//delgieren
	}
	return true;

}

