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

/*
 * 
[반례]
*x*x*
.....
*xox*
.....
*x*x*

 *
 */

int w, h;
string room[20];
pair<int, int> cleaner;
vector<pair<int, int>> dirty;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool cmp(pair<int, int>& L, pair<int, int>& R)
{
	if (L.first != R.first)
		return (L.first < R.first);
	return (L.second < R.second);
}

int bfs()
{
	auto cur = cleaner.front();
	cleaner.clear();
	queue<tuple<int, int, int>> queue;
	bool is_visited[20][20] = {};
	is_visited[cur.first][cur.second] = true;
	cout << "start, y: " << cur.first << ' ' << cur.second << '\n';
	queue.push({cur.first, cur.second, 0});
	room[cur.first][cur.second] = '.';
	int min_dist = 0x7fffffff;
	while (!queue.empty())
	{
		int y, x, cnt;
		tie(y, x, cnt) = queue.front(); queue.pop();
		cout << "in queue, y: " << y << " x: " << x << " cnt: " << cnt << '\n';
//		cout << "y: " << y << " x: " << x << ' ' << room[y][x] << '\n';
		if (room[y][x] == '*')
		{
			if (cnt <= min_dist)
			{
				min_dist = cnt;
				cout << "arrive y: " << y << " x: " << x << '\n';
				cleaner.push_back({y, x});				
			}
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)
				continue ;
			if (room[ny][nx] == 'x' || is_visited[ny][nx])
				continue ;
			is_visited[ny][nx] = true;
			queue.push({ny, nx, cnt + 1});
		}
	}
	sort(cleaner.begin(), cleaner.end(), cmp);
	if (min_dist == 0x7fffffff)
		return (0);
	return (min_dist);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int ans = 0;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break ;
		int dirty_place = 0;
		for (int i = 0; i < h; ++i) 
		{
			cin >> room[i];
			for (int j = 0; j < w; ++j) 
			{
				if (room[i][j] == 'o')
				{
					cleaner = {i, j};
					room[i][j] = '.';
				}
				if (room[i][j] == '*')
				{
					dirty.push_back({i, j});
				}
			}
		}
		int move = 0;
		bool is_error = false;
		for (int i = 0; i < dirty_place; ++i) 
		{
			move = bfs();
			cout << "move: " << move << '\n';
			if (move == 0)
			{
				cout << -1 << '\n';
				is_error = true;
				break ;
			}
			ans += move;
		}
		if (!is_error)
			cout << ans << '\n';
	}
}
