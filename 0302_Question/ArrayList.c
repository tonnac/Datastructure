#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}
void LInsert(List * plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("더 이상 저장이 불가능합니다.");
		return;
	}
	plist->arr[plist->numOfData++] = data;
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->numOfData == 0)
		return FALSE;
	plist->curPosition = 0;
	*pdata = plist->arr[plist->curPosition++];
	return TRUE;
}
int LNext(List * plist, LData * pdata)
{
	if (plist->curPosition >= plist->numOfData)
		return FALSE;
	*pdata = plist->arr[plist->curPosition++];
	return TRUE;
}

LData LRemove(List * plist)
{
	int delnum = plist->curPosition-1;
	LData rdata = plist->arr[delnum];
	for (int i = delnum; i < plist->numOfData - 1; i++)
		plist->arr[i] = plist->arr[i + 1];
	plist->curPosition--;
	plist->numOfData--;
	return rdata;
}
int LCount(List * plist)
{
	return plist->numOfData;
}