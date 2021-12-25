#include <bits/stdc++.h>
using namespace std;

int stair[301];
int dp[301];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int stairs;

	cin >> stairs;
	for (int idx = 0; idx < stairs; idx++)
		cin >> stair[idx];
	dp[0] = stair[0];
	dp[1] = max(stair[1], stair[0] + stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);
	for (int idx = 3; idx < stairs; idx++)
		dp[idx] = max(stair[idx] + dp[idx - 2], stair[idx] + stair[idx - 1] + dp[idx - 3]);
	cout << dp[stairs - 1];
}
