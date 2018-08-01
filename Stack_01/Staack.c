#include "Stack_01.h"
#include <stdio.h>

int main()
{
	STACK sc;
	init(&sc);

	if (empty(&sc))	{printf("empty Stack\n");}

	push(&sc, 3);push(&sc, 4);
	push(&sc, 6);push(&sc, 7);
	push(&sc, 8);push(&sc, 9);
	push(&sc, 10);
//	push(&sc, 11);
	DATA p = peek(&sc);

	Show(&sc);

	pop(&sc);

	int iCnt = sc.m_iTop+1;
	for (int i = 0; i < iCnt; i++)
	{
		pop(&sc);
	}

	if (empty(&sc)) { printf("empty Stack\n"); }

	return 0;
}