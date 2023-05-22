#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList2.h"
#include "Point.h"

int who_is_precede(Point *ppos1, Point *ppos2)
{
	if (ppos1->xpos < ppos2->xpos)
		return 0;
	else if (ppos1->xpos == ppos2->xpos)
	{
		if (ppos1->ypos < ppos2->ypos)
			return 0;
		else
			return 1;
	}
	else
		return 1;
}


int main(void)
{
	List list;
	Point comp;
	Point * ppoint;
	ListInit(&list);

	SetSortRule(&list, who_is_precede);     // 정렬기준을 등록!

	ppoint = (Point*)malloc(sizeof(Point));
	SetPointPos(ppoint, 3, 2);
	LInsert(&list, ppoint);

	ppoint = (Point*)malloc(sizeof(Point));
	SetPointPos(ppoint, 3, 1);
	LInsert(&list, ppoint);

	ppoint = (Point*)malloc(sizeof(Point));
	SetPointPos(ppoint, 2, 2);
	LInsert(&list, ppoint);

	ppoint = (Point*)malloc(sizeof(Point));
	SetPointPos(ppoint, 2, 1);
	LInsert(&list, ppoint);

	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppoint))
	{
		ShowPointPos(ppoint);
		
		while (LNext(&list, &ppoint))
			ShowPointPos(ppoint);
	}
	printf("\n");

	// xpos가 2인 모든 데이터 삭제  ////////
	comp.xpos = 2;
	comp.ypos = 0;

	if (LFirst(&list, &ppoint))
	{
		if (PointComp(ppoint, &comp) == 1)
		{
			ppoint = LRemove(&list);
			free(ppoint);
		}
		
		while (LNext(&list, &ppoint))
		{
			if (PointComp(ppoint, &comp) == 1)
			{
				ppoint = LRemove(&list);
				free(ppoint);
			}
		}
	}

	// 삭제 후 저장된 데이터 출력 ////////
	printf("현재 데이터의 수: %d \n", LCount(&list));

	if (LFirst(&list, &ppoint))
	{
		ShowPointPos(ppoint);
		
		while (LNext(&list, &ppoint))
			ShowPointPos(ppoint);
	}
	printf("\n");

	return 0;
}
