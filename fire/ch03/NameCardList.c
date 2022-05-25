#include <stdio.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList3.h"

int main(void)
{
	List list;
	NameCard * pcard;
	ListInit(&list);

	pcard = MakeNameCard("지준혁", "010-1111-2222");
	LInsert(&list, pcard);
	pcard = MakeNameCard("준토", "010-2222-5555");
	LInsert(&list, pcard);
	pcard = MakeNameCard("junto", "010-3333-7777");
	LInsert(&list, pcard);

	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "지준혁")) 
			ShowNameCardInfo(pcard);
		else 
		{
			while(LNext(&list, &pcard)) 
			{
				if(!NameCompare(pcard, "지준혁")) 
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "준토")) 
		{
			ChangePhoneNum(pcard, "010-8367-9999");
			ShowNameCardInfo(pcard);
		}
		else 
		{
			while(LNext(&list, &pcard)) 
			{
				if(!NameCompare(pcard, "준토")) 
				{
					ChangePhoneNum(pcard, "010-8367-9999");
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	if(LFirst(&list, &pcard))
	{
		if(!NameCompare(pcard, "junto")) 
		{
			ShowNameCardInfo(pcard);
			pcard = LRemove(&list);
			free(pcard);
		}
		else 
		{
			while(LNext(&list, &pcard)) 
			{
				if(!NameCompare(pcard, "junto")) 
				{
					ShowNameCardInfo(pcard);
					pcard = LRemove(&list);
					free(pcard);					
					break;
				}
			}
		}
	}
	printf("현재 데이터의 수: %d \n", LCount(&list));
	if(LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);
		while(LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}
	return 0;
}
