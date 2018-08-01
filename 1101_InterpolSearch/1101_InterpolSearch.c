#include <stdio.h>

int InterpolSearch(int * arr, int src, int start, int end)
{
	if (src < arr[start] || src > arr[end]) { return -1; }

	int s = (double)(src - arr[start]) / (arr[end] - arr[start]) * (end - start) + start;
	if (arr[s] == src)
		return s;
	else if (arr[s] > src)
		return InterpolSearch(arr, src, start, s-1);
	else
		return InterpolSearch(arr, src, s+1, end);
}

int main()
{
	int arr[20];
	for (int i = 0; i < 20; i++)
	{
		arr[i] = i + 3;
	}

	int idx = InterpolSearch(arr, 18, 0, 20);
	if (idx == -1)
		printf("X\n");
	else
		printf("%d\n", idx);

	return 0;
}