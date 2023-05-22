#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int is_visited[51][51];
int land[51][51];
int M, N;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> M >> N;
		queue<pair<int, int>> Q;
		memset(is_visited, 0, sizeof(is_visited));
		memset(land, 0, sizeof(land));
		int locate;
		int y, x;
		cin >> locate;
		for (int i = 0; i < locate; ++i) 
		{
			cin >> x >> y;
			land[y][x] = 1;
		}
		int cnt = 0;
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < M; ++j) 
			{
				if (land[i][j] == 1 && !is_visited[i][j])
				{
					is_visited[i][j] = 1;
					Q.push({i, j});
					++cnt;
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
						if (!land[ny][nx] || is_visited[ny][nx])
							continue ;
						is_visited[ny][nx] = 1;
						Q.push({ny, nx});
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}
