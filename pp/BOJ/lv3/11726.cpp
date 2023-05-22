#include <bits/stdc++.h>
using namespace std;

//D[n] = D[n-1] + D[n-2];
int dp[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	dp[0] = 1;
	dp[1] = 1;

	for (int idx = 2; idx <= n; idx++)
		dp[idx] = (dp[idx - 1] + dp[idx - 2]) % 10007;
	cout << dp[n];
}
