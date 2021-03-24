#pragma once
#include <iostream>
using namespace std;

//Zweite Version merge Funktion 24.03., Sebastian
//weitere sinnvolle Funktionen sinnvoll

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest);			//Wie in Aufgabenstellung gefordert
//Deklaration in cpp Datei

bool checkSorting(int* v, int vLen);



int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) {

	if (checkSorting(v1, v1Len) == false || checkSorting(v2, v2Len) == false)		//Bedingung falls ein Wert nicht sortiert ist, wird der Fehlercode -1 zurückgeliefert
	{
		return -1;
	}


	int vDestLen = v1Len + v2Len;					//umbennen, weil nicht länge sondern Anz Elemente
	int* v1ptr = v1;
	int* v2ptr = v2;
	/*
	* aneinanderreihen funktionsfähig
	*
	*/
	for (int* vDestptr = vDest; (vDestptr - vDest) < vDestLen; vDestptr++)
	{
		if (((v1ptr - v1) < v1Len) && ((v2ptr - v2) < v2Len))
		{
			if (*v1ptr <= *v2ptr) {
				*vDestptr = *v1ptr;
				v1ptr++;
			}
			else
			{
				*vDestptr = *v2ptr;
				v2ptr++;
			}
		}
		else if (((v1ptr - v1) >= v1Len))
		{
			*vDestptr = *v2ptr;
			v2ptr++;
		}
		else if (((v2ptr - v2) >= v2Len))
		{
			*vDestptr = *v1ptr;
			v1ptr++;
		}

	}
	return vDestLen;
}


bool checkSorting(int* v, int vLen)									//Die Funktion checkSorting überprüft ob die Vektoren aufsteigend sortiert sind, gibt true oder false zurück
{
	vLen--;															//vLen muss um 1 reduziert werden, da  nicht überprüft werden muss ob der Letzte Wert kleiner als ein darauf folgender Wert ist.
	for (int* i = v; (i - v) < vLen; i++)							//Schleife zum überprüfen von jedem Wert
	{
		if (*i > *(i + 1))											//Bedingung erfüllt falls ein Wert größer als sein darauf folgender Wert ist
		{
			//cout << *i << " ist groesser als " << *(i + 1) << endl;	//optionale Fehlermeldung 
			return false;											
		}
	}
	return true;
}