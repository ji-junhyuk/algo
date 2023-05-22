#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int arr[10];
	int max;
	int count;

	count = 0;
	i = 0;
	cin >> arr[0];
	max = arr[0];
	while (++i < 9)
	{
		cin >> arr[i];
		if (arr[i] > max)
		{
			max = arr[i];
			count = i;
		}
	}
	cout << max << '\n';
	cout << count + 1;
}
