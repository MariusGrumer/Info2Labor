//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.06.02
//
//Sinn, Zweck der Datei:
//Deklaration  der Klassen


#pragma once

#include <iostream>
using namespace std;
class CDevice // Basisklasse
{
public:
	virtual void mPlus() = 0;
	virtual void mMinus() = 0;
	virtual void mZustandsausgabe() = 0;
protected:
	int mInternerZustand;
	string mDeviceName;
};
class CFernbedienung :public CDevice
{
public:
	enum Mode {
		Kaffeemaschine, Radio, Heizung, Unbekannt
	};
	CFernbedienung(string deviceName, CDevice* Dev1Ptr, CDevice* Dev2Ptr, CDevice* Dev3Ptr); // hier werden die //Adressen der Device-Objekte übergeben
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
	void mModeChange();
private:
	CDevice* mDevPtr; // dieser Zeiger zeigt auf das jeweils per Mode-Taste selektierte Objekt.
	// Damit können dann direkt dessen Funktionen aufgehoben werden.
	CDevice* mDev1Ptr; // hier werden die Adressen der Device-Objekte aufgehoben
	CDevice* mDev2Ptr;
	CDevice* mDev3Ptr;
	Mode mMode; // hier wird der Status der Mode-Taste aufgehoben
};
class CKaffemaschine :public CDevice
{
public:
	CKaffemaschine(string deviceName, int i); // ctor mit Startwert
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
};
class CRadio :public CDevice
{
public:
	CRadio(string deviceName, int i); // ctor mit Startwert
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
private:
};
class CHeizung :public CDevice
{
public:
	CHeizung(string deviceName, int i); // ctor mit Startwert
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
};