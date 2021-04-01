//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.30
//
//Sinn, Zweck der Datei:
//Implementierung der Mehtoden
//


#include<iostream>
#include "PhoneCard.h"
using namespace std;

CPhoneCard::CPhoneCard()					//Standart ctor
{
	mCredit = 15;							//Member Guthaben und Status zu Beginn auf 15€ bzw 2 setzen							
	mStatus = 2;
}

void CPhoneCard::makeCall()					//Implementierung der Methode "makeCall()"
{
	switch (mCredit)						// je nach Guthaben wird der Anruf ausgeführt(Geld abgezogen) und der Status entsprechend gesetzt
	{										//Es sind immer nur die Vielfachen von 3 von Bedeutung, da nur 3 abgezogen werden kann
	case 0:
		mStatus = 0;
		break;
	case 3:
		mCredit -= 3;
		mStatus = 0;
		break;
	case 6:
		mCredit -= 3;
		mStatus = 0;
		break;
	case 9:
		mCredit -= 3;
		mStatus = 1;
		break;
	case 12:
		mCredit -= 3;
		mStatus = 1;
		break;
	default:								// wenn das Guthaben >=15 ist werden 3 abgezogen und immer der Status auf 2 gesetzt
		mCredit -= 3;
		mStatus = 2;
		break;
	}
}

void CPhoneCard::refill_15()				//Implementierung der Methode "refill()"
{
	mCredit += 15;							//Das Guthaben wird um 15 erhöht und der Status auf 2 gesetzt
	mStatus = 2;
}

void CPhoneCard::display()					//Implementierung der Methode "display()" zum ANzeigen des Statuses
{
	switch (mStatus)						//Ausgabe ist abhängig vom Status
	{
	case 0:
		cout << "Karte bitte auffuellen " << mCredit << endl;
		break;
	case 1:
		cout << "Karte ist ca. halbvoll " << mCredit << endl;
		break;
	case 2:
		cout << "Karte ist gut gefuellt " << mCredit << endl;
		break;
	default:
		cout << "Error: Falscher Wert bei mStatus" << endl;		//Abfangen eines Fehlers, falls mStatus einen Falschen Wert hat
		break;
	}
}