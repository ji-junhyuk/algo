#include <stdio.h>
#include "ArrayList2.h"

void ListInit(List *plist)
{
	(plist->numOfData) = 0; 
	(plist->cursor) = -1; 
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData > LIST_LEN)
	{
		puts("can't store\n");
		return ;
	}
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData == 0)
		return FALSE;
	(plist->cursor) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->cursor >= (plist->numOfData) - 1)
		return FALSE;
	(plist->cursor)++;
	*pdata = plist->arr[plist->cursor];
	return TRUE;
}

LData LRemove(List *plist)
{
	int remove_index = plist->cursor;
	int idx;

	LData rdata = plist->arr[remove_index];
	idx = remove_index - 1;
	while (idx++ <= (plist->numOfData) - 1)
		plist->arr[idx] = plist->arr[idx + 1];
	(plist->numOfData)--;
	(plist->cursor)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}
