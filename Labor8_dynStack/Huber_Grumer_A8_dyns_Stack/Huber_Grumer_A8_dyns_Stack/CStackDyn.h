//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.05.12
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse CStackdyn

#pragma once
#include<string>
using namespace std;


class CStackDyn						// LIMFO wächst nach oben, zeigt auf Leerelement
{
public:
	CStackDyn();						//ctor ohne Param
	~CStackDyn();

	bool push(const string& data);
	bool pop(string& data);
	void display(void);




private:
	CElement* mPtrHead;				//Zeigt auf Kopf des Stacks
};

