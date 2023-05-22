#include <stdio.h>

int BSearch(int arr[], int length, int number)
{
	int left;
	int right;
	int center;
	int count;

	count = 0;
	left = 0;
	right = length - 1;
	while (left <= right)
	{
		center = (left + right) / 2;
		if (arr[center] == number)
			return center;
		else
		{
			if (arr[center] < number)
				left = center + 1;
			else
				right = center - 1;
		}
		count++;
	}
	printf("count: %d\n", count);
	return -1;
}

int main(void)
{
	int idx;
	int arr1[500] = {0, };
	int arr2[5000] = {0, };
	int arr3[50000] = {0, };
	idx = BSearch(arr1, sizeof(arr1) / sizeof(int), 6);
	if (idx == -1)
		printf("not exist\n");
	else
		printf("index is %d\n", idx);
	idx = BSearch(arr2, sizeof(arr2) / sizeof(int), 6);
	if (idx == -1)
		printf("not exist\n");
	else
		printf("index is %d\n", idx);
	idx = BSearch(arr3, sizeof(arr3) / sizeof(int), 6);
	if (idx == -1)
		printf("not exist\n");
	else
		printf("index is %d\n", idx);
}
