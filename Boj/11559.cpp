#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

char map[12][6];
bool is_visited[12][6];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void tilt()
{
	for (int col = 0; col < 6; ++col) 
	{
		int selected[12] = {};
		fill(selected, selected + 12, '.');
		int idx = 11;
		for (int row = 11; row >= 0; --row) 
		{
			if (map[row][col] != '.')
			{
				selected[idx--] = map[row][col];
			}
		}
//		cout << "sel\n";
//		for (int i = 0; i < 12; ++i) 
//		{
//			cout << selected[i] << ' ';
//		}
//		cout << '\n';
		for (int i = 0; i < 12; ++i) 
		{
			map[i][col] = selected[i];
		}
	}
}

bool bfs(int i, int j)
{
	queue<pair<int, int>> Q;
	queue<pair<int, int>> S;
	char c = map[i][j];
//	cout << i << ' ' << j << ' ' << c << '\n';
	Q.push({i, j});
	S.push({i, j});
	is_visited[i][j] = true;
	int cnt = 0;
	while (!Q.empty())
	{
		int y, x;
		tie(y, x) = Q.front();
		Q.pop();
		++cnt;
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6)
				continue ;
			if (is_visited[ny][nx] || map[ny][nx] != c)
				continue ;
			is_visited[ny][nx] = true;
			Q.push({ny, nx});
			S.push({ny, nx});
		}
	}
	if (cnt >= 4)
	{
		while (!S.empty())
		{
			int y, x;
			tie(y, x) = S.front();
			S.pop();
			map[y][x] = '.';
		}
		return true;
	}
	return false;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 12; ++i) 
	{
		for (int j = 0; j < 6; ++j) 
		{
			cin >> map[i][j];
		}
	}
	int boom_cnt = 0;
	while (1)
	{
		bool can_boom = false;
		memset(is_visited, 0, sizeof(is_visited));
		for (int i = 0; i < 12; ++i) 
		{
			for (int j = 0; j < 6; ++j) 
			{
				if (map[i][j] != '.' && !is_visited[i][j])
				{
					if (bfs(i, j) == true)
					{
//						cout << "canboom, i: " << i << ' ' << j << '\n';
						can_boom = true;
					}
//					cout << '\n';
//				for (int i = 0; i < 12; ++i) 
//				{
//					for (int j = 0; j < 6; ++j) 
//					{
//						cout << map[i][j] << ' ';
//					}
//					cout << '\n';
//				}
//					cout << '\n';
				}
			}
		}
//		cout << "tilt\n";
		tilt();
//					cout << '\n';
//				for (int i = 0; i < 12; ++i) 
//				{
//					for (int j = 0; j < 6; ++j) 
//					{
//						cout << map[i][j] << ' ';
//					}
//					cout << '\n';
//				}
//					cout << '\n';
		if (can_boom == false)
			break ;
						++boom_cnt;
	}
	cout << boom_cnt << '\n';
}
