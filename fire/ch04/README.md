### 단일 연결리스트(Singly Linked List)
```
각 원소가 자신의 다음 원소의 주소를 들고 있는 연결리스트이다.
노드의 삽입할 경우 insert인자로 newNode를 받게 된다.
삽입시 이전 노드와의 연결을 위해서 이전 노드의 주소를 가리키는 변수가 필요하다.
```

### 새 노드를 연결리스트의 꼬리에 추가하기
- 저장된 순서가 유지된다.
- 포인터 변수 tail이 필요하다.
```c
if (head == NULL)
	head = newNode;
else
    tail->next = newNode;
tail = newNode;
```

### 새 노드를 연결리스트의 머리에 추가하기
- 저장된 순서를 유지하지 않는다. (입력 1 2 3 4 5 -> 5 4 3 2 1)
- 포인터 변수 tail이 불필요하다. 
```c
if (head == NULL)
        head = newNode;
else
{
        newNode->next = head;
        head = newNode;
}
```

### 단일 연결리스트(Singly Linked List) 자료구조의 ADT

```c
- void ListInit(List *plist);
	- 초기화할 리스트의 주소 값을 인자로 전달한다.
	- 리스트 생성 후 제일 먼저 호출된다.
- void FInsert(List *plist, LData data);
- void SInsert(List *plist, LData data);
- void LInsert(List *plist, LData data);
	- 리스트에 데이터를 저장한다. 매개변수 data에 전달된 값을 저장한다.
	- plist에 함수가 주어지면 SInsert를, 없다면 FInsert를 실행한다.
- int LFirst(List *plist, LData *pdata);
	- 첫 번째 데이터가 pdata가 가리키는 메모리에 저장된다.
	- 데이터의 참조를 위한 초기화가 진행된다.
	- 참조 성공 시 1, 실패 시 0을 반환한다.
- int LNext(List *plist, LData *pdata);
	- 참조된 데이터의 다음 데이터가 pdata가 가리키는 메모리에 저장된다.
	- 순차적인 참조를 위해서 반복 호출이 가능하다.
	- 참조를 새로 시작하려면 LFirst를 먼저 호출해야 한다.
	- 참조 성공 시 1, 실패 시 0을 반환한다.
- LData LRemove(List *plist);
	- LFirst 또는 LNext 함수의 마지막 반환 데이터를 삭제한다.
	- 삭제된 데이터는 반환된다.
	- 마지막 반환 데이터를 삭제하므로 연이은 반복 호출을 허용하지 않는다.
- int LCount(List *plist);
	- 리스트에 저장되어 있는 데이터의 수를 반환한다.
- void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
	- 리스트에 정렬의 기준이 되는 함수를 등록한다.
	- d1이 정렬 순서상 앞서면 0, d2가 정렬 순서상 앞서거나 같으면 1을 반환한다.
```

### 더미 노드 기반의 단일 연결리스트(Singly Linked List) 구현
```c
typedef struct _node
{
	int data;
	struct _node *next;
} Node;
```

```c
typedef struct _linkedList
{
   	Node *head; 						// 더미 노드를 가리키는 멤버
	Node *cur;							// 참조 및 삭제를 돕는 멤버
	Node *before;						// 삭제를 돕는 멤버
	int numOfData;						// 저장된 데이터의 수를 기록하는 멤버
	int (*cmp)(LData d1, LData d2);		// 정렬의 기준을 등록하기 위한 멤버
} List;
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList2.h"

void ListInit(List *plist)
{
	plist->head = (Node*)malloc(sizeof(Node));
	plist->head->next = NULL;
	plist->comp = NULL;
	plist->numOfData = 0;
}

void FInsert(List *plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head->next;
	plist->head->next = newNode;

	(plist->numOfData)++;
}

void SInsert(List * plist, LData data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *pred = plist->head;
	newNode->data = data;

	while (pred->next != NULL &&
		plist->comp(data, pred->next->data) != 0)
	{
		pred = pred->next;
	}
	newNode->next = pred->next;
	pred->next = newNode;
	(plist->numOfData)++;
}


void LInsert(List * plist, LData data)
{
	if (plist->comp == NULL)
		FInsert(plist, data);
	else
		SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
	if (plist->head->next == NULL)
		return FALSE;

	plist->before = plist->head;
	plist->cur = plist->head->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

LData LRemove(List * plist)
{
	Node * rpos = plist->cur;
	LData rdata = rpos->data;

	plist->before->next = plist->cur->next;
	plist->cur = plist->before;

	free(rpos);
	(plist->numOfData)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
	plist->comp = comp;
}

/* 
 * Point 구조체
 * - x 좌표 값 기준 오름차순
 * - x 좌표 값 같은 경우 y좌표 기준 오름차순
 */
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
```

