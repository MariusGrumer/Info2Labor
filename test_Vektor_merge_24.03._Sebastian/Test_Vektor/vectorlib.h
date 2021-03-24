#pragma once
#include <iostream>
using namespace std;

//Zweite Version merge Funktion 24.03., Sebastian
//weitere sinnvolle Funktionen sinnvoll

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest);			//Wie in Aufgabenstellung gefordert

int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) {
	int vDestLen = v1Len + v2Len;					//ggf
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
		else if(((v1ptr - v1) >= v1Len))
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