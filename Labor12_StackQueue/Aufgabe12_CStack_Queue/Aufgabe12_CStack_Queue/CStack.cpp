//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Implementierung der Klasse CStack


#include "CStack.h"
#include "Cmessage.h"


CStack::CStack(int pSize) :mSize(pSize), mIndex(0)		//ctor mit Param
{
	/*mIndex = 0;
	mSize = pSize;*/
	mStackPtr = new CMessage[pSize];
}

CStack::~CStack()
{
	delete[] mStackPtr;				//loesche das Array
}

bool CStack::add(CMessage& pMsg)
{
	if (mIndex >= mSize)				// Stack voll?
	{
		return false;					// da 10 nicht als Platz verfügbar ist
	}


	mStackPtr[mIndex] = pMsg;			// MSG schreiben, 1zu1 Kpie des Zuweisungsoperator
	mIndex++;							// SP inkrementieren

	return true;
}


bool CStack::get(CMessage& pMsg)
{
	if (mIndex == 0)						//stack leer?
	{
		return false;					//SP leer?
	}

	mIndex--;
	pMsg = mStackPtr[mIndex];

	return true;
}
