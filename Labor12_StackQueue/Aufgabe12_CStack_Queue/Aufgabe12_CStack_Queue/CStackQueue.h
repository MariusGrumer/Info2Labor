
//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse CStackQueue. 
//Sie ist eine Komposition aus CStack und CQueue ("hat ein")

#pragma once
#include"CMessage.h"
#include"CQueue.h"
#include"CStack.h"


class CStackQueue
{
public:
	CStackQueue(int pSize);					//ctor mit param
	bool add(CMessage &pMessage);			//einlesen
	bool get(CMessage &pMessage);			//Auslesen

private:
	CStack myStack;							//Komposition : "hat ein"
	CQueue myQueue;
	

};



