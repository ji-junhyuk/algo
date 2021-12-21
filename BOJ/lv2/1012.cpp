#include <bits/stdc++.h>
using namespace std;

int board[51][51];
int visited[51][51];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void dfs(int y, int x, int M, int N)
{
	visited[y][x] = 1;

	for (int idx = 0; idx < 4; idx++)
	{
		int nx = x + dx[idx];
		int ny = y + dy[idx];

		if (nx < 0 || nx >= M || ny < 0 || ny >= N)
			continue;
		if (board[ny][nx] == 1 && visited[ny][nx] == 0)
			dfs(ny, nx, M, N);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int M, N, K; //가로 세로 배추

	cin >> T;
	while (T--)
	{
		cin >> M >> N >> K;
		for (int idx = 0; idx < N; idx++)
			for (int jdx =0; jdx < M; jdx++)
				board[idx][jdx] = 0;
		for (int idx = 0; idx < N; idx++)
			for (int jdx =0; jdx < M; jdx++)
				visited[idx][jdx] = 0;
		while (K--)
		{
			int x, y;
			cin >> x >> y;
			board[y][x] = 1;
		}
		int cnt = 0;
		for (int idx = 0; idx < N; idx++)
		{
			for (int jdx = 0; jdx < M; jdx++)
			{
				if (board[idx][jdx] == 1 && visited[idx][jdx] == 0)
				{
					dfs(idx, jdx, M, N);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}
