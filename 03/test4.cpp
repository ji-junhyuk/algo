#include <iostream>
using namespace std;

int arr2[1000];

int func2(int arr[], int N)
{
	int	i;
	if (N == 1)
	{
		if (arr[0] == 100)
			cout << 1;
		else
			cout << 0;
	}
	i = 0;
	while (i < N)
	{
                if (arr2[100 - arr[i]] >= 1 && arr2[arr[i]] >= 1)
                        return 1;
		arr2[arr[i]]++;
		i++;
	}
return 0;
	// arr2[i]: 99, 48, 52
	i = 0;
	while (i < N)
	{
	0
	return 0;
}

int main()
{
	int N;
	int arr[] = {1, 52, 48};
	int i;

	i = 0;
	while (arr[i])
		i++;
	cout << func2(arr, N);
}
