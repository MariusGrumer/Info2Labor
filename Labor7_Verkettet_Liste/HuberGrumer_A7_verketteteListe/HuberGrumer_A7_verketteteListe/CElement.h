#pragma once
#include <string>
#include<iostream>
using namespace std;

class CElement
{
public:
	CElement();
	CElement(string& pText);
	~CElement();

	bool einfuegen(string& pText);
	bool ausgabe();


private:
	string mText;
	CElement* mNextPtr;

};

