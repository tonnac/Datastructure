#include "0702_ListBaseQueue.h"
#include <stdio.h>
#include <stdlib.h>

void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}
int QIsEmpty(Queue * pq)
{
	if (pq->front == NULL)
		return TRUE;
	return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * tt = (Node*)malloc(sizeof(Node));
	tt->next = NULL;
	tt->data = data;
	if (QIsEmpty(pq))
	{
		pq->front = tt;
		pq->rear = tt;
	}
	else
	{
		pq->rear->next = tt;
		pq->rear = pq->rear->next;
	}
}
Data Dequeue(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("QUEUE MEMORY ERROR!");
		exit(-1);
	}
	Node * temp = pq->front;
	Data delData = temp->data;
	pq->front = pq->front->next;
	free(temp);
	return delData;
}
Data QPeek(Queue * pq)
{
	if (QIsEmpty(pq))
	{
		printf("QUEUE MEMORY ERROR!");
		exit(-1);
	}

	return pq->front->data;
}

void QPrint(Queue * pq)
{
	Node * temp = pq->front;

	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}