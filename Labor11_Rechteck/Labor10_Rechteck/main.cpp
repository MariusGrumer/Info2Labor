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

	// Flächenberechnung
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

	cout << endl << "pruefeUeberlappung(R1, R2) = " << pruefeUeberlappung(RechteckA, RechteckB) << endl;
	cout << "pruefeUeberlappung(R2, R1) = " << pruefeUeberlappung(RechteckB, RechteckA) <<"(Aufruf mit vertauschten Parametern R1 und R2)"<< endl;
	cout << endl << endl;
	return 0;
}


bool pruefeUeberlappung(CRechteck& R1, CRechteck& R2)
{
	float R1AX, R1AY, R1BX, R1BY, R2AX, R2AY, R2BX, R2BY;	//alle Eckpunkte der Rechtecke
	R1.getPunktA(R1AX, R1AY);		// unten Links von R1
	R1.getPunktB(R1BX, R1BY);		// oben Rechts von R1
	R2.getPunktA(R2AX, R2AY);		// unten Links von R2
	R2.getPunktB(R2BX, R2BY);		// oben Rechts von R2
	

	if (R1AX == R2AX && R1AY == R2AY && R1BX == R2BX && R1BY == R2BY)		//Deckungsgleich
	{
		//cout << "Rechtecke sind Deckungsgleich" << endl;
		return true;
	}

	if (R1AY == R2AY && R1BY == R2BY && (R1AX<R2BX && R1AX>R2AX || R1BX<R2BX && R1BX>R2AX))
	{
		//cout << "Y-Werte gleich, X-Verschoben" << endl;
		return true;
	}
	if (R1AX == R2AX && R1BX == R2BX && (R1AY<R2BY && R1AY>R2AY || R1BY<R2BY && R1BY>R2AY))
	{
		//cout << "X-Werte gleich, Y-Verschoben" << endl;
		return true;
	}


	//Sobald ein Punkt eines Rechteckes in einem Anderen Rechteck liegt überdecken sich diese

	//Überprüfung ob ein Punkt von R2 in R1 liegt
	if (R2AX<R1BX && R2AX>R1AX && R2AY<R1BY && R2AY>R1AY)	//R2A
	{
		//cout << "R2A liegt in R1" << endl;
		return true;
	}
	if (R2BX<R1BX && R2BX>R1AX && R2BY<R1BY && R2BY>R1AY)	//R2B
	{
		//cout << "R2B liegt in R1" << endl;
		return true;
	}
	if (R2BX<R1BX && R2BX>R1AX && R2AY<R1BY && R2AY>R1AY)	//R2C --> unten rechts	(R2BX, R2AY)
	{
		//cout << "R2C liegt in R1" << endl;
		return true;
	}
	if (R2AX<R1BX && R2AX>R1AX && R2BY<R1BY && R2BY>R1AY)	//R2D --> oben links	(R2AX, R2BY)
	{
		//cout << "R2C liegt in R1" << endl;
		return true;
	}

	// Überprüfung ob ein Punkt von R1 in R2 liegt
	if (R1AX<R2BX && R1AX>R2AX && R1AY<R2BY && R1AY>R2AY)	//R1A
	{
		//cout << "R1A liegt in R2" << endl;
		return true;
	}
	if (R1BX<R2BX && R1BX>R2AX && R1BY<R2BY && R1BY>R2AY)	//R1B
	{
		//cout << "R1B liegt in R2" << endl;
		return true;
	}
	if (R1BX<R2BX && R1BX>R2AX && R1AY<R2BY && R1AY>R2AY)	//R1C --> unten rechts	(R1BX, R1AY)
	{
		//cout << "R1C liegt in R2" << endl;
		return true;
	}
	if (R1AX<R2BX && R1AX>R2AX && R1BY<R2BY && R1BY>R2AY)	//R1D --> oben links	(R1AX, R1BY)
	{
		//cout << "R1D liegt in R2" << endl;
		return true;
	}

	return false;
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