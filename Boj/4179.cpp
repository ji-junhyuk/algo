#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string map[1000];
stack<pair<int, int>> S;
int f_dist[1000][1000];
int j_dist[1000][1000];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
queue<pair<int, int>> J, F;
int R, C;
bool escape = false;

void F_bfs()
{
	while (!F.empty())
	{
		auto cur = F.front();
		F.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (map[ny][nx] == '#' || f_dist[ny][nx] != -1)
				continue ;
			f_dist[ny][nx] = f_dist[cur.first][cur.second] + 1;
			F.push({ny, nx});
		}
	}
//	for (int i = 0; i < R; ++i) 
//	{
//		for (int j = 0; j < C; ++j) 
//		{
//			cout << f_dist[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}

void J_bfs()
{
	int last = 0;
	while (!J.empty())
	{
		auto cur = J.front();
//		cout << cur.first << ' ' << cur.second << '\n';
		if (cur.first <= 0 || cur.first >= R - 1 || cur.second <= 0 || cur.second >= C - 1)
		{
			cout << j_dist[cur.first][cur.second] + 1 << '\n';
			escape = true;
			break ;
		}
		J.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
//			cout << "ny: " << ny << ' ' << "nx: " << nx << '\n';
			if (ny < 0 || ny >= R || nx < 0 || nx >= C)
				continue ;
			if (map[ny][nx] == '#' || j_dist[ny][nx] != -1)
				continue ;
//			cout << j_dist[cur.first][cur.second] << ' ' << 1 << ' ' << f_dist[ny][nx] << '\n';

			if (f_dist[ny][nx] != -1 && j_dist[cur.first][cur.second] + 1 >= f_dist[ny][nx])
			{
				continue ;
			}
			j_dist[ny][nx] = j_dist[cur.first][cur.second] + 1;
			last = j_dist[cur.first][cur.second];
			J.push({ny, nx});
		}
	}
//	cout << '\n';
//	for (int i = 0; i < R; ++i) 
//	{
//		for (int j = 0; j < C; ++j) 
//		{
//			cout << j_dist[i][j] << ' ';
//		}
//		cout << '\n';
//	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;
	fill(&f_dist[0][0], &f_dist[0][0] + sizeof(f_dist) / sizeof(f_dist[0][0]), -1);
	fill(&j_dist[0][0], &j_dist[0][0] + sizeof(j_dist) / sizeof(j_dist[0][0]), -1);
	for (int i = 0; i < R; ++i) 
	{
		cin >> map[i];
		for (int j = 0; j < C; ++j) 
		{
			if (map[i][j] == 'J')
			{
				j_dist[i][j] = 0;
				J.push({i, j});
			}
			else if (map[i][j] == 'F')
			{
				f_dist[i][j] = 0;
				F.push({i, j});
			}
		}
	}
	F_bfs();
	J_bfs();
	if (!escape)
		cout << "IMPOSSIBLE" << '\n';
}
