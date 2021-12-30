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
```c
void swap(int arr[], int idx1, int idx2);

int Partition(int arr[], int left, int right)
{
	int pivot = arr[left];
	int low = left + 1;
	int hight = right;

	while (low <= high)
	{
		if (arr[low] <= pivot && low <= right)
			low++;
		if (arr[high] >= pivot && high >= left + 1)
			high--;
		if (low <= high)
			Swap(arr, low, high);
	}
	Swap(arr, left, high);
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)
	{
		int pivot = Partition(arr, left, right);
		QuickSort(arr, left ,pivot - 1);
		QuickSort(arr, pivot + 1 , right);
	}
}
```

### RadixSort
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
