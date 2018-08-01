#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE		1
#define FALSE		0

void BubbleSort(int arr[], int len)
{
	int i, j;
	int temp;

	for (i = 0; i < len; i++)
	{
		int bool = FALSE;
		for (j = 0;j < len-1-i;j++)
		{
			//if (arr[j] > arr[j + 1])
			//{
			//	int temp = arr[j];
			//	arr[j] = arr[j + 1];
			//	arr[j + 1] = temp;
			//}
			bool += Swap(&arr[j], &arr[j + 1], arr[j] > arr[j + 1]);
		}
		if (bool == FALSE)
			break;
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
	BubbleSort(arr, length);
	etime = clock() - stime;
	printf("Elapsed time: %f\n\n", etime/(double)CLK_TCK);
//	PrintData(arr, length);
	
	return 0;
}