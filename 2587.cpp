#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int number;
	int average;
   	int median;
	int arr[5];
	int i;
	int j;
	int temp;
	int sum;
	
	i = 0;
	while (i < 5)
	{
		cin >> arr[i];
		i++;
	}
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	i = 0;
	sum = 0;
	while (i < 5)
	{
		sum += arr[i];
		i++;
	}
	cout << sum / 5 << '\n';
	cout << arr[2];
}
