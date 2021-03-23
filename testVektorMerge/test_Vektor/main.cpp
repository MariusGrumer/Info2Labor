#include <iostream>
#include"vectorlib.h"
using namespace std;
//Test erste Version merge Funktion 23.03., Sebastian

void aneinanderreihen(int* v1, int v1Len, int* v2, int v2Len, int* vDest);
void ausgabe(int* v, int vLen);
int main()
{
	//Vektordefinition vereinfacht zu Probezwecken
	const int v1Len = 4;			
	int v1[v1Len] = { 2,3,6,8 };
	const int v2Len = 4;
	int v2[v2Len] = { 1,4,6,8 };
	int vDest[v1Len + v2Len];

	int vDestLen = merge(v1, v1Len, v2, v2Len, vDest);		// warum werden Variablen und nicht Pointer übergeben, funktioniert aber
															//unsauber, dass Laenge nochmal ausgegeben?
	cout << " Vektor 1: ";
	ausgabe(v1, v1Len);
	cout << " Vektor 2: ";
	ausgabe(v2, v2Len);
	cout << " Zielvektor: ";
	ausgabe(vDest, vDestLen);

	//Test Pointer, Vektoren etc.
	/*
	const int v1Len = 4;
	int v1[v1Len] = { 1,3,6,7 };
	const int v2Len = 4;
	int v2[v2Len] = { 2,4,6,7 };
	int vDest[v1Len + v2Len];
	const int vDestLen = v1Len + v2Len;
	aneinanderreihen(v1, v1Len, v2, v2Len, vDest);

	cout << "Zielvektor: ";
	ausgabe(vDest, vDestLen);

	cout << "v2 alt: ";
	ausgabe(v2, v2Len);

	v2[0] = 9;
	cout << "v2 neu: ";
	ausgabe(v2, v2Len);

	cout << "Testausgabe, ob Zielvektor noch gleich: ";
	ausgabe(vDest, vDestLen);

	//for (int* ptr = v1; (ptr - v1) < v1Len; ptr++)
	//{
	//	cout << *ptr << endl;
	//};
	*/

	return (0);
}

void aneinanderreihen(int* v1, int v1Len, int* v2, int v2Len, int* vDest) { //aneinanderreihen von zwei Vektoren, Test, funktioniert
	
		for (int* ptrv1 = v1; (ptrv1 - v1) < v1Len; ptrv1++)
		{
			*vDest = *ptrv1;
			vDest++;
		}
		for (int* ptrv2 = v2; (ptrv2 - v2) < v2Len; ptrv2++)
		{
			*vDest = *ptrv2;
			vDest++;
		}
			
	}

void ausgabe(int*v, int vLen)		//Vereinfachte Ausgabe, ggf. neu ohne Übergabe Länge
{
	
	for (int* ptr = v; (ptr - v) < vLen; ptr++)
	{
		cout << *ptr;
	}
	cout << endl;
}