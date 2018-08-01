#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Median(int arr[], int idx1, int idx2, int idx3);

void swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int Partition(int arr[], int left, int right)
{
	int idx = Median(arr, left, (left + right) / 2, right);
	swap(arr, left, idx);
	int pivot = arr[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		while (pivot >= arr[low] && low <= right)
			low++;

		while (pivot <= arr[high] && high >= (left + 1))
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
int Median(int arr[], int idx1, int idx2, int idx3)
{
	int p1 = (arr[idx1] - arr[idx2]) * (arr[idx1] - arr[idx3]);
	int p2 = (arr[idx2] - arr[idx1]) * (arr[idx2] - arr[idx3]);
	int p3 = (arr[idx3] - arr[idx1]) * (arr[idx3] - arr[idx2]);
	if (p1 <= 0)
		return idx1;
	else if (p2 <= 0)
		return idx2;
	else
		return idx3;
}

int main()
{
	srand((unsigned int)time(NULL));
//	clock_t stime, etime;
	int arr[15];
	int length = sizeof(arr) / sizeof(int);
	for (int i = 0; i < 15; i++)
	{
		arr[i] = 15 - i;
	}

	PrintData(arr, length);
	QuickSort(arr, 0, length - 1);
	PrintData(arr, length);
}