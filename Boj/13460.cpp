#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M;
char map[10][10];
int dist[10][10][10][10];
pair<int, int> red, blue;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int bfs()
{
	queue<tuple<int, int, int, int>> Q;
	memset(dist, -1, sizeof(dist));
	Q.push({red.first, red.second, blue.first, blue.second});
	dist[red.first][red.second][blue.first][blue.second] = 0;
	while (!Q.empty())
	{
		int ry, rx, by, bx;
		tie(ry, rx, by, bx) = Q.front(); Q.pop();
		if (dist[ry][rx][by][bx] >= 10)
			return (-1);
		for (int dir = 0; dir < 4; ++dir) 
		{
			int nry, nrx, nby, nbx;
			nry = ry, nrx = rx, nby = by, nbx = bx;
			while (map[nby + dy[dir]][nbx + dx[dir]] == '.')
			{
				nby += dy[dir];
				nbx += dx[dir];
			}
			if (map[nby + dy[dir]][nbx + dx[dir]] == 'O')
				continue ;
			while (map[nry + dy[dir]][nrx + dx[dir]] == '.')
			{
				nry += dy[dir];
				nrx += dx[dir];
			}
			if (map[nry + dy[dir]][nrx + dx[dir]] == 'O')
				return (dist[ry][rx][by][bx] + 1);
			if ((nry == nby) && (nrx == nbx))
			{
				if (dir == 0)
					(ry > by) ? ++nry : ++nby;
				else if (dir == 1)
					(ry > by) ? --nby : --nry;
				else if (dir == 2)
					(rx > bx) ? ++nrx : ++nbx;
				else if (dir == 3)
					(rx > bx) ? --nbx : --nrx;
			}
			if (dist[nry][nrx][nby][nbx] != -1)
				continue ;
			Q.push({nry, nrx, nby, nbx});
			dist[nry][nrx][nby][nbx] = dist[ry][rx][by][bx] + 1;
		}
	}
	return (-1);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> map[i][j];
			if (map[i][j] == 'R')
			{
				red = {i, j};
				map[i][j] = '.';
			} 
			else if (map[i][j] == 'B')
			{
				blue = {i, j};
				map[i][j] = '.';
			}
		}
	}
	cout << bfs() << '\n';
}
