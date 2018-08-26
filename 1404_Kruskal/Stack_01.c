#include "Stack_01.h"
#include <stdio.h>

void init(STACK * sc)
{
	sc->m_iTop = -1;
}
void push(STACK * sc, DATA data)
{
	if (sc->m_iTop >= MAX_TOP - 1)
	{
		printf("Stack Overflow\n");
		exit(-1);
	}
	sc->stackarr[++(sc->m_iTop)] = data;
}
DATA pop(STACK * sc)
{
	DATA rc = sc->stackarr[sc->m_iTop];
	if (empty(sc))
	{
		printf("Stack Underflow\n");
		exit(-1);
	}
	sc->m_iTop--;
	return rc;
}
int empty(STACK * sc)
{
	if (sc->m_iTop == -1)
		return TRUE;
	return FALSE;
}
void Show(STACK * sc)
{
	for (int i = 0; i < sc->m_iTop + 1; i++)
	{
		printf("%d ", sc->stackarr[i]);
	}
	printf("\n\n");
}
DATA peek(STACK * sc)
{
	return sc->stackarr[sc->m_iTop];
}