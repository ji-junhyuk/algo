#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string map[1501];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
bool is_visited[1501][1501]; //queue
bool is_svisited[1501][1501];
int R, C;
queue<pair<int, int>> IQ; // ice braking
queue<pair<int, int>> IQ2;
queue<pair<int, int>> JQ; // find swan
queue<pair<int, int>> JQ2;

int main(void)
{
	cin >> R >> C;
	for (int i = 0; i < R; ++i) 
	{
		cin >> map[i];
	}
	pair<int, int> cur;
	for (int i = 0; i < R; ++i) 
	{
		for (int j = 0; j < C; ++j) 
		{
			if (map[i][j] != 'X')
				IQ.push({i, j});
			if (map[i][j] == 'L')
			{
				cur = {i, j};
			}
		}
	}
	is_svisited[cur.first][cur.second] = 1;
	JQ.push({cur.first, cur.second});
	bool is_found = false;
	int ans = 0;
	while (!is_found)
	{
		while (!IQ.empty())
		{
			auto cur = IQ.front();
			IQ.pop();
			is_visited[cur.first][cur.second] = 1;
			for (int dir = 0; dir < 4; ++dir) 
			{
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue ;
				if (is_visited[ny][nx])
					continue ;
				if (map[ny][nx] == 'X')
					IQ2.push({ny, nx});
				is_visited[ny][nx] = 1;
			}
		}
		while (!IQ2.empty())
		{
			auto cur = IQ2.front();
//			cout << cur.first << ' ' << cur.second << '\n';
			IQ2.pop();
			map[cur.first][cur.second] = '.';
			IQ.push({cur.first, cur.second});
		}
		++ans;
		while (!JQ.empty())
		{
			auto cur = JQ.front();
			JQ.pop();
			for (int dir = 0; dir < 4; ++dir) 
			{
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];
				if (ny < 0 || ny >= R || nx < 0 || nx >= C)
					continue ;
				if (is_svisited[ny][nx])
					continue ;
				if (map[ny][nx] == 'L')
				{
					is_found = true;
					break ;
				}
				if (map[ny][nx] == 'X')
				{
					is_svisited[ny][nx] = 1;
					JQ2.push({ny, nx});
					continue ;
				}
				is_svisited[ny][nx] = 1;
				JQ.push({ny, nx});
			}
		}
		while (!JQ2.empty())
		{
			auto cur = JQ2.front();
			JQ2.pop();
			JQ.push({cur.first, cur.second});
		}
	}
	cout << ans << '\n';
}
