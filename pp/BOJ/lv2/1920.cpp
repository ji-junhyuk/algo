#include <bits/stdc++.h>
using namespace std;

int arr[100000];

void binary_search(int number, int key)
{
	int left;
	int right;
	int center;

	left = 0;
	right = number - 1;
	while (left <= right)
	{
		center = (left + right) / 2;
		if (arr[center] == key)
		{
			cout << 1 << '\n';
			return ;
		}
		else if (arr[center] > key)
			right = center - 1;
		else
			left = center + 1;
	}
	cout << 0 << '\n';
	return ;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	int temp;
	
	cin >> N;
	for (int idx = 0; idx < N; idx++)
		cin >> arr[idx];
	sort(arr, arr + N);
	cin >> M;
	for (int idx = 0; idx < M; idx++)
	{
		cin >> temp;
		binary_search(N, temp);
	}
}
