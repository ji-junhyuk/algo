# 05-1 원형 연결 리스트(Circular Linked List)
- 마지막 노드가 첫 번째 노드를 가리켜서, 연결의 형태가 원을 이루는 연결리스트.
- 머리와 꼬리의 구분이 없다. (포인터 관점에서는 위치에 따라 구분할 수 있겠지만, 배치된 노드 순서에 대한 관점으로는 연결 순서는 같다)

```c
typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _CLL
{
	Node *tail;
	Node *cur;
	Node *before;
	int numOfData;
} Clist;
```

```c
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
	plist->tail = NULL;
	plist->cur = NULL;
	plist->before = NULL;
	plist->numOfData = 0;
}

void LInsertFront(List * plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
	}

	(plist->numOfData)++;
}

void LInsert(List * plist, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	if(plist->tail == NULL) 
	{
		plist->tail = newNode;
		newNode->next = newNode;
	}
	else 
	{
		newNode->next = plist->tail->next;
		plist->tail->next = newNode;
		plist->tail = newNode; // tail만 이동시키면 새 노드를 꼬리에 추가한 결과가 된다. LInsertFront함수와 유일한 차이점.
	}
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	if(plist->tail == NULL)
		return FALSE;

	plist->before = plist->tail;
	plist->cur = plist->tail->next;

	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	if(plist->tail == NULL)
		return FALSE;

	plist->before = plist->cur;
	plist->cur = plist->cur->next;

	*pdata = plist->cur->data;
	return TRUE;
}

Data LRemove(List * plist)
{
/*
원형 연결리스트에는 더미 노드가 없기에 삭제의 과정이 상황에 따라 다르다.
삭제할 노드가 tail을 가리키는 경우
삭제할 노드가 리스트에 혼자 남은 경우
/*
	Node * rpos = plist->cur;
	Data rdata = rpos->data;

	if(rpos == plist->tail)    // 삭제 대상을 tail이 가리킨다면
	{
		if(plist->tail == plist->tail->next)    // 그리고 마지막 남은 노드라면
			plist->tail = NULL;
		else
			plist->tail = plist->before;
	}

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
```

### 원형연결리스트의 장단점
```
1) 단점
- 기본적으로 연결리스트의 단점을 가진다.
2) 장점
- 기본적으로 연결리스트의 장점을 가진다.
- 머리와 꼬리를 가리키는 하나의 포인터 변수만 두어도 머리 또는 꼬리에 노드를 추가할 수 있다.
```

# 05-2 양방향 연결 리스트(doubly linked list)
- 노드가 양쪽 방향으로 연결된 구조의 리스트이다.
- 더미노드가 없는 양방향 연결리스트, 양 끝쪽에 더미노드가 있는 양방향 연결리스트, 원형 연결기반의 양방향 연결리스트

```c
typedef struct _node
{
	Data data;
	struct _node *next;
	struct _node *prev;
} Node;

typedef struct _DLinkedList
{
	Node *head;
	Node *cur;
	int numOfData;
} DBLinkedList;
```

```c
머리에 새 노드를 추가하는 방식으로 구현.

void ListInit(List *plist)
{
	plist->head = NULL;
	plist->numOfData = 0;
}
// 조회에 사용되는 cur은 LFirst함수가 호출됨과 동시에 초기화

void LInsert(List *plist, Data data)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = plist->head;
	if (plist->head != NULL)
		plist->head->prev = newNode;
	newNode->prev = NULL;
	plist->head = newNode;

	(plist->numOfData)++;
}

int LFirst(List *plist, Data *pdata)
{
	if (plist->head == NULL)
		return false;

	plist->cur = plist->head;
	*pdata = plist->cur->data;
	return TRUE;
}

int LNext(List *plist, Data *pdata)
{
	if (plist->cur->next == NULL)
		return FALSE;
	
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;
	return TRUE;
}

int LPrevious(List *plist, Data *pdata)
{
	if (plist->cur->prev == NULL)
		return FALSE;

	plist->cur = plist->cur->prev;
	*pdata = plist->cur->data;
	return TRUE;
}
```

# 양방향 연결 리스트 장단점(단일연결리스트 대비)
```
1)단점
- 연속적인 탐색과 접근이 이루어지는 경우 탐색 시간 절감됨.
2)장점
- 포인터를 위한 공간이 2배로 사용됨.
```
