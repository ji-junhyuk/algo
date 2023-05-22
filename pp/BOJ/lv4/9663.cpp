#include <bits/stdc++.h>
using namespace std;

int N;

struct s_chess {
	int		row[14];
	int		queen_located[15];
	char	diag1[30];
	char	diag2[28];
	int		count;
} chess_board;

void	set_queen_checklist(int row, int col, int queen)
{
	chess_board.row[row] = queen;
	chess_board.diag1[col - row + (N - 1)] = queen;
	chess_board.diag2[col + row] = queen;
}

void	find_optimal_position(int col)
{
	int	row;
//	int idx;

	if (col == N)
	{
		chess_board.count++;
//		idx = 0;
//		while (idx < N)
//			cout << chess_board.queen_located[idx++];
//		cout << '\n';
	}
	row = 0;
	while (row < N)
	{
		if (!chess_board.row[row]
			&& !chess_board.diag1[col - row + (N - 1)]
			&& !chess_board.diag2[col + row])
		{
			set_queen_checklist(row, col, 1);
			chess_board.queen_located[col] = row;
			find_optimal_position(col + 1);
			set_queen_checklist(row, col, 0);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	idx;

	idx = 0;
	while (idx < N)
	{
		chess_board.row[idx] = 0;
		chess_board.diag1[idx] = 0;
		chess_board.diag2[idx] = 0;
		idx++;
	}
	while (idx < (2 * N))
	{
		chess_board.diag1[idx] = 0;
		chess_board.diag2[idx] = 0;
		idx++;
	}
	find_optimal_position(0);
	return (chess_board.count);
}
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	cout << ft_ten_queens_puzzle();
}
