연결리스트 자료구조의 ADT
```c
/*
   typedef struct
   {
   		Node *head;
		Node *cur;
		Node *before;
		int numOfData;
		int (*cmp)(LData d1, LData d2);
	} LinkedList;
*/
- void ListInit(List *plist);
- void LInsert(List *plist, LData data);
- int LFirst(List *plist, LData *pdata);
- int LNext(List *plist, LData *pdata);
- LData LRemove(List *plist);
- int LCount(List *plist);
- void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
```

### 새 노드를 연결리스트의 꼬리에 추가하기
```c
if (head == NULL)
	head = newNode;
else
{
	tail->next = newNode;
	tail = newNode;
}
```

### 새 노드를 연결리스트의 머리에 추가하기
```c
if (head == NULL)
{
	head = newNode;
	tail = newNode;
}
else
{
	newNode->next = head;
	head = newNode;
}
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList2.h"
