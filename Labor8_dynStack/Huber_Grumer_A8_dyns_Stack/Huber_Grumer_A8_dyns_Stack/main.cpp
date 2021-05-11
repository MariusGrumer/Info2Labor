//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.12
//
//Sinn, Zweck der Datei:
//Hier läuft das Eigentliche Programm


#include"CElement.h"
#include"CStackDyn.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;



int main()
{

	
	CStackDyn myStack;									//ctor ohne Param
	
	int Wahl;
	string pdata;



	do
	{
		cout << "1 = PUSH, 2 = POP, 3 = ENDE. Ihre Wahl: ";
		cin >> Wahl;
		switch (Wahl)
		{
		case 1:
		{
			

			cout << "Ihre Nachricht: ";
			cin >> pdata;
			myStack.push(pdata);
			myStack.display();
			break;
		}

		case 2:
		{
			
			if (myStack.pop(pdata))											//Abfangen von Fehlern, beim lesen des Stack, kopieren der StackMessage in myMessage
			{
				cout << "Folgendes wurde gelesen: " << pdata << endl;
				cout << "Der restliche Stack lautet wie folgt: ";
				myStack.display();
				cout<< endl;
			}
			else
			{
				cout << "Der Stack ist leer! POP konnte nicht ausgefuehrt werden." << endl;
			}

			break;
		}

		case 3:
		{
			cout << "Vielen Dank - auf Wiedersehen." << endl;
			break;
		}

		default:
			cout << "Ihre Eingabe wurde nicht erkannt. Bitte versuchen Sie es nocheinmal." << endl;					//Abfangen von Falsch eingegebenen Werten für Wahl
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');														//löschen des Buffers
			break;
		}


		cout << endl;
	} while (Wahl != 3);





	return 0;
}
