#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
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
			printf(" ");
		printf("%d", arr[i]);
	}
	puts("\n");
}
void BuildHeap(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int idx = i;
		do
		{
			int parent = (idx - 1) / 2;
			if (arr[idx] < arr[parent])
			{
				Swap(&arr[idx], &arr[parent]);
			}
			idx = parent;
		} while (idx != 0);
	}
}
void RebuildHeap(int arr[], int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		int a = 0;
		Swap(&arr[a], &arr[i]);
		while(a < i)
		{
			int iChild = a * 2 + 1;
			if (arr[iChild] > arr[iChild+1]
				&& iChild < i-1)
				iChild++;
			if (arr[a] > arr[iChild]
				&& iChild < i)
				Swap(&arr[a], &arr[iChild]);
			a = iChild;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	int arr[10];
	SetData(arr, _countof(arr));
	PrintData(arr, _countof(arr));
	BuildHeap(arr, _countof(arr));
	PrintData(arr, _countof(arr));
	RebuildHeap(arr, _countof(arr));
	PrintData(arr, _countof(arr));

	return 0;
}