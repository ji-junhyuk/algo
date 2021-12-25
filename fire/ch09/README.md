### 힙 구현
- 힙은 완전 이진 트리이다.
- 힙의 구현은 배열을 기반으로 하며 인덱스가 0인 요소는 비워둔다.
- 따라서 힙에 저장된 노드의 개수와 마지막 노드의 고유번호는 일치한다.
- 노드의 고유번호가 노드가 저장되는 배열의 인덱스 값이 된다.
- 우선순위를 나타내는 정수 값이 작을수록 높은 우선순위를 나타낸다고 가정한다.

```c
typedef struct _healElem
{
	Priority pr;
	HData data;
} HeapElem;

typedef struct _heap
{
	int numOfData;
	HeapElem heapArr[HEAP_LEN];
} Heap;

// 개선된 힙 구조체
typedef struct _heap
{
	PriorityComp *comp; // typedef int PriorityComp(HData 1, HData 2);
	int numOfData;
	HData heapArr[HEAP_LEN];
}

void HeapInit(Heap *ph)
{
	ph->numOfData = 0;
	ph->comp = pc; // ++우선순위 비교에 사용되는 함수 등록
}

int HIsEmpty(Heap *ph)
{
	if (ph->numOfData == 0)
		return 1;
	else
		return 0;
}

int GetParentIDX(int idx)
{
	return idx / 2;
}

int GetLChildIDX(int idx)
{
	return idx * 2;
}

int GetRChildIdx(int idx)
{
	return GetLChildIDX(idx) + 1;
}

int GetHiPriChildIDX(Heap *ph, int idx) // 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스값 반환
{
	// 자식 노드가 존재하지 않는다면,
	if (GetLChildIDX(idx) > ph->numOfData)
		return 0;
	// 자식 노드가 왼쪽 자식 노드 하나만 존재한다면,
	else if (GetLChildIDX(idx) == ph->numOfData)
		return GetLChildIDX(idx);
	// 자식 노드가 둘 다 존재한다면,
	else
	{
		// 오른쪽 자식 노드의 우선순위가 높다면,
//		if (ph->heapArr[GetLChildIDX(idx)].pr 
//				> ph->heapArr[GetRChildIDX(idx)].pr)
		if (ph->comp(ph->heapArr[GetLChildIDX(idx)], 
					ph->heapArr[GetRChildIDX(idx)]) < 0)
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}

void HInsert(Heap *ph, HData data, Priority pr)
{
	int idx = ph->numOfData + 1; // 새 노드가 저장될 인덱스 값을 idx에 저장
	HeapElem nelem = {pr, data}; // 새 노드의 생성 및 초기화

	// 새 노드가 저장될 위치가 루트노드의 위치가 아니라면 while문 반복
	while (idx != 1)
	{
//		if (pr < (ph->heapArr[GetParentIDX(idx)].pr)) // 새 노드의 우선순위 높다면
		if (ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			// 부모 노드를 한 레벨 내림, 실제로 내림
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			// 새 노드를 한 레벨 올림, 실제로는 올리지 않고 인덱스 값만 갱신
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	ph->heapArr[idx] = nelem;
	ph->numOfData += 1;
}

HData HDelete(Heap *ph)
{
	HData retData = (ph->heapArr[1]).data;
	HeapElem lastElem = ph->heapArr[ph->numOfData];

	int parentIdx = 1;
	int childIdx;

	// 루트 노드의 우선순위가 높은 자식 노드를 시작으로 반복문 시작
	while (childIdx = GetHiPriChildIDX(ph, parentIDX))
	{
//		if (lastElem.pr <= pr->heapArr[childIdx].pr)
		if (ph->comp(lastElem, ph->heapArr[childIdx]) >= 0)
			break; // 마지막 노드의 우선순위가 높으면 break;
		
		//마지막 노드보다 우선순위 높으니, 비교대상 노드의 위칠를 한 레벨 올림. (실제로 올림)
		ph->heapArr[parentIdx] = ph->heapArr[childIdx]; 

		//마지막 노드가 저장될 위치정보를 한 레벨 내림. (실제로 내리진 않음)
		parentIdx = childIdx; 
	} // 반복문을 탈출하면 parentIdx에는 마지막 노드의 위치 정보가 저장됨.

	ph->heapArr[parentIdx] = lastElem; // 마지막 노드 최종 저장
	ph->numOfData -= 1;
	return retData;
}
```

### 우선순위 큐 자료구조의 ADT
```c
void PQueueInit(PQueue *ppq, PriorityComp pc);
- 우선순위 큐의 초기화를 진행한다.
- 우선순위 큐 생성 후 제일 먼저 호출되어야 하는 함수이다.

int PQIsEmpty(PQueue *ppq);
- 우선순위 큐가 빈 경우 1을, 그렇지 않은 경우 0을 반환한다.

void PEnqueue(PQueue *ppq, PQData data);
- 우선순위 큐에 데이터를 저장한다. 매개변수 data로 전달된 값을 저장한다.

PQData PDequeue(PQueue *ppq);
- 우선순위가 가장 높은 데이터를 삭제한다.
- 삭제된 데이터는 반환한다.
- 본 함수의 호출을 위해서는 데이터가 하나 이상 존재함이 보장되어야 한다.

구현
void PQueueInit(PQueue *ppq, PriorityComp pc) {
	HeapInit(ppq, pc);
}

int PQIsEmpty(PQueue *ppq) {
	return HIsEmpty(ppq);
}

void PEnqueue(PQueue *ppq, PQData data) {
	HInsert(ppq, data);
}

PQData PDequeue(PQueue *ppq) {
	return HDelete(ppq);
}
```
