#include <iostream>
#include "CQueue.h"
using namespace std;


int main()
{
	int queueSize;
	int option;
	cout << "Bitte geben Sie die Anzahl der Nachrichten ein, die die Warteschlange maximal aufnehmen kann: ";

	while (!(cin >> queueSize))									//Einlesen der Stacksize, solange bis die richtigen Werte eingegeben wurden
	{
		cout << "Fehlerhafte Eingabe" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<int>::max(), '\n');		//löschen des Buffers
	}

	CQueue myQueue(queueSize);									//ctor mit Parameter
	CMessage myMessage;											//Standart ctor

	int messageId = 0;

	do
	{
		cout << "1 = ENQUEUE, 2 = DEQUEUE, 3 = ENDE. Ihre Wahl: ";
		cin >> option;
		switch (option)
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
			myMessage.setID(messageId);											//Die Id der Message entspricht dem counter messageId
			messageId++;
			if (myQueue.enqueue(myMessage))										//Abfangen von Fehlern beim enqueue vorgang (Queue voll?), schreiben von MyMessage in Queue
			{
				cout << "							-> " << myMessage.getID() << "-" << tempmsg << " ";
				myQueue.display();
				cout << " (" << myQueue.getNumOfMessages() << ")" << endl;
			}
			else
			{
				cout << "FEHLER: Die Warteschlange ist voll!" << endl;
			}
			break;
		}

		case 2:
		{
			char tempmsg[MSG_MAX_LEN];
			if (myQueue.dequeue(myMessage))											//Abfangen von Fehlern, beim lesen der Queue, kopieren der QueueMessage in myMessage
			{
				myMessage.getMsg(tempmsg);										//kopieren der Msg von myMessage in tempmsg
				cout << "							<- " << myMessage.getID() << "-" << tempmsg << " ";
				myQueue.display();
				cout << " (" << myQueue.getNumOfMessages() << ")" << endl;
			}
			else
			{
				cout << "FEHLER: Die Warteschlange ist leer!" << endl;
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
