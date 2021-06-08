//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.08
//
//Sinn, Zweck der Datei:
//Hier läuft das eigentliche Programm

#include "CRechteck.h"
#include <iostream>
using namespace std;

bool pruefeUeberlappung(CRechteck& R1,CRechteck& R2);

bool rechteckEinlesen(float &xA, float& yA, float& xB, float& yB);	//Funktion zum Einlesen von Rechtecken, speichert Eingelesen Werte in Alias ab


int main()
{
	float P1X, P1Y, P2X, P2Y;	//float Variablen zum einlesen der Punkte

	cout << "Bitte geben Sie zwei Rechtecke ein:" << endl << endl;
	cout << "Rechteck R1" << endl;
	if (rechteckEinlesen(P1X, P1Y, P2X, P2Y) == false)
	{
		cout << "ERROR bei Eingabe" << endl;
		return -1;
	}
	CRechteck RechteckA(P1X, P1Y, P2X, P2Y);



	cout << "Rechteck 2" << endl;
	if (rechteckEinlesen(P1X, P1Y, P2X, P2Y) == false)
	{
		cout << "ERROR bei Eingabe" << endl;
		return -1;
	}
	CRechteck RechteckB(P1X, P1Y, P2X, P2Y);

	float A1, A2;
	RechteckA.getFlaeche(A1);
	RechteckB.getFlaeche(A2);

	cout << "Ausgabe der Ergebnisse: " << endl << "-----------------------------" << endl;
	cout << "R1 = ";
	RechteckA.display();
	cout << ", A(R1) = " << A1 << endl;

	cout << "R2 = ";
	RechteckB.display();
	cout << ", A(R2) = " << A2 << endl;

	cout << endl << endl;
	pruefeUeberlappung(RechteckA, RechteckB);
	cout << endl << endl;
	return 0;
}


bool pruefeUeberlappung(CRechteck& R1, CRechteck& R2)
{
	// überprüfung der Überlappung???
	float R1AX, R1AY, R1BX, R1BY, R2AX, R2AY, R2BX, R2BY;	//alle Eckpunkte der Rechtecke
	R1.getPunktA(R1AX, R1AY);
	R1.getPunktB(R1BX, R1BY);
	R2.getPunktA(R2AX, R2AY);
	R2.getPunktB(R2BX, R2BY);
	
	//Sobald ein Punkt eines Rechteckes in einem Anderen Rechteck liegt überdecken sich diese

	if (R2AX<R1BX && R2AX>R1AX && R2AY<R1BY && R2AY>R1AY)
	{
		//cout << "R2A liegt in R1" << endl;
		return true;
	}
	if (R2BX<R1BX && R2BX>R1AX && R2BY<R1BY && R2BY>R1AY)
	{
		//cout << "R2B liegt in R1" << endl;
		return true;
	}

	if (R1AX<R2BX && R1AX>R2AX && R1AY<R2BY && R1AY>R2AY)
	{
		//cout << "R1A liegt in R2" << endl;
		return true;
	}
	if (R1BX<R2BX && R1BX>R2AX && R1BY<R2BY && R1BY>R2AY)
	{
		//cout << "R1B liegt in R2" << endl;
		return true;
	}

	//es fehlt:
	// - vollständige umschließung ?? fehlt das wirklich
	// - exakte Deckungsgleichheit
	// Falls Punkt C oder D in einem anderen Rechteck liegt





	return true;
}

bool rechteckEinlesen(float& xA, float& yA, float& xB, float& yB)
{
	cout << "-----------------------------" << endl;
	cout << "Punkt 1, X-Koordinate?: ";
	cin >> xA;
	cout << "Punkt 1, Y-Koordinate?: ";
	cin >> yA;
	cout << "Punkt 2, X-Koordinate?: ";
	cin >> xB;
	cout << "Punkt 2, Y-Koordinate?: ";
	cin >> yB;
	cout << endl;

	return true;
}