#include <stdio.h>

int RecursiveBSearch(int arr[], int left, int right, int number)
{
	int center; 

	if (left > right)
		return -1;
	center = (left + right) / 2;
	if (arr[center] == number)
		return center;
	else if (arr[center] < number)
		return RecursiveBSearch(arr, center + 1, right, number);
	else
		return RecursiveBSearch(arr, left, center - 1, number);
}

int main(void)
{
	int left;
	int right;
	int number;
	int arr[] = {1, 3, 5, 7, 9};

	left = 0;
	right = (sizeof(arr) / sizeof(int)) - 1;
	number = 6;
	printf("%d\n", RecursiveBSearch(arr, left, right, number));
	return (0);
}
