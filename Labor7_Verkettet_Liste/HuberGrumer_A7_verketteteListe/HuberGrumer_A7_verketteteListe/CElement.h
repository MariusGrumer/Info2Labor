//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.05
//
//Sinn, Zweck der Datei:
//Deklartion der Methoden der Klasse CElement

#pragma once
#include <string>
#include<iostream>
using namespace std;

class CElement
{
public:
	CElement();							//Ctor
	CElement(string& pText);			//Ctor mit Param
	~CElement();						//Dtor

	bool einfuegen(string& pText);		//einfuegen Methode
	bool ausgabe();						//ausgabe Methode


private:
	string mText;						//enthält den eingebenen Text
	CElement* mNextPtr;					//Ptr auf das nächste Element

};

