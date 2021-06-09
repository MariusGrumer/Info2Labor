//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.08
//
//Sinn, Zweck der Datei:
//Initialisierung von CRechteck

#include "CRechteck.h"


CRechteck::CRechteck()
{
	mPunktA.mX = 0;
	mPunktA.mY = 0;
	mPunktB.mX = 1;
	mPunktB.mY = 1;
}


CRechteck::CRechteck(float& pXA, float& pYA, float& pXB, float& pYB)
{
	// X Werte Sortieren
	if (pXA < pXB)
	{
		mPunktA.mX = pXA;
		mPunktB.mX = pXB;
	}
	else
	{
		mPunktA.mX = pXB;
		mPunktB.mX = pXA;
	}

	//Y Werte Sortieren
	if (pYA < pYB)
	{
		mPunktA.mY = pYA;
		mPunktB.mY = pYB;
	}
	else
	{
		mPunktA.mY = pYB;
		mPunktB.mY = pYA;
	}
}


bool CRechteck::getPunktA(float& pXA, float& pYA)
{
	pXA = mPunktA.mX;
	pYA = mPunktA.mY;
	return true;
}

bool CRechteck::getPunktB(float& pXB, float& pYB)
{
	pXB = mPunktB.mX;
	pYB = mPunktB.mY;
	return true;
}

bool CRechteck::getFlaeche(float& pA)
{
	pA = (mPunktB.mX - mPunktA.mX) * (mPunktB.mY - mPunktA.mY);	//Berechnug x-Differenz und y-Differenz --> multipliziert=Fläche
	return true;
}

void CRechteck::display()
{
	cout << "[ ( " << mPunktA.mX << ", " << mPunktA.mY << "), ( " << mPunktB.mX << ", " << mPunktB.mY << ") ]";
}