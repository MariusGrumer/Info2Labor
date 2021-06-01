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
	CFernbedienung(CDevice* Dev1Ptr, CDevice* Dev2Ptr, CDevice* Dev3Ptr); // hier werden die //Adressen der Device-Objekte übergeben
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
	CKaffemaschine(int i); // ctor mit Startwert
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
};
class CRadio :public CDevice
{
public:
	CRadio(int i); // ctor mit Startwert
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
private:
};
class CHeizung :public CDevice
{
public:
	CHeizung(int i); // ctor mit Startwert
	virtual void mPlus();
	virtual void mMinus();
	virtual void mZustandsausgabe();
};