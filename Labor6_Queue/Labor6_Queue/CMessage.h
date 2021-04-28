//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.28
//
//Sinn, Zweck der Datei:
//Deklaration der Methoden der Klasse CMessage (vlg gegeben von letzter Aufgabe)


//#pragma once							//Alternativ
#ifndef CMESSAGE_H_
#define CMESSAGE_H_
#include<cstring>						//Funktion "strcpy_s()"

const int	 MSG_MAX_LEN = 255;

class CMessage
{
public:
	int getID();
	void setID(int id);
	void getMsg(char* Msg)
	{
		strcpy_s(Msg, MSG_MAX_LEN, mMsg);
		//Fuer C-String (Null terminerte Stings)
		//funktioniert eine einfache Zuweisung nicht wie gewuenscht!
	}

	void setMsg(const char* Msg)				//implizite inline Definition
	{
		strcpy_s(mMsg, MSG_MAX_LEN, Msg);
	}


private:
	int mID;
	char mMsg[MSG_MAX_LEN];						//Null terminiert C-String

};


#endif // !CMESSAGE_H_

