#ifndef __DEQUE_LNA_H_
#define __DEQUE_LNA_H_


#define TRUE	1
#define FALSE	0
#define MAX_LEN	9

typedef int Data;

typedef struct __DEQUE_L
{
	Data m_DValue;
	struct __DEQUE_L * m_pNext;
}LISTDEQUE;

struct _DEQUE_L
{
	LISTDEQUE * m_pHead;
	LISTDEQUE * m_pTail;
};

struct _DEQUE_A
{
	int m_iFront;
	int m_iRear;
	Data Quearr[MAX_LEN];
};

typedef struct _DEQUE_L DEQUE;
typedef struct _DEQUE_A ADEQUE;

void initial(DEQUE * dq);
void pushback(DEQUE * dq, Data src);
void pushfront(DEQUE * dq, Data src);
Data popback(DEQUE * dq);
Data popfront(DEQUE * dq);
int empty(DEQUE * dq);
Data getfront(DEQUE * dq);
Data getback(DEQUE * dq);
void Print(DEQUE * dq);

void Ainitial(ADEQUE * dq);
int Apushback(ADEQUE * dq, Data src);
int Apushfront(ADEQUE * dq, Data src);
Data Apopback(ADEQUE * dq);
Data Apopfront(ADEQUE * dq);
int Aempty(ADEQUE * dq);
Data Agetfront(ADEQUE * dq);
Data Agetback(ADEQUE * dq);
void APrint(ADEQUE * dq);
int PrevPos(int pos);

#endif