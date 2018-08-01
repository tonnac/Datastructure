#include "NameCard.h"
#include <stdio.h>
#include <stdlib.h>

NameCard * MakeNameCard(char * name, char * phone)
{
	NameCard * pcard = (NameCard*)malloc(sizeof(NameCard));
	strcpy_s(pcard->name,NAME_LEN ,name);
	strcpy_s(pcard->phone,PHONE_LEN ,phone);
	return pcard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	printf("이름:%s\n전화번호:%s\n", pcard->name, pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
	if (!_stricmp(pcard->name, name))
		return 0;
	else
		return 1;
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
	strcpy_s(pcard->phone, PHONE_LEN ,phone);
}
