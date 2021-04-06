//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.30
//
//Sinn, Zweck der Datei:
//hier läuft das eigentliche Programm des Teil2
//

#include <iostream>
#include "PhoneCard.h"
using namespace std;


CPhoneCard DSObject;											//Ein Objekt der Klasse PhoneCard wird auf dem Datensegment wird erzeugt

int main()
{
	CPhoneCard StackObject;										//Ein Objekt der Klasse PhoneCard wird auf dem Stack wird erzeugt

	CPhoneCard* HeapObject = new CPhoneCard;					//Ein Pointer auf das Objekt der Klasse PhoneCard wird auf dem Heap wird erzeugt

	cout << "Datasegment object: ";
	DSObject.display();											//Die Methode "display" wird für das Objekt auf dem DS aufgerufen

	cout << "Stack object: ";
	StackObject.display();										//Die Methode "display" wird für das Objekt auf dem Stack aufgerufen

	cout << endl;

	HeapObject->display();										//Die Methode "display" wird für das Objekt auf dem Heap mittel Pfeiloperator aufgerufen, das es sich um einen Pointer handelt
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->refill_15();
	HeapObject->display();
	HeapObject->refill_15();
	HeapObject->display();

	cout << endl;

	cout << "Groesse von DSObject: " << sizeof(DSObject) << endl;			//Die Größe des Objektes kann mittels des Befehls "sizeof()" ermittelt werden
	cout << "Groesse von StackObject: " << sizeof(StackObject) << endl;		//Die Größe des Objektes kann mittels des Befehls "sizeof()" ermittelt werden	
	cout << "Groesse von HeapObject: " << sizeof(*HeapObject) << endl;		//"sizeof()" muss den Inhalt des Objektes übergeben werden, auf das der Pointer zeigt

	delete HeapObject;														//Löschen der Heaps


	return 0;
}