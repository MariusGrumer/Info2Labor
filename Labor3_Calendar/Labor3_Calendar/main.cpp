
#include <iostream>
#include "CDate.h"

using namespace std;

CDate readData(int nr);

int main()
{
	cout << "Bitte geben Sie zwei Kalendertage ein: " << endl << endl;

	CDate Date1 = readData(1);
	cout << endl;

	CDate Date2 = readData(2);
	cout << endl;
	
	cout << "Datum1:	";
	Date1.display();
	cout << "Datum2:	";
	Date2.display();

	cout << "Differenz: Datum2 - Datum1 = " << Date1.difference(Date2) << " Tage." << endl;
	
	return 0;
}


CDate readData(int nr)
{
	int day, month, year;
	cout << "Datum" <<nr<<": "<< endl;
	cout << "Tag	-> ";
	cin >> day;
	cout << "Monat	-> ";
	cin >> month;
	cout << "Jahr	-> ";
	cin >> year;

	return CDate(day, month, year);
}