//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.14
//
//Sinn, Zweck der Datei:
//Hier läuft das Eigentliche Programm
//Deklaration Funktionen


#include <iostream>
#include "MyClass.h"

using namespace std;

MyClass callByValue(MyClass callByValueObject);

void callByReference(MyClass& callByReferenceObject);


MyClass GlobalObject;

int main()
{
	cout << "start" << endl;
	MyClass StackObject;
	MyClass *HeapObject = new MyClass;

	MyClass myObjB;
	MyClass myObjA = myObjB;

	MyClass myObjC;
	myObjC = myObjB;


	delete HeapObject;


	cout << endl;
	StackObject = callByValue(GlobalObject);
	cout << endl;
	callByReference(GlobalObject);
	cout << endl;
	return 0;
}


MyClass callByValue(MyClass callByValueObject)
{
	return callByValueObject;
}

void callByReference(MyClass& callByReferenceObject)
{

}