#include <iostream>
using namespace std;

//int arr2[1000];
//int func2(int arr[], int N)
//{
//	int	i;
//	int count;
//
//	count = 0;
//	i = 0;
//	while (i < N)
//	{
//		arr2[arr[i]]++;
//		if (arr[i] == 100)
//			return 1;
//		if (arr2[100 - arr[i]] >= 1 && arr2[arr[i]] >= 1)
//		{
//			if (arr[i] == 50)
//				count++;
//			if (arr[i] == 50 && count == 2)
//				return 1;
//			if (arr[i] != 50)
//				return 1;
//		}
//		i++;
//	}
//	return 0;
//}

// 답지 코드 문제점: {100}일 때 1을 반환하지 못함.
// 100이 배열의 끝에 위치했을 때 1을 반환하지 못함.
int func2(int arr[], int N)
{
	int occur[101] = {};
	int i;

	i = 0;
	while (i < N)
	{
		if (occur[100 - arr[i]] == 1)
			return 1;
		occur[arr[i]] = 1;
		i++;
	}
	return 0;
}

int main()
{
	int N;
	int arr[] = {1, 100};
	int i;
	int count;

	N = sizeof(arr) / sizeof(int);
	cout << func2(arr, N);
}
