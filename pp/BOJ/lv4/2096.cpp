#include <bits/stdc++.h>
using namespace std;

int max_dp[3];
int min_dp[3];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int idx;
	int a, b, c;

	cin >> N;
	cin >> a >> b >> c;

	max_dp[0] = a;
	max_dp[1] = b;
	max_dp[2] = c;
	min_dp[0] = a;
	min_dp[1] = b;
	min_dp[2] = c;
	while (--N)
	{
		cin >> a >> b >> c;
		int temp = max_dp[0];
		int temp2 = max_dp[2];
		max_dp[0] = max(max_dp[0], max_dp[1]) + a;
		max_dp[2] = max(max_dp[1], max_dp[2]) + c;
		max_dp[1] = max(max(temp, max_dp[1]), temp2) + b;
		temp = min_dp[0];
		temp2 = min_dp[2];
		min_dp[0] = min(min_dp[0], min_dp[1]) + a;
		min_dp[2] = min(min_dp[1], min_dp[2]) + c;
		min_dp[1] = min(min(temp, min_dp[1]), temp2) + b;
	}
	cout << max(max(max_dp[0], max_dp[1]), max_dp[2]) << ' ';
	cout << min(min(min_dp[0], min_dp[1]), min_dp[2]);
}
