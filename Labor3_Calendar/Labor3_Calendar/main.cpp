
#include <iostream>
#include "CDate.h"

using namespace std;

int main()
{
	CDate Date;
	string hello = Date.getDayOfWeek();
	cout << hello << endl;
	return 0;
}