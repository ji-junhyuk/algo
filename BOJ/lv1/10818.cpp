#include <bits/stdc++.h>
using namespace std;

int arr[1000000];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int idx;
	int min;
	int max;
	
	idx = -1;
	cin >> N;
	while (++idx < N)
		cin >> arr[idx];
	idx = -1;
	min = arr[0];
	max = arr[0];
	while (++idx < N)
	{
		if (arr[idx] > max)
			max = arr[idx];
		if (arr[idx] < min)
			min = arr[idx];
	}
	cout << min << ' ' << max;
}
