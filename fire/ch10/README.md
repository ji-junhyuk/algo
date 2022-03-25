### BubbleSort
```c
void BubbleSort(int arr[], int n)
{
	int temp;

	for (int idx = 0; idx < n - 1; idx++)
	{
		for (int jdx = 0; jdx < (n - idx) - 1; jdx++)
		{
			if (arr[jdx] > arr[jdx + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
```

### SelectionSort
```c
void SelectionSort(int arr[], int n)
{
	for (int idx = 0; idx < n - 1; idx++)
	{
		int minValue = idx;
		for (int jdx = idx + 1; jdx < n; jdx++)
		{
			if (arr[j] < arr[minValue]) // 최소값을 찾은 뒤 minValue에 저장한다.
				minValue = j;
		}
		temp = arr[i];
		arr[i] = arr[minValue];
		arr[minValue] = temp;
	}
}
```

### InsertionSort
```c
void InsertSort(int arr[], int n)
{
	for (int idx = 1; idx < n; idx++)
	{
		int insData = arr[idx];
		for (int jdx = idx - 1; jdx >= 0; jdx--)
		{
			if (arr[jdx] > insData)
				arr[jdx + 1] = jdx];
			else
				break;
		}
		arr[jdx + 1] = insData;
	}
}
```

### HeapSort(nlogn)
```c
int PriComp(int n1, int n2)
{
	return n2 - n1; // 오름차순
	// return n1 - n2;
}

void HeapSort(int arr[], int n, PriorityComp pc)
{
	Heap heap;
	int i;
	HeapInit(&heap, pc);

	for (int idx = 0; idx < n; idx++)
		HInsert(&heap, arr[idx]);
}
```

### MergeSort
```c
void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	int *sortArr = (int *)malloc(sizeof(int) * (right + 1));
	int sIdx = left;
	
	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx] = arr[fIdx++];
		else
			sortArr[sIdx] = arr[rIdx++];
		sIdx++;
	}
	if (fIdx > mid)
	{
		for (int idx = rIdx; idx <= right; idx++, sIdx++)
			sortArr[sIdx] = arr[idx];
	}
	else
	{
		for (int idx = fIdx; idx <= mid; idx++, sIdx++)
			sortArr[sIdx] = arr[idx];
	}
	for (int idx = left; idx <= right; idx++)
		arr[idx] = sortArr[idx];
	free(sortArr);
}

void MegreSort(int arr[], int left, int right)
{
	int mid;
	
	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);
		MergeTwoArea(arr, left, mid, right);
	}
}
```

### QuickSort
- 부등호 2개만 바꿔서 내림차순으로 할 수 있다.
- 좀 더 나은 성능을 위해 pivot 선택 방식을 개선할 수 있다.
```c
void ft_swap(int *a, int *b)
{
        int temp;

        temp = *a;
        *a = *b;
        *b = temp;
}

void quick_sort(int arr[], int start, int end)
{
        int pivot = start;
        int left = start + 1;
        int right = end;
        if (start >= end)
                return ;
        while (left <= right)
        {
                while (left <= end && arr[left] <= arr[pivot])
                        left++;
                while (right > start && arr[right] >= arr[pivot])
                        right++;
                if (left > right)
                        ft_swap(&arr[pivot], &arr[right]);
                else
                        ft_swap(&arr[left], &arr[right]);
        }
        quick_sort(arr, start, right - 1);
        quick_sort(arr, right + 1, end);
}
```

### RadixSort(기수 정렬)
- 일반적으로 길이가 같은 데이터 대상으로만 정렬이 가능하다.
- 데이터를 구성하는 기본 요소만큼 메모리가 필요하다. (영단어를 정렬하려면, 얼마나 많은 기수가 필요할까?)
- LSD(Least Significant Digit) 방식과 MST(Most Significant Digit) 방식이 있다. 
- LSD는 첫번째 자릿수부터 정렬이 진행되고, MST는 가장 큰 자릿수부터 정렬이 진행된다. 따라서, LSD는 처음부터 끝까지 자릿수 비교를 해야 값의 대소를 판단할 수 있는 반면 MSD는 중간지점 전에도 대소 판단이 가능하다.
- 하지만 MSD는 모든 데이터에 일괄적인 연산이 불가능하고, 추가적인 연산과 별도의 메모리가 필요하다. 구현의 용이성을 위해 LSD로 구현한다. 
```c
void RadixSort(int arr[], int num, int maxLen)
{
	Queue buckets[BUCKET_LEN];

	int divfac = 1;
	int radix;

	for (int bi = 0; bi < BUCKET_LEN; bi++)
		QueueInit(&buckets[bi]);
	for (int pos = 0; pos < maxLen; pos++)
	{
		for (int di = 0; di < num; di++)
		{
			radix = (arr[di] / divfac) % 10;
			Enqueue(&buckets[radix], arr[di]);
		}
		for (int bi = 0; bi < BUCKET_LEN; bi++)
		{
			while (!QIsEmpty(&buckets[bi]))
				arr[di++] = Dequeue[&buckets[bi]);
		}
		divfac *= 10;
	}
}
```
