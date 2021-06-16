//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse Cqueue

#pragma once
#include"CMessage.h"


class CQueue
{

public:
	CQueue(int pSize);					//Ctor mit param		
	~CQueue();

	bool add(CMessage& pMsg);
	bool get(CMessage& pMsg);


private:
	CMessage* mQueuePtr;
	int mCurrentSize;					//Füllstand;
	int mHeadIndex;						//readIndex
	int mTailIndex;						//writeIndex
	int mSize;



};
