#include "Queue_Array.h"


void init(Queue * pq)
{
	pq->m_iFront = 0;
	pq->m_iRear = 0;
}
void push(Queue * pq, DATA data)
{
	if (pq->m_iFront == (pq->m_iRear+1)%MAX_LEN)
	{
		printf("Queue Overflow");
		return;
	}
//	pq->m_iRear = Nextposidx(pq->m_iRear);
	pq->m_iRear = (++pq->m_iRear) % MAX_LEN;
	pq->quearr[pq->m_iRear] = data;
}
void pop(Queue * pq)
{
	if (empty(pq))
	{
		printf("Queue Underflow");
		return;
	}
//	pq->m_iFront = Nextposidx(pq->m_iFront);
	pq->m_iFront = (++pq->m_iFront) % MAX_LEN;
	pq->quearr[pq->m_iFront] = 0;
}
DATA top(Queue * pq)
{
	return pq->quearr[pq->m_iFront+1];
}
void show(Queue * pq)
{
	for (int i = pq->m_iFront+1; i <= pq->m_iRear; i++)
	{
		printf("%d ",pq->quearr[i]);
	}
}
int empty(Queue * pq)
{
	if (pq->m_iFront == pq->m_iRear)
		return TRUE;
	return FALSE;
}
int Nextposidx(int pos)
{
	if ((pos+1) == MAX_LEN)
	{
		return 0;
	}
	return pos+1;
}