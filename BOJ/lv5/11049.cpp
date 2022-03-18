#include <iostream>
#include <algorithm>
#include <climits>
#define MAX 501
#define INF INT_MAX
using namespace std;

int N;
int row, col;
int dp[MAX][MAX];
int board[MAX][2]; 

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 1; idx <= N; ++idx)
	{
		cin >> row >> col;
		board[idx][0] = row;
		board[idx][1] = col;
	}
	for (int idx = 1; idx < N; ++idx)
	{
		for (int jdx = 1; idx + jdx <= N; ++jdx)
		{
			dp[jdx][idx + jdx] = INF;
			for (int kdx = jdx; kdx <= idx + jdx; ++kdx)
				dp[jdx][idx + jdx] = min(dp[jdx][idx + jdx], dp[jdx][kdx] + dp[kdx + 1][idx + jdx] + board[jdx][0] * board[kdx][1] * board[idx + jdx][1]);
		}
	}
	cout << dp[1][N];
	return (0);
}
