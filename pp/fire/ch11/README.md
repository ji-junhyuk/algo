### 보간 탐색(InterpolSearch)
```c
int ISearch(int ar[], int first, int last, int taget)
{
	int mid;

	if (ar[first] > target || ar[last] < target)
		return -1;
	mid = ((double)(target-ar[first]) / ar[last] - ar[first] * (last - first)) + first;
	// cf. 이진탐색 mid = (first + last ) / 2
	if (ar[mid] == target)
		return mid;
	else if (target < ar[mid])
		return ISearch(ar, first, mid - 1, target);
	else
		return ISearch(ar, mid + 1, last, target);
}
```

### 이진탐색트리
```c
BTreeNode *MakeBTreeNode(void);
- 노드를 동적으로 할당해서 그 노드의 주소 값을 반환한다.
BTData GetData(BTreeNode *bt);
- 노드에 저장된 데이터를 반환한다.
void SetData(BTreeNode *bt, BTData data);
- 인자로 전달된 데이터를 노드에 저장한다.
BTreeNode *GetLeftSubTree(BTreeNode *bt);
- 인자로 전달된 노드의 왼쪽 자식 노드의 주소 값을 반환한다.
BTreeNode *GetRightSubTree(BTreeNode *bt);
- 인자로 전달된 노드의 오른쪽 자식 노드의 주소 값을 반환한다.
void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
- 인자로 전달된 노드의 왼쪽 자식 노드를 교체한다.
void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
- 인자로 전달된 노드의 오른쪽 자식 노드를 교체한다.

void BSTMakeAndInit(BTreeNode **pRoot); // BTS의 생성 및 초기화
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode *bst); // 노드에 저장된 데이터 반환
{
	return GetData(bst);
}

void BSTInsert(BTreeNode **pRoot, BSTData data); // BST를 대상으로 데이터 저장(노드의 생성과정 포함)
{
	BTreeNode *pNode = NULL;
	BTreeNode *cNode = *pRoot;
	BTreeNode *cNode = NULL;

	while (cNode != NULL)
	{
		if (data == GetData(cNode))
			return ;
		pNode = cNode;
		if (GetData(cNode) > data)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	nNode = MakeBTreeNode();
	SetData(nNode, data);
	if (pNode != NULL)
	{
		if (data < GetData(pNode))
			MakeLeftSubTree(pNode, nNode);
		else
			MakeRightSubTree(pNode, nNode);
	}
	else
		*pRoot = nNode;
}

BTreeNode *BSTSearch(BTreeNode *bst, BSTData target); // BST를 대상으로 데이터 탐색
{
	BTreeNode *cNode = bst;
	BSTData cd;

	while (cNode != NULL)
	{
		cd = GetData(cNode);
		if (target == cd)
			return cNode;
		else if (target < cd)
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	return NULL;
}

BTreeNode *BSTRemove(BTreeNode **pRoot, BSTData target) 
{
	BTreeNode *pVRoot = MakeBTreeNode();
	BTreeNode *pNode = pVRoot;
	BTreeNode *cNode = *pRoot;
	BTreeNode *dNode;

	ChangeRightSubTree(pVRoot, *pRoot);
	while (cNode != NULL && GetData(cNode) != target) 
	{
		pNode = cNode;
		if(target < GetData(cNode))
			cNode = GetLeftSubTree(cNode);
		else
			cNode = GetRightSubTree(cNode);
	}
	if(cNode == NULL)
		return NULL;
	dNode = cNode;
	if (GetLeftSubTree(dNode) == NULL && GetRightSubTree(dNode) == NULL) 
	{
		if(GetLeftSubTree(pNode) == dNode)
			RemoveLeftSubTree(dNode);
		else
			RemoveRightSubTree(dNode);
	}
	else if (GetLeftSubTree(dNode) == NULL || GetRightSubTree(dNode) == NULL) 
	{
		BTreeNode *dcNode;

		if(GetLeftSubTree(dNode) != NULL)
			dcNode = GetLeftSubTree(dNode);
		else
			dcNode = GetRightSubTree(dNode);

		if(GetLeftSubTree(pNode) == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}
	else 
	{
		BTreeNode *mNode = GetRightSubTree(dNode);
		BTreeNode *mpNode = dNode;
		int delData;
		while (GetLeftSubTree(mNode) != NULL) 
		{
			mpNode = mNode;
			mNode = GetLeftSubTree(mNode);
		}
		delData = GetData(dNode);
		SetData(dNode, GetData(mNode));
		if(GetLeftSubTree(mpNode) == mNode)
			ChangeLeftSubTree(mpNode, GetRightSubTree(mNode));
		else
			ChangeRightSubTree(mpNode, GetRightSubTree(mNode));
		dNode = mNode;
		SetData(dNode, delData);
	}
	if(GetRightSubTree(pVRoot) != *pRoot)
		*pRoot = GetRightSubTree(pVRoot);
	free(pVRoot);
	return dNode;
}

void ShowIntData(int data) 
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode *bst) 
{
	InorderTraverse(bst, ShowIntData);
}

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode *left;
	struct _bTreeNode *right;
} BTreeNode;

BTreeNode *MakeBTreeNode(void);
{
	BTreeNode *nd = (BTreeNode *)malloc(sizeof(BTreeNode));
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTData GetData(BTreeNode *bt)
{
	return bt->data;
}

void SetData(BTreeNode *bt, BTData data);
{
	bt->data = data;
}

BTreeNode *GetLeftSubTree(BTreeNode *bt);
{
	return bt->left;
}

BTreeNode *GetRightSubTree(BTreeNode *bt);
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode *main, BTreeNode *sub);
{
	if (main->left != NULL)
		free(main->left);
	main->left = sub;
}

void MakeRightSubTree(BTreeNode *main, BTreeNode *sub);
{
	if (main->right != NULL)
		free(main->right);
	main->right = sub;
}

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return ;
	action(bt->data);
	PreorderTraverse(bt->left, action);
	PreorderTraverse(bt->right, action);
}

void InorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return ;
	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action)
{
	if (bt == NULL)
		return ;
	PostorderTraverse(bt->left, action);
	PostorderTraverse(bt->right, action);
	action(bt->data);
}

BTreeNode *GetLeftSubTree(BTreeNode *bt);
{
	BTreeNode *delNode;

	if (bt != NULL)
	{
		delNode = bt->left;
		bt->left = NULL;
	}
	return delNode;
}

BTreeNode *GetRightSubTree(BTreeNode *bt);
{
	BTreeNode *delNode;

	if (bt != NULL)
	{
		delNode = bt->right;
		bt->right = NULL;
	}
	return delNode;
}

void ChangeLeftSubTree(BTreeNode *main, BTreeNode *sub)
{
	main->left = sub;
}

void ChangeRightSubTree(BTreeNode *main, BTreeNode *sub);
{
	main->right = sub;
}




