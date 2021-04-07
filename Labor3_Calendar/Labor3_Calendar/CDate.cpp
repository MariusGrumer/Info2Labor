
#include <iostream>
#include "CDate.h"

using namespace std;

CDate::CDate()
{
	mPrevDays = 1;
	mDay = 1;
	mMonth = 1;
	mYear = 1600;
}

CDate::CDate(int pDay, int pMonth, int pYear)
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

unsigned long int CDate::difference(CDate pDate)
{
	return pDate.getDays()- mPrevDays;
}
unsigned long int CDate::getDays()
{
	return mPrevDays;
}
string CDate::getDayOfWeek()
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
		return "-1";
		break;
	}
}
void CDate::display()		
{
	cout << this->getDayOfWeek() << ", " << mDay << "." << mMonth << "." << mYear << "  ( " << mPrevDays << ". Tag seit 01.01.1600 )" << endl;
}

