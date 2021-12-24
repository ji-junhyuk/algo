### 연결리스트 기반 트리 ADT
```c
BTreeNode *MakeBTreeNode(void)
- 이진 트리 노드를 생성하여 그 주소 값을 반환한다.

BTdata GetData(BTreeNode *bt)
- 노드에 저장된 데이터를 반환한다.

void SetData(BTreeNode *bt, BRData data)
- 노드에 데이터를 저장한다. data로 전달된 값을 저장한다.

BTreeNode *GetLeftSubTree(BTreeNode *bt)
- 왼쪽 서브 트리의 주소 값을 반환한다.

BTreeNode *GetRightSubTree(BTreeNode *bt)
- 오른쪽 서브 트리의 주소 값을 반환한다.

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
- 왼쪽 서브 트리를 연결한다.

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
- 오른쪽 서브 트리를 연결한다.
```

### 연결리스트 기반 트리 구현
```c
typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BTreeNode;
//왜 이진트리를 구현한 구조체는 정의하지 않은거지?
//노드를 표현하는 구조체와 큐를 표현하는 구조체를 각각 정의.
//노드가 위치할 수 있는 곳에 노드가 존재하지 않는다면, 공집합 노드가 존재하는 것으로 간주.
//즉, bTreeNode는 노드를 표현함과 동시에 이진 트리를 표현한 결과가 된다!
(노드의 표현결과 일뿐 아니라 이진 트리의 표현결과도 된다)

BTreeNode *MakeBTreeNode(void)
{
	BTreeNode *nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTdata GetData(BTreeNode *bt)
{
	return bt->data;
}

void SetData(BTreeNode *bt, BRData data)
{
	bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt)
{
	return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub)
{
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}

/* 한 번의 free함수 호출이 전부이기 때문에, 이진트리라면 메모리 누수로 이어진다 */

void DeleteTree(BTreeNode *bt)
{
	if (bt == NULL)
		return ;
	DeleteTree(bt->left);
	DeleteTree(bt->right);

	printf("del tree data: %d \n", bt->data);
	free(bt);
}
```

### 이진트리의 순회(Traversal)
- 전위 순회(Preorder Traversal): 루트 노드를 먼저 
- 중위 순회(Inorder Traversal): 루트 노드를 중간에
- 후위 순회(Postorder Traversal): 루트 노드를 마지막에
```c
void InorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return ;
	InorderTraverse(bt->left);
	printf("%d \n", bt->data);
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return ;
	printf("%d \n", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode *bt)
{
	if (bt == NULL)
		return ;
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%d \n", bt->data);
}
```

### 수식 트리(Expression Tree)의 구현
"루트 노드에 저장된 연산자의 연산을 하되, 두 개의 자식 노드에 저장된 두 피연산자를 대상으로 연산을 한다."
```c
중위 표기법의 수식 -> 후위 표기법의 수식 -> 수식 트리
```
```c
BTreeNode *MakeExpTree(char exp[])
{
	/*
	   후위 표기법의 수식을 문자열의 형태로 입력 받고, 이를 기반으로
	   수식 트리 구성하고 그 수식트리의 주소값(루트 노드의 주소) 반환.
	   
	   cf. 후위 표기법
	   1. 연산 순서대로 왼쪽에서 오른쪽으로 연산자 나열된다.
	   2. 해당 연산자의 두 피연산자는 연산자 앞에 나열된다.
	*/
	Stack stack;
	BTreeNode *pnode;

	int expLen = strlen(exp);
	int i;
	StackInit(&stack);

	for (int i = 0; i < expLen; i++)
	{
		pnode = MakeBTreeNode();

		if (isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');
		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			setData(pnode, exp[i]);
		}
		SPush(&stack, pnode);
	}
	return SPop(&stack);
}

}

int EvaluateExpTree(BTreeNode *bt)
{
	/*
	   인자로 전달된 수식 트리의 수식을 계산하여 그 결과 반환
	*/
	int op1, op2;

	if (GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);
	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch(GetData(bt))
	{
		case '+':
			return op1 + op2;
		case '-':
			return op1 - op2;
		case '*':
			return op1 * op2;
		case '/':
			return op1 / op2;
	}
}

void ShowPrefixTypeExp(BTreeNode *bt); // 전위 표기법 수식으로 출력
void ShowInfixTypeExp(BTreeNode *bt); // 중위 표기법 수식으로 출력
void ShowPostTypeExp(BTreeNode *bt); // 후위 표기법 수식으로 출력

cf. 중위표기법에서 괄호 추가
void ShowInfixTypeExp(BTreeNode * bt)
{
	if(bt == NULL)
		return;
	
	if(bt->left != NULL || bt->right != NULL)
		printf(" ( ");
		
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	if(bt->left != NULL || bt->right != NULL)
		printf(" ) ");
} 
```

