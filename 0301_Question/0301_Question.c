#include "ArrayList.h"
#include <stdio.h>

int main()
{
	int data;
	List list;
	ListInit(&list);

	for (int i = 0; i < 9; i++)
	{
		LInsert(&list, i + 1);
	}
	int total = 0;
	
	if (LFirst(&list, &data))
	{
		total += data;
		while (LNext(&list, &data))
			total += data;
		printf("%d\n", total);
	}
	if (LFirst(&list, &data))
	{
		if (!(data % 2) || !(data % 3))
			LRemove(&list);
		while (LNext(&list, &data))
		{
			if (!(data % 2) || !(data % 3))
				LRemove(&list);
		}
	}

	if (LFirst(&list, &data))
	{
		printf("%d ", data);
		while (LNext(&list,&data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}