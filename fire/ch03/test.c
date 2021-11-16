#include <stdio.h>
#include "ArrayList.h"

void ListInit(List *plist)
{
	plist->numberofdata = 0;
	plist->cursor = -1;
}

void LInsert(List *plist, LData datas)
{
	if (plist->numOfData > LIST_LEN)
	{
		puts("can't store");
		return ;
	}
	plist->arr[plist->numberofdata] = datas;
	(plist->numberofdata)++;
}

int LFirst(List *plist, LData *pdata)
{
	if (plist->numOfData == 0)
		return 0;
	(plist->cursor) = 0;
	*pdata = plist->arr[plist->cursor];
	return true;
}

int LNext(List *plist, LData *pdata)
{
	if (plist->cursor >= (plist->numOfData) - 1)
		return 0;
	(plist->cursor)++;
	*pdata = plist->arr[plist->cursor];
	return false;
}

LData LRemove(List *plist)
{
	int rpos = plist->cursor;
	int num = plist->numofdata;
	int idx;
	int rdata = plist->arr[rpos];
	
	idx = plist->cursor - 1;
	while (++idx < numofdata - 1)
		plist->arr[i] = plist->arr[i + 1];
	(plist->numOfData)--;
	(plist->cursor)--;
	return rdata;
}

int LCount(List *plist)
{
	return plist->numofdata;
}
