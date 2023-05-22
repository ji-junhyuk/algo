#include <bits/stdc++.h>
using namespace std;

char board[101][101];
int visited[101][101];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0 ,0};

int yes;
int no;
int N;

void bfs(int a, int b)
{
	queue<pair<int, int>> Q;
	Q.push({a,b});
	visited[a][b] = 1;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int idx = 0; idx < 4; idx++)
		{
			int nx = x + dx[idx];
			int ny = y + dy[idx];

			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
			{
				if (visited[nx][ny] == 0)
				{
					if (board[nx][ny] == board[x][y])
					{
						visited[nx][ny] = 1;
						Q.push({nx, ny});
					}
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);


	cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			cin >> board[idx][jdx];
		}
	}
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			if (visited[idx][jdx] == 0)
			{
				bfs(idx, jdx);
				yes++;
			}
		}
	}
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			visited[idx][jdx] = 0;
		}
	}
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			if (board[idx][jdx] == 'G')
				board[idx][jdx] = 'R';
		}
	}
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			if (visited[idx][jdx] == 0)
			{
				bfs(idx, jdx);
				no++;
			}
		}
	}
	cout << yes << ' ' << no;
}
