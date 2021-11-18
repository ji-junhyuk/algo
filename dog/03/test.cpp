#include <stdio.h>
//void	array_insert(int idx, int num, int arr[], int &len)
//{
//	int temp;
//
//	temp = len;
//	while (idx < len)
//	{
//		arr[len] = arr[len - 1];
//		len--;
//	}
//	arr[idx] = num;
//	len = temp + 1;
//}

void	array_insert(int idx, int num, int arr[], int &len)
{
	int jdx;

	jdx = len;
	while (jdx > idx)
	{
		arr[jdx] = arr[jdx - 1];
		jdx--;
	}
	arr[idx] = num;
	len++;
}

//void	erase(int idx, int arr[], int &len)
//{
//	while (idx <= len)
//	{
//		arr[idx] = arr[idx + 1];
//		idx++;
//	}
//	len--;
//}

void	erase(int idx, int arr[], int &len)
{
	int	jdx;
	jdx = idx;

	len--;
	while (jdx < len)
	{
		arr[jdx] = arr[jdx + 1];
		jdx++;
	}

int	main(void)
{
	int arr[10] = {10, 50, 40, 30, 70, 20};
	int len = 6;
	array_insert(3, 60, arr, len);
	erase(4, arr,len);

	int i = 0;
	while (i < 10)
	{
		printf("%d ", arr[i]);
		i++;
	}
	return (0);
}
