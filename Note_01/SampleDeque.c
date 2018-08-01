#include "SampleDeque.h"
#include <stdio.h>
#include <stdlib.h>

void initial(DEQUE * dq)
{
	dq->m_pHead = NULL;
	dq->m_pTail = NULL;
}
void pushback(DEQUE * dq, Data src)
{
	LISTDEQUE * NewDeque = (LISTDEQUE*)malloc(sizeof(LISTDEQUE));
	NewDeque->m_DValue = src;
	NewDeque->m_pNext = NULL;
	if (empty(dq))
	{
		dq->m_pHead = NewDeque;
		dq->m_pTail = NewDeque;
		return;
	}
	dq->m_pTail->m_pNext = NewDeque;	
	dq->m_pTail = NewDeque;
	return;
}
void pushfront(DEQUE * dq, Data src)
{
	LISTDEQUE * NewDeque = (LISTDEQUE*)malloc(sizeof(LISTDEQUE));
	NewDeque->m_DValue = src;
	if (empty(dq))
	{
		NewDeque->m_pNext = NULL;
		dq->m_pTail = NewDeque;
		dq->m_pHead = NewDeque;
		return;
	}
	NewDeque->m_pNext = dq->m_pHead;
	dq->m_pHead = NewDeque;
	return;
}
Data popback(DEQUE * dq)
{
	LISTDEQUE * temp = dq->m_pHead;
	Data rn = dq->m_pTail->m_DValue;
	if (temp->m_pNext)
	{
		while (temp->m_pNext != dq->m_pTail)
		{
			temp = temp->m_pNext;
		}
	}	
	if (temp != dq->m_pTail)
	{
		dq->m_pTail = temp;
		temp = temp->m_pNext;
		dq->m_pTail->m_pNext = NULL;
	}
	if (temp == dq->m_pHead)
	{
		dq->m_pHead = NULL;
	}
	free(temp);
	return rn;
}
Data popfront(DEQUE * dq)
{
	LISTDEQUE * DelQueue = dq->m_pHead;
	Data rn = DelQueue->m_DValue;
	dq->m_pHead = dq->m_pHead->m_pNext;
	free(DelQueue);
	return rn;
}
int empty(DEQUE*dq)
{
	if (dq->m_pTail == NULL || dq->m_pHead == NULL)
		return TRUE;
	return FALSE;
}
Data getfront(DEQUE * dq)
{
	return dq->m_pHead->m_DValue;
}
Data getback(DEQUE * dq)
{
	return dq->m_pTail->m_DValue;
}
void Print(DEQUE * dq)
{
	LISTDEQUE * peer = dq->m_pHead;
	while (peer != NULL)
	{
		printf("%d ", peer->m_DValue);
		peer = peer->m_pNext;
	}
}

void Ainitial(ADEQUE * dq)
{
	dq->m_iFront = 0;
	dq->m_iRear = 0;
}
int Apushback(ADEQUE * dq, Data src)
{
	if ((dq->m_iRear + 1) % MAX_LEN == dq->m_iFront)
	{
		printf("QArray MEMORY Error\n");
		return FALSE;
	}
	dq->m_iRear = (dq->m_iRear + 1) % MAX_LEN;
	dq->Quearr[dq->m_iRear] = src;
	return TRUE;
}
int Apushfront(ADEQUE * dq, Data src)
{
	if (PrevPos(dq->m_iFront) == dq->m_iRear)
	{
		printf("QArray MEMORY Error\n");
		return FALSE;
	}
	dq->m_iFront = PrevPos(dq->m_iFront);
	dq->Quearr[dq->m_iFront] = src;
	return TRUE;
}
Data Apopback(ADEQUE * dq)
{
	if (Aempty(dq))
	{
		printf("QArray MEMORY ERROR\n");
		exit(-1);
	}
	Data DelQueue = dq->Quearr[dq->m_iRear];
	dq->m_iRear = PrevPos(dq->m_iRear);
	return DelQueue;
}
Data Apopfront(ADEQUE * dq)
{
	if (Aempty(dq))
	{
		printf("QArray MEMORY ERROR\n");
		exit(-1);
	}
	dq->m_iFront = (dq->m_iFront + 1) % MAX_LEN;
	Data DelQueue = dq->Quearr[dq->m_iFront];
	return DelQueue;
}
int Aempty(ADEQUE * dq)
{
	if (dq->m_iFront == dq->m_iRear)
		return TRUE;
	return FALSE;
}
Data Agetfront(ADEQUE * dq)
{
	return dq->Quearr[(dq->m_iFront) + 1];
}
Data Agetback(ADEQUE * dq)
{
	return dq->Quearr[(dq->m_iRear)];
}
void APrint(ADEQUE * dq)
{
	int temp = dq->m_iFront + 1;
	while (temp != (dq->m_iRear + 1) % MAX_LEN)
	{
		printf("%d ", dq->Quearr[temp]);
		temp = (temp + 1) % MAX_LEN;
	}
	puts("");
}

int PrevPos(int pos)
{
	if (pos - 1 < 0)
	{
		pos = MAX_LEN-1;
		return pos;
	}
	return pos - 1;
}