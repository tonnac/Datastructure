#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void SelSort(int arr[], int len)
{
	int i, j;
	int maxIdx;
	int temp;

	for (i = 0; i < len - 1; i++)
	{
		maxIdx = i;

		for (j = i + 1; j < len; j++)
		{
			if (arr[j] < arr[maxIdx])
				maxIdx = j;
		}

		temp = arr[i];
		arr[i] = arr[maxIdx];
		arr[maxIdx] = temp;
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
int main(void)
{
	clock_t stime, etime;
	srand((unsigned int)time(NULL));
	int arr[15];
	int length = sizeof(arr) / sizeof(int);
	SetData(arr, length);
	//PrintData(arr, length);
	stime = clock();
	SelSort(arr, length);
	etime = clock() - stime;
	printf("Elapsed time: %f\n\n", etime / (double)CLK_TCK);
	//PrintData(arr, length);

	return 0;
}