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
int map[8][8];
//int copy_map[8][8];
vector<pair<int, int>> Empty;
int ans;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void bfs(int copy_map[][8])
{
	queue<pair<int, int>> Q;
	bool is_visited[8][8] = {};
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (copy_map[i][j] == 2 && !is_visited[i][j])
			{
				Q.push({i, j});
				is_visited[i][j] = true;
			}
			while (!Q.empty())
			{
				auto cur = Q.front(); Q.pop();
				for (int dir = 0; dir < 4; ++dir) 
				{
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (ny < 0 || ny >= N || nx < 0 || nx >= M)
						continue ;
					if (is_visited[ny][nx] || copy_map[ny][nx] != 0)
						continue ;
					copy_map[ny][nx] = 2;
					Q.push({ny, nx});
					is_visited[ny][nx] = true;
				} 
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (copy_map[i][j] == 0)
				++cnt;
		}
	}
	ans = max(cnt, ans);
}
int is_visited[8][8];
pair<int,int> selected[3];
void dfs(int depth, int y, int x)
{
	if (depth == 3)
	{
		int copy_map[8][8] = {};
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				copy_map[i][j] = map[i][j];
			}
		}
		for (int i = 0; i < 3; ++i) 
		{
			if (copy_map[selected[i].first][selected[i].second] != 0)
				return ;
		}
		for (int i = 0; i < 3; ++i) 
		{
			copy_map[selected[i].first][selected[i].second] = 1;
		}
		bfs(copy_map);
		return ;
	}
	for (int i = y; i < N; ++i) 
	{
		for (int j = x; j < M; ++j) 
		{
			if (!is_visited[i][j])
			{
				is_visited[i][j] = true;
				selected[depth] = {i, j};
				dfs(depth + 1, 0, 0);
				selected[depth] = {0, 0};
				is_visited[i][j] = false;
			}
		}
	}
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
			if (map[i][j] == 0)
				Empty.push_back({i, j});
		}
	}
	dfs(0, 0, 0);
//
//	int size = Empty.size();
//	vector<int> selected(64, 1);
//	fill(selected.begin(), selected.begin() + 3, 0);
//	do {
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < M; ++j) 
//			{
//				copy_map[i][j] = map[i][j];
//			}
//		}
//		for (int i = 0; i < size; ++i) 
//		{
//			if (!selected[i])
//			{
//				int y, x;
//				tie(y, x) = Empty[i];
//				copy_map[y][x] = 1;
//			}
//		}
//		bfs();
//	} while (next_permutation(selected.begin(), selected.begin() + size));
	cout << ans;
}
