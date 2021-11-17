#include <bits/stdc++.h>
using namespace std;

int arr[4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int min;
	int idx;

	idx = -1;
	while (++idx < 4)
		cin >> arr[idx];
	arr[2] -= arr[0];
	arr[3] -= arr[1];
	min = arr[0];
	idx = -1;
	while (++idx < 4)
	{
		if (min > arr[idx])
			min = arr[idx];
	}
	cout << min;
}
