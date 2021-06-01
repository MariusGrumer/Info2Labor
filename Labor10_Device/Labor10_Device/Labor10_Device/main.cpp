
#include"Device.h"
#include<iostream>
using namespace std;

int main()
{
	CRadio myRadio(10);
	CHeizung myHeizung(80);
	CKaffemaschine myKaffem(1000000);

  	CFernbedienung myFernbedienung(&myKaffem,&myRadio,&myHeizung);
	myFernbedienung.mZustandsausgabe();
	myFernbedienung.mModeChange();
	myFernbedienung.mZustandsausgabe();
	myFernbedienung.mMinus();
	myFernbedienung.mZustandsausgabe();

	return 0;
}