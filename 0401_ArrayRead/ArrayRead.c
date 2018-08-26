#include <stdio.h>

int main(void)
{
	int arr[10];
	int readCount = 0;
	int readData;
	int i;

	while (1)
	{
		printf("ÀÚ¿¬¼ö :");
		scanf_s("%d", &readData, sizeof(int));
		if (readData < 1)
		{
			break;
		}
		arr[readCount++] = readData;
	}

	for (i = 0; i < readCount; ++i)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}