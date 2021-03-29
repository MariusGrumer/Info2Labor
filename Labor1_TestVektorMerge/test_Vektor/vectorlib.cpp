//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.24
//
//Sinn, Zweck der Datei:
//Implementieren der Funktionen
//


#include"vectorlib.h"
using namespace std;

void einlesenLaenge(int* vLen, int Vektornummer)
{
	do
	{
		cout << "Geben Sie die Laenge des "<<Vektornummer<<". Vectors ein (max. 10) -> ";
		cin >> *vLen;															//Wert f�r vLen einlesen
	} while (*vLen > 10 || *vLen < 1);											// Fehlerabfrage, ob die L�nge zwischen der Erlaubten 1 und 10 als L�nge liegt
																				//Schleife l�uft so lange bis vLen f�r das richtige Intervall angegeben wurde
}

void einlesen(int* vektoradr, int vektLen)					
{
																		
	for (int* ptr = vektoradr; (ptr - vektoradr) < vektLen; ptr++)				//Schleife, die f�r jede Position einen Wert f�r den Vektor einliest
	{
		cout << (ptr - vektoradr) + 1 << ". Vektorelement -> ";
		cin >> *ptr;
	}

}


int merge(int* v1, int v1Len, int* v2, int v2Len, int* vDest) 
{

	if (isSorted(v1, v1Len) == false || isSorted(v2, v2Len) == false)			//Bedingung falls ein Wert nicht sortiert ist, wird der Fehlercode -1 zur�ckgeliefert
	{
		return -1;
	}


	int* v1ptr = v1;
	int* v2ptr = v2;
	
	//Sortieralgorithmus
	for (int* vDestptr = vDest; (vDestptr - vDest) < (v1Len+v2Len); vDestptr++)
	{
		if (((v1ptr - v1) < v1Len) && ((v2ptr - v2) < v2Len))				//�berpr�fung ob einer der beiden Vektoren bereits komplett in vDest kopiert wurde
		{
			if (*v1ptr <= *v2ptr) {											//Falls v2 gr��er als v1 ist, wird v1 in vDest kopiert
				*vDestptr = *v1ptr;
				v1ptr++;
			}
			else															//Anderer Fall, v2 wird in vDest kopiert
			{
				*vDestptr = *v2ptr;
				v2ptr++;
			}
		}
		else if (((v1ptr - v1) >= v1Len))									//Falls v1 schon komplett in vDest kopiert wurde, wird der rest von v2 in vDest kopiert
		{
			*vDestptr = *v2ptr;
			v2ptr++;
		}
		else if (((v2ptr - v2) >= v2Len))									//Anderer Fall, v1 wird komplett in vDest kopiert
		{
			*vDestptr = *v1ptr;
			v1ptr++;
		}

	}
	return v1Len+v2Len;
}


bool isSorted(int* v, int vLen)											//Die Funktion isSorted �berpr�ft ob die Vektoren aufsteigend sortiert sind, gibt true oder false zur�ck
{
	vLen--;																//vLen muss um 1 reduziert werden, da  nicht �berpr�ft werden muss ob der Letzte Wert kleiner als ein darauf folgender Wert ist.
																		//Sonst w�rde auf einen Speicherplatz zugegriffen werden, welcher nicht teil des Array ist.
	for (int* i = v; (i - v) < vLen; i++)								//Schleife zum �berpr�fen von jedem Wert
	{
		if (*i > *(i + 1))												//Bedingung erf�llt falls ein Wert gr��er als sein darauf folgender Wert ist
		{
			//cout << *i << " ist groesser als " << *(i + 1) << endl;	//optionale Fehlermeldung 
			return false;
		}
	}
	return true;
}


void ausgabe(int* v, int vLen)											//Ausgabe eines Vektors in {...}
{
	cout << "{ ";
	for (int* ptr = v; (ptr - v) < vLen; ptr++)
	{
		cout << *ptr<<" ";
	}
	cout <<"}"<< endl;
}