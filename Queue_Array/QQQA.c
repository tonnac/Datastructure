#include "Queue_Array.h"
#include <stdio.h>

int main()
{
	Queue pq;
	init(&pq);

	empty(&pq);

	push(&pq, 8);
	push(&pq, 1);
	push(&pq, 3);
	push(&pq, 4);
	push(&pq, 6);
	puts("");

	show(&pq);
	puts("");

	top(&pq);

	pop(&pq);
	pop(&pq);
	push(&pq, 4);
	push(&pq, 6);
	pop(&pq);
	pop(&pq);
	push(&pq, 4);
	push(&pq, 6);

	return 0;
}