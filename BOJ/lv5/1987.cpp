#include <iostream>
#define MAX 20
using namespace std;

int i_R, i_C;
char c_board[MAX][MAX];
bool b_visited[26];
int i_dx[] = {0, 0, 1, -1};
int i_dy[] = {1, -1, 0, 0};
int i_max_move;

void dfs(int i_row, int i_col, int i_cnt)
{
	if (i_max_move < i_cnt)
		i_max_move = i_cnt;
	for (int idx = 0; idx < 4; idx++)
	{
		int x = i_row + i_dx[idx];
		int y = i_col + i_dy[idx];

		if (x >= 0 && y >= 0 && x < i_R && y < i_C)
		{
			if (b_visited[c_board[x][y] - 'A'] == false)
			{
				b_visited[c_board[x][y] - 'A'] = true;
				dfs(x, y, i_cnt + 1);
				b_visited[c_board[x][y] - 'A'] = false;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> i_R >> i_C;
	for (int idx = 0; idx < i_R; ++idx)
	{
		for (int jdx = 0; jdx < i_C; ++jdx)
		{
			cin >> c_board[idx][jdx];
		}
	}
	b_visited[c_board[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	cout << i_max_move;
}
