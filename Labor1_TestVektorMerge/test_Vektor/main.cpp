#include <iostream>
#include"vectorlib.h"
using namespace std;
//Zweite Version merge Funktion 24.03., Sebastian




int main()
{
	//Einlesen fehlt --> Philipp?
	//Vektordefinition vereinfacht zu Probezwecken
	const int v1Len = 8;
	int v1[v1Len] = { 1,3,3,4,5,6,7,7 };
	const int v2Len = 4;
	int v2[v2Len] = { 1,2,6,8 };
	int vDest[v1Len + v2Len];			//Vektor mit ausreichender Länge definieren

	int vDestLen = merge(v1, v1Len, v2, v2Len, vDest);		//Rückgabewert der Funktion merge wird abgespeichert

	if(vDestLen <= 0)						//Hier werden Fehler abgefangen
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


	return (0);
}
