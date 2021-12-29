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
