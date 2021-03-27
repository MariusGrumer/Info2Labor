//Informatik 2 Labor  Aufgabe 1
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.27
//
//Sinn, Zweck der Datei:
//Implementieren der Funktionen
//



#pragma once
#include <iostream>
using namespace std;

void einlesenLaenge(int* vLen, int Vektornummer);					//Einlesen der L�nge des Vektors (bsp 1. Vektor hat die Vektornummer = 1)

void einlesen(int* vektoradr, int vektLen);							//Funktion zum Einlesen von Vektoren

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest);		//Wie in Aufgabenstellung gefordert

bool isSorted(int* v, int vLen);									//�berpr�ft die Aufsteigende Reihenfolge der Vektoren

void ausgabe(int* v, int vLen);										//Gibt einen Vektor aus
