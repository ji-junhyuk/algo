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
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
bool visited[100][100];
int n;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> Q;
	int distinct = 2;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			if (map[i][j] == 1)
			{
				map[i][j] = distinct;
				visited[i][j] = 1;
				Q.push({i, j});
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) 
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (ny < 0 || ny >= n || nx < 0 || nx >= n)
							continue;
						if (visited[ny][nx] || map[ny][nx] != 1)
							continue ;
						visited[ny][nx] = 1;
						map[ny][nx] = distinct;
						Q.push({ny, nx});
					}
				}
				distinct++;
			}
	stack<pair<int, int>> S;
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			if (map[i][j] == 0)
			{
				for (int dir = 0; dir < 4; ++dir) 
				{
					int y = i + dy[dir];
					int x = j + dx[dir];
					if (y - 1 < 0 || y + 1 >= n || x - 1 < 0 || x + 1 >= n)
						continue ;
					if (map[y][x] != 0)
					{
						cout << i << ' ' << j << '\n';
						S.push({i, j});
					}
				}
			}
		}
	}
	while (!S.empty())
	{
		map[S.top().first][S.top().second] = 9;
		S.pop();
	}
		cout << '\n';
	for (int i = 0; i < n; ++i) 
	{
		for (int j = 0; j < n; ++j) 
		{
			cout << map[i][j] << ' ' ;
		}
		cout << '\n';
	}
		cout << '\n';
		}
	}

}
