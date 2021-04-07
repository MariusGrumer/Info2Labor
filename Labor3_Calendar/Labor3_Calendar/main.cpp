//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.07
//
//Sinn, Zweck der Datei:
//Hier läuft das Eigentliche Programm
//Deklaration Funktionen


#include <iostream>
#include "CDate.h"

using namespace std;

CDate readData(int nr);										//Funtkion zum Einlesen des Datums, gibt ein Objekt der Klasse CDate zurück

int main()
{
	cout << "Bitte geben Sie zwei Kalendertage ein: " << endl << endl;

	CDate Date1 = readData(1);								//Einlesen des Datums für das erste Datum
	cout << endl;

	CDate Date2 = readData(2);								//Einlesen des Datums fpr das zweite Datum
	cout << endl;
	
	cout << "Datum1:	";
	Date1.display();										//Aufruf der Methode display für das erste Datum
	cout << "Datum2:	";
	Date2.display();

	cout << "Differenz: Datum2 - Datum1 = " << Date1.difference(Date2) << " Tage." << endl;		//Die Methode difference wird ein Objekt der Klasse CDate zum Vergleich übergeben
	
	return 0;
}


CDate readData(int nr)										//Funtkion zum Einlesen des Datums, gibt ein Objekt der Klasse CDate zurück
{
	int day, month, year;
	cout << "Datum" <<nr<<": "<< endl;						// int nr wird für die Ausgabe benötigt (Welches Datum eingelesn wird)
	cout << "Tag	-> ";
	cin >> day;
	cout << "Monat	-> ";
	cin >> month;
	cout << "Jahr	-> ";
	cin >> year;

	return CDate(day, month, year);							//Ctor mit Paramter wird aufgerufen
}