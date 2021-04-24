//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.21
//
//Sinn, Zweck der Datei:
//Implementierung der Mehtoden für CStack


#include "CStack.h"
#include <iostream>
using namespace std;


CStack::CStack(int stackize) :mSize(stackize),mStackIndex(0)					//Ctor mit Listeninitalisierung
{
	mStackPtr= new CMessage [stackize];											
	mStackPtrNext = mStackPtr;													//mStackPrtNext zeigt zunächt auf die erste Leere Stelle in dem reservierten Speicher
}



CStack::~CStack()																//dtor
{
	delete mStackPtr;
}


bool CStack:: push(const CMessage& msg)											//eine Nachricht auf den Stack legen
{
	if (mStackIndex>=mSize)														//Stack voll
	{
		return false;
	}
	else
	{
		mStackPtr[mStackIndex] = msg;											//Nachricht auf die aktuelle Stelle (mittels StackINdex) legen
		mStackIndex++;															//Index und NextPtr erhöhen
		mStackPtrNext++;
				
	}
	return true;
}



bool CStack:: pop(CMessage& msg)											//eien nachricht vom Stack herunterholen
{
	if (mStackIndex <=0 )													//Stack leer
	{
		return false;
	}
	else
	{
		
		mStackIndex--;														//um eine Position nach unten wandern, da Index und nextptr zuvor bei push erhöht wurde
		mStackPtrNext--;													// vlg Zeile darüber
		msg = mStackPtr[mStackIndex];										//Inhalt des Stacks an der aktuellen Position auf die msg zur Rückgabe schreiben
		
	}
	return true;
}

int CStack:: getNumOfMessages(void)											//Aktuelle Anzahl der Nachrichten auf dem Stack
{											
	return mStackIndex;														//Member der Klasse zurückgeben
}


int CStack:: getNumOfByteNeeded(void)										//Anzahl der Bytes, die vom Stack insgesmat belegt werden
{
	int bytes = 0;

	for (int i = 0; i < mStackIndex; i++)									//für jede Position des Stackes soll die Größe ermittelt werden...
	{																		
		bytes = bytes + sizeof(mStackPtr[i]);								//... und akumuliert werden
	}
	return bytes;
}

void CStack:: display(void)													//Gibt den gesamten aktuellen INhalt des Stacks auf dem Bildschirm aus
{
	cout << "Stack = [";


	for (int i = 0; i < mStackIndex; i++)
	{
		char  msgtemp[MSG_MAX_LEN];											//lokale Variable um den Text abzuspeichern
		
		mStackPtr[i].getMsg(msgtemp);										//Zugriff auf den Text mittels getMsg; Inhalt wird auf msgtemp gespeichert


		cout << "(" << i << ", " << msgtemp << ")";							//msgtemp kann im cout ausgegeben werden
		if (i < mStackIndex - 1)
		{
			cout << ", ";
		}
	}
	
	cout << "]" << endl;
	//cout << "aktuell sind durch den Stack " << this->getNumOfByteNeeded() << " bytes belegt" << endl;	// Kontrollausgabe für belegten Speicher

}


