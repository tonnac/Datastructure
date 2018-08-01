#include <stdio.h>

#define TRUE	1
#define FALSE	0

#define MAX_LEN	5

typedef int DATA;

typedef struct __Queue_ARRAY_
{
	int m_iFront;
	int m_iRear;
	DATA quearr[MAX_LEN];
}QArray;

typedef QArray Queue;

void init(Queue * pq);
void push(Queue * pq, DATA data);
void pop(Queue * pq);
DATA top(Queue * pq);
void show(Queue * pq);
int empty(Queue * pq);
int Nextposidx(int pos);