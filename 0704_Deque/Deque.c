#include "Deque.h"
#include <stdio.h>
#include <stdlib.h>

void DequeInit(Deque * pdeq)
{
	pdeq->Head = NULL;
	pdeq->Tail = NULL;
}
int DQIsEmpty(Deque * pdeq)
{
	if (pdeq->Head == NULL)
		return TRUE;
	return FALSE;
}

void DQAddFirst(Deque * pdeq, Data data)
{
	Node * NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->prev = NULL;
	NewNode->next = NULL;
	if (DQIsEmpty(pdeq))
	{
		pdeq->Head = NewNode;
		pdeq->Tail = NewNode;
	}
	else
	{
		NewNode->next = pdeq->Head;
		pdeq->Head->prev = NewNode;
		pdeq->Head = NewNode;
	}
}
void DQAddLast(Deque * pdeq, Data data)
{
	Node * NewNode = (Node*)malloc(sizeof(Node));
	NewNode->data = data;
	NewNode->prev = NULL;
	NewNode->next = NULL;
	if (DQIsEmpty(pdeq))
	{
		pdeq->Head = NewNode;
		pdeq->Tail = NewNode;
	}
	else
	{
		NewNode->prev = pdeq->Tail;
		pdeq->Tail->next = NewNode;
		pdeq->Tail = NewNode;
	}
}

Data DQRemoveFirst(Deque * pdeq)
{
	Node * temp = pdeq->Head;
	Data Deldata = temp->data;
	pdeq->Head = pdeq->Head->next;
	if (pdeq->Head == NULL)
	{
		pdeq->Tail = NULL;
	}
	else
	{
		pdeq->Head->prev = NULL;
	}
	free(temp);

	return Deldata;
}
Data DQRemoveLast(Deque * pdeq)
{
	Node * temp = pdeq->Tail;
	Data Deldata = temp->data;
	pdeq->Tail = pdeq->Tail->prev;
	if (pdeq->Tail == NULL)
	{
		pdeq->Head = NULL;
	}
	else
	{
		pdeq->Tail->next = NULL;
	}
	free(temp);

	return Deldata;
}

Data DQGetFirst(Deque * pdeq)
{
	return pdeq->Head->data;
}
Data DQGetLast(Deque * pdeq)
{
	return pdeq->Tail->data;
}