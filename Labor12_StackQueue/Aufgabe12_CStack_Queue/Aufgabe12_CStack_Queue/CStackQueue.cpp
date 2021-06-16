//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Implementierung der Klasse CStackQueue

#include"CMessage.h"
#include"CStackQueue.h"



CStackQueue::CStackQueue(int psize):myStack(psize), myQueue(psize)		//Listeninit.
{																		//die Größe des Stacks und der Queue entspricht jeweils der in der main eingelesene size 
}





bool CStackQueue::add(CMessage& pMessage)
{
	switch (pMessage.BufferType)					//Unterscheidung nach Buffertyp ob Stack oder Queue
	{
	case 'S':
		return myStack.add(pMessage);				//ruft Methode add des Stacks auf. Gibt bool-return Wert weiter
		break;
	case 'Q':
		return myQueue.add(pMessage);				//ruft Methode add der Queue auf. Gibt bool-return Wert weiter
		break;
	default:
		return false;
		break;
	}
	
}


bool CStackQueue::get(CMessage& pMessage)			//mit Refernezparamter, damit direkt in die CMessage aus der main geschrieben werden kann
{
	if (myStack.get(pMessage))						//zuerst wird der Stack ausgelese. Falls dieser leer ist wird ein false erwartet
		return true;
	else
		return myQueue.get(pMessage);				//Auslesen der Queue

	

}






