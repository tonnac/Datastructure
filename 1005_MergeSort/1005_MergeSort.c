#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int i;

	int * sortArr = (int*)malloc(sizeof(int)*(right + 1));
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];

		sIdx++;
	}

	if (fIdx > mid)
	{
		for (i = rIdx; i <= right; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}
	else
	{
		for (i = fIdx; i <= mid; i++, sIdx++)
			sortArr[sIdx] = arr[i];
	}

	for (i = left; i <= right; i++)
		arr[i] = sortArr[i];

	free(sortArr);
}
void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		
		MergeTwoArea(arr, left, mid, right);
	}
}
void SetData(int arr[], int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 100000;
	}
}
void PrintData(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	puts("\n");
}



//
//int main()
//{
//	clock_t stime, etime;
//	srand((unsigned int)time(NULL));
//	int arr[100000];
//	SetData(arr, sizeof(arr) / sizeof(int));
//	stime = clock();
//	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);
//	etime = clock() - stime;
//	//PrintData(arr, 10);
//	printf("Elapsed time: %f\n\n", etime / (double)CLK_TCK);
//
//	return 0;
//}