#include"CElement.h"
#include<iostream>
using namespace std;

CElement myListe;

int main()
{
	string myText;
	do
	{
		cout<<"Bitte geben Sie die Zeichenkette ein, die Sie einlesen wollen. (xxx bedeutet Abbruch) ";
		cin >> myText;
		if (myText!="xxx")
		{
			myListe.einfuegen(myText);
		}
	} while (myText!="xxx");

	cout << endl << "Folgende Liste wurde eingegeben: " << endl;
	myListe.ausgabe();

	return 0;
}