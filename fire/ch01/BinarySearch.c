#include <stdio.h>

int BSearch(int arr[], int size, int number)
{
	int left;
	int right;
	int center;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		center = (left + right) / 2;
		if (arr[center] == number)
			return center;
		else if (arr[center] > number)
			right = center - 1;
		else
			left = center + 1;
//		else
//		{
//			if (arr[center] > number)
//				right = center - 1;
//			else
//				left = center + 1;
//		}
	}
	return -1;
}

int main(void)
{
	int arr[] = {1, 3, 5, 7, 9};
	int idx;

	idx = BSearch(arr, sizeof(arr) / sizeof(int), 7);
	if (idx == -1)
		printf("fail\n");
	else
		printf("idx is %d\n", idx);
	idx = BSearch(arr, sizeof(arr) / sizeof(int), 6);
	if (idx == -1)
		printf("fail\n");
	else
		printf("idx is %d\n", idx);
	return (0);
}
