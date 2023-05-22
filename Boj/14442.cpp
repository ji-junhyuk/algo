#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int R, C, K;
string map[1000];
int dist[1000][1000][11];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs()
{
	queue<tuple<int, int, int>> Q; //y, x, broken
	memset(dist, -1, sizeof(dist));
	for (int i = 0; i < 10; ++i) 
	{
		dist[0][0][i] = 1;
	}
	Q.push({0, 0, 0});
	while (!Q.empty())
	{
		int y, x, broken;
		tie(y, x, broken) = Q.front();
//		cout << y << ' ' << x << ' ' << broken << '\n';
		Q.pop();
		if (y == R - 1 && x == C - 1)
		{
			cout << dist[y][x][broken] << '\n';
			return ;
		}

		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (dist[ny][nx][broken] != -1)
				continue ;
			if (map[ny][nx] == '1')
			{
				if (dist[ny][nx][broken + 1] != -1)
					continue ;
				if (broken + 1 <= K)
				{
					dist[ny][nx][broken + 1] = dist[y][x][broken] + 1;
					Q.push({ny, nx, broken + 1});
				}
			}
			else
			{
				dist[ny][nx][broken] = dist[y][x][broken] + 1;
				Q.push({ny, nx, broken});
			}
		}
	}
	cout << -1 << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> K;
	for (int i = 0; i < R; ++i) 
	{
		cin >> map[i];
	}
	bfs();
}
