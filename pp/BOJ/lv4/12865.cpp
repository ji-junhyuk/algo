#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[101][100001];
int weight[101];
int value[101];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int idx = 1; idx <= N; idx++)
		cin >> weight[idx] >> value[idx];
	for (int idx = 1; idx <= N; idx++)
	{
		for (int jdx = 1; jdx <= K; jdx++)
		{
			if (jdx >= weight[idx])
				dp[idx][jdx] = max(dp[idx - 1][jdx], dp[idx - 1][jdx - weight[idx]] + value[idx]);
			else
				dp[idx][jdx] = dp[idx - 1][jdx];
		}
	}
	cout << dp[N][K];
}
