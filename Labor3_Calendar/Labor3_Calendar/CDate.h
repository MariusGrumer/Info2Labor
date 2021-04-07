//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.07
//
//Sinn, Zweck der Datei:
//Deklaration der Methoden

#pragma once
#include <iostream>

using namespace std;

class CDate
{
public:
	CDate();											//Ctor ohne param
	CDate(int pDay, int pMonth, int pYear);				//Ctor mit param

	unsigned long int difference(CDate pDate);	//gibt differenz in Tagen zwischen 2 Datum zurück
	unsigned long int getDays();						//gibt mPrevDays (Tage seit 1.1.1600) zurück
	string getDayOfWeek();								//gibt Name des Wochentages zurück
	void display();										//gibt Informationen auf Konsole aus

private:
	unsigned long int mPrevDays;		//Vergangene Tage seit 1.1.1600
	int mDay;							// Datum aktueller Tag
	int mMonth;							//Datum aktueller Monat
	int mYear;							//Datum aktuelles Jahr
};