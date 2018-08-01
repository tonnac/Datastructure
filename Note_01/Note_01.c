#include "Note_01.h"
#include <stdio.h>

void initial(STACK * p)
{
	p->m_iTop = -1;
}
int push(STACK * p, Data src)
{
	if (p->m_iTop + 1 > MAX_LEN)
	{
		printf("Stack Memory ERROR\n");
		return FALSE;
	}
	p->arr[++p->m_iTop] = src;
	return TRUE;
}
Data pop(STACK * p)
{
	if (empty(p))
	{
		printf("Stack MEMORY ERROR\n");
		exit(-1);
	}
	Data delData = p->arr[p->m_iTop--];
	return delData;
}
int empty(STACK*p)
{
	if (p->m_iTop == -1)
		return TRUE;
	return FALSE;
}
Data get(STACK * p)
{
	return p->arr[p->m_iTop];
}
void Print(STACK * p)
{
	int temp = p->m_iTop;
	while (temp!=-1)
	{
		printf("%d ", p->arr[temp]);
		temp--;
	}
	return;
}