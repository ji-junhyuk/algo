#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M, K;
string map[1000];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dist[2][10][1000][1000];

void	bfs()
{
	queue<tuple<int, int, int, int>> Q;
	memset(dist, -1, sizeof(dist));
	dist[0][0][0][0] = 1;
	Q.push({0, 0, 0, 0});
	while (!Q.empty())
	{
		int day_night, broken, y, x;
		tie(day_night, broken, y, x) = Q.front();
		if (y == N - 1 && x == M - 1)
		{
			cout << dist[day_night][broken][y][x] << '\n';
			return ;
		}
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (map[ny][nx] == '0')
			{
				if (dist[(day_night + 1) % 2][broken][ny][nx] != -1)
					continue ;
				dist[(day_night + 1) % 2][broken][ny][nx] = dist[day_night][broken][y][x] + 1;
				Q.push({(day_night + 1) % 2, broken, ny, nx});
			}
			else // 1번일 때
			{
				if (broken >= K)
					continue ;
				if (day_night == 0) //  낮
				{
					if (dist[(day_night + 1) % 2][broken + 1][ny][nx] != -1)
						continue ;
					dist[(day_night + 1) % 2][broken + 1][ny][nx] = dist[day_night][broken][y][x] + 1;
					Q.push({(day_night + 1 % 2), broken + 1, ny, nx});
				}
				else // 밤
				{
					if (dist[(day_night + 1) % 2][broken][y][x] != -1)
						continue ;
					dist[(day_night + 1) % 2][broken][y][x] = dist[day_night][broken][y][x] + 1;
					Q.push({(day_night + 1) % 2, broken, y, x});
				}
			}
		}
	}
	cout << -1 << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i) 
	{
		cin >> map[i];
	}
	bfs();
}
