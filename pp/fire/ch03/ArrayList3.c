#include <stdio.h>
#include "ArrayList3.h"

void ListInit(List *plist)
{
	(plist->numOfData) = 0;
	(plist->cursor) = -1;
}

void LInsert(List *plist, LData data)
{
	if (plist->numOfData > LIST_LEN)
	{
		puts("can't store.");
		return;
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
	int rpos = plist->cursor;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++)
		plist->arr[i] = plist->arr[i + 1];

	(plist->numOfData)--;
	(plist->cursor)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numOfData;
}
