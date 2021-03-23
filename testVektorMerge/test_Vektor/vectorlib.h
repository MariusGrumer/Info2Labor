#pragma once
#include <iostream>
using namespace std;

//Erste Version merge Funktion 23.03., Sebastian

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest);			//Wie in Aufgabenstellung geforder

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) {
	int vDestLen = v1Len + v2Len;					//ggf
	int* v1ptr = v1;
	int* v2ptr = v2;
	/*
	* aneinanderreihen noch nicht voll funktionsfähig: nur gleich lange Vektoren, Sortieren funktioniert, aber letzter Wert nicht zuverlässig
	*/
	for (int* vDestptr = vDest; (vDestptr - vDest) < vDestLen; vDestptr++)		
	{
		//if((v1ptr-v1)<v1Len)		Beginn Verbesserung Sortierung
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
	return vDestLen;
}