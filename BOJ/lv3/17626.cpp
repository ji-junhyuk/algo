#include <bits/stdc++.h>
using namespace std;

int dp[50001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	dp[0] = 0;
	dp[1] = 1;
	cin >> n;	
	for (int idx = 2; idx <= n; idx++)
	{
		int min_sum = 50001;
		for (int jdx = 1; jdx * jdx <= idx; jdx++)
		{
			min_sum = min(min_sum, dp[idx - jdx * jdx] + 1); // 제곱수는 제곱수의 합이다.
		}
		dp[idx] = min_sum;
	}
	cout << dp[n];
}
