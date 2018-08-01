#include "Stack.h"
#include "DataStructure.h"
#include "BasicFunction.cpp"


int main()
{
	DataStructure<int> * prc = new Stack<int>;
	push<int> * spush = prc->createpush();
	pop<int> * spop = prc->createpop();
	print<int> * sprint = prc->createprint();
	empty<int> * sempty = prc->createempty();
	
	(*sempty)(prc);

	for (int i = 0; i < 11; i++)
	{
		(*spush)(prc, i + 1);
	}

	(*sprint)(prc);

	while (!(*sempty)(prc))
	{
		(*spop)(prc);
	}
	
	(*sempty)(prc);

	return 0;
}