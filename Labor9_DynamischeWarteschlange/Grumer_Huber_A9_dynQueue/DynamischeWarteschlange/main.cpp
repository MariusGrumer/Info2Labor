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

#include <iostream>
#include "CQueueDyn.h"
using namespace std;

int main()
{
	CQueueDyn myQueue;

	int option;
	string pdata;



	do
	{
		cout << "1 = enqueue, 2 = dequeue, 3 = ENDE. Ihre Eingabe: ";
		cin >> option;
		switch (option)
		{
		case 1:
		{


			cout << "Ihre Nachricht: ";
			cin >> pdata;
			myQueue.enqueue(pdata);			//auf stack legen
			myQueue.display();				//anzeigen
			break;
		}

		case 2:
		{

			if (myQueue.dequeue(pdata))											//von Stack nehmen und abfangen von Fehler
			{
				cout << "Folgendes wurde gelesen: " << pdata << endl;
				cout << "Die restliche Queue lautet wie folgt: ";
				myQueue.display();
				cout << endl;
			}
			else
			{
				cout << "Die Queue ist leer! dequeue konnte nicht ausgefuehrt werden." << endl;
			}

			break;
		}

		case 3:
		{
			cout << "Vielen Dank - auf Wiedersehen." << endl;
			break;
		}

		default:
			cout << "Ihre Eingabe wurde nicht erkannt. Bitte versuchen Sie es nocheinmal." << endl;					//Abfangen von Falsch eingegebenen Werten für option
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');														//löschen des Buffers
			break;
		}


		cout << endl;
	} while (option != 3);

	return 0;
}