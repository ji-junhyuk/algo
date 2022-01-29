#include <bits/stdc++.h>
using namespace std;

int Max;
int arr[501][501];
int dp[501][501];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int idx = 1; idx <= n; idx++)
		for (int jdx = 1; jdx <= idx; jdx++)
			cin >> arr[idx][jdx];
	dp[1][1] = arr[1][1];
	for (int idx = 2; idx <= n; idx++)
		for (int jdx = 1; jdx <= idx; jdx++)
			dp[idx][jdx] = max(dp[idx - 1][jdx - 1], dp[idx - 1][jdx]) + arr[idx][jdx];
	for (int idx = 1; idx <= n; idx++)
		if (Max < dp[n][idx])
			Max = dp[n][idx];
	cout << Max;
}
