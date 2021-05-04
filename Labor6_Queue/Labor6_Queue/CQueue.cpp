//Informatik 2 Labor
// 
//Teilnehmer			Matr.Nr.	Kurs			Semester	VS- Version		Betriebssystem
//Philipp Huber			63326	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//Marius Grumer			63284	Maschinenbau(Mabb)	6			2019 Community	Windows 10
//
//Datum: 2021.04.28
//
//Sinn, Zweck der Datei:
//Implementierung der Methoden der Klasse CQueue
#include "CQueue.h"
CQueue::CQueue(int maxSize):mMaxSize(maxSize), mCurrentSize(0), mHeadIndex(0), mTailIndex(0)	//Ctor mit Param; Listeninialsierung	
{
	mQueueArray = new CMessage[mMaxSize];		//halbdynamische Queue, Speicher wird abhängig von der übergeben mMaxSize reserviert
}

CQueue::~CQueue()								//dtor
{
	delete[] mQueueArray;
}

bool CQueue::enqueue(const CMessage& msg)		//Methode zum anhängen
{
	if (mCurrentSize >= mMaxSize)				//Queue full?
		return false;									//falls ja

	mQueueArray[mTailIndex] = msg;				// write
	mTailIndex++;								// Index ++
	mCurrentSize++;

	if (mTailIndex >= mMaxSize)					// wrap around
<<<<<<< HEAD
		mTailIndex = 0;
=======
		mTailIndex = 0;									//wahe wieder auf Null stetzen
>>>>>>> 308d133c0b83926e0544b4838f77a1d03d275b5b

	return true;
}

bool CQueue::dequeue(CMessage& msg)
{
	if (mCurrentSize == 0)						// leer?
		return false;
	msg = mQueueArray[mHeadIndex];				// read
	mHeadIndex++;								// index
<<<<<<< HEAD
	mCurrentSize--;

	mHeadIndex = mHeadIndex % mMaxSize;			// andere Moeglichkeit für wrap around
=======
	mCurrentSize--;								//anzahl der gespeicheten Elemnte nimmt beim ablesen ab

	mHeadIndex = mHeadIndex % mMaxSize;			// andere Moeglichkeit für wrap around (schoener xD   )
>>>>>>> 308d133c0b83926e0544b4838f77a1d03d275b5b
	return true;
}

int CQueue::getNumOfMessages()					//getter methode
{
	return mCurrentSize;
}

void CQueue::display()							//display Methode			
{
	CMessage tempMsg;
	char msg[MSG_MAX_LEN];
	int displayIndex = 0;							//Index, welcher die aktuell auszugebende Stelle des Array angibt
	cout << "[";

	//==============================================================================================
	//Schoenere Losesung siehe unten
	//==============================================================================================
	/*
	for (int i = 0; i < mCurrentSize; i++)						//gibt es hier eine schönere Lösung???
	{													// Schleife mit der Länge der Anzahl der Element in der Warteschlange
		if (i + mHeadIndex >= mMaxSize)					//Bedingung für warp around
		{
			displayIndex = i + mHeadIndex - mMaxSize;	// wrap around --> displayIndex zurücksetzen, falls über  Arraygrenze
		}
		else
		{
			displayIndex = i + mHeadIndex;				// Beginne mit der Ausgabe am Anfang der Queue	
		}
		tempMsg = mQueueArray[displayIndex];			// Kopieren der auszugebenden msg in tempMsg
		tempMsg.getMsg(msg);							// extrahieren der msg aus CMessage
		cout << tempMsg.getID() << "-" << msg;			// entsprechende Ausgabe mit der zugewiesenen ID

		if (i < mCurrentSize - 1)						// Ausgabe des Komma, nicht am ende der jeweiligen Ausgabe
		{
			cout << ", ";
		}

	}
	*/
	
	displayIndex = mHeadIndex;							//Startindex der Queue

	for (int i = 0; i < mCurrentSize; i++)				// Anzahl der Elemente in der Queue 
	{
		tempMsg = mQueueArray[displayIndex];			// Kopieren der auszugebenden msg in tempMsg
		tempMsg.getMsg(msg);							// extrahieren der msg aus CMessage
		cout << tempMsg.getID() << "-" << msg;			// entsprechende Ausgabe mit der zugewiesenen ID

		if (i < mCurrentSize - 1)						// Ausgabe des Komma, nicht am ende der jeweiligen Ausgabe
		{
			cout << ", ";
		}
		
		displayIndex++;									// erhöhen Index
		displayIndex = displayIndex % mMaxSize;			// wrap around
	}

	cout << "]";
}