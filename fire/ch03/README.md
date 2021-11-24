## 추상
```
추상: 여러 가지 사물이나 개념에서 `공통되는 특성이나 속성` 따위를 추출하여 파악하는 작용.
```

컴퓨터 과학에서 `추상화(abstraction)`는 복잡한 자료, 모듈, 시스템 등으로부터 핵심적인 개념 또는 기능을 간추려 내는 것을 말한다.

### 추상화가 가지는 효과
- 코드의 재사용성, 가독성을 높임.
- 프로그래머가 기능 개발에 투자하는 시간보다 유지 보수, 버그 해결에 더 많은 시간을 쓴다는 것을 감안하면 추상화는 생각보다 더욱 중요하다.

## ADT(Abstrct Data Type, ADT) (밑그림)
```
추상적 자료형, 컴퓨터 과학에서 자료들과 그 자료들에 대한 연산들을 명기한 것이다. 즉, `특정 자료형과 그 자료형을 바탕으로 하는 기능들의 집합`을 ADT라고 한다. 무엇(what)이라는 것에만 중점을 두고 명세를 하고, 내부 구현은 명세에 포함시키지 않는다. 
```

ex) 전기 밥솥을 ADT라고 한다면 그 속에 들어가는 밥은 재료가 되고, 밥솥에 있는 취사, 예약 취사, 보온 버튼 등은 그 자료를 바탕으로 하는 기능들의 집합을 말하는 것이다.

### 리스트
```
- 리스트: 데이터를 순차적으로 저장, 중복된 데이터의 저장을 막지 않음. 
- 순차리스트: 배열 기반(인덱스를 통해 원소 탐색), 탐색에 유리
- 연결리스트: 동적 할당 기반(이전 노드를 통해서 원소 탐색), 추가 삭제가 유리
```

### 리스트 자료구조의 ADT
```c
- void ListInit(List *plist);
    - 초기화할 리스트의 주소 값을 인자로 전달
	- 리스트 생성 후 제일 먼저 호출
- void LInsert(List *plist, LDATA data);
- int LFirst(List *plist, Ldata *pdata);
- int LNext(List *plist, Ldata *pdata);
- Ldata LRemove(List *plist);
	- 삭제된 데이터는 반환된다. (메모리 할당 해제하기 위해서)
- int LCount(List *plist);
```

### 배열기반 연결리스트 구현

void ListInit(List *plist)
{
        (plist->numOfData) = 0;
        (plist->cursor) = -1;
}

void LInsert(List *plist, LData data)
{
        if (plist->numOfData > LIST_LEN)
        {
                puts("can't store.");
                return;
        }

        plist->arr[plist->numOfData] = data;
        (plist->numOfData)++;
}

int LFirst(List *plist, LData *pdata)
{
        if (plist->numOfData == 0)
                return FALSE;
        (plist->cursor) = 0;
        *pdata = plist->arr[0];
        return TRUE;
}

int LNext(List *plist, LData *pdata)
{
        if (plist->cursor >= (plist->numOfData) - 1)
                return FALSE;

        (plist->cursor)++;
        *pdata = plist->arr[plist->cursor];
        return TRUE;
}

LData LRemove(List *plist)
{
        int rpos = plist->cursor;
        int num = plist->numOfData;
        int i;
        LData rdata = plist->arr[rpos];

        for (i = rpos; i < num - 1; i++)
                plist->arr[i] = plist->arr[i + 1];

        (plist->numOfData)--;
        (plist->cursor)--;
        return rdata;
}

int LCount(List *plist)
{
        return plist->numOfData;
}
```
