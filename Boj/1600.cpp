#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int h_dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int h_dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int grid[201][201];
int dist[201][201][30];

int K;
int R, C;

void	bfs()
{
	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> Q; // y, x, Monkeymove
	Q.push({0, 0, 0});
	dist[0][0][0] = 0;
	while (!Q.empty())
	{
		auto cur = Q.front();
		int y = get<0>(cur);
		int x = get<1>(cur);
		Q.pop();
//		cout << "y: " << y << ' ' << "x: " << x <<'\n';
		int monkey_move = get<2>(cur);
		if (y == R - 1 && x == C - 1)
		{
			cout << dist[y][x][monkey_move] << '\n';
			return ;
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (grid[ny][nx] != 0 || dist[ny][nx][monkey_move] != -1)
				continue ;
			dist[ny][nx][monkey_move] = dist[y][x][monkey_move] + 1;
			Q.push({ny, nx, monkey_move});
		}

		if (monkey_move + 1 <= K)
		{
			for (int h_dir = 0; h_dir < 8; ++h_dir) 
			{
				int ny = y + h_dy[h_dir];
				int nx = x + h_dx[h_dir];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue ;
				if (grid[ny][nx] != 0 || dist[ny][nx][monkey_move + 1] != -1)
					continue ;
				dist[ny][nx][monkey_move + 1] = dist[y][x][monkey_move] + 1;
				Q.push({ny, nx, monkey_move + 1});
			}
		}
	}
	cout << -1 << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K >> C >> R;
	for (int i = 0; i < R; ++i) 
	{
		for (int j = 0; j < C; ++j) 
		{
			cin >> grid[i][j];
		}
	}
	bfs();
}
