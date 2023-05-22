#include <bits/stdc++.h>
using namespace std;

int sum[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;

	cin >> N >> M;
	int idx = 0;
	while (N--)
	{
		int number;
		cin >> number;
		sum[idx + 1] = sum[idx] + number;
		idx++;
	}
	for (int idx = 0; idx < M; idx++)
	{
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << '\n';
	}	
}
