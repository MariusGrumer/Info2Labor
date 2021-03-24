#include <iostream>
#include"vectorlib.h"
using namespace std;
//Zweite Version merge Funktion 24.03., Sebastian


void ausgabe(int* v, int vLen);
int main()
{
	//Einlesen fehlt --> Philipp?
	//Vektordefinition vereinfacht zu Probezwecken
	const int v1Len = 8;
	int v1[v1Len] = { 1,1,2,3,6,8,9,9 };
	const int v2Len = 4;
	int v2[v2Len] = { 1,4,6,8 };
	int vDest[v1Len + v2Len];			//Vektor mit ausreichender Länge definieren

	int vDestLen = merge(v1, v1Len, v2, v2Len, vDest);		// warum werden Variablen und nicht Pointer übergeben, funktioniert aber
															//Anzahl Elemente in Vektor statt länge zurückgeben
	cout << " Vektor 1: ";
	ausgabe(v1, v1Len);
	cout << " Vektor 2: ";
	ausgabe(v2, v2Len);
	cout << " Zielvektor: ";
	ausgabe(vDest, vDestLen);


	return (0);
}



void ausgabe(int* v, int vLen)		//Vereinfachte Ausgabe
{

	for (int* ptr = v; (ptr - v) < vLen; ptr++)
	{
		cout << *ptr;
	}
	cout << endl;
}