#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int dist[101][101];
int n, m;
string board[100];

void bfs(int i, int j)
{
	queue<pair<int, int>> Q;

	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};

	dist[i][j] = 1;
	Q.push({i, j});
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue ;
			if (board[ny][nx] == '0' || dist[ny][nx] != -1)
				continue ;
			dist[ny][nx] = dist[cur.first][cur.second] + 1;
			Q.push({ny, nx});
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	
	cin >> n >> m;
	fill(&dist[0][0], &dist[0][0] + sizeof(dist) / sizeof(dist[0][0]), -1);
	for (int i = 0; i < n; ++i) 
	{
		cin >> board[i];
	}
	bfs(0, 0);

	cout << dist[n - 1][m - 1] << '\n';
}
