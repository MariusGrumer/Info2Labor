//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse CStack

#pragma once

#include "CMessage.h"



class CStack						// LIMFO wächst nach oben, zeigt auf Leerelement
{
public:
	CStack(int pSize);						//ctor mit Parameter, Größe bei Aufruf
	~CStack();
	bool add(CMessage& pMsg);
	bool get(CMessage& pMsg);



private:
	int mSize;									//store size
	unsigned int mIndex;						//Stackpointer
	CMessage* mStackPtr;						//zeigt auf dynamisches Array
};

