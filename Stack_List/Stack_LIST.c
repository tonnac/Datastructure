#include "Stack_LIST.h"
#include <stdio.h>
#include <stdlib.h>

//#define PREORDER
#define POSTORDER

void init(STACKLIST * sc)
{
	sc->pHead = NULL;
	sc->pTail = NULL;
}

void push(STACKLIST * sc, DATA data)
{
	if (sc->pHead == NULL)
	{
		Stack * temp = (Stack*)malloc(sizeof(Stack));
		temp->dValue = data;
		temp->pNext = NULL;
		sc->pHead = temp;
		sc->pTail = sc->pHead;
		return;
	}
#ifdef PREORDER
	sc->pTail->pNext = (Stack*)malloc(sizeof(Stack));
	sc->pTail = sc->pTail->pNext;
#endif
#ifdef POSTORDER
	Stack * newHead = (Stack*)malloc(sizeof(Stack));
	newHead->dValue = data;
	newHead->pNext = sc->pHead;
	sc->pHead = newHead;
#endif
}

void pop(STACKLIST * sc)
{
	if (empty(sc))
	{
		printf("Stack Underflow\n");
		exit(-1);
	}
	Stack * temp = sc->pHead;
	sc->pHead = sc->pHead->pNext;
	free(temp);
}

int empty(STACKLIST * sc)
{
	if (sc->pHead == NULL)
		return TRUE;
	return FALSE;
}

void Show(STACKLIST * sc)
{
	Stack * temp = sc->pHead;
	while (temp != NULL)
	{
		printf("%d ", temp->dValue);
		temp = temp->pNext;
	}

	printf("\n\n");
}

DATA peek(STACKLIST * sc)
{
	return sc->pHead->dValue;
}