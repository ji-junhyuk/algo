#include <bits/stdc++.h>
using namespace std;

int ans[1001][3];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int cost[3];

	cin >> N;
	for (int idx = 1; idx <= N; idx++)
	{
		cin >> cost[0] >> cost[1] >> cost[2];
		ans[idx][0] = min(ans[idx - 1][1], ans[idx - 1][2]) + cost[0];
		ans[idx][1] = min(ans[idx - 1][0], ans[idx - 1][2]) + cost[1];
		ans[idx][2] = min(ans[idx - 1][0], ans[idx - 1][1]) + cost[2];
	}
	cout << min(min(ans[N][0], ans[N][1]), ans[N][2]);
}
