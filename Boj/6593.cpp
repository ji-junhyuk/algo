#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string building[30][30];
int dist[30][30][30];

int dy[] = {-1, 1, 0, 0, 0, 0};
int dx[] = {0, 0, -1, 1, 0, 0};
int dz[] = {0, 0, 0, 0, -1, 1};
int L, R, C;

void bfs(queue<tuple<int, int, int>> &Q)
{
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int z = get<0>(cur);
		int y = get<1>(cur);
		int x = get<2>(cur);
//		cout << z << ' ' << y << ' ' << x << ' ' << building[z][y][x] << '\n';
		if (building[z][y][x] == 'E')
		{
			cout << "Escaped in " << dist[z][y][x] << " minute(s)." << '\n';
			return ;
		}
		for (int dir = 0; dir < 6; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			int nz = z + dz[dir];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C || nz < 0 || nz >= L)
				continue ;
			if (dist[nz][ny][nx] != -1 || building[nz][ny][nx] == '#')
				continue ;
			dist[nz][ny][nx] = dist[z][y][x] + 1;
			Q.push({nz, ny, nx});
		}
	}
	cout << "Trapped!" << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> L >> R >> C;
		queue<tuple<int, int, int>> Q;
		memset(dist, -1, sizeof(dist));
		if (L == 0 && R == 0 && C == 0)
			break ;
		for (int i = 0; i < L; ++i) 
		{
			for (int j = 0; j < R; ++j) 
			{
				cin >> building[i][j];
				for (int k = 0; k < C; ++k) 
				{
					if (building[i][j][k] == 'S')
					{
						dist[i][j][k] = 0;
						Q.push({i, j, k});
					}
				}
			}
		}
//		cout << '\n';
//		for (int i = 0; i < L; ++i) 
//		{
//			for (int j = 0; j < R; ++j) 
//			{
//				for (int k = 0; k < C; ++k) 
//				{
//					cout << building[i][j][k];
//				}
//				cout << '\n';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		bfs(Q);
	}
}
