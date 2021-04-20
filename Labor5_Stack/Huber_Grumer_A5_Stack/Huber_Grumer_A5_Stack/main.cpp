

#include "CMessage.h"
#include"CStack.h"
#include <iostream>
using namespace std;


int main()
{

	int maxNachrichten;
	int Wahl;
	cout << "Bitte geben Sie die Anzahl der Nachrichten ein, die der Stack maximal aufnehmen kann: ";
	cin >> maxNachrichten;

	do
	{
		cout << "1 = PUSH, 2 = POP, 3 = ENDE. Ihre Wahl: ";
		cin >> Wahl;
		switch (Wahl)
		{
		case 1: 
		{
			cout << "Ihre Nachricht: " << endl;
			break;
		}
			
		case 2:
		{
			cout << "POP " << endl;
			break;
		}
			
		case 3:
		{
			cout << "Vielen Dank - auf Wiedersehen." << endl;
			break;
		}

		default:
			cout << "Falsche Eingabe" << endl;
			break;
		}			//end switch case


		cout << endl;
	} while (Wahl!=3);

	
	


	return 0;
}
