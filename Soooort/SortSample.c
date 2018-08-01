#include "Soooort.h"
#include <time.h>

int main()
{
	int arr[MAX_LEN];
	int Length = sizeof(arr) / sizeof(int);

	Settingarr(arr, Length);
	SelecDsSort(arr, Length);

	SortTimer(arr, Length, BubbleAsSort);
	SortTimer(arr, Length, SelecDsSort);
	SortTimer(arr, Length, InsertionAsSort);
	SortTimer1(arr, 0, Length - 1, MergeDsSort);
	SortTimer(arr, Length, ShellAsSort);
	SortTimer1(arr, 0, Length - 1, MergeDsSort);
	SortTimer(arr, Length, HeapAsSort);
	SortTimer1(arr, 0, Length - 1, MergeDsSort);
	SortTimer1(arr, 5, Length, RadixSort);

	//BubbleAsSort(arr, Length);
	//PrintData(arr, Length);
	//puts("");
	//SelecDsSort(arr, Length);
	//PrintData(arr, Length);
	//puts("");
	//InsertionAsSort(arr, Length);
	//PrintData(arr, Length);
	//puts("");


	//MergeDsSort(arr, 0, Length - 1);
	//PrintData(arr, Length);
	//puts("");
	//ShellAsSort(arr,Length);
	//PrintData(arr, Length);
	//puts("");
	//QuickDsSort(arr, 0, Length - 1);
	//PrintData(arr, Length);
	//puts("");
	//HeapAsSort(arr, Length);
	//PrintData(arr, Length);

	return 0;
}