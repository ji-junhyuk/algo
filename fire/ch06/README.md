# 스택(Stack)
- 데이터를 일시적으로 저장하기 위해 사용하는 자료구조.
- 데이터의 입력과 출력 순서는 후입선출(LIFO).

### 스택 자료구조의 ADT
```c
- void StackInit(Stack *pstack);
	- 스택의 초기화를 진행한다.
	- 스택 생성 후 제일 먼저 호출되어야 하는 함수이다.
- int SIsEmpty(Stack *pstack);
	- 스택이 빈 경우 TRUE(1)을, 그렇지 않은 경우 FALSE(0)을 반환한다.
- void SPush(Stack *pstack, Data data);
	- 스택에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.
- Data SPop(Stack *pstack);
	- 마지막에 저장된 요소를 삭제한다.
	- 삭제된 데이터는 반환이 된다.
	- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
- Data SPeek(Stack *pstack);
	- 마지막에 저장된 요소를 반환하되 삭제하지 않는다.
	- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.
```

### 스택의 배열 기반 구현
#### 구현 시 주목할 것 2가지
1. 인덱스 0의 배열 요소가 '스택의 바닥'으로 정의되어 있다. (배열의 길이에 상관없이 언제나 인덱스 0은 배열의 바닥이 된다)
2. 마지막에 저장된 데이터의 위치를 기억해야 한다.

```c
typedef struct _arrayStack
{
	Data stackArr[STACK_LEN];
	int topIndex;
} ArrayStack;
```

```c
void StackInit(Stack *pstack)
{
	pstack->topIndex = -1;
}

int SIsEmpty(Stack *pstack)
{
	if (pstack->topIndex == -1)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	pstack->topIndex += 1;
	pstack->stackArr[pstack->topIndex] = data;
}

Data SPop(Stack *pstack)
{
	int rIdx;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->stackArr[rIdx];
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->stackArr[pstack->topIndex];
}
```

### 스택의 연결 리스트 기반 구현
- 새로운 노드를 꼬리가 아닌 머리에 추가하는 형태로 구현한 연결리스트.

```c
typedef struct _node
{
	Data data;
	struct _node *next;
} Node;

typedef struct _listStack
{
	Node *head;
} ListStack;
```

```c
void stackInit(Stack *pstack)
{
	pstack->head = NULL;
}

void SIsEmpty(Stack *pstack)
{
	if (pstack->head == NULL)
		return TRUE;
	else
		return FALSE;
}

void SPush(Stack *pstack, Data data)
{
	Node *newNode = (Node *)malloc(sizeof(Node));

	newNode->data = data;
	newNode->next = pstack->head;
	pstack->head = newNode;
}

Data SPop(Stack *pstack)
{
	Data rdata;
	Node *rnode;

	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rdata = pstack->head->data;
	rnode = pstack->head;

	pstack->head = pstack->head->next;
	free(rnode);
	return rdata;
}

Data SPeek(Stack *pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	return pstack->head->data;
}

### 계산기 프로그램 구현
- (3 + 4) * (5 / 2) + (7 + (9 - 5)) = ?
```c
1. 소괄호를 파악하여 그 부분을 먼저 연산한다.
2. 연산자의 우선순위를 근거로 연산의 순위를 결정한다.
* 전위, 후위 표기법의 수식은 연산자의 배치순서에 따라 연산순서가 결정된다. 따라서 계산할 때 수식의 우선순위를 알 필요가 없고, 소괄호도 삽입되지 않으니 소괄호에 대한 처리도 불필요하다.

우리가 구현할 계산기는
1. 중위 표기법의 수식을 후위 표기법의 수식으로 바꾼다.
2. 후위 표기법으로 바뀐 수식을 계산하여 그 결과를 얻는다.

* 중위 표기법의 수식을 후위 표기법의 수식으로 바꿀 경우
- 피연산자는 그냥 옮긴다.
- 연산자는 쟁반으로 옮긴다.
- 연산자가 쟁반에 있다면 우선순위를 비교하여 처리방법을 결정한다.
	- 우선순위가 높은 연산자는 우선순위가 낮은 연산자 위에 올라서서 먼저 자리를 잡지 못하게 한다.
	- 사칙연산의 경우 연산자의 우선순위가 동일하면, 먼저 등장한 연산자를 먼저 진행한다.
- 마지막까지 쟁반에 남아있는 연산자들은 하나씩 꺼내서 옮긴다.
```

* 소괄호가 포함되어 있는 중위 표기법의 수식을 후위 표기법의 수식으로 바꿀 경우
- (연산자는 )연산자가 등장할 때까지 쟁반 위에 남아있어야 하기 때문에 사칙 연산자들보다 연산의 우선순위가 낮다고 간주한다.
```

### 중위 표기법을 후위 표기법으로 바꾸는 프로그램의 구현
```c
void ConvToRPNExp(char exp[]) // 후위 표기법을 수식으로 변환
{
}

int GetOpPrec(char op)
{
	switch(op)
	{
		case '*':
		case '/':
			return 5;
		case '+':
		case '-':
			return 3;
		case '(':
			return 1;
	}
	return -1;
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if (op1Prec > op2Prec)
		return 1;
	else if (op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char *convExp = (char *)malloc(expLen + 1); // 변환된 수식을 담을 공간 마련

	int i, idx = 0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char) * expLen + 1); // 할당된 배열을 0으로 초기화
	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		tok = exp[i]; //exp로 전달된 수식을 한 문자씩 tok에 저장
		if (isdigit(tok)) // tok에 저장된 문자가 숫자인지 확인
			convExp[idx++] = tok; // 숫자이면 배열 convExp에 저장
		else
		{
			switch(tok)
			{
				case '(':
					SPush(&stack, tok);
					break;
				case ')':
					while (1)
					{
						popOp = SPop(&stack); // 스택에서 연산자 꺼내어
						if (popOp == '(')
							break;
						convExp[idx++] = popOp;
					}
					break;
				case '+': case '-':
				case '*': case '/':
					while (!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0) // 스택에 저장된 연산자가 먼저 연산이 되어야 하는 경우 
						convExp[idx++] = SPop(&stack);
					SPush(&stack, tok);
					break;
			}
		}
	}
	while (!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);

