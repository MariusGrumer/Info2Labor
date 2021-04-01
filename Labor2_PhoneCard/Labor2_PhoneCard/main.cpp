//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.30
//
//Sinn, Zweck der Datei:
//hier läuft das eigentliche Programm und die Funtktionen werden deklariert
//die Objektorientierte Variente ist in dem Projekt Labor2_Phonecard_OOP zu finden

#include <iostream>
using namespace std;

//Deklaration der Funktionen, die unten im Programm implementiert werden
void phoneCardMakeCall();
void phoneCardDisplay();
void phoneCardRefill_15();


//globale Variable phoneCard mit dem Startguthaben 15 Euro:
unsigned int phoneCard = 15;			//kann nicht negativ werden

//globale Variable welche den Status des Guthabens wiedergibt:
int phoneCardStatus = 2;		



int main()
{
	//gefordeter Aufruf der Funktionen
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

void phoneCardMakeCall()							//Funktion für die Anruffuntion
{
	switch (phoneCard)								//je nach Guthaben wird der Anruf ausgeführt (Geld abgezogen) und der Status entsprechend gesetzt
	{												//Es sind immer nur die Vielfachen von 3 von Bedeutung, da nur 3 abgezogen werden kann
	case 0:
		phoneCardStatus = 0;
		break;
	case 3:
		phoneCard -= 3;
		phoneCardStatus = 0;
		break;
	case 6:
		phoneCard -= 3;
		phoneCardStatus = 0;
		break;
	case 9:
		phoneCard -= 3;
		phoneCardStatus = 1;
		break;
	case 12:
		phoneCard -= 3;
		phoneCardStatus = 1;
		break;
	default:
		phoneCard -= 3;
		phoneCardStatus = 2;
		break;
	}
}

void phoneCardDisplay()
{
	switch (phoneCardStatus)											//Ausgabe des Guthabens und des Kartenstatus je nach dem welcher Status in der globalen Variable des Statuses hinterlegt ist
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
	phoneCard += 15;													//die globaen Variablen zu Guthaben und Status werden bei einem Aufladen angepasst
	phoneCardStatus = 2;
}

