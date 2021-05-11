#include"CElement.h"
#include"CStackDyn.h"

CStackDyn::CStackDyn()
{
	mPtrHead = NULL;
}

CStackDyn::~CStackDyn()
{

}

bool CStackDyn::push(const string& data);
bool CStackDyn::pop(string& data);
void CStackDyn::display(void);