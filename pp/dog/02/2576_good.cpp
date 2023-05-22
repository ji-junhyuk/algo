#include <bits/stdc++.h>
using namespace std;

int arr[7];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int	i;
	int j;
	int odd_number;
	int min;
	int sum = 0;
	int first = 1;

	odd_number = 0;
	i = 0;
	j = 0;
	while (i < 7)
	{
		cin >> arr[i];
		i++;
	}
	i = 0;
	while (i < 7)
	{
		if (arr[i] % 2 != 0)
		{
			if (first)
			{
				first = 0;
				min = arr[i];
			}
			if (arr[i] < min)
				min = arr[i];
			sum += arr[i];
			odd_number = 1;
		}
		i++;
	}
	if (!odd_number)
		cout << -1;
	else
	{
		cout << sum << '\n';
		cout << min;
	}
}
