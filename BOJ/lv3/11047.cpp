#include <bits/stdc++.h>
using namespace std;

int arr[11];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	int N, K;
	int cnt;

	cin >> N >> K;
	for (int idx = 0; idx < N; idx++)
		cin >> arr[idx];
	cnt = 0;
	for (int idx = N - 1; idx >= 0; idx--)
	{
		cnt += K / arr[idx];
		K %= arr[idx];
	}
	cout << cnt << '\n';
}
