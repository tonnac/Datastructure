#ifndef __STACK_H_
#define __STACH_H_

#define TRUE	1
#define FALSE	0

#define MAX_TOP 7

typedef int DATA;

typedef struct _STACK_
{
	int m_iTop;
	DATA stackarr[MAX_TOP];
}AStack;

typedef AStack STACK;

void init(STACK * sc);
void push(STACK * sc, DATA data);
void pop(STACK * sc);
int empty(STACK * sc);
void Show(STACK * sc);

DATA peek(STACK * sc);

#endif

