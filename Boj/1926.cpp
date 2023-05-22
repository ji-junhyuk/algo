#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int board[501][501];
bool is_visited[501][501];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int n, m;
int max_size = 0;

void bfs(int i, int j)
{
	queue<pair<int, int>> Q;
	is_visited[i][j] = 1;
	Q.push({i, j});
	int count = 0;
	while (!Q.empty())
	{
		++count;
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue ;
			if (is_visited[ny][nx] || board[ny][nx] != 1)
				continue ;
			is_visited[ny][nx] = 1;
			Q.push({ny, nx});
		}
	}
	max_size = max(max_size, count);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int picture_cnt = 0;

	cin >> n >> m;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j) 
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < m; ++j) 
		{
			if (board[i][j] == 1 && !is_visited[i][j])
			{
				++picture_cnt;
				bfs(i, j);
			}
		}
	}
	cout << picture_cnt << '\n' << max_size << '\n';
}
