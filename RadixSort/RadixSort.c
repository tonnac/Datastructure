#include <stdio.h>
#include <stdlib.h>
#include "0702_ListBaseQueue.h"

void RadixSort(int arr[], int max, int len)
{
	Queue q1[10];

	for (int i = 0; i < 10; i++)
	{
		QueueInit(&q1[i]);
	}

	int p = 1;
	for (int i = 0; i < max; i++)
	{
		for (int k = 0; k < len; k++)
		{
			int radix = arr[k] / p % 10;
			Enqueue(&q1[radix], arr[k]);
		}

		int idx = 0;
		for (int k = 0; k < 10; k++)
		{
			while (!QIsEmpty(&q1[k]))
			{
				arr[idx++] = Dequeue(&q1[k]);
			}
		}
		p *= 10;
	}
}


int main()
{
	int arr[15];
	for (int i = 0; i < 15; i++)
	{
		arr[i] = rand() % 10000;
	}

	for (int i = 0; i < 15; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	puts("");

	RadixSort(arr, 4, sizeof(arr) / sizeof(int));
	for (int i = 0; i < 15; i++)
	{
		if (i != 0)
		{
			printf(" ");
		}
		printf("%d", arr[i]);
	}
	puts("");
	return 0;
}