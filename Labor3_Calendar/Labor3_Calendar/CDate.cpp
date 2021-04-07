//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.07
//
//Sinn, Zweck der Datei:
//Implementierung der Mehtoden


#include <iostream>
#include "CDate.h"

using namespace std;

CDate::CDate()										//Ctor ohne Parameter
{
	mPrevDays = 1;
	mDay = 1;
	mMonth = 1;
	mYear = 1600;
}

CDate::CDate(int pDay, int pMonth, int pYear)		//Ctor mit Parameter
{
	mDay = pDay;
	mMonth = pMonth;
	mYear = pYear;

	mPrevDays = (pYear - 1600) * 365;		//Jahre hinzuaddieren

	switch (pMonth)							//Monate hinzuaddieren
	{
	case 1:	
		break;
	case 2:
		mPrevDays += 31;
		break;
	case 3:
		mPrevDays += (31 + 28);
		break;
	case 4: 
		mPrevDays += (31 + 28 + 31);
		break;
	case 5:
		mPrevDays += (31 + 28 + 31 + 30);
		break;
	case 6:
		mPrevDays += (31 + 28 + 31 + 30 + 31);
		break;
	case 7:
		mPrevDays += (31 + 28 + 31 + 30 + 31 + 30);
		break;
	case 8:
		mPrevDays += (31 + 28 + 31 + 30 + 31 + 30 + 31);
		break;
	case 9:
		mPrevDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31);
		break;
	case 10:
		mPrevDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30);
		break;
	case 11:
		mPrevDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31);
		break;
	case 12:
		mPrevDays += (31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30);
		break;
	default:
		cout << "Error 1" << endl;
		break;
	}

	mPrevDays += (pDay);											//Tage hinzuaddieren 


	//Schaltjahre hinzuaddieren

	mPrevDays = mPrevDays + (((pYear - 1600) / 4) +1);				//alle 4 Jahre einen Schalttag inklusive 1600 (+1)

	mPrevDays = mPrevDays - ((pYear - 1600) / 100);					//alle 100 Jahre ist kein Schaltjahr --> Abziehen

	mPrevDays = mPrevDays + ((pYear - 1600) / 400);					//alle 400 Jahre ein zusätzliches Schaltjahr


	if (pYear % 400 == 0 || (pYear % 100 != 0 && pYear % 4 == 0))	//Abfrage ob aktuelles Jahr ein Schaltjahr ist
	{
		if (pMonth < 3)												//Falls vor März, wird der Schalttag wieder abgezogen
		{
			mPrevDays--;
		}
	}

}

unsigned long int CDate::difference(CDate pDate)					//ermittelt Differenz zwischen übergebenen Objekt und dem Datum des eigenen Objektes
{
	return pDate.getDays()- mPrevDays;								//zugriff mittels pDate.getDays() auf Tage des Übergebenen Objektes; Zugriff auf die privaten Attribute mittels Aufruf der Variblen mPreDays
}

unsigned long int CDate::getDays()									//Methode um das Attribut mPrevDays aus private zurückzugeben
{
	return mPrevDays;
}
string CDate::getDayOfWeek()										//Methode um den Wochentag zu ermittlen
{
	//1.1.1600 war ein Samstag
	switch (mPrevDays % 7)		//ausgehend von 1.1.1600 werden Wochen mit Modulo Operator eingeteilt und der entsprechende Tag zurückgegeben
	{
	case 1:
		return "Samstag";
		break;
	case 2:
		return "Sonntag";
		break;
	case 3:
		return "Montag";
		break;
	case 4:
		return "Dienstag";
		break;
	case 5:
		return "Mittwoch";
		break;
	case 6:
		return "Donnerstag";
		break;
	case 0:
		return "Freitag";
		break;
	default:
		return "-1";			//Errorhandling
		break;
	}
}
void CDate::display()		
{
	cout << this->getDayOfWeek() << ", " << mDay << "." << mMonth << "." << mYear << "  ( " << mPrevDays << ". Tag seit 01.01.1600 )" << endl;
			// mittels dem Pfeiloperator kann auf auf die Methode der eigenen Klasse aufgeführt werden. Ansonsten erhält man keinen Zugriff auf mPrevDays, da diese private sind.
}

