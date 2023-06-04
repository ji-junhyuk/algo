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
int r, c, d;
int map[50][50];
bool is_cleaned[50][50];
int dy[] = {-1, 0, 1, 0}; // 북 동 남 서
int dx[] = {0, 1, 0, -1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> map[i][j];
		}
	}
	queue<pair<int, int>> Q;
	Q.push({r, c});
	int cleaning_cnt = 0;
	while (!Q.empty())
	{
		int y, x;
		tie(y, x) = Q.front();
		Q.pop();
		if (map[y][x] == 0)
		{
			++cleaning_cnt;
			map[y][x] = 3;
		}
//		cout << y << ' ' << x << '\n';
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < M; ++j) 
//			{
//				cout << map[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		bool all_cleaned = true;
		for (int dir = 0; dir < 4; ++dir) 
		{
			d = (d + 3) % 4;
			int ny = y + dy[d];
			int nx = x + dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (map[ny][nx] != 0)
				continue ;
			all_cleaned = false;
			Q.push({ny, nx});
//			cout << "Q.push" << " ny: " << ny << " nx: " << nx << '\n';
			break ;
		}
		if (all_cleaned)
		{
			int ny = y - dy[d];
			int nx = x - dx[d];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (map[ny][nx] == 1)
				break ;
			Q.push({ny, nx});
//			cout << "all_cleaned" << " ny: " << ny << " nx: " << nx << '\n';
		}
	}
	cout << cleaning_cnt << '\n';
}
