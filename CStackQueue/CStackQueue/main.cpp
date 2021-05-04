
#include <iostream>
#include "CStackQueue.h"
#define PSIZE 10
using namespace std;

int main()
{
    CMessage myMessage;
    CStackQueue myStackQueue(PSIZE);

    for (int i = 0; i < (2*PSIZE); i++)
    {
        if (i % 2==0)
        {
            myMessage.BufferType = 'Q';
            myMessage.mID = i;
        }
        else if (i % 2 == 1)
        {
            myMessage.BufferType = 'S';
            myMessage.mID = i;          
        }
        myStackQueue.add(myMessage);
    }


    while (myStackQueue.get(myMessage))
    {
        cout << " Stack oder Queue: " << myMessage.BufferType << " ID: " << myMessage.mID << endl;
    }
    

    return 0;
}
