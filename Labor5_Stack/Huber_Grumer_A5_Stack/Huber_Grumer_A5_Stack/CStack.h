#pragma once

//#ifdef CSTACK_H_
//#define CSTACK_H_

#include "CMessage.h"

class CStack
{
public:
	CStack(int stacksize);
	~CStack();
	bool push(const CMessage& msg);		//eine Nachricht auf den Stack legen
	bool pop(CMessage & msg);			//eien nachricht vom Stack herunterholen
	int getNumOfMessages(void);			//Aktuelle Anzahl der Nachrichten auf dem Stack
	int getNumOfByteNeedet(void);		//Anzahl der Bytes, die vom Stack insgesmat belegt werden

	void display(void);					//Gibt den gesamten aktuellen INhalt des Stacks auf dem Bildschirm aus

private:
	int mSize;							//Groeße des Stacks;
	int mStackIndex;					//ANzahl aktueller Nachrichten auf mdem Stack
	CMessage* mStackPtr;				//Steck Pointer für delete Befehl _ NICHT verändern

	CMessage* mStackPtrNext;			//Pointer auf die naechte freie Nachrichtim Stack
};


//#endif // CSTACK_H_
