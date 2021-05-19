//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.19
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse CQueueDyn

#pragma once
#include "CElement.h"

class CQueueDyn
{
public:
	CQueueDyn();
	~CQueueDyn();
	bool enqueue(string& pElement);
	bool dequeue(string& pElement);
	void display(void);

private:
	CElement* mHeadPtr;
	CElement* mTailPtr;
};
