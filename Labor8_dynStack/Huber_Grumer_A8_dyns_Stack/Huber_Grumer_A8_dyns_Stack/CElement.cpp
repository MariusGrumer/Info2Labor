//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.12
//
//Sinn, Zweck der Datei:
//Implementierung der Klasse CElement


#include"CElement.h"

CElement::CElement(string data)			//ctor mit param
{
	mData = data;
	mPtrNext = NULL;

}