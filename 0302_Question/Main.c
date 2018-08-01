#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
	List namecard;
	ListInit(&namecard);
	NameCard * pcard = (NameCard*)malloc(sizeof(NameCard));
	
	pcard = MakeNameCard("qqq", "111");
	LInsert(&namecard, pcard);

	pcard = MakeNameCard("www", "222");
	LInsert(&namecard, pcard);

	pcard = MakeNameCard("eee", "333");
	LInsert(&namecard, pcard);

	printf("저장된 데이터:%d \n", LCount(&namecard));

	if (LFirst(&namecard, &pcard))
	{
		if (!_stricmp(pcard->name, "eee"))
			ShowNameCardInfo(pcard);

		while (LNext(&namecard, &pcard))
		{
			if (!_stricmp(pcard->name, "eee"))
				ShowNameCardInfo(pcard);
		}
	}

	if (LFirst(&namecard, &pcard))
	{
		if (!_stricmp(pcard->name, "www"))
			ChangePhoneNum(pcard, "111-2222");

			while (LNext(&namecard, &pcard))
			{
				if (!_stricmp(pcard->name, "www"))
					ChangePhoneNum(pcard, "111-2222");
			}
	}

	if (LFirst(&namecard, &pcard))
	{
		if (!_stricmp(pcard->name, "qqq"))
		{
			LRemove(&namecard);
			free(pcard);
		}

		while (LNext(&namecard, &pcard))
		{
			if (!_stricmp(pcard->name, "qqq"))
			{
				LRemove(&namecard);
				free(pcard);
			}
		}
	}


	if (LFirst(&namecard, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&namecard, &pcard))
		{
			ShowNameCardInfo(pcard);
		}
	}


	return 0;
}