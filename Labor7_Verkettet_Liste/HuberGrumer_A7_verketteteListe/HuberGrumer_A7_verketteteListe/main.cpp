//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.05
//
//Sinn, Zweck der Datei:
//Hier läuft das eigentliche Programm


#include"CElement.h"
#include <string>
#include<iostream>
using namespace std;

CElement myListe;																						//root Element erzeugen

int main()
{
	string myText;																						//Variable zum Einlesen

	do
	{
		cout<<"Bitte geben Sie die Zeichenkette ein, die Sie einlesen wollen. (xxx bedeutet Abbruch) ";
		cin >> myText;
		if (myText!="xxx")																				//wenn kein "xxx" eingegeben wurde wird der eingegebne Text eingefuegt
		{
			myListe.einfuegen(myText);
		}
	} while (myText!="xxx");

	cout << endl << "Folgende Liste wurde eingegeben: " << endl;
	myListe.ausgabe();																					//Aufruf der Ausgabe Methode

	return 0;
}