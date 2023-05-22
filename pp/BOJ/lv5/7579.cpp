#include <iostream>
# define MAX 100
using namespace std;

int N, M;
int i_use_memory[MAX];
int i_off_cost[MAX];
int i_dp[MAX * MAX];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
		cin >> i_use_memory[idx];
	int i_sum = 0;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> i_off_cost[idx];
		i_sum += i_off_cost[idx];
	}
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = i_sum; jdx >= i_off_cost[idx]; --jdx)
		{
			i_dp[jdx] = max(i_dp[jdx], i_dp[jdx - i_off_cost[idx]] + i_use_memory[idx]);
		}
	}
	int i_index = -1;
	while (++i_index < i_sum && i_dp[i_index] < M)
		;
	cout << i_index;
	return (0);
}
