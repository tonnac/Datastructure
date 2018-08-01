#include "0901Q.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
//	srand((unsigned int)time(NULL));
	HEAP heap;
	HInit(&heap,CmpFp);

	HIsEmpty(&heap);

	for (int i = 0; i < 20; i++)
	{
		char * ch = NULL;
		int Len = rand() % 7 + 2;
		ch = (char*)malloc(sizeof(char)*Len);
		for (int k = 0; k < Len; k++)
		{
			if (k == Len - 1)
			{
				ch[k] = 0;
				break;
			}
			ch[k] = rand() % 26 + 65;
		}
		HInsert(&heap, ch);
	}

	HPrint(&heap, 1);

	HDeleteAll(&heap, 1);
	//while (!HIsEmpty(&heap))
	//{
	//	HData pr = HDelete(&heap);
	//	printf("%s\n", pr);
	//	free(pr);
	//}

	return 0;
}