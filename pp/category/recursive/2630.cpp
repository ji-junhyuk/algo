#include <iostream>
using namespace std;
#define ll long long
#define MAX_LEN 128

ll N;
ll board[MAX_LEN][MAX_LEN];
ll ans[2];

ll	check_square(ll row, ll col, ll N)
{
	for (int idx = row; idx < row + N; ++idx)
		for (int jdx = col; jdx < col + N; ++jdx)
			if (board[row][col] != board[idx][jdx])
				return (0);
	return (1);
}

void	recur(ll row, ll col, ll N)
{
	if (check_square(row, col, N))
	{
		ans[board[row][col]]++;
		return ;
	}
	N = (N >> 1);
	for (int idx = 0; idx < 2; ++idx)
		for (int jdx = 0; jdx < 2; ++jdx)
			recur(row + idx * N, col + jdx * N, N);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N;
	for (int idx = 0; idx < N; ++idx)
		for (int jdx = 0; jdx < N; ++jdx)
			cin >> board[idx][jdx];
	recur(0, 0, N);
	cout << ans[0] << '\n' << ans[1];
}
