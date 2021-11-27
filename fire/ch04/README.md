### 단일 연결리스트(Singly Linked List)
```
각 원소가 자신의 다음 원소의 주소를 들고 있는 연결리스트이다.
노드의 삽입할 경우 insert인자로 newNode를 받게 된다.
삽입시 이전 노드와의 연결을 위해서 이전 노드의 주소를 가리키는 변수가 필요하다.
```

### 연결리스트 자료구조의 ADT
```c가
int main(void)
{
	Node *head = NULL;
	Node *tail = NULL;
	Node *cur = NULL;

	Node *newNode = NULL;
	int readData;
```

```c
typedef struc _node
{
	int data;
	struct _node *next;
} Node;
```

```c
typedef struct
{
   	Node *head;
	Node *cur;
	Node *before;
	int numOfData;
	int (*cmp)(LData d1, LData d2);
} List;
```

```c
- void ListInit(List *plist);
- void LInsert(List *plist, LData data);
- int LFirst(List *plist, LData *pdata);
- int LNext(List *plist, LData *pdata);
- LData LRemove(List *plist);
- int LCount(List *plist);
- void SetSortRule(List *plist, int (*comp)(LData d1, LData d2));
```

### 새 노드를 연결리스트의 꼬리에 추가하기
- 저장된 순서가 유지된다.
- 포인터 변수 tail이 필요하다.
```c
if (head == NULL)
        head = newNode;
else
{
        tail->next = newNode;
}

tail = newNode;
```

### 새 노드를 연결리스트의 머리에 추가하기
- 저장된 순서를 유지하지 않는다.
- 포인터 변수 tail이 불필요하다.
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

### 연결리스트 구현
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
        Node * newNode = (Node*)malloc(sizeof(Node));
        Node * pred = plist->head;
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
        if(plist->comp == NULL)
                FInsert(plist, data);
        else
                SInsert(plist, data);
}

int LFirst(List * plist, LData * pdata)
{
        if(plist->head->next == NULL)
                return FALSE;

        plist->before = plist->head;
        plist->cur = plist->head->next;

        *pdata = plist->cur->data;
        return TRUE;
}

int LNext(List * plist, LData * pdata)
{
        if(plist->cur->next == NULL)
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
```

