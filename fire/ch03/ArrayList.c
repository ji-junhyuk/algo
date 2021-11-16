#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	plist->numOfData = 0;
	plist->cursor = -1;
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData >= LIST_LEN)
	{
		puts("삽입할 수 없음");
		return ;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData == 0)
		return 0;
	plist->cursor = 0;
	*pdata = plist->arr[plist->cursor];
	return 1;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->cursor >= plist->numOfData - 1)
		return 0;
	(plist->cursor)++;
	*pdata = plist->arr[plist->cursor];
	return 1;
}

LData LRemove(List *plist)
{
	int idx;

	idx = plist->cursor - 1;
	while (++idx < plist->numOfData - 1)
		plist->arr[idx] = plist->arr[idx + 1];
	(plist->numOfData)--;
	(plist->cursor)--;
	return plist->arr[plist->cursor];
}

int LCount(List *plist)
{
	return plist->numOfData;
}
