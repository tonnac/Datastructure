#include "Stack_LIST.h"
#include <stdio.h>

int main()
{
	STACKLIST st;
	init(&st);


	if (empty(&st))	{printf("empty Stack\n");}

	push(&st, 3);push(&st, 4);
	push(&st, 6);push(&st, 7);
	push(&st, 8);push(&st, 9);
	push(&st, 10);
//	push(&sc, 11);
	DATA p = peek(&st);

	Show(&st);

	
	while (st.pHead != NULL)
	{
		pop(&st);
	}




	if (empty(&st)) { printf("empty Stack\n"); }

	return 0;
}