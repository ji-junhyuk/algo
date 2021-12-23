# 큐
- 선입선출 자료구조(FIFO)
### 큐 자료구조의 ADT
```c
void QueueInit(Queue *pq)
- 큐의 초기화를 진행한다.
- 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.

int QIsEmpty(Queue *pq)
- 큐가 빈 경우 1, 그렇지 않은 경우 0반환한다.

void Enqueue(Queue *pq, Data data)
- 큐에 데이터를 저장한다. 매개 변수 data에 전달된 값을 저장한다.

Data Dequeue(Queue *pq)
- 저장순서가 가장 앞선 데이터를 삭제한다.
- 삭제된 데이터는 반환한다.
- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

Data QPeek(Queue *pq)
- 저장순서가 가장 앞선 데이터를 반환하되 삭제하지 않는다.
- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
```

### 배열 기반 원형 큐 구현
"enque 연산 시, R이 가리키는 위치를 한 칸 이동시킨 다음에, R이 가리키는 위치에 데이터를 저장한다."
"dequeue 연산 시, R이 가리키는 위치를 한 칸 이동시킨 다음에, F가 가리키는 위치에 저장된 데이터를 반환 및 소멸한다.
- 원형 큐가 텅 빈 상태: F와 R이 동일한 위치를 가리킨다.
- 원형 큐가 꽉 찬 상태(len - 1): R이 가리키는 위치의 앞을 F가 가리킨다.
```c
typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[QUE_LEN];
} CQueue;

void QueueInit(Queue *pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue *pq)
{
	if (pq->front == pq->rear)
		return 1;
	else
		return 0;
}

int NextPosIdx(int pos) //큐의 다음 위치에 해당하는 인덱스 값 반환
{
	if (pos == QUE_LEN - 1)
		return 0;
	else 
		return pos + 1;
}

void Enqueue(Queue *pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front) // 큐가 꽉찼다면
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Deque(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	return pq->queArr[NextPosIdx(pq->front)];
}
```

### 큐의 연결리스트 기반 구현
```c
typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _lQueue
{
	Node *front;
	Node *rear;
} LQueue;

void QueueInit(Queue *pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

// 연길리스트 기반의 큐가 비었다면, F에 NULL이 저장된다.
int QisEmpty(Queue *pq)
{
	if (pq->front == NULL)
		return 1;
	else
		return 0;
}

void Enqueue(Queue *pq, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;
	if (QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Deque(Queue *pq)
{
	Node *delNode;
	Data retData;

	if (QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}
	Delnode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}
```
### 덱 자료구조의 ADT
"덱은 앞으로도 뒤로도 넣을 수 있고, 앞으로도 뒤로도 뺄 수 있는 자료구조!"
```c
void DequeInit(Deque *pdeq)
- 덱의 초기화를 진행한다.
- 덱 생성 후 제일 먼저 호출되어야 하는 함수이다.

int DQIsEmpty(Deque *pdeq)
- 덱이 빈 경우 1을, 그렇지 않은 경우 0을 반환한다.

void DQAddFirst(Deque *pdeq, Data data)
- 덱의 머리에 데이터를 저장한다. data로 전달된 값을 저장한다.

void DQAddLast(Deque *pdeq, Data data)
- 덱의 꼬리에 데이터를 저장한다. data로 전달된 값을 저장한다.

Data DQRemoveFirst(Deque *pdeq)
- 덱의 머리에 위치한 데이터를 반환 및 소멸한다.

Data DQRemoveLast(Deque *pdeq)
- 덱의 꼬리에 위치한 데이터를 반환 및 소멸한다.

Data DQgetFirst(Deque *pdeq)
- 덱의 머리에 위치한 데이터를 소멸하지 않고 반환한다.

Data DQGetLast(Deque *pdeq)
- 덱의 꼬리에 위치한 데이터를 소멸하지 않고 반환한다.
```

### 덱 자료구조 구현
```c
typedef struct _node
{
	Data data;
	struct _node *next;
	sturct _node *prev;
} Node;

typedef struct _dlDeque
{
	Node *head;
	Node *tail;
} DLDeque;

void DequeInit(Deque *pdeq)
{
	pdeq->head = NULL;
	pdeq->tail = NULL;
}

int DQIsEmpty(Deque *pdeq)
{
	if (pdeq->head == NULL)
		return 1;
	else
		return 0;
}

void DQAddFirst(Deque *pdeq, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;

	newNode->next = pdeq->head;

	if (DQIsEmpty(pdeq))
		pdeq->tail = newNode;
	else
		pdeq->head->prev = newNode;
	
	newNode->prev = NULL;
	pdeq->head = newNode;
}

void DQAddLast(Deque *pdeq, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->data = data;
	newNode->prev = pdeq->tail;

	if (DQIsEmpty(pdeq))
		pdeq->head = newNode;
	else
		pdeq->tail->next = newNode;
	newNode->next = NULL;
	pdeq->tail = newNode;
}

Data DQRemoveFirst(Deque *pdeq)
{
	Node *rnode = pdeq->head;
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	Data rdata = pdeq->head->data;
	pdeq->head = pdeq->head->next;
	free(rnode);
	if (pdeq->head == NULL)
		pdeq->tail = NULL;
	else
		pdeq->head->prev = NULL;
	return rdata;
}

Data DQRemoveLast(Deque *pdeq)
{
	Node *rnode = pdeq->tail;
	if (DQIsEmpty(pdeq))
	{
		printf("Deque Memory Error!");
		exit(-1);
	}
	Data rdata = pdeq->head->data;
	pdeq->tail = pdeq->tail->prev;
	free(rnode);
	if (pdeq->tail == NULL)
		pdeq->head = NULL;
	else
		pdeq->tail->next = NULL;
	return rdata;
}

Data DQGetFirst(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		if (DQIsEmpty(pdeq))
		{
			printf("Deque Memory Error!");
			exit(-1);
		}
		return pdeq->head->data;
	}
}

Data DQGetLast(Deque *pdeq)
{
	if (DQIsEmpty(pdeq))
	{
		if (DQIsEmpty(pdeq))
		{
			printf("Deque Memory Error!");
			exit(-1);
		}
		return pdeq->tail->data;
	}
}
```



void DQAddFirst(Deque *pdeq, Data data)
void DQAddLast(Deque *pdeq, Data data)
Data DQRemoveFirst(Deque *pdeq)
Data DQRemoveLast(Deque *pdeq)
Data DQgetFirst(Deque *pdeq)
Data DQGetLast(Deque *pdeq)

