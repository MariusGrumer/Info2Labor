//#pragma once
#ifndef CMESSAGE_H_
#define CMESSAGE_H_
#include<cstring>						//Funktion "strcpy_s()"

const int	 MSG_MAX_LEN = 3;

class CMessage
{
public:
	int getID();
	void setID(int id);
	void getMsg(char* Msg)			//done?
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
	char mMsg[MSG_MAX_LEN];	//Null terminiert C-String

};


#endif // !CMESSAGE_H_

