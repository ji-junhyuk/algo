#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;

	ListInit(&list);
	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);
	LInsert(&list, 33);
	printf("현재 데이터의 수: %d \n", LCount(&list));
	if (LFirst(&list, &data))   
	{
		printf("%d ", data);
		
		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	if(LFirst(&list, &data))
	{
		if(data == 33)
		{
			printf("*");
			LRemove(&list);
		}
		
		while(LNext(&list, &data))
		{
			if(data == 33)
				LRemove(&list);
		}
	}
	printf("현재 데이터의 수: %d \n", LCount(&list));
	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
