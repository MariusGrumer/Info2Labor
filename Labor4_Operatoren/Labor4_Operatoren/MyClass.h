//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.14
//
//Sinn, Zweck der Datei:
//Deklaration der Methoden

#pragma once

class MyClass
{
public:
	MyClass();											//Ctor ohne param
	~MyClass();											//dtor
	MyClass(const MyClass &rhs);						//copy Ctor
	MyClass& operator=(const MyClass&);					//Zuweisungsoperator

private:

};