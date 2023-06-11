#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
#include <map>
using namespace std;

int lab[50][50];
int N, M;
vector<pair<int, int>> virus;
int ans = 0x7fffffff;
int dist[50][50];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
queue<pair<int, int>> que;

void bfs()
{
	bool all_spreaded = true;
	while (!que.empty())
	{
		int y, x;
		tie(y, x) = que.front(); que.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue;
			if (dist[ny][nx] != -1 || lab[ny][nx] == 1)
				continue ;
			dist[ny][nx] = dist[y][x] + 1;
			que.push({ny, nx});
		}
	}
//	cout << "dist\n";
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			cout << dist[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << "lab\n";
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			cout << lab[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
	int max_value = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (dist[i][j] == -1 && lab[i][j] == 0)
			{
				all_spreaded = false;
				return ;
			}
			if (lab[i][j] != 3 && dist[i][j] != -1)
				max_value = max(max_value, dist[i][j]);
		}
	}
	if (all_spreaded)
	{
		ans = min(ans, max_value);
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> lab[i][j];
			if (lab[i][j] == 2)
			{
				virus.push_back({i, j});
				lab[i][j] = 0;
			}
		}
	}
	int v_size = virus.size();
	vector<int> selected(v_size, 1);
	fill(selected.begin(), selected.begin() + M, 0);
	do {
		int idx = 0;
		int jdx = 0;
		int activated[v_size];
		int inactivated[v_size];
		for (int i = 0; i < v_size; ++i) 
		{
			if (!selected[i])
				activated[idx++] = i;
			else
				inactivated[jdx++] = i;
		}
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < idx; ++i) 
		{
			int index = activated[i];
			int y = virus[index].first;
			int x = virus[index].second;
			lab[y][x] = 2;
			dist[y][x] = 0;
			que.push({y, x});
		}
		for (int i = 0; i < jdx; ++i) 
		{
			int index = inactivated[i];
			int y = virus[index].first;
			int x = virus[index].second;
			lab[y][x] = 3;
		}
		bfs();
		for (int i = 0; i < idx; ++i) 
		{
			int index = activated[i];
			lab[virus[index].first][virus[index].second] = 0;
		}
		for (int i = 0; i < jdx; ++i) 
		{
			int index = inactivated[i];
			lab[virus[index].first][virus[index].second] = 0;
		}
	} while (next_permutation(selected.begin(), selected.end()));
	if (ans == 0x7fffffff)
	{
		cout << -1 << '\n';
		return (0);
	}
	cout << ans << '\n';
}
