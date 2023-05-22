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
int box[1000][1000];
int day[1000][1000];
int max_day;
stack<pair<int, int>> S;

void bfs()
{
	int dy[] = {-1, 1, 0, 0};
	int dx[] = {0, 0, -1, 1};

	queue<pair<int, int>> Q;
	while (!S.empty())
	{
		auto cur = S.top();
		day[cur.first][cur.second] = 0;
		Q.push({cur.first, cur.second});
		S.pop();
	}
	while (!Q.empty())
	{
		auto cur = Q.front();
		max_day = max(max_day, day[cur.first][cur.second]);
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (box[ny][nx] != 0 || day[ny][nx] != -1)
				continue ;
			day[ny][nx] = day[cur.first][cur.second] + 1;
			Q.push({ny, nx});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				S.push({i, j});
		}
	}
	fill(&day[0][0], &day[0][0] + sizeof(day) / sizeof(day[0][0]), -1);
	bfs();
	bool ripe = true;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			if (box[i][j] == 0 && day[i][j] == -1)
			{
				ripe = false;
				break ;
			}
		}
	}
	if (ripe)
		cout << max_day << '\n';
	else
		cout << -1 << '\n';
}
