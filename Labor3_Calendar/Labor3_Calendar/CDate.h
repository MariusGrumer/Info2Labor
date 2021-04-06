#pragma once
#include <iostream>

using namespace std;

class CDate
{
public:
	CDate();
	CDate(int pDay, int pMonth, int pYear);

	int difference(int pDay, int pMonth, int pYear);
	int getDays();
	string getDayOfWeek();
	void display();

private:
	int mPrevDays;
	int mDay;
	int mMonth;
	int mYear;

};