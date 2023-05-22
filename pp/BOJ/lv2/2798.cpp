#include <bits/stdc++.h>
using namespace std;

int arr[300];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int M;
	int min;
	int max;
	int sum;

	sum = 0;
	min = 100001;
	max = 0;
	cin >> N >> M;
	for (int idx = 0; idx < N; idx++)
		cin >> arr[idx];

	for (int idx = 0; idx < N - 2; idx++)
		for (int jdx = idx + 1; jdx < N - 1; jdx++)
			for (int kdx = jdx + 1; kdx < N; kdx++)
			{
				sum = arr[idx] + arr[jdx] + arr[kdx];
				if (M - sum < min && M - sum >= 0)
				{
					min = M - sum;
					max = sum;
				}
			}
	cout << max;
}
