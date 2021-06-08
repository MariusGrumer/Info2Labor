//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.08
//
//Sinn, Zweck der Datei:
//Deklaration von CPunkt
#pragma once
#include <iostream>
using namespace std;

class CPunkt
{
public:
	CPunkt();
	CPunkt(float& pX, float& pY);
	
	float mX;
	float mY;

};
