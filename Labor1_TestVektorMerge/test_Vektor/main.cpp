//Informatik 2 Labor – 3er Team(Abgesprochen mit Herr Prof.Wietzke)
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Sebastian Schmitt		63304	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.23
//
//Sinn, Zweck der Datei:
//hier läuft das eigentliche Programm
//



#include <iostream>
#include"vectorlib.h"
using namespace std;





int main()
{
	int v1Len, v2Len;													//Initialisieung der Variablen fpr die Länge der Vektoren

	//1. Vektor
	einlesenLaenge(&v1Len, 1);											//Einlesen der Länge, Adresse wird übergeben

	int* v1 = new int[v1Len];											//Erzeugen dyn Array der Laenge v1Len
	einlesen(v1, v1Len);												//Einlesen des Vektors v1 mit der Länge V1Len



	//2.Vektor															//Wiederholung (siehe oben)
	einlesenLaenge(&v2Len, 2);

	int* v2 = new int[v2Len];
	einlesen(v2, v2Len);

	


	int vDest[10 + 10];											//Vektor mit ausreichender Länge definieren

	int vDestLen = merge(v1, v1Len, v2, v2Len, vDest);					//Rückgabewert der Funktion merge wird abgespeichert

	if(vDestLen <= 0)													//Hier werden Fehler abgefangen 
	{
		cout << "Error /n Fehlercode: " << vDestLen << endl;
		cout << "ein Vektor ist nicht Sortiert" << endl;
		return(0);
	}

	cout << " Vektor 1: ";
	ausgabe(v1, v1Len);
	cout << " Vektor 2: ";
	ausgabe(v2, v2Len);
	cout << " Ergebnis: ";
	ausgabe(vDest, vDestLen);


	delete[] v1;															//Löschen der dyn Arrays
	delete[] v2;

	return (0);
}
