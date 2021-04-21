//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.21
//
//Sinn, Zweck der Datei:
//Deklaration der Methoden der Klasse CStack (in Aufgabe gegeben)


//#pragma once							//Alternativ

#ifndef CSTACK_H_
#define CSTACK_H_

#include "CMessage.h"

class CStack
{
public:
	CStack(int stacksize);
	~CStack();
	bool push(const CMessage& msg);		//eine Nachricht auf den Stack legen
	bool pop(CMessage & msg);			//eien nachricht vom Stack herunterholen
	int getNumOfMessages(void);			//Aktuelle Anzahl der Nachrichten auf dem Stack
	int getNumOfByteNeeded(void);		//Anzahl der Bytes, die vom Stack insgesmat belegt werden

	void display(void);					//Gibt den gesamten aktuellen INhalt des Stacks auf dem Bildschirm aus

private:
	int mSize;							//Groeße des Stacks;
	int mStackIndex;					//ANzahl aktueller Nachrichten auf mdem Stack
	CMessage* mStackPtr;				//Steck Pointer für delete Befehl _ NICHT verändern

	CMessage* mStackPtrNext;			//Pointer auf die naechte freie Nachrichtim Stack
};


#endif // CSTACK_H_
