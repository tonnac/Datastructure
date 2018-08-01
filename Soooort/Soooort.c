#include "Soooort.h"
#include "0702_ListBaseQueue.h"
#include <time.h>

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
void SetData(int arr[], int len)
{
//	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
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
	puts("");
}
void Settingarr(int arr[], int len)
{
	SetData(arr, len);
//	PrintData(arr, len);
}
void SortTimer(int arr[], int len, char*(*fp)(int* arr,int len))
{
	char * ch = NULL;
	clock_t stime, etime;
	stime = clock();
	ch = fp(arr, len);
	etime = clock() - stime;
	printf("%s : %.2f\n", ch, etime / (double)CLK_TCK);
}
void SortTimer1(int arr[], int start, int end, char*(*fp)(int* arr, int start, int end))
{
	char * ch = NULL;
	clock_t stime, etime;
	stime = clock();
	ch = fp(arr, start ,end);
	etime = clock() - stime;
	printf("%s : %.2f\n", ch, etime / (double)CLK_TCK);
}

char* BubbleAsSort(int arr[], int len)
{
	char * ch = __func__;
	for (int i = 0; i < len; i++)
	{
		int bflag = FALSE;
		for (int j = 0; j < len - i - 1; j++)
		{
			bflag += Swap(&arr[j], &arr[j + 1], arr[j] > arr[j + 1]);
		}
		if (bflag = FALSE)
			break;
	}
	return ch;
}
char* SelecDsSort(int arr[], int len)
{
	char * ch = __func__;
	for (int i = 0; i < len; i++)
	{
		int idx = SearchMinIdx(arr, len, i);
		Swap(&arr[len-i-1],&arr[idx],1);
	}
	return ch;
}
int SearchMinIdx(int arr[], int len, int end)
{
	int Minidx = 0;
	for (int i = 1; i < len - end; i++)
	{
		if (arr[Minidx] > arr[i])
		{
			Minidx = i;
		}
	}
	return Minidx;
}
char* InsertionAsSort(int arr[], int len)
{
	char * ch = __func__;
	for (int i = 1; i < len; i++)
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
	return ch;
}
char* MergeDsSort(int arr[], int start, int end)
{
	char * ch = __func__;
	if (start < end)
	{
		int mid = (start + end) / 2;
		MergeDsSort(arr, start, mid);
		MergeDsSort(arr, mid + 1, end);
		MergeTwoArea(arr, start, mid ,end);
	}
	return ch;
}
void MergeTwoArea(int arr[], int start, int mid, int end)
{
	int * ptr = (int*)malloc(sizeof(int)*(end + 1));
	int pidx = start;
	int lidx = start;
	int ridx = mid + 1;

	while(lidx <= mid && ridx <= end)
	{
		if (arr[lidx] > arr[ridx])
			ptr[pidx++] = arr[lidx++];
		else
			ptr[pidx++] = arr[ridx++];
	}

	if (lidx > mid)
	{
		while(ridx<=end)
			ptr[pidx++] = arr[ridx++];
	}
	else
	{
		while (lidx <= mid)
			ptr[pidx++] = arr[lidx++];
	}

	for (int i = start; i <= end; i++)
	{
		arr[i] = ptr[i];
	}
	free(ptr);
}
char* ShellAsSort(int arr[], int len)
{
	char * ch = __func__;
	int k = 0;
	while (k < len)	{k = 3 * k + 1;}
	k = (k - 1) / 3;
	do
	{
		InsertbyShellSort(arr, len, k);
		k = (k - 1) / 3;
	} while (k != 0);
	return ch;
}
void InsertbyShellSort(int arr[], int len, int gap)
{
	for (int i = gap; i<len; i+=gap)
	{
		int element = arr[i];
		int j = i - gap;
		while (j >= 0 && element < arr[j]
		 && j+gap < len)
		{
			arr[j + gap] = arr[j];
			j -= gap;
		}
		arr[j + gap] = element;
	}
}
int Partition(int arr[], int start, int end)
{
	int Pivot = arr[start];
	int left = start + 1;
	int right = end;
	while (left <= right)
	{
		while (Pivot <= arr[left] && left <= end)
			left++;
		while (Pivot >= arr[right] && right >= start)
			right--;

		if (left <= right)
			Swap(&arr[left], &arr[right], 1);
	}
	Swap(&arr[start], &arr[right], 1);
	return right;
}
char* QuickDsSort(int arr[], int start, int end)
{
	char * ch = __func__;
	if (start <= end)
	{
		int mid = Partition(arr, start, end);
		QuickDsSort(arr, start, mid - 1);
		QuickDsSort(arr, mid+1, end);
	}
	return ch;
}
char* HeapAsSort(int arr[], int len)
{
	char * ch = __func__;
	BuildHeap(arr, len);
	RebuildHeap(arr, len);
	return ch;
}
void BuildHeap(int arr[], int len)
{
	for (int i = 1; i < len; i++)
	{
		int child = i;
		int parent;
		do
		{
			parent = (child - 1) / 2;
			if (arr[parent] < arr[child])
				Swap(&arr[parent], &arr[child], 1);
			child = parent;
		} while (parent != 0);
	}
}
void RebuildHeap(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int parent = 0;
		Swap(&arr[parent], &arr[len-i-1], 1);
		int child = (parent * 2) + 1;
		do
		{
		if (arr[child] < arr[child + 1] 
			&& child < len-i-2)
			child++;
		if (arr[parent] <= arr[child]
			&& child < len-i - 1)
			Swap(&arr[parent], &arr[child], 1);
		parent = child;
		child = (parent * 2) + 1;
		} while (child < len - i);
	}
}

char* RadixSort(int arr[], int max, int len)
{
	Queue list[10];
	for (int i = 0; i < 10; i++)
	{
		QueueInit(&list[i]);
	}

	int p = 1;
	for (int i = 0; i < max; i++)
	{
		for (int k = 0; k < len; k++)
		{
			int radix = arr[k] / p % 10;
			Enqueue(&list[radix], arr[k]);
		}
		int idx = 0;
		for (int k = 0; k < 10; k++)
		{
			while (!QIsEmpty(&list[k]))
			{
				arr[idx++] = Dequeue(&list[k]);
			}
		}
		p *= 10;
	}
	char * ch = __func__;
	return ch;
}