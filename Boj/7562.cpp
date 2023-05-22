#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int dy[8] = {-1, -2, -2, -1, 1, 2, 1, 2};
int dx[8] = {-2, -1, 1, 2, -2, -1, 2, 1};
int chess[300][300];
int dist[300][300];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		queue<pair<int, int>> Q;
		int N;
		cin >> N;
		memset(chess, -1, sizeof(chess));
		memset(dist, -1, sizeof(dist));
		int y, x;
		cin >> y >> x;
		dist[y][x] = 0;
		Q.push({y, x});
		int a, b;
		cin >> a >> b;
		while (!Q.empty())
		{
			auto cur = Q.front();
			if (cur.first == a && cur.second == b)
			{
				cout << dist[cur.first][cur.second] << '\n';
				break ;
			}
			Q.pop();
			for (int dir = 0; dir < 8; ++dir) 
			{
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue ;
				if (dist[ny][nx] != -1)
					continue ;
				dist[ny][nx] = dist[cur.first][cur.second] + 1;
				Q.push({ny, nx});
			}
		}
	}

}
