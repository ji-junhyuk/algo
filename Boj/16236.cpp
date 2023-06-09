#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

// if (m_step >= time) 이 조건을 빼먹고 push해서 헤맴.
int N;
int sea[20][20];
int b_size = 2;
int eat_count = 0;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};

priority_queue<int, vector<int>, greater<int>> pq;
vector<pair<int, int>> location;
bool cmp(pair<int, int> &L, pair<int, int> &R)
{
	if (L.first != R.first)
		return L.first < R.first;
	if (L.second != R.second)
		return L.second < R.second;
	return true;
}

int bfs()
{
	bool is_visited[20][20] = {};
	queue<tuple<int, int, int>> Q;
	Q.push({location[0].first, location[0].second, 0});
	sea[location[0].first][location[0].second] = 0;
	is_visited[location[0].first][location[0].second] = true;
	location.erase(location.begin(), location.end());
	int m_step = 0x7fffffff;
	int is_moved = false;
	while (!Q.empty())
	{
		int y, x, time;
		tie(y, x, time) = Q.front(); Q.pop();
//		cout << "y: " << y << " x: " << x << '\n';
		if (sea[y][x] && sea[y][x] < b_size)
		{
//			cout << "eat, y: " << y << " x: " << x << '\n';
			is_moved = true;
			if (m_step >= time) 
			{
				m_step = min(m_step, time);
				location.push_back({y, x});
			}
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue ;
			if (sea[ny][nx] > b_size)
				continue ;
			if (is_visited[ny][nx])
				continue ;
			is_visited[ny][nx] = 1;
			Q.push({ny, nx, time + 1});
		}
	}
	sort(location.begin(), location.end(), cmp);
	if (!is_moved)
		return (0);
	return m_step;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> sea[i][j];
			if (sea[i][j] == 9)
			{
				location.push_back({i, j});
				sea[i][j] = 0;
			}
		}
	}
	int eat_time = 0;
	int cur_eat_time;
	int eat_cnt = 0;
	while (1)
	{
		cur_eat_time = bfs();
//		cout << "cur_eat_time: " << cur_eat_time << '\n';
		if (!cur_eat_time)
			break ;
		++eat_cnt;
		eat_time += cur_eat_time;
		if (eat_cnt == b_size)
		{
			++b_size;
			eat_cnt = 0;
		}
	}
	cout << eat_time << '\n';
}
