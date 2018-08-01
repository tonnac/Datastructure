#ifndef __STACK_A_P
#define __STACK_A_P

#define TRUE	1
#define FALSE	0
#define MAX_LEN	9

typedef int Data;

struct __STACK_ARRAY
{
	int m_iTop;
	Data arr[MAX_LEN];
};

typedef struct __STACK_ARRAY STACK;

void initial(STACK * p);
int push(STACK * p, Data src);
Data pop(STACK * p);
int empty(STACK*p);
Data get(STACK * p);
void Print(STACK * p);

#endif