#include <bits/stdc++.h>
using namespace std;

int arr[10];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int j;
	int k;
	int sum;
	int temp;

	i = 0;
	sum = 0;
	while (i < 9)
	{
		cin >> arr[i];
		sum += arr[i];
		i++;
	}
	i = 0;
	j = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 8)
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
	j = 0;
	while (i < 9)
	{
		j = i + 1;
		while (j < 9)
		{
			sum -= (arr[i] + arr[j]);
			if (sum == 100)
			{
				k = -1;
				while (++k < 9)
				{
					if (k == i || k == j)
						continue;
					cout << arr[k] << '\n';
				}
				break;
			}
			sum += (arr[i] + arr[j]);
			j++;
		}
		if (sum == 100)
			break;
		i++;
	}
}
