#pragma once
#include<string>
using namespace std;

class CElement
{
public:
	CElement(string data);
	string mData;
	CElement* mPtrNext;  //!zeigt Rückwärts da sonst nicht möglich???



};

