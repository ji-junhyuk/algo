#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string area[100];
bool is_visited[100][100];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int N;
queue<pair<int, int>> Q;

void bfs()
{
	int cnt = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (!is_visited[i][j])
			{
				++cnt;
				is_visited[i][j] = 1;
				Q.push({i, j});
			}

			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				char shape = area[cur.first][cur.second];
				for (int dir = 0; dir < 4; ++dir) 
				{
					int ny = cur.first + dy[dir];
					int nx = cur.second + dx[dir];
					if (ny < 0 || ny >= N || nx < 0 || nx >= N)
						continue ;
					if (area[ny][nx] != shape || is_visited[ny][nx])
						continue ;
					is_visited[ny][nx] = 1;
					Q.push({ny, nx});
				}
			}
		}
	}
	cout << cnt << ' ';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> area[i];
	}
	bfs();
	memset(is_visited, 0, sizeof(is_visited));
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (area[i][j] == 'R')
				area[i][j] = 'G';
		}
	}
	bfs();
}
