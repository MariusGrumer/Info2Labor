//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Hier läuft das Eigentliche Programm

#include"CStack.h"
#include"CQueue.h"
#include"CStackQueue.h"
#include"CMessage.h"
#include<iostream>
using namespace std;


int main()
{

	cout << "Bitte geben Sie die max Speichergroesse an: ";
	int size;
	cin >> size;
	CStackQueue myCStackQueue(size);				//aufrufen Ctor mit Param

	CMessage myMessage;								//Message zum ein und auslesen. Wird per Refernez übergeben

	int Wahl;
	string pdata;
	char pBuffertype;




	do
	{
		cout << "1 = PUSH, 2 = POP, 3 = ENDE. Ihre Wahl: ";
		cin >> Wahl;
		switch (Wahl)
		{
		case 1:			//einlesen
		{


			cout << "Ihre Nachricht: ";
			cin >> pdata;
			myMessage.mData = pdata;
			do
			{														//Auswahl von Stack oder Queue
				cout << "Stack (S) oder Queue (Q)?";
				cin >> pBuffertype;
			} while (pBuffertype!='S'&&pBuffertype!='Q');			//Fehler abfangen
			
			myMessage.BufferType = pBuffertype;

			if (myCStackQueue.add(myMessage))						//falls Buffer voll wird ein false erwartet
				cout << "Die Nachricht '" << pdata << "' wurde erfolgreich auf der CStackQueue abgelegt" << endl;
			else
				cout << "Dieser Buffertype ist voll!!!" << endl;
			break;
		}

		case 2:
		{
			if (myCStackQueue.get(myMessage))						//Falls Stack und Queue leer wird ein false erwartet
			{
				pdata = myMessage.mData;
				cout << "Die Nachricht lautet: " << pdata << endl;
			}
			else
			{
				cout << "Die CStackqueue ist leer" << endl;
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