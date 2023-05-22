#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int map[100][100];
bool is_visited[100][100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> Q;
	int fill = 2;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (map[i][j] == 1)
			{
				Q.push({i, j});
				map[i][j] = fill;
				is_visited[i][j] = 1;
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) 
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (ny < 0 || ny >= N || nx < 0 || nx >= N)
							continue ;
						if (is_visited[ny][nx] || map[ny][nx] == 0)
							continue ;
						is_visited[ny][nx] = 1;
						map[ny][nx] = fill;
						Q.push({ny, nx});
					}
				}
				++fill;
			}
		}
	}

	queue<tuple<int, int, int, int>> S;
	int is_visited[100][100] = {};
	int is_visited2[100][100] = {};
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (map[i][j] == 0)
			{
				for (int dir = 0; dir < 4; ++dir) 
				{
					int y = i + dy[dir];
					int x = j + dx[dir];
					if (y < 0 || y >= N || x < 0 || x >= N)
						continue ;
					if (is_visited[i][j] || map[y][x] == 0)
						continue ;
//					cout << "locate 0: " << i << ' ' << j << ' '<< map[y][x] << '\n';
//					cout << "y: " << y << ' ' << "x: " << x << '\n';
					S.push({i, j, map[y][x], 0});
				}
			}
		}
	}
	int ans = 0x7fffffff;
//	cout << S.size() << '\n';

	while (!S.empty())
	{
		auto cur = S.front();
		queue<tuple<int, int, int, int>> Q;
		bool is_visited2[100][100] = {};
		int y1 = get<0>(cur);
		int x1 = get<1>(cur);
		int region1 = get<2>(cur);
		int cnt1 = get<3>(cur);

		is_visited2[y1][x1] = 1;
		Q.push({y1, x1, region1, cnt1}); 
		while (!Q.empty())
		{
			auto curr = Q.front();
			Q.pop();
			int y = get<0>(curr);
			int x = get<1>(curr);
			int region = get<2>(curr);
//			cout << "region1: " << region1 << '\n';
//			cout << "y: " << y << ' ' << "x: " << x << " region: " << region << '\n';
			int cnt = get<3>(curr);
			if (cnt >= ans)
				continue ;
			if (region != 0 && region != region1)
			{
				ans = min(ans, cnt);
				break ;
			}
			for (int dir = 0; dir < 4; ++dir) 
			{
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny < 0 || ny >= N || nx < 0 || nx >= N)
					continue ;
				if (map[ny][nx] == region1 || is_visited2[ny][nx])
					continue ;
				is_visited2[ny][nx] = 1;
				Q.push({ny, nx, map[ny][nx], cnt + 1});
			}
		}
		S.pop();
	}
	cout << ans << '\n';
//	cout << '\n';
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			cout << map[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
}
