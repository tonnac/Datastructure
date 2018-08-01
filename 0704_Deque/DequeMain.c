#include "Deque.h"
#include <stdio.h>

int main()
{
	Deque Pe;
	DequeInit(&Pe);

	DQAddFirst(&Pe, 3);DQAddFirst(&Pe, 4);
	DQAddFirst(&Pe, 5);DQAddFirst(&Pe, 6);
	DQAddLast(&Pe, 1);DQAddLast(&Pe, 1);
	DQAddLast(&Pe, 4);DQAddLast(&Pe, 3);
	DQAddLast(&Pe, 5);DQAddLast(&Pe, 6);

	while (!DQIsEmpty(&Pe))
		printf("%d ", DQRemoveFirst(&Pe));

	printf("\n\n\n\n");

	DQAddLast(&Pe, 6);DQAddLast(&Pe, 5);
	DQAddLast(&Pe, 4);DQAddLast(&Pe, 3);
	DQAddLast(&Pe, 2);DQAddLast(&Pe, 1);

	while (!DQIsEmpty(&Pe))
		printf("%d ", DQRemoveLast(&Pe));

	return 0;
}