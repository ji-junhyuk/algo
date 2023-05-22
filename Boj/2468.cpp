#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int area[100][100];
bool visited[100][100];
int start = 101;
int arrive = 0;
int N;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> area[i][j];
			if (area[i][j] < start)
				start = area[i][j];
			if (area[i][j] > arrive)
				arrive = area[i][j];
		}
	}
	int ans = 0;
	for (int l = 0; l <= arrive; ++l) 
	{
		int safe_area = 0;
		memset(visited, 0, sizeof(visited));
		queue<pair<int, int>> Q;

		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < N; ++j) 
			{
				if (area[i][j] > l && !visited[i][j])
				{
					++safe_area;
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
						if (ny < 0 || ny >= N || nx < 0 || nx >= N)
							continue ;
						if (visited[ny][nx] || area[ny][nx] <= l)
							continue ;
						visited[ny][nx] = 1;
						Q.push({ny, nx});
					}
				}
			}
		}
		if (ans <= safe_area )
			ans = safe_area;
	}
	cout << ans << '\n';
}
