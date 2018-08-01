#include "SampleQueue.h"
#include <stdio.h>
#include <stdlib.h>

void initial(QUEUE * p)
{
	p->m_pHead = NULL;
	p->m_pTail = NULL;
}
void push(QUEUE * p, Data src)
{
	if (empty(p))
	{
		p->m_pHead = (QLIST*)malloc(sizeof(QLIST));
		p->m_pHead->m_DValue = src;
		p->m_pHead->m_pNext = NULL;
		p->m_pTail = p->m_pHead;
		return;
	}
	QLIST * NewQueue = (QLIST*)malloc(sizeof(QLIST));
	NewQueue->m_DValue = src;
	NewQueue->m_pNext = NULL;
	p->m_pTail->m_pNext = NewQueue;
	p->m_pTail = NewQueue;
	return;
}
Data pop(QUEUE * p)
{
	if (empty(p))
	{
		printf("QUEUE MEMORY ERROR");
		exit(-1);
	}
	QLIST * DelQueue = p->m_pHead;
	Data rn = DelQueue->m_DValue;
	p->m_pHead = p->m_pHead->m_pNext;
	free(DelQueue);
	return rn;
}
int empty(QUEUE*p)
{
	if (p->m_pHead == NULL)
		return TRUE;
	return FALSE;
}
Data get(QUEUE * p)
{
	return p->m_pHead->m_DValue;
}
void Print(QUEUE * p)
{
	QLIST * temp = p->m_pHead;
	while (temp != NULL)
	{
		printf("%d ", temp->m_DValue);
		temp = temp->m_pNext;
	}
}

void Qinitial(QARR * p)
{
	p->m_iFront = 0;
	p->m_iRear = 0;
}
int Qpush(QARR * p, Data src)
{
	if ((p->m_iRear + 1) % MAX_LEN == p->m_iFront)
	{
		printf("QArray MEMORY Error\n");
		return FALSE;
	}
	p->m_iRear = (p->m_iRear + 1) % MAX_LEN;
	p->Qarr[p->m_iRear] = src;
	return TRUE;
}
Data Qpop(QARR * p)
{
	if (Qempty(p))
	{
		printf("QArray MEMORY ERROR\n");
		exit(-1);
	}
	p->m_iFront = (p->m_iFront + 1) % MAX_LEN;
	Data DelQueue = p->Qarr[p->m_iFront];
	return DelQueue;
}
int Qempty(QARR*p)
{
	if (p->m_iFront == p->m_iRear)
		return TRUE;
	return FALSE;
}
Data Qget(QARR * p)
{
	return p->Qarr[(p->m_iFront) + 1];
}
void QPrint(QARR * p)
{
	int temp = p->m_iFront+1;
	while (temp != (p->m_iRear+1) % MAX_LEN)
	{
		printf("%d ", p->Qarr[temp]);
		temp = (temp + 1) % MAX_LEN;
	}
	puts("");
}