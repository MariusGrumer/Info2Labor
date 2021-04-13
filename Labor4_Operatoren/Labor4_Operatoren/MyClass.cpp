//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.14
//
//Sinn, Zweck der Datei:
//Implementierung der Mehtoden

#include <iostream>
#include "MyClass.h"

using namespace std;

MyClass::MyClass()
{
	cout << "Ctor wurde gerade aufgerufen" << endl;
}
MyClass::~MyClass()
{
	cout << "Dtor wurde gerade aufgerufen" << endl;
}
MyClass::MyClass(const MyClass &rhs)
{
	cout << "copy Ctor wurde gerade aufgerufen" << endl;
}
MyClass& MyClass::operator=(const MyClass &rhs)
{
	cout << "Zuweisungsoperator wurde gerade aufgerufen" << endl;
	return *this;
}