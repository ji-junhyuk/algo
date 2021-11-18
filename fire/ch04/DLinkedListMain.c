#include <stdio.h>
#include "DLinkedList.h"

int main(void)
{
	List list;
	int data;
	ListInit(&list);

	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	if(LFirst(&list, &data))    // 첫 번째 데이터 조회
	{
		printf("%d ", data);
		while(LNext(&list, &data)) 
			printf("%d ", data);
	}
	printf("\n\n");

	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);
		
		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	if(LFirst(&list, &data))
	{
		printf("%d ", data);
		
		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
