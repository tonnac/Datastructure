#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE		1
#define FALSE		0

int Minidx(int arr[], int len, int start);
int Swap(int * a, int * b, int bool);
void PrintData(int arr[], int len);
void SetData(int arr[], int len);

void SelectionSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int idx = Minidx(arr, len, i);
		Swap(&arr[i], &arr[idx], 1);
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
int Swap(int * a, int * b, int bool)
{
	if (bool)
	{
		int temp = *a;
		*a = *b;
		*b = temp;
		return TRUE;
	}
	return FALSE;
}
int Minidx(int arr[], int len, int start)
{
	int Value = start;
	for (int j = start+1; j < len; j++)
	{
		if (arr[Value] > arr[j])
		{
			Value = j;
		}
	}
	return Value;
}
int main()
{
	clock_t stime, etime;
	srand((unsigned int)time(NULL));
	int arr[10];
	int length = sizeof(arr) / sizeof(int);
	SetData(arr, length);
	//PrintData(arr, length);
	stime = clock();
	SelectionSort(arr, length);
	etime = clock() - stime;
	printf("Elapsed time: %f\n\n", etime / (double)CLK_TCK);
	//PrintData(arr, length);

	return 0;
}