
#include <iostream>
#include "CDate.h"

using namespace std;

CDate::CDate()
{
	mPrevDays = 0;
	mDay = 1;
	mMonth = 1;
	mYear = 1600;
}

CDate::CDate(int pDay, int pMonth, int pYear)
{
	mDay = pDay;
	mMonth = pMonth;
	mYear = pYear;

	mPrevDays = (pYear - 1600) * 365;	//Jahre hinzuaddieren

	switch (pMonth-1)		//Monate hinzuaddieren				Funktioniert so nicht!!!!!!!!!!!!!!!!!!!!!!!!
	{
	case 1:	//Alle Monate mit 31 Tagen
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
		mPrevDays += 31;
		break;

	case 4:	//Alle Monate mit 30 Tagen
	case 6:
	case 9:
	case 11:
		mPrevDays += 30;
		break;

	case 2:	//Alle Monate mit 28 Tagen
		mPrevDays += 28;
		break;
	default:
				//Fehlermeldung
		break;
	}

	mPrevDays += pDay;	//Tage hinzuaddieren


	//Schaltjahre hinzuaddieren

	mPrevDays = mPrevDays + ((pYear - 1600) / 4) + 1;	//alle 4 Jahre einen Tag inklusive 1600 auch als Schaltjahr

	mPrevDays = mPrevDays - ((pYear - 1600) / 100);		//alle 100 Jahre ist kein Schaltjahr --> Abziehen

	mPrevDays = mPrevDays + ((pYear - 1600) / 400);		//alle 400 Jahre ein zusätzliches Schaltjahr

}

int CDate::difference(int pDay, int pMonth, int pYear)
{
	return 0;
}
int CDate::getDays()
{
	return mPrevDays;
}
string CDate::getDayOfWeek()
{
	//1.1.1600 war ein Samstag
	switch (mPrevDays % 7)
	{
	case 0:
		return "Samstag";
		break;
	case 1:
		return "Sonntag";
		break;
	case 2:
		return "Montag";
		break;
	case 3:
		return "Dienstag";
		break;
	case 4:
		return "Mittwoch";
		break;
	case 5:
		return "Donnerstag";
		break;
	case 6:
		return "Freitag";
		break;
	default:
		//Fehlermeldung
		break;
	}
}
void CDate::display()
{

}

