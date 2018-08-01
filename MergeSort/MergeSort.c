#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void MergeTwoArea(int arr[], int left, int mid, int right);
void MergeSort(int arr[], int left, int right);

void SetData(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		arr[i] = rand() % 100;
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
void MergeSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int lidx = left;
	int ridx = mid+1;
	int pidx = left;
	int * ptr = (int*)malloc(sizeof(int)*(right + 1));

	while (lidx <= mid && ridx <= right)
	{
		if (arr[lidx] > arr[ridx])
			ptr[pidx++] = arr[ridx++];
		else
			ptr[pidx++] = arr[lidx++];
	}

	if (lidx > mid)
	{
		for (;ridx <= right; pidx++, ridx++)
			ptr[pidx] = arr[ridx];
	}
	else
	{
		for (;lidx <= mid; lidx++, pidx++)
			ptr[pidx] = arr[lidx];
	}

	for (int i = left; i <= right; i++)
	{
		arr[i] = ptr[i];
	}

	free(ptr);
}





int main()
{
	srand((unsigned int)time(NULL));
	clock_t stime, etime;
	int arr[250000];
	int length = sizeof(arr) / sizeof(int);
	SetData(arr, length);
	//PrintData(arr, length);
	stime = clock();
	MergeSort(arr, 0, length-1);
	etime = clock() - stime;
	printf("Elapsed time: %.2f\n\n\n", etime / (double)CLK_TCK);
	//PrintData(arr, length);



	return 0;
}