#include "QList.h"
#include <stdio.h>
#include <stdlib.h>

void QInit(Qlist * qp)
{
	qp->pFront = NULL;
	qp->pRear = NULL;
}
void QPush(Qlist * qp, DATA data)
{
	QL * NewNode = (QL*)malloc(sizeof(QL));
	NewNode->data = data;
	NewNode->pNext = NULL;
	if (qp->pFront == NULL)
	{
		qp->pFront = NewNode;
		qp->pRear = NewNode;
		qp->pFront->pNext = qp->pRear;
	}
	qp->pRear->pNext = NewNode;
	qp->pRear = qp->pRear->pNext;
}
DATA QPop(Qlist * qp)
{
	if (QEmpty(qp))
	{
		printf("UF\n");
		return;
	}
	QL * DelNode = qp->pFront;
	DATA Deldata = DelNode->data;
	qp->pFront = qp->pFront->pNext;
	free(DelNode);
	return Deldata;
}
int QEmpty(Qlist * qp)
{
	if (qp->pFront == NULL)
		return TRUE;
	return FALSE;
}