#include <iostream>
# define MAX 2001
using namespace std;

int N, M, S, E;
int pel[MAX];
bool dp[MAX][MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 1; idx <= N; ++idx)
		cin >> pel[idx];
	for (int idx = 1; idx <= N; ++idx)
		dp[idx][idx] = true;
	for (int idx = 1; idx < N; ++idx)
	{
		if (pel[idx] == pel[idx + 1])
			dp[idx][idx + 1] = true;
	}
	for (int idx = 2; idx < N; ++idx)
	{
		for (int jdx = 1; jdx <= N - idx; ++jdx)
		{
			if (pel[jdx] == pel[idx + jdx] && dp[jdx + 1][idx + jdx - 1])
				dp[jdx][idx + jdx] = true;
		}
	}
	cin >> M;
	while (M--)
	{
		cin >> S >> E;
		cout << dp[S][E] << '\n';
	}
	return 0;
}
