//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.30
//
//Sinn, Zweck der Datei:
//hier läuft das eigentliche Programm
//

#include <iostream>
using namespace std;

void phoneCardMakeCall();
void phoneCardDisplay();
void phoneCardRefill_15();


//globale Variable phoneCard mit dem Startguthaben 15 Euro:
int phoneCard = 15;

//globale Variable welche den Status des Guthabens wiedergibt:
int phoneCardStatus = 2;



int main()
{
	phoneCardDisplay();
	phoneCardMakeCall();
	phoneCardDisplay();
	phoneCardMakeCall();
	phoneCardDisplay();
	phoneCardMakeCall();
	phoneCardDisplay();
	phoneCardMakeCall();
	phoneCardDisplay();
	phoneCardMakeCall();
	phoneCardDisplay();
	phoneCardMakeCall();
	phoneCardDisplay();
	phoneCardRefill_15();
	phoneCardDisplay();
	phoneCardRefill_15();
	phoneCardDisplay();

	return 0;
}

void phoneCardMakeCall()
{
	switch (phoneCardStatus)
	{
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;

	}


	phoneCard -= 3;

}

void phoneCardDisplay()
{
	switch (phoneCardStatus)				//Ausgabe des Guthabens und des Kartenstatus
	{
	case 0:
		cout << "Karte bitte auffuellen " << phoneCard<< endl;
		break;
	case 1:
		cout << "Karte ist ca. halbvoll " << phoneCard << endl;
		break;
	case 2:
		cout << "Karte ist gut gefuellt " << phoneCard << endl;
		break;
	default:
		cout << "Error: Falscher Wert bei phoneCardStatus" << endl;		//Abfangen eines Fehlers, falls phoneCardStatus einen Falschen Wert hat
		break;
	}
}

void phoneCardRefill_15()
{
	phoneCard += 15;
	phoneCardStatus = 2;
}

