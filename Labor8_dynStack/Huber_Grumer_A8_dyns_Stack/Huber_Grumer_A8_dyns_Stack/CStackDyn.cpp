//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.12
//
//Sinn, Zweck der Datei:
//Implementierung der Klasse CStackDyn


#include"CElement.h"
#include"CStackDyn.h"
#include <iostream>
using namespace std;


CStackDyn::CStackDyn()						//Ctor 
{
	mPtrHead = NULL;						//ein unverkettetes Element erzeugen
}

CStackDyn::~CStackDyn()						//dtor
{
	string dummydata;
	while (this->pop(dummydata))			//leerlesen
	{
		//cout << "dtor zerstoert : " << dummydata << endl;		//Instrumentierung
	}
}

bool CStackDyn::push(const string& data)	//auf Stack legen
{
	CElement* tmpPtr = new CElement(data);	//1. neuen Knoten erzeugen
	tmpPtr->mPtrNext = mPtrHead;			//2. neuer Knoten mit Stack verbinden
	mPtrHead = tmpPtr;						//3.mPtrHead mit neuem Knoten verbinden

	return true;
}



bool CStackDyn::pop(string& data)
{
	if (NULL==mPtrHead)					//leer?
	{
		return false;
	}
	else
	{
		data = mPtrHead->mData;			//1. lesen	
		CElement* tmpPtr;				//2. tmpptr erzeugen
		tmpPtr = mPtrHead;				//3. tempptr zeigt auf zu lesendes Element	
		mPtrHead = tmpPtr->mPtrNext;	//4. mPtrHead zeigt auf das Element eins darunter
		tmpPtr->mPtrNext = NULL;		//5. gelesenens Element abkoppeln
		delete tmpPtr;					//6. loeschen des Elementes

	}
	return true;

}



void CStackDyn::display(void)
{
	cout << "Stack [";
	CElement* tmpPtr = mPtrHead;			//Ptr wandert zum auslesen nach unten

	while (tmpPtr!=NULL)					//am ENde angekommen
	{
		cout << tmpPtr->mData;				//Data ausgeben
		if (tmpPtr->mPtrNext!=NULL)			//Abfrage wegen Formatierung; ob Komma dazwischen muss
		{
			cout << ", ";
		}
		tmpPtr = tmpPtr->mPtrNext;			//durchhangeln
	}


	cout << "]" << endl;
}