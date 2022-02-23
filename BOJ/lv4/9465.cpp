#include <iostream>
#include <algorithm>

# define MAX 100001
using namespace std;

int T, n;
int arr[2][MAX];
int dp[2][MAX];

void make_dp(void)
{
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = arr[1][0] + arr[0][1];
	dp[1][1] = arr[0][0] + arr[1][1];

	for (int idx = 2; idx < n; ++idx)
	{
		dp[0][idx] = arr[0][idx] + max(dp[1][idx - 1], dp[1][idx - 2]);
		dp[1][idx] = arr[1][idx] + max(dp[0][idx - 1], dp[0][idx - 2]);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;

	while (T--)
	{
		cin >> n;
		for (int idx = 0; idx < n; idx++)
			cin >> arr[0][idx];
		for (int idx = 0; idx < n; idx++)
			cin >> arr[1][idx];
		make_dp();
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}
