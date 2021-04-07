#pragma once
#include <iostream>

using namespace std;

class CDate
{
public:
	CDate();											//Ctor ohne param
	CDate(int pDay, int pMonth, int pYear);				//Ctor mit param

	unsigned long int difference(CDate pDate);	//gibt differenz in Tagen zwischen 2 Datum zur�ck
	unsigned long int getDays();						//gibt mPrevDays (Tage seit 1.1.1600) zur�ck
	string getDayOfWeek();								//gibt Name des Wochentages zur�ck
	void display();										//gibt Informationen auf Konsole aus

private:
	unsigned long int mPrevDays;		//Vergangene Tage seit 1.1.1600
	int mDay;							// Datum aktueller Tag
	int mMonth;							//Datum aktueller Monat
	int mYear;							//Datum aktuelles Jahr
};