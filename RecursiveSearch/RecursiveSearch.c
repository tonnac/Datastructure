#include <stdio.h>


int Search(int * arr, int start ,int end, int src)
{
	if (arr[start] > src || arr[end] < src) { return -1; }
	int s = ((double)(src - arr[start]) / (arr[end] - arr[start]) * (end - start)) + start;
	if (arr[s] == src)
		return s;
	else if (arr[s] > src)
		return Search(arr, start, s-1, src);
	else
		return Search(arr, s+1, end, src);	
}

int main()
{
	int arr[20];
	int k = 1;
	for (int i = 0; i < 20; i++,k+=15)
	{
		arr[i] = i + k;
	}

	int idx = Search(arr, 0, 19, 176);
	if (idx == -1)
		printf("X\n");
	else
		printf("%d\n", idx);

	return 0;
}