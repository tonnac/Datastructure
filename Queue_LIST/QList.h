#pragma once
#ifndef __QUEUE__LIST_H
#define __QUEUE__LIST_H

#define TRUE		1
#define FALSE		0

typedef int DATA;

typedef struct __QUEUE_LIST
{
	DATA data;
	struct __QUEUE_LIST * pNext;
}QL;

struct Q_List
{
	struct __QUEUE_LIST * pFront;
	struct __QUEUE_LIST * pRear;
};

typedef struct Q_List Qlist;

void QInit(Qlist * qp);
void QPush(Qlist * qp, DATA data);
DATA QPop(Qlist * qp);
int QEmpty(Qlist * qp);



#endif