//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.08
//
//Sinn, Zweck der Datei:
//Deklaration von CRechteck
#pragma once

#include "CPunkt.h"
#include <iostream>
using namespace std;

class CRechteck
{
public:
	CRechteck();
	CRechteck(float& pXA, float& pYA, float& pXB, float& pYB);
	~CRechteck();
	bool setPunktA(float& pXA, float& pYA);
	bool getPunktA(float& pXA, float& pYA);
	bool setPunktB(float& pXB, float& pYB);
	bool getPunktB(float& pXB, float& pYB);
	bool getFlaeche(float &pA);
	void display();

private:
	CPunkt mPunktA;
	CPunkt mPunktB;
};

