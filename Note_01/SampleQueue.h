#ifndef __QUEUE_ANL_
#define __QUEUE_ANL_

#define TRUE	1
#define FALSE	0
#define MAX_LEN	9

typedef int Data;

struct __QUEUE_L
{
	Data m_DValue;
	struct __QUEUE_L * m_pNext;
};

struct _QUEUE_L
{
	struct __QUEUE_L * m_pHead;
	struct __QUEUE_L * m_pTail;
};

struct _QUEUE_A
{
	int m_iFront;
	int m_iRear;
	Data Qarr[MAX_LEN];
};

typedef struct __QUEUE_L QLIST;
typedef struct _QUEUE_L QUEUE;
typedef struct _QUEUE_A QARR;

void initial(QUEUE * p);
void push(QUEUE * p, Data src);
Data pop(QUEUE * p);
int empty(QUEUE*p);
Data get(QUEUE * p);
void Print(QUEUE * p);

void Qinitial(QARR * p);
int Qpush(QARR * p, Data src);
Data Qpop(QARR * p);
int Qempty(QARR*p);
Data Qget(QARR * p);
void QPrint(QARR * p);

#endif