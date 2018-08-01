#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "0701_CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR		0
#define BUL_BUR		1
#define DUB_BUR		2

#define CHE_TERM	12
#define BUL_TERM	15
#define DUB_TERM	24

int main()
{
	int makeProc = 0;
	int cheOrder = 0, bulOrder = 0, dubOrder = 0;
	int sec;

	Queue que;

	QueueInit(&que);
	srand((unsigned int)time(NULL));

	for (sec = 0; sec < 3600; sec++)
	{
		if (sec % CUS_COME_TERM == 0)
		{
			switch (rand() % 3)
			{
			case CHE_BUR:
				Enqueue(&que, CHE_TERM);
				cheOrder += 1;
				break;
			case BUL_BUR:
				Enqueue(&que, BUL_TERM);
				bulOrder += 1;
				break;
			case DUB_BUR:
				Enqueue(&que, DUB_TERM);
				dubOrder += 1;
				break;
			}
		}
		if (makeProc == 0 && !QIsEmpty(&que))
			makeProc = Dequeue(&que);

		makeProc--;
	}

	printf("Simulation Report! \n");
	printf(" - Cheese burger: %d \n",cheOrder);
	printf(" - Bulgogi burger: %d \n", bulOrder);
	printf(" - Double burger: %d \n", dubOrder);
	printf(" - Waiting room size: %d \n", QUE_LEN);
	return 0;
}