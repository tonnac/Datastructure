#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;

		while (pivot <= arr[high] && high >= (left+1))
			high--;

		if (low <= high)
			swap(arr, low, high);
	}

	swap(arr, left, high);
	return high;
}
void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left, pivot - 1);
		QuickSort(arr, pivot + 1, right);
	}
}
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

int main()
{
	srand((unsigned int)time(NULL));
	clock_t stime, etime;
	int arr[200000];
	int length = sizeof(arr) / sizeof(int);
	SetData(arr, length);

//	PrintData(arr, length);
	stime = clock();
	QuickSort(arr, 0, length-1);
	etime = clock() - stime;
	printf("Elapsed time: %.2f\n\n\n", etime / (double)CLK_TCK);
//	PrintData(arr, length);
}