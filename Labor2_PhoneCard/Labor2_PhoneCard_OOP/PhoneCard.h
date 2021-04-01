//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.30
//
//Sinn, Zweck der Datei:
//Deklaration der Klassen und Methoden
//

#pragma once

class CPhoneCard					//Deklaration der Klasse PhoneCard
{
public:
	CPhoneCard();					//ctor 
	void makeCall();				//methode für Anruf
	void refill_15();				//Methode zum Auffüllen
	void display();					//Methode zum Anzeigen des Statuses

private:
	unsigned int mCredit;			//Guthaben, kann nicht negativ sein
	int mStatus;					//Status der Telefonkarte

};