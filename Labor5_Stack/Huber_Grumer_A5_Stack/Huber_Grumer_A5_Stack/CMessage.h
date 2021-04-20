#pragma once
//#ifndef CMESSAGE_H_
//#define CMESSAGE_H_
#include<cstring>						//Funktion "strcpy_s()"

const int	 MSG_MAX_LEN = 255;

class CMessage
{
public:
	int getID();
	void setID(int id);
	void getMsg(char* Msg);
	
	void setMsg(const char* Msg);				//implizite inline Definition
	

private:
	int mID;
	char mMsg[MSG_MAX_LEN];	//Null terminiert C-String

};


//#endif // !CMESSAGE_H_

