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
	switch (mCredit)
	{
	case 0:
		mStatus = 0;
		break;
	case 3:
		mCredit -= 3;
		mStatus = 0;
		break;
	case 6:
		mCredit -= 3;
		mStatus = 0;
		break;
	case 9:
		mCredit -= 3;
		mStatus = 1;
		break;
	case 12:
		mCredit -= 3;
		mStatus = 1;
		break;
	default:
		mCredit -= 3;
		mStatus = 2;
		break;
	}
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
		cout << "Error: Falscher Wert bei mStatus" << endl;		//Abfangen eines Fehlers, falls mStatus einen Falschen Wert hat
		break;
	}
}