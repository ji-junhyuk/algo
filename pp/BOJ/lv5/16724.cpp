#include <iostream>
#define MAX 1000
using namespace std;

int N, M, safe_zone;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int	board[MAX][MAX];
int visited[MAX][MAX];

void dfs(int y, int x)
{
	visited[y][x] = 1;
	int nx = x + dx[board[y][x]];
	int ny = y + dy[board[y][x]];
	if (visited[ny][nx] == 1)
	{
		safe_zone++;
	}
	if (!visited[ny][nx])
		dfs(ny, nx);
	visited[y][x] = 2;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < M; ++jdx)
		{
			char c;
			cin >> c;
			if (c == 'U') 
				board[idx][jdx] = 0;
			else if (c == 'D')
				board[idx][jdx] = 1;
			else if (c == 'L')
				board[idx][jdx] = 2;
			else
				board[idx][jdx] = 3;
		}
	}
	for (int idx = 0; idx < N; ++idx)
	{
		for (int jdx = 0; jdx < M; ++jdx)
		{
			if (!visited[idx][jdx])
				dfs(idx, jdx);
		}
	}
	cout << safe_zone;
}
