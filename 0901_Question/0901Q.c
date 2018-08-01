#include "0901Q.h"
#include <string.h>
#include <stdio.h>

int CmpFp(HData c1, HData c2)
{
	if (c2 == NULL)
		return 1;
	size_t c1Len = strlen(c1);
	size_t c2Len = strlen(c2);
	int result = (int)c1Len - (int)c2Len;
	return result;
}

int GetParent(int idx)
{
	return idx / 2;
}
int GetLChild(int idx)
{
	return idx * 2;
}
int GetRChild(int idx)
{
	return (idx * 2) + 1;
}
int GetHiPriority(HEAP * src, int idx)
{
	if (GetLChild(idx) > src->numofData)
		return 0;
	else if (GetLChild(idx) == src->numofData)
		return GetLChild(idx);
	else
	{
		if (src->cmp(src->p[GetLChild(idx)], src->p[GetRChild(idx)]) < 0)
			return GetLChild(idx);
		else
			return GetRChild(idx);
	}
}

void HInit(HEAP * src, PriorityComp fp)
{
	src->numofData = 0;
	src->cmp = fp;
	for(int i=0; i<HeapLEN; i++)
	{
		src->p[i] = NULL;
	}
}
void HInsert(HEAP * src, HData data)
{
	int idx = src->numofData + 1;
	int Parent = GetParent(idx);

	while(src->cmp(data, src->p[Parent]) <= 0)
	{
		src->p[idx] = src->p[Parent];
		idx = GetParent(idx);
		Parent = GetParent(idx);
	}

	src->p[idx] = data;
	src->numofData++;
}
int HIsEmpty(HEAP * src)
{
	if (src->numofData == 0)
		return TRUE;
	return FALSE;
}
HData HDelete(HEAP * src)
{
	HData ret = src->p[1];
	HData pp = src->p[src->numofData];

	int idx = 1;
	int child;
	while (child = GetHiPriority(src, idx))
	{
		if (src->cmp(pp, src->p[child]) >= 0)
			src->p[idx] = src->p[child];
		else
			break;
		idx = child;
	}
	src->p[idx] = pp;
	src->numofData--;
	return ret;
}

void HPrint(HEAP * src, int idx)
{
	if (src->p[idx] != NULL)
	{
		printf("%s %d\n", src->p[idx],idx);
		HPrint(src, GetLChild(idx));
		HPrint(src, GetRChild(idx));
	}
}

void HDeleteAll(HEAP * src, int idx)
{
	if (src->p[idx] != NULL)
	{
		HDeleteAll(src, GetLChild(idx));
		HDeleteAll(src, GetRChild(idx));
		free(src->p[idx]);
		src->p[idx] = NULL;
	}
}