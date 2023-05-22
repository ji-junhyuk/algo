#include <iostream>
using namespace std;
#define ll long long
#define MAX_LEN 2187 

ll N;
ll board[MAX_LEN][MAX_LEN];
ll ans[3];

ll	find_square(ll row, ll col, ll N)
{
	for (int idx = row; idx < row + N; ++idx)
		for (int jdx = col; jdx < col + N; ++jdx)
			if (board[row][col] != board[idx][jdx])
					return (0);
	return (1);
}

void	recur(ll row, ll col, ll N)
{
	if (find_square(row, col, N))
	{
		ans[board[row][col] + 1] += 1;
		return ;
	}
	N /= 3;
	for (int idx = 0; idx < 3; ++idx)
		for (int jdx = 0; jdx < 3; ++jdx)
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
	for (int idx = 0; idx < 3; ++idx)
		cout << ans[idx] << '\n';
}
