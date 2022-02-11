#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001];
int dp[1001];
int dp2[1001];
int ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int idx = 1; idx <= N; idx++)
		cin >> arr[idx];

	for (int idx = 1; idx <= N; idx++)
	{
		dp[idx] = 1;
		for (int jdx = 1; jdx <= idx; jdx++)
		{
			if (arr[jdx] < arr[idx] && dp[idx] < dp[jdx] + 1)
				dp[idx] = dp[jdx] + 1;
		}
	}
	for (int idx = N; idx >= 1; idx--)
	{
		dp2[idx] = 1;
		for (int jdx = N; jdx >= idx; jdx--)
		{
			if (arr[idx] > arr[jdx] && dp2[jdx] + 1 > dp2[idx])
				dp2[idx] = dp2[jdx] + 1;
		}
	}
	for (int idx = 0; idx <= N; idx++)
		if (ans < dp[idx] + dp2[idx] - 1)
			ans = dp[idx] + dp2[idx] - 1;
	cout << ans;
}
