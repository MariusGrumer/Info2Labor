

#include "CMessage.h"
#include"CStack.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;



int main()
{

	int maxNachrichten;
	int Wahl;
	cout << "Bitte geben Sie die Anzahl der Nachrichten ein, die der Stack maximal aufnehmen kann: ";
	cin >> maxNachrichten;

	CStack myStack(maxNachrichten);
	CMessage myMessage;



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

			while (!(cin >> tempmsg))
			{
				std::cout << "Falsche Eingabe!" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
			
			myMessage.setMsg(tempmsg);
			if (myStack.push(myMessage))
			{
				cout << "(" << myStack.getNumOfMessages() << ", " << tempmsg << ") wurde in den Stack geschrieben." << endl;
				myStack.display();
			}
			else
			{
				cout << "Der Stack ist voll! Ihre Nachricht konnte nicht geschrieben werden." << endl;
			}
			break;
		}
			
		case 2:
		{
			cout << "POP " << endl;
			char tempmsg[MSG_MAX_LEN];
			if (myStack.pop(myMessage))
			{
				myMessage.getMsg(tempmsg);
				cout << "(" << myStack.getNumOfMessages() << ", " << tempmsg << ") wurde vom Stack genommen." << endl;
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
			cout << "Falsche Eingabe" << endl;
			break;
		}			//end switch case


		
		cout << endl;
	} while (Wahl!=3);

	
	


	return 0;
}
