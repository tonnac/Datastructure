#ifndef __STACK_H_
#define __STACH_H_

#define TRUE	1
#define FALSE	0


typedef int DATA;

typedef struct _STACK_
{
	DATA dValue;
	struct _STACK_ * pNext;
}Stack;

struct _STACK_LIST_
{
	struct _STACK_ * pHead;
	struct _STACK_ * pTail;
};

typedef struct _STACK_LIST_ STACKLIST;

void init(STACKLIST * sc);
void push(STACKLIST * sc, DATA data);
void pop(STACKLIST * sc);
int empty(STACKLIST * sc);
void Show(STACKLIST * sc);

DATA peek(STACKLIST * sc);

#endif

