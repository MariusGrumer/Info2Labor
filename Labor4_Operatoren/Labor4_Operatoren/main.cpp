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
/*-----------------------------------------------------------------------------------------------------------------
*	Erklearung des Programm:
*	Das Globale Objekt wird zuerst erzeugt und somit wird dieser Destruktor auch zuletzt aufgrufen
*	Ein Heap Objekt kann mit new erstellt werden und bleibt solange bestehen bis es mit delete zerstört wird
*	Stackobjekte werden nacheinander konstruiert und am ende der Laufzeit in umgekehrter Reihenfolge zerstört. Da kein Destruktor aufgerufen wird, erfolgt dies nach system("PAUSE")
*	Der copyCtor wird an unterschiedlichen Stellen aufgerufen. Zur Instrumentation wird der ursprüngliche copyCtor überschrieben.
*	Der Zuweisungsoperator wird wie der copyCtor neu definiert und wird bei zuweisungen ohne neuinitialisierung aufgerufen.
*	Beim Aufruf der Funktion callbyValue wird eine Kopie erzeugt des Objektes, dieses besteht solang bis die Funktion die geschweiften Klammern verlaesst. 
*	Besonderheit hier ist die Kopie für den Returnwert über die Laufzeit der Funktion hinweg. 
*	Beim Aufruf der Funktion callbyReference wird ein Alias der übergebenen Referenz angelegt.
***************************************/


#include <iostream>
#include "MyClass.h"


using namespace std;

MyClass callByValue(MyClass callByValueObject);

void callByReference(MyClass& callByReferenceObject);


MyClass GlobalObject;							//Ctor wurde aufgerufen (GlobalObject)

int main()
{
	MyClass StackObject;						//Ctor wurde aufgerufen (StackObject)
	MyClass *HeapObject = new MyClass;			//Ctor wurde aufgerufen (HeapObject)
	cout << endl;

	MyClass myObjB;								//Ctor wurde aufgerufen (myObjB)
	MyClass myObjA = myObjB;					//copy Ctor wurde aufgerufen (myObjA)
	cout << endl;

	MyClass myObjC;								//Ctor wurde aufgerufen (myObjC)
	myObjC = myObjB;							//Zuweisungsoperator wurde aufgerufen (myObjB in myObjC)
	cout << endl;

	delete HeapObject;							//Dtor wurde aufgerufen (HeapObject)
	cout << endl;
	cout << "callByValue: " << endl;
	StackObject = callByValue(GlobalObject);	//copy Ctor wurde aufgerufen (GlobalObject wird in CallByValue Object kopiert)
												//copy Ctor wurde aufgerufen (callByValueObject wird in returnObject kopiert)
												//Dtor wurde aufgerufen (CallByValueObject)
												//Zuweisungsoperator wurde aufgerufen (dem StackObject wir das returnObject zugewiesen)
												//Dtor wurde aufgerufen (returnObject)
	cout << endl;
	cout << "callByReference: " << endl;
	callByReference(GlobalObject);				//hier gibt es keine ausgaben, da hier keine Zuweisung, Kopie oder eine Konstruktion eines Objektes erfolgt
	cout << endl;
	system("PAUSE");							// Drücken Sie eine beliebige Taste . . .
												// Dtor wurde aufgerufen(myObjC)
												// Dtor wurde aufgerufen(myObjA)
												// Dtor wurde aufgerufen(myObjB)
												// Dtor wurde aufgerufen(StackObject)
												// Dtor wurde aufgerufen(GlobalObject)
	return 0;
}


MyClass callByValue(MyClass callByValueObject)
{
	return callByValueObject;
}

void callByReference(MyClass& callByReferenceObject)
{

}