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

