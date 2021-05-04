//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.28
//
//Sinn, Zweck der Datei:
//Deklaration der Methoden der Klasse CQueue	
#pragma once
#include <iostream>
#include "CMessage.h"
using namespace std;

class CQueue
{
public:
	CQueue(int maxSize);				//ctor mit Parama
	~CQueue();							//dtor
	bool enqueue(const CMessage& msg);	//anhängen
	bool dequeue(CMessage& msg);		//auslesen
	int getNumOfMessages();				//getter methode
	void display();						//metode zur Ausgabe

private:
	int mMaxSize;						// Max. Größe der Warteschlange
	CMessage* mQueueArray;				// Warteschlange (Array/ Ringspeicher)

	int mCurrentSize;					// Füllstand
	int mHeadIndex;						// readIndex
	int mTailIndex;						// writeIndex
};
