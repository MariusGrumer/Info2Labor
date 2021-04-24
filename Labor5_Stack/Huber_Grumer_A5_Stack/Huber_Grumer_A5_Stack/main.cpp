//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.21
//
//Sinn, Zweck der Datei:
//Hier läuft das Eigentliche Programm

#include "CMessage.h"
#include"CStack.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;



int main()
{

	int stackSize;
	int Wahl;
	cout << "Bitte geben Sie die Anzahl der Nachrichten ein, die der Stack maximal aufnehmen kann: ";

	while (!(cin >> stackSize))									//Einlesen der Stacksize, solange bis die richtigen Werte eingegeben wurden
	{
		cout << "Fehlerhafte Eingabe" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');		//löschen des Buffers
	}

	CStack myStack(stackSize);									//ctor mit Parameter
	CMessage myMessage;											//Standart ctor



	do
	{
		cout << "1 = PUSH, 2 = POP, 3 = ENDE. Ihre Wahl: ";
		cin >> Wahl;
		switch (Wahl)
		{
		case 1: 
		{
			char tempmsg[MSG_MAX_LEN];
			
			cout << "Ihre Nachricht: ";
			do
			{
				while (!(cin >> tempmsg))										//Einlesen von tempmsg, abfangen von Flascheingaben
				{
					cout << "Fehlerhafte Eingabe" << endl;
					cin.clear();
					cin.ignore(std::numeric_limits<int>::max(), '\n');			//Buffer löschen

				}
				if (strlen(tempmsg) >= MSG_MAX_LEN) {							//Falls zu viele Zeichen eingegeben wurden
					cout << "Fehlerhafte Eingabe: zu viele Zeichen!" << endl;	//Rückmeldung 
				}
			} while (strlen(tempmsg) >= MSG_MAX_LEN);							//Es soll solange ein Wert eingelesen werden, bis dieser richtig ist

			
			myMessage.setMsg(tempmsg);											//kopieren der tempmsg in myMessage
			myMessage.setID(myStack.getNumOfMessages());						//Die Id der Message entspricht der Nummer auf dem Stack
			if (myStack.push(myMessage))										//Abfangen von Fehlern beim push vorgang (Stack voll?), schreiben von MyMessage auf Stack
			{	
				cout << "(" << myMessage.getID() << ", " << tempmsg << ") wurde in den Stack geschrieben." << endl;
				myStack.display();
			}
			else
			{
				cout << "Der Stack ist voll! Ihre Nachricht konnte nicht geschrieben werden." << endl<<"!Der Index wurde im Gegensatz zu den Screendumps aus der Aufgabenstellung NICHT erhoeht!"<<endl;
			}
			break;
		}
			
		case 2:
		{
			char tempmsg[MSG_MAX_LEN];	
			if (myStack.pop(myMessage))											//Abfangen von Fehlern, beim lesen des Stack, kopieren der StackMessage in myMessage
			{
				myMessage.getMsg(tempmsg);										//kopieren der Msg von myMessage in tempmsg
				cout << "(" << myMessage.getID() << ", " << tempmsg << ") wurde vom Stack genommen." << endl;
				myStack.display();
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
	} while (Wahl!=3);

	
	
	

	return 0;
}
