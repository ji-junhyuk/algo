#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M, H;
int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int box[100][100][100];
int dist[100][100][100];
queue<tuple<int, int, int>> Q;

void bfs()
{
	while (!Q.empty())
	{
		auto cur = Q.front();
		int y = get<0>(cur);
		int x = get<1>(cur);
		int z = get<2>(cur);
		Q.pop();

		for (int dir = 0; dir < 6; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int nz = z + dz[dir];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || nz < 0 || nz >= H)
				continue ;
			if (dist[ny][nx][nz] != -1 || box[ny][nx][nz] != 0)
				continue ;
			dist[ny][nx][nz] = dist[y][x][z] + 1;
			Q.push({ny, nx, nz});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	fill(&dist[0][0][0], &dist[0][0][0] + sizeof(dist) / sizeof(dist[0][0][0]), -1);
	fill(&box[0][0][0], &box[0][0][0] + sizeof(box) / sizeof(box[0][0][0]), -1);
	cin >> M >> N >> H;
	for (int k = 0; k < H; ++k) 
	{
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
				{
					Q.push({i, j, k});
					dist[i][j][k] = 0;
				}
			}
		}

	}
	bfs();
	int is_valid = true;
	int day = 0;
	for (int k = 0; k < H; ++k) 
	{
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				if (dist[i][j][k] > day)
					day = dist[i][j][k];
				if (dist[i][j][k] == -1 && box[i][j][k] == 0)
				{
					is_valid = false;
					break ;
				}
			}
		}
	}
	if (is_valid)
		cout << day << '\n';
	else
		cout << -1 << '\n';
}
