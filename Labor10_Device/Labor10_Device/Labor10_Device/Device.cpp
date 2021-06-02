//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.02
//
//Sinn, Zweck der Datei:
//Implementierung der Methoden der Klassen


#include "Device.h"

//#########################
//Fernbedienung
//#########################


CFernbedienung::CFernbedienung(string deviceName, CDevice* Dev1Ptr, CDevice* Dev2Ptr, CDevice* Dev3Ptr)
{
	mDev1Ptr = Dev1Ptr;				//enthält den Ptr der auf das erste Device zeigt
	mDev2Ptr = Dev2Ptr;				//							...zweite...
	mDev3Ptr = Dev3Ptr;				//							...dritte...
	mDevPtr = mDev1Ptr;				//zeigt zunaechst auf des erste Element
	mDeviceName = deviceName;		//Name der Fernbedienung
}


void CFernbedienung::mPlus()
{
	mDevPtr->mPlus();					//Delegation an das Device
}

void CFernbedienung::mMinus()
{
	mDevPtr->mMinus();					//Delegation an das Device
}

void CFernbedienung::mZustandsausgabe()
{
	cout << mDeviceName << " - Mode: ";	//Ausgabe des Namens der Fernbedierung
	mDevPtr->mZustandsausgabe();		//Delegation der Ausgabe des Zustandes des aktuellen Devices an das Device selbst
}

void CFernbedienung::mModeChange()		//beim Drücken der Taste wird auf das nächste Element gewechselt
{
	switch (mMode)				
	{
	case CFernbedienung::Kaffeemaschine:
		mDevPtr = mDev2Ptr;				//die Attribute mDevPtr, mMode der Klasse Fernbedienung werden für das folgende Device zugeordnet
		mMode = Radio;
		break;
	case CFernbedienung::Radio:
		mDevPtr = mDev3Ptr;				//die Attribute mDevPtr, mMode der Klasse Fernbedienung werden für das folgende Device zugeordnet
		mMode = Heizung;
		break;
	case CFernbedienung::Heizung:
		mDevPtr = mDev1Ptr;				//die Attribute mDevPtr, mMode der Klasse Fernbedienung werden für das folgende Device zugeordnet
		mMode = Kaffeemaschine;
		break;
	case CFernbedienung::Unbekannt:
		cout << "error, Mode auf Kaffe gesetzt" << endl;		//falls der Mode der Fernbedienung unbekannt ist wird dieser Automatisch auf das Device1 gesetzt
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
CKaffemaschine::CKaffemaschine(string deviceName, int i)
{
	mInternerZustand = i;										//interner Zustand wird der Wert i zugewiesen									
	mDeviceName = deviceName;									//Das Device erhält den übergebenen Namen
}

void CKaffemaschine::mPlus() { cout << mDeviceName<<": Mehr Kaffeepulver" << endl;	mInternerZustand++; }			//bei Plus wird vom Zustand eins dazu addiert
void CKaffemaschine::mMinus() { cout << mDeviceName << ": Weniger Kaffeepulver" << endl; mInternerZustand--;}		//bei Minus wird vom Zustand eins abgezochen
void CKaffemaschine::mZustandsausgabe()
{
	cout << mDeviceName << " - Kaffemenge seht auf " << mInternerZustand << endl;									//Ausgabe mit Device Name und Zustand
}

//###########################

CRadio::CRadio(string deviceName, int i)						//Kommentare vgl. Implementierung der Kaffemaschine!
{
	mInternerZustand = i;
	mDeviceName = deviceName;
}

void CRadio::mPlus() { cout << mDeviceName << ": Lauter" << endl;	 mInternerZustand++; }
void CRadio::mMinus() { cout << mDeviceName << ": Leiser" << endl;	 mInternerZustand--; }
void CRadio::mZustandsausgabe()
{
	cout << mDeviceName << " - Lautstaerke seht auf " << mInternerZustand << endl;
}

//############################

CHeizung::CHeizung(string deviceName, int i)						//Kommentare vgl. Implementierung der Kaffemaschine!
{
	mInternerZustand = i;
	mDeviceName = deviceName;
}

void CHeizung::mPlus() { cout << mDeviceName << ": Heisser" << endl;	 mInternerZustand++; }
void CHeizung::mMinus() { cout << mDeviceName << ": Kaelter" << endl;	 mInternerZustand--; }
void CHeizung::mZustandsausgabe()
{
	cout << mDeviceName<<" - Temperatur seht auf " << mInternerZustand << endl;
}

//##########################