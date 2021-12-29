#include <bits/stdc++.h>
using namespace std;

int dp[11];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int n;

	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	for (int i = 4; i < 11; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	while (T--)
	{
		cin >> n;
		cout << dp[n] << '\n';
	}
}
