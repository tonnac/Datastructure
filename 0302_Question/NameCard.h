#ifndef __NAME_CARD_
#define __NAME_CARD_

#include <string.h>

#define NAME_LEN			30
#define PHONE_LEN			30

typedef struct __namecard
{
	char name[NAME_LEN];
	char phone[PHONE_LEN];
}NameCard;

NameCard * MakeNameCard(char * name, char * phone);

void ShowNameCardInfo(NameCard * pcard);

int NameCompare(NameCard * pcard, char * name);

void ChangePhoneNum(NameCard * pcard, char * phone);

#endif