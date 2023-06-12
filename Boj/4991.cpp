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
1. 간단한 bfs문제로 인식
2. 풀어보니 위의 반례가 있음.
3. 아기상어처럼 한쪽방향으로만 찾고 싶었는데
(가장 짧은 거리에 있는 걸 방문, 시계방향으로 방문)
-> (가장 짧은 게 여러개 있다면, 이 방식도 힘듬)
4. 결국엔 모든 점에 대해 완전 탐색을 하는 문제
	- 1. 더러운 곳은 최대 10개(이 순열은 10!)
	- 2. 방문순서 모든 순열로 기록
	- 3. 해당 순열마다 최소값 갱신
	- 4. 어떤 순열에서 갈 수 없는 곳이라면 -1
	- 5. -1인 곳을 만났을 땐 유효하지 않은 순열이니까 해당 순열 무시
 */

int w, h;
string room[20];
pair<int, int> cleaner;
vector<pair<int, int>> dirty;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int dirty_to_dirty[20][20];
int start_to_dirty[10];
int dist[20][20];

void bfs(int y, int x)
{
//	cout << "y: " << y << " x: " << x << '\n';
	memset(dist, -1, sizeof(dist));
	queue<pair<int, int>> queue;
	queue.push({y, x});
	dist[y][x] = 0;

	while (!queue.empty())
	{
		int y, x;
		tie(y, x) = queue.front(); queue.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (ny < 0 || ny >= h || nx < 0 || nx >= w)
				continue ;
			if (room[ny][nx] == 'x' || dist[ny][nx] != -1)
				continue ;
			dist[ny][nx] = dist[y][x] + 1;
			queue.push({ny, nx});
		}
	}
//	cout << "dist\n";
//	for (int i = 0; i < h; ++i) 
//	{
//		for (int j = 0; j < w; ++j) 
//		{
//			cout << dist[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
}

void find_start_to_dirty(int y, int x)
{
	bfs(y, x);
	for (int i = 0; i < dirty.size(); ++i) 
	{
		start_to_dirty[i] = dist[dirty[i].first][dirty[i].second];
	}
}

void find_dirty_to_dirty(const int& dirty_size)
{
	for (int i = 0; i < dirty_size; ++i) 
	{
		bfs(dirty[i].first, dirty[i].second);
		for (int j = 0; j < dirty_size; ++j) 
		{
			if (i != j)
			{
				dirty_to_dirty[i][j] = dist[dirty[j].first][dirty[j].second];
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		int ans = 0x7fffffff;
		cin >> w >> h;
		if (w == 0 && h == 0)
			break ;
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
		memset(dirty_to_dirty, -1, sizeof(dirty_to_dirty));
		memset(start_to_dirty, -1, sizeof(start_to_dirty));
		int dirty_size = dirty.size();
		find_start_to_dirty(cleaner.first, cleaner.second);
		find_dirty_to_dirty(dirty_size);
		vector<int> selected(dirty_size);
		for (int i = 0; i < dirty_size; ++i) 
			selected[i] = i;
		do {
			bool can_move = true;
			int move = start_to_dirty[selected[0]];
			for (int i = 0; i < dirty_size - 1; ++i) 
			{
				if (dirty_to_dirty[selected[i]][selected[i + 1]] == -1)
				{
					can_move = false;
					break ;
				}
				move += dirty_to_dirty[selected[i]][selected[i + 1]];
			}
			if (can_move)
				ans = min(ans, move);
		} while (next_permutation(selected.begin(), selected.end()));
		if (ans == 0x7fffffff)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
		dirty.clear();
	}
}
