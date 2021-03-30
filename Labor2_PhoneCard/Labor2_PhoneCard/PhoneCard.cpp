#include<iostream>
#include "PhoneCard.h"
using namespace std;

CPhoneCard::CPhoneCard()
{
	mCredit = 15;
	mStatus = 2;
}

void CPhoneCard::makeCall()
{

}

void CPhoneCard::refill_15()
{
	mCredit += 15;
	mStatus = 2;
}

void CPhoneCard::display()
{
	switch (mStatus)				//Ausgabe des Guthabens und des Kartenstatus
	{
	case 0:
		cout << "Karte bitte auffuellen " << mCredit << endl;
		break;
	case 1:
		cout << "Karte ist ca. halbvoll " << mCredit << endl;
		break;
	case 2:
		cout << "Karte ist gut gefuellt " << mCredit << endl;
		break;
	default:
		cout << "Error: Falscher Wert bei mStatus" << endl;		//Abfangen eines Fehlers, falls phoneCardStatus einen Falschen Wert hat
		break;
	}
}