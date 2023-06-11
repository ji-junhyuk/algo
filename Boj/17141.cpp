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

int N, M;
int lab[50][50];
vector<pair<int, int>> virus;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dist[50][50];
int ans = 0x7fffffff;

void bfs(queue<pair<int, int>>& Q)
{
	int cnt = 0;
	while (!Q.empty())
	{
		int y, x;
		tie(y, x) = Q.front(); Q.pop();
		cnt = max(cnt, dist[y][x]);
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue ;
			if (dist[ny][nx] != -1 || lab[ny][nx] != 0)
				continue ;
			dist[ny][nx] = dist[y][x] + 1;
			Q.push({ny, nx});
		}
	}
	bool is_fulled = true;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (lab[i][j] == 0 && dist[i][j] == -1)
				is_fulled = false;
		}
	}
	if (is_fulled)
		ans = min(cnt, ans);
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
	int vsize = virus.size();
	vector<int> selected(vsize, 1);
	fill(selected.begin(), selected.begin() + M, 0);
//	for (int i = 0; i < selected.size(); ++i) 
//	{
//		cout << selected[i] << ' ';
	do {
		int idx = 0;
		int stored[vsize];
		for (int i = 0; i < vsize; ++i) 
		{
			if (!selected[i])
			{
				stored[idx++] = i;
			}
		}
		queue<pair<int, int>> Q;
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < idx; ++i) 
		{
			int y = virus[stored[i]].first;
			int x = virus[stored[i]].second;
			lab[y][x] = 2;
			dist[y][x] = 0;
			Q.push({y, x});
		}
		bfs(Q);
		for (int i = 0; i < idx; ++i) 
		{
			lab[virus[stored[i]].first][virus[stored[i]].second] = 0;
		}
	} while (next_permutation(selected.begin(), selected.end()));
	if (ans == 0x7fffffff)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
}

