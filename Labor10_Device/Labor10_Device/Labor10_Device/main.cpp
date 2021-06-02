//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.02
//
//Sinn, Zweck der Datei:
//Hier l�uft das eigentliche Programm



#include"Device.h"
#include<iostream>
#include <string>
using namespace std;

int main()
{

	CRadio myRadio("Radio_1",10);								//ctor der verschiedenen Devices mit Param
	CHeizung myHeizung("Heizung_1",80);							//ctor der verschiedenen Devices mit Param
	CKaffemaschine myKaffem("Tschibo-Automat_1",100);			//ctor der verschiedenen Devices mit Param

	CFernbedienung myFernbedienung("Fernbedienung_1",&myKaffem, &myRadio, &myHeizung);		//ctor der Fernbedienung mit Param; Adressen der Devices wird �bergeben

	myFernbedienung.mZustandsausgabe();							//Zustandsausgabe des ersten Devices 

	char option;												//Variable zum Einlesen was als n�chstens passieren soll
	do
	{
		cout << " bitte Eingabe, M(ode), +, -, E(nde)"<<endl;
		cin >> option;
		switch (option)
		{
		case 'M':												//Es werden immmer die entsprechenden Methoden der Klasse Fernbedienung aufgerufen. 
		{
			myFernbedienung.mModeChange();						//Mode �ndern
			myFernbedienung.mZustandsausgabe();
			break;
		}

		case '+':												//Taste + gedr�ckt
		{
			myFernbedienung.mPlus();
			myFernbedienung.mZustandsausgabe();
			break;
		}

		case '-':												//Taste - gedr�ckt
		{
			myFernbedienung.mMinus();
			myFernbedienung.mZustandsausgabe();
			break;
		}
		case 'E':												//Es passiet nichts. Die Schleife wird anschlie�end verlassen
		{
			break;
		}

		default:
			cout << "Ihre Eingabe wurde nicht erkannt. Bitte versuchen Sie es nocheinmal." << endl;					//Abfangen von Falsch eingegebenen Werten f�r option
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');														//l�schen des Buffers
			break;
		}


		
	} while (option != 'E');									//Schleife verlassen wenn "E" eingegeben wurde


	return 0;
}