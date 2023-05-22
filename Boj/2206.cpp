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
int dx[] = {0, 0, 1, -1};
int dist[1001][1001][2];
int N, M;
string map[1001];

void bfs()
{
	queue<tuple<int, int, int>> Q; // Q에 내가 벽을 몇번 부쉈는지 포함하자.
	Q.push({0, 0, 0});
	dist[0][0][0] = 1;
	dist[0][0][1] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		int y = get<0>(cur);
		int x = get<1>(cur);
		int broken = get<2>(cur);
//		cout << y << ' ' << x << ' ' << broken << ' ' << dist[y][x][0] << ' ' << dist[y][x][1] << '\n';
		Q.pop();
		if (y == N - 1 && x == M - 1)
		{
			cout << dist[y][x][broken] << '\n';
			return ;
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (dist[ny][nx][broken] != -1 || broken > 1)
			{
//				cout << "dist[ny][nx]: " << dist[ny][nx] << '\n';
//				cout << "broken: " << broken << '\n';
//				cout << "@" << '\n';
				continue;
			}
			if (map[ny][nx] == '1')
			{
				if (broken == 0)
				{
					dist[ny][nx][1] = dist[y][x][broken] + 1;
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

	fill(&dist[0][0][0], &dist[0][0][0] + sizeof(dist) / sizeof(dist[0][0][0]), -1);
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		cin >> map[i];
	}
	bfs();
}
