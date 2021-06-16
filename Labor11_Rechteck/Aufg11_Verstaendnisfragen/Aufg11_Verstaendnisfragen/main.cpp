#include"CA.h"
#include"CB.h"
#include<iostream>
using namespace std;



int   main()
{
	CA* myCAPtr = new   CA();		//my CAPtr zu myCAPtr
	CB* myCBPtr = new   CB();
	//myCAPtr->dummy_Method();
	myCAPtr = myCBPtr;
	//myCBPtr->dummy_Method();
	myCAPtr->dummy_Method();		//dummy Method zu dummy_Method
	return 0;
}
