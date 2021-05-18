//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.18
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse CElement
#pragma once
#include <string>
using namespace std;

class CElement
{
public:
	CElement(string data);
	string mData;
	CElement* mPtrNext;	//Zeigt auf das nächste Element in der Warteschlange
};


