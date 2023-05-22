#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


int ocean[300][300];
int o_copy[300][300];
bool is_visited[300][300];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> ocean[i][j];
		}
	}

	int ans = 0;
	while (1)
	{
		queue<pair<int, int>> Q;
		memset(is_visited, 0, sizeof(is_visited));
		memset(o_copy, 0, sizeof(o_copy));
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				int count = 0;
				// one year later
				if (ocean[i][j] != 0)
				{
					if (ocean[i - 1][j] == 0)
						++count;
					if (ocean[i + 1][j] == 0)
						++count;
					if (ocean[i][j - 1] == 0)
						++count;
					if (ocean[i][j + 1] == 0)
						++count;
					if (ocean[i][j] <= count)
						o_copy[i][j] = 0;
					else
						o_copy[i][j] = ocean[i][j] - count;
				}
			}
		}
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				ocean[i][j] = o_copy[i][j];
			}
		}
//		cout << '\n';
//		for (int i = 0; i < N; ++i) 
//		{
//			for (int j = 0; j < M; ++j) 
//			{
//				cout << ocean[i][j] << ' ';
//			}
//			cout << '\n';
//		}
		++ans;
		int cnt = 0;
		bool is_melted = true;
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				if (ocean[i][j] != 0 && !is_visited[i][j])
				{
					++cnt;
					is_melted = false;
					is_visited[i][j] = 1;
					Q.push({i, j});
				}
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int dir = 0; dir < 4; ++dir) 
					{
						int ny = cur.first + dy[dir];
						int nx = cur.second + dx[dir];
						if (ny < 0 || ny >= N || nx < 0 || nx >= M)
							continue ;
						if (is_visited[ny][nx] || !ocean[ny][nx])
							continue;
						is_visited[ny][nx] = 1;
						Q.push({ny, nx});
					}
				}
			}
		}
		if (is_melted)
		{
			cout << 0 << '\n';
			return (0);
		}
		if (cnt > 1)
		{
			cout << ans << '\n';
			return 0;
		}
	}
}
