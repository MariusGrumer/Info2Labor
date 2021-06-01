#include "Device.h"

//#########################
//Fernbedienung
//#########################



CFernbedienung::CFernbedienung(CDevice* Dev1Ptr, CDevice* Dev2Ptr, CDevice* Dev3Ptr)
{
	mDev1Ptr = Dev1Ptr;
	mDev2Ptr = Dev2Ptr;
	mDev3Ptr = Dev3Ptr;
	mDevPtr = mDev1Ptr;		//zeigt zunaechst auf des erste Element
}


void CFernbedienung::mPlus()
{
	mDevPtr->mPlus();
}

void CFernbedienung::mMinus()
{
	mDevPtr->mMinus();
}

void CFernbedienung::mZustandsausgabe()
{
	mDevPtr->mZustandsausgabe();
}

void CFernbedienung::mModeChange()
{
	switch (mMode)
	{
	case CFernbedienung::Kaffeemaschine:
		mDevPtr = mDev2Ptr;
		mMode = Radio;
		break;
	case CFernbedienung::Radio:
		mDevPtr = mDev3Ptr;
		mMode = Heizung;
		break;
	case CFernbedienung::Heizung:
		mDevPtr = mDev1Ptr;
		mMode = Kaffeemaschine;
		break;
	case CFernbedienung::Unbekannt:
		cout << "error, Mode auf Kaffe gesetzt" << endl;
		mDevPtr = mDev1Ptr;
		mMode = Kaffeemaschine;
		break;
	default:
		break;
	}
}











//##########################
// Devices
//##########################
CKaffemaschine::CKaffemaschine(int i)
{
	mInternerZustand = i;
	mDeviceName = "Kaffemaschine";
}

void CKaffemaschine::mPlus() { mInternerZustand++; }
void CKaffemaschine::mMinus() { mInternerZustand--;}
void CKaffemaschine::mZustandsausgabe()
{
	cout << "Tschibo- Automat - Kaffemenge seht auf " << mInternerZustand << endl;
}

//###########################

CRadio::CRadio(int i)
{
	mInternerZustand = i;
	mDeviceName = "Radio";
}

void CRadio::mPlus() { mInternerZustand++; }
void CRadio::mMinus() { mInternerZustand--; }
void CRadio::mZustandsausgabe()
{
	cout << "Radio - Lautstaerke seht auf " << mInternerZustand << endl;
}

//############################

CHeizung::CHeizung(int i)
{
	mInternerZustand = i;
	mDeviceName = "Radio";
}

void CHeizung::mPlus() { mInternerZustand++; }
void CHeizung::mMinus() { mInternerZustand--; }
void CHeizung::mZustandsausgabe()
{
	cout << "Heizung - Temperatur seht auf " << mInternerZustand << endl;
}

//##########################