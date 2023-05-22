#include <bits/stdc++.h>
using namespace std;

int dp[1000000];
int make_one(int n)
{
	if (n == 1)
		return 0;
	if (dp[n] > 0)
		return dp[n];
	dp[n] = make_one(n - 1) + 1;
	if (n % 2 == 0)
	{
		int temp = make_one(n / 2) + 1;
		if (dp[n] > temp) 
			dp[n] = temp;
	}
	if (n % 3 == 0)
	{
		int temp = make_one(n / 3) + 1;
		if (dp[n] > temp) 
			dp[n] = temp;
	}
	return dp[n];
}

/*
 * Bottom up

int make_one(int n)
{
	dp[1] = 0;
	for (int idx = 2; idx <= n; idx++)
	{
		dp[idx] = dp[idx - 1] + 1;
		if (idx % 2 == 0 && dp[idx] > dp[idx / 2] + 1)
			dp[idx] = dp[idx / 2] + 1;
		if (idx % 3 == 0 && dp[idx] > dp[idx / 3] + 1)
			dp[idx] = dp[idx / 3] + 1;
	}
	return dp[n];
}
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	
	cin >> N;
	cout << make_one(N) << '\n';
}
