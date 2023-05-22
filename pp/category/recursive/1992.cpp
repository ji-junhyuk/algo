#include <iostream>
using namespace std;
#define ll long long
#define MAX_LEN 64

ll board[MAX_LEN][MAX_LEN];
ll N;
string s1;

void	input(void)
{
	cin >> N;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> s1;
		for (int jdx = 0; jdx < N; ++jdx)
			board[idx][jdx] = s1[jdx] - '0';
	}
}

int	check_square(ll row, ll col, ll N)
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
		cout << board[row][col];
		return ;
	}
	N = (N >> 1);
	cout << '(';
	for (int idx = 0; idx < 2; ++idx)
		for (int jdx = 0; jdx < 2; ++jdx)
			recur(row + idx * N, col + jdx * N, N);
	cout << ')';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	input();
	recur(0, 0, N);
}		
