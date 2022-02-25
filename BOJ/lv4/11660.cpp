#include "../includes/junto.h"
# define MAX 1025

int arr[MAX][MAX];
int dp[MAX][MAX];
int N, M;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 1; idx <= N; idx++)
	{
		for (int jdx = 1; jdx <= N; jdx++)
		{
			cin >> arr[idx][jdx];
			dp[idx][jdx] = dp[idx - 1][jdx] + dp[idx][jdx - 1] - dp[idx - 1][jdx - 1] + arr[idx][jdx];
		}
	}
	int x1, x2, y1, y2;
	while (M--)
	{
		cin >> x1 >> y1;
		cin >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << '\n';
	}
}
