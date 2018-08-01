#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE		1
#define FALSE		0

int Swap(int * a, int * b, int bool);
void PrintData(int arr[], int len);
void SetData(int arr[], int len);

void InsSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int element = arr[i];
		int j = i - 1;
		while (j >= 0 && element < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = element;
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

int main()
{
	clock_t stime, etime;
	srand((unsigned int)time(NULL));
	int arr[100000];
	int length = sizeof(arr) / sizeof(int);
	SetData(arr, length);
	//	PrintData(arr, length);
	stime = clock();
	InsSort(arr, length);
	etime = clock() - stime;
	printf("Elapsed time: %.2f\n\n", etime / (double)CLK_TCK);
	//	PrintData(arr, length);

	return 0;
}