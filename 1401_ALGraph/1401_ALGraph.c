#include "1401_ALGraph.h"
#include <stdlib.h>
#include <stdio.h>

int WhoIsPrecede(int d1, int d2)
{
	if (d1 < d2)
		return 0;    // d1�� ���� ������ �ռ���.
	else
		return 1;    // d2�� ���� ������ �ռ��ų� ����.
}

void GraphInit(ALGraph * pg, int nv)
{
	int i;

	pg->adjList = (List*)malloc(sizeof(List)*nv);

	pg->numV = nv;
	pg->numE = 0;

	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c�� ����� ����: ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx));
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}