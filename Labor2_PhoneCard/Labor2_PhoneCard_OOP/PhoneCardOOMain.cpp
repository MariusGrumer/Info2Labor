//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.03.30
//
//Sinn, Zweck der Datei:
//hier läuft das eigentliche Programm
//

#include <iostream>
#include "PhoneCard.h"
using namespace std;


CPhoneCard DSObject;

int main()
{
	CPhoneCard StackObject;

	CPhoneCard* HeapObject = new CPhoneCard;
	cout << "Datasegment object: ";
	DSObject.display();

	cout << "Stack object: ";
	StackObject.display();

	cout << endl;

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
	HeapObject->makeCall();
	HeapObject->display();
	HeapObject->refill_15();
	HeapObject->display();
	HeapObject->refill_15();
	HeapObject->display();

	cout << endl;

	cout << "Groesse von DSObject: " << sizeof(DSObject) << endl;
	cout << "Groesse von StackObject: " << sizeof(StackObject) << endl;
	cout << "Groesse von HeapObject: " << sizeof(*HeapObject) << endl;

	delete HeapObject;


	return 0;
}