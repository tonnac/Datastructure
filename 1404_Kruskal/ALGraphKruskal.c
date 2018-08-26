#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ALGraphKruskal.h"
#include "Stack_01.h"

int WhoIsPrecede(LData d1, LData d2);
int PWeightComp(Edge d1, Edge d2);
int VisitVertex(ALGraph * pg, int visitV);
void RemoveEdge(ALGraph * pg, int fromV, int toV);
void RemoveWayEdge(ALGraph * pg, int fromV, int toV);
void RecoverEdge(ALGraph * pg, int fromV, int toV);
int IsConnVertex(ALGraph * pg, int v1, int v2);

void GraphInit(ALGraph * pg, int nv)
{
	int i;

	pg->numV = nv;
	pg->numE = 0;

	pg->adjList = (List*)malloc(sizeof(List)*nv);
	pg->visitInfo = (int*)malloc(sizeof(int) * pg->numV);

	memset(pg->visitInfo, 0, sizeof(int)* pg->numV);



	for (i = 0; i < nv; ++i)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
	PQueueInit(&(pg->pqueue), PWeightComp);
}
void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
	if (pg->visitInfo != NULL)
		free(pg->visitInfo);
}
void AddEdge(ALGraph * pg, int fromV, int toV, int weight)
{
	Edge edge = { fromV, toV, weight };

	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;

	PEnqueue(&(pg->pqueue), edge);
}
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; ++i)
	{
		printf("%c와 연결된 정점: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}
void DFShowGraphVertex(ALGraph * pg, int startV)
{
	STACK stack;
	int visitV = startV;
	int nextV;

	init(&stack);
	VisitVertex(pg, visitV);
	push(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;

		if (VisitVertex(pg, nextV) == TRUE)
		{
			push(&stack, visitV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (VisitVertex(pg, nextV) == TRUE)
				{
					push(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (empty(&stack) == TRUE)
				break;
			else
				visitV = pop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
}
int VisitVertex(ALGraph * pg, int visitV)
{
	if (pg->visitInfo[visitV] == 0)
	{
		pg->visitInfo[visitV] = 1;
//		printf("%c ", visitV + 65);
		return TRUE;
	}
	return FALSE;
}
int WhoIsPrecede(LData d1, LData d2)
{
	if (d1 < d2)
		return 0;
	else
		return 1;
}
int PWeightComp(Edge d1, Edge d2)
{
	return d1.weight - d2.weight;
}
void ConKruskalMST(ALGraph * pg)
{
	Edge recvEdge[20];
	Edge edge;
	int eidx = 0;
	int i;

	while (pg->numE + 1 > pg->numV)
	{
		edge = PDequeue(&(pg->pqueue));
		RemoveEdge(pg, edge.v1, edge.v2);

		if (!IsConnVertex(pg, edge.v1, edge.v2))
		{
			RecoverEdge(pg, edge.v1, edge.v2, edge.weight);
			recvEdge[eidx++] = edge;
		}
	}

	for (i = 0; i < eidx; ++i)
		PEnqueue(&(pg->pqueue), recvEdge[i]);

}
void ShowGraphEdgeWeightInfo(ALGraph * pg)
{
	PQueue copyPQ = pg->pqueue;
	Edge edge;

	while (!PQIsEmpty(&copyPQ))
	{
		edge = PDequeue(&copyPQ);
		printf("(%c - %c), w:%d \n", edge.v1 + 65, edge.v2 + 65, edge.weight);
	}
}
void RemoveEdge(ALGraph * pg, int fromV, int toV)
{
	RemoveWayEdge(pg, fromV, toV);
	RemoveWayEdge(pg, toV, fromV);
	(pg->numE)--;
}
void RemoveWayEdge(ALGraph * pg, int fromV, int toV)
{
	int edge;

	if (LFirst(&(pg->adjList[fromV]), &edge))
	{
		if (edge == toV)
		{
			LRemove(&(pg->adjList[fromV]));
			return;
		}
		while (LNext(&(pg->adjList[fromV]), &edge))
		{
			if (edge == toV)
			{
				LRemove(&(pg->adjList[fromV]));
				return;
			}
		}
	}
}
void RecoverEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	(pg->numE)++;
}
int IsConnVertex(ALGraph * pg, int v1, int v2)
{
	STACK stack;
	int visitV = v1;
	int nextV;

	init(&stack);
	VisitVertex(pg, visitV);
	push(&stack, visitV);

	while (LFirst(&(pg->adjList[visitV]), &nextV) == TRUE)
	{
		int visitFlag = FALSE;
		if (nextV == v2)
		{
			memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
			return TRUE;
		}

		if (VisitVertex(pg, nextV) == TRUE)
		{
			push(&stack, nextV);
			visitV = nextV;
			visitFlag = TRUE;
		}
		else
		{
			while (LNext(&(pg->adjList[visitV]), &nextV) == TRUE)
			{
				if (nextV == v2)
				{
					memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
					return TRUE;
				}

				if (VisitVertex(pg, nextV) == TRUE)
				{
					push(&stack, visitV);
					visitV = nextV;
					visitFlag = TRUE;
					break;
				}
			}
		}

		if (visitFlag == FALSE)
		{
			if (empty(&stack) == TRUE)
				break;
			else
				visitV = pop(&stack);
		}
	}
	memset(pg->visitInfo, 0, sizeof(int) * pg->numV);
	return FALSE;
}