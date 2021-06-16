//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.16
//
//Sinn, Zweck der Datei:
//Deklaration der Klasse CMessage

#pragma once
#include <iostream>
#include<string>
using namespace std;


class CMessage
{
public:
	char BufferType;				//auf Stack oder Queue?
	int mID;
	string mData;					//enthaelt den Text



};