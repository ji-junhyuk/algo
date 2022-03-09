#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
# define MAX 1000
# define MAX_COST 1000
using namespace std;

int N;
int i_color[MAX][3];
int i_dp[MAX][3];
int i_ans = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int idx = 0; idx < N; ++idx)
		for (int jdx = 0; jdx < 3; ++jdx)
			cin >> i_color[idx][jdx];
	for (int RGB = 0; RGB < 3; RGB++)
	{
		for (int idx = 0; idx < 3; ++idx)
		{
			if (idx == RGB) 
				i_dp[0][idx] = i_color[0][idx];
			else 
				i_dp[0][idx] = MAX_COST;
		}
		for (int idx = 1; idx < N; ++idx)
		{
			i_dp[idx][0] = i_color[idx][0] + min(i_dp[idx - 1][1], i_dp[idx - 1][2]);
			i_dp[idx][1] = i_color[idx][1] + min(i_dp[idx - 1][0], i_dp[idx - 1][2]);
			i_dp[idx][2] = i_color[idx][2] + min(i_dp[idx - 1][0], i_dp[idx - 1][1]);
		}
		for (int idx = 0; idx < 3; ++idx)
		{
			if (idx == RGB) 
				continue;
			else 
				i_ans = min(i_ans, i_dp[N - 1][idx]);
		}
	}
	cout << i_ans;
}
//https://velog.io/@ohjinseo/%EB%B0%B1%EC%A4%80-17404%EB%B2%88-RGB%EA%B1%B0%EB%A6%AC2-C 재귀풀이 방식도 참고하자.
