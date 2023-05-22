#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


// (1, 1)의 방은 켜져있다.
// (1, 1)에 스위치에 있는 방들에 불을 킨다.
// - 만약 스위치에 있는 방이 인접해있다면
//   - 그 방에서 스위치를 킬 수 있는 방들에 불을 킨다.
int N, M;
int room[101][101];
int is_visited[101][101];
vector<pair<int, int>> V[101][101]; // 인접노드 저장
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

bool	is_connected(pair<int, int> p)
{
	for (int dir = 0; dir < 4; ++dir) 
	{
		int ny = p.first + dy[dir];
		int nx = p.second + dx[dir];
		if (ny < 1 || ny > N || nx < 1 || nx > N)
			continue;
		if (is_visited[ny][nx])
			return true;
	}
	return false;
}

void	bfs()
{
	queue<pair<int, int>> Q;

	Q.push({1, 1});
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (auto c : V[cur.first][cur.second])
		{
			if (is_visited[c.first][c.second])
				continue ;
			if (is_connected(c)) // 인접해있으면,
			{
				is_visited[c.first][c.second] = 1;
				Q.push({c.first, c.second});
			}
			room[c.first][c.second] = 1;
		}
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 1 || ny > N || nx < 1 || nx > N)
				continue ;
			if (is_visited[ny][nx] || room[ny][nx] == 0)
				continue ;
			is_visited[ny][nx] = 1;
			Q.push({ny, nx});
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < M; ++i) 
	{
		int y, x, a, b;
		cin >> y >> x >> a >> b;
		V[y][x].push_back({a, b});
	}
	room[1][1] = 1;
	is_visited[1][1] = 1;
	bfs();
	int ans = 0;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			ans += room[i][j];
		}
	}
	cout << ans << '\n';
}
