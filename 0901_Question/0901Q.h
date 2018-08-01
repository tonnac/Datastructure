#pragma once

#define TRUE	1
#define FALSE	0

#define HeapLEN	50

typedef const char* HData;
typedef int PriorityComp(HData c1, HData c2);

typedef struct _HEAP_C
{
	PriorityComp * cmp;
	int numofData;
	HData p[HeapLEN];
}HEAP;

void HInit(HEAP * src, PriorityComp fp);
void HInsert(HEAP * src, HData data);
HData HDelete(HEAP * src);
int HIsEmpty(HEAP * src);
void HDeleteAll(HEAP * src, int idx);
void HPrint(HEAP * src, int idx);
int GetParent(int idx);
int GetLChild(int idx);
int GetRChild(int idx);
int GetHiPriority(HEAP * src, int idx);
int CmpFp(HData c1, HData c2);