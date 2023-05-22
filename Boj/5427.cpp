#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string building[1000];
int T;
int w, h;
int s_dist[1000][1000];
int f_dist[1000][1000];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void f_bfs(queue<pair<int, int>> &F)
{
	while (!F.empty())
	{
		auto cur = F.front();
		F.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)
				continue ;
			if (building[ny][nx] == '#' || f_dist[ny][nx] != -1)
				continue ;
			f_dist[ny][nx] = f_dist[cur.first][cur.second] + 1;
			F.push({ny, nx});
		}
	}
}

void s_bfs(queue<pair<int, int>> &S, bool &escape)
{
	while (!S.empty())
	{
		auto cur = S.front();
		if (cur.first == 0 || cur.first == h - 1 || cur.second == 0 || cur.second == w - 1)
		{
			escape = true;
			cout << s_dist[cur.first][cur.second] + 1 << '\n';
			break;
		}
		S.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)
				continue ;
			if (building[ny][nx] == '#' || s_dist[ny][nx] != -1)
				continue ;
			if (f_dist[ny][nx] != -1 && s_dist[cur.first][cur.second] + 1 >= f_dist[ny][nx])
				continue ;
			s_dist[ny][nx] = s_dist[cur.first][cur.second] + 1;
			S.push({ny, nx});
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		bool escape = false;
		queue<pair<int, int>> S;
		queue<pair<int, int>> F;
		memset(s_dist, -1, sizeof(s_dist));
		memset(f_dist, -1, sizeof(f_dist));
		cin >> w >> h;
		for (int i = 0; i < h; ++i) 
		{
			cin >> building[i];
			for (int j = 0; j < w; ++j) 
			{
				if (building[i][j] == '@')
				{
					s_dist[i][j] = 0;
					S.push({i, j});
				}
				if (building[i][j] == '*')
				{
					f_dist[i][j] = 0;
					F.push({i, j});
				}
			}
		}
		f_bfs(F);
//		for (int i = 0; i < h; ++i) 
//		{
//			for (int j = 0; j < w; ++j) 
//			{
//				cout << f_dist[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		s_bfs(S, escape);
//		for (int i = 0; i < h; ++i) 
//		{
//			for (int j = 0; j < w; ++j) 
//			{
//				cout << s_dist[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		if (!escape)
			cout << "IMPOSSIBLE" << '\n';
	}
}
