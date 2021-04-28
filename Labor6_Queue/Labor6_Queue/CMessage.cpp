//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.21
//
//Sinn, Zweck der Datei:
//Implementierung der Mehtoden für CMessage

#include "CMessage.h"

int CMessage::getID()						//Rückgabe des privaten Members
{
	return mID;

}

void CMessage::setID(int id)				//set-Methode
{
	mID = id;

}


