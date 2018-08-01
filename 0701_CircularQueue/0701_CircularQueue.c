#include "0701_CircularQueue.h"
#include <stdio.h>

void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
}
int QIsEmpty(Queue * pq)
{
	if (pq->rear == pq->front)
		return FALSE;
	return TRUE;
}

void QPrint(Queue * pq)
{
	int temp = NextPosIdx(pq->front);
	while (temp != pq->rear)
	{
		printf("%d ", pq->queArr[temp]);
		temp = NextPosIdx(temp);
	}
	printf("%d ", pq->queArr[temp]);
}

int NextPosIdx(int pos)
{
	if (pos == QUE_LEN - 1)
		return 0;

	return pos + 1;
}

void Enqueue(Queue * pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		puts("Queue MEMORY ERROR!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}
Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		puts("Queue MEMORY ERROR!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}
Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		puts("Queue MEMORY ERROR!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}