#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, L, R;
int land[52][52];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool is_move()
{
	bool is_moved = false;
	bool is_visited[52][52] = {};
	queue<pair<int, int>> Q;
	queue<pair<int, int>> Q2;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			int cnt = 0;
			int sum = 0;
			if (land[i][j] && land[i][j + 1] && !is_visited[i][j])
			{
				int diff = abs(land[i][j] - land[i][j + 1]);
				if (diff >= L && diff <= R)
				{
					is_moved = true;
					is_visited[i][j] = true;
					Q.push({i, j});
					Q2.push({i, j});
				}
			}
			if (land[i][j] && land[i + 1][j] && !is_visited[i][j])
			{
				int diff = abs(land[i][j] - land[i + 1][j]);
				if (diff >= L && diff <= R)
				{
					is_moved = true;
					is_visited[i][j] = true;
					Q.push({i, j});
					Q2.push({i, j});
				}
			}
			while (!Q.empty())
			{
				int y, x;
				tie(y, x) = Q.front(); Q.pop();
				++cnt;
				sum += land[y][x];
				for (int dir = 0; dir < 4; ++dir) 
				{
					int ny = y + dy[dir];
					int nx = x + dx[dir];
					if (ny < 1 || ny > N || nx < 1 || nx > N)
						continue ;
					if (is_visited[ny][nx])
						continue ;
					int diff = abs(land[y][x] - land[ny][nx]);
					if (diff < L || diff > R)
						continue ;
					is_visited[ny][nx] = 1;
					Q.push({ny, nx});
					Q2.push({ny, nx});
				}
			}
//			cout << "cnt: " << cnt << " sum: " << sum << '\n';
			int shared;
			if (cnt)
			{
				shared = sum / cnt;
			}
			while (!Q2.empty())
			{
				int y, x;
				tie(y, x) = Q2.front(); Q2.pop();
				land[y][x] = shared;
			}
		}
	}
	if (is_moved)
		return true;
	return false;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L >> R;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cin >> land[i][j];
		}
	}
	int cnt = 0;
	while (1)
	{
		if (!is_move())
			break ;
		++cnt;
//		for (int i = 1; i <= N; ++i) 
//		{
//			for (int j = 1; j <= N; ++j) 
//			{
//				cout << land[i][j] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
	}
	cout << cnt;
}
