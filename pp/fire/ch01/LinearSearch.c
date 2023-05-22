#include <stdio.h>

int LSearch(int arr[], int len, int target)
{
	int idx;

	idx = -1;
	while (++idx < len)
		if (arr[idx] == target)
			return idx;
	return -1;
}

int main(void)
{
	int arr[] = {3, 5, 2, 4, 9};

	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 5);
	if (idx == -1)
		printf("fail\n");
	else
		printf("index is %d\n", idx);
	idx = LSearch(arr, sizeof(arr) / sizeof(int), 1);
	if (idx == -1)
		printf("fail\n");
	else
		printf("index is %d\n", idx);
	return (0);
}
