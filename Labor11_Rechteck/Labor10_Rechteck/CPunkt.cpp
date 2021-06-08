//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.08
//
//Sinn, Zweck der Datei:
//Initialisierung von CPunkt

#include "CPunkt.h"


CPunkt::CPunkt()
{
	mX = 0;
	mY = 0;
}

CPunkt::CPunkt(float& pX, float& pY)
{
	mX = pX;
	mY = pY;
}