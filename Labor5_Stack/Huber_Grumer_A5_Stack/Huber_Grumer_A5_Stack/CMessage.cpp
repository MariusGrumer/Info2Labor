#include "CMessage.h"

int CMessage::getID()						//done
{
	return mID;

}

void CMessage:: setID(int id)				//
{
	mID = id;		

}

void CMessage:: getMsg(char* Msg)			//done?
{
	strcpy_s(Msg, MSG_MAX_LEN, mMsg);
	//Fuer C-String (Null terminerte Stings)
	//funktioniert eine einfache Zuweisung nicht wie gewuenscht!
}

void CMessage:: setMsg(const char* Msg)				//implizite inline Definition
{
	strcpy_s(mMsg, MSG_MAX_LEN, Msg);
}

