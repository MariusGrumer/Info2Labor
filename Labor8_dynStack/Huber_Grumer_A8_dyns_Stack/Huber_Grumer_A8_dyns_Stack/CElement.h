#pragma once
#include<string>
using namespace std;

class CElement
{
public:
	CElement(string data);
	string mData;
	CElement* mPtrNext;  //!zeigt R�ckw�rts da sonst nicht m�glich???



};

