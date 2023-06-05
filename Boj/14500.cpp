#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

// -------
// 
//bfs로 확인할 수 없는 도형
// ***
//  *
//
// *
//**
// *
//
// *
//***
//
//*
//**
//*

int map[500][500];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ans = -1;
int N, M;
// 4, 4
void check_1(int y, int x)
{
// ***
//  *
	if (y + 2 > N || x + 3 > M)
		return;
	int sum = 0;
	sum += map[y][x];
	sum += map[y][x + 1];
	sum += map[y][x + 2];
	sum += map[y + 1][x + 1];
	ans = max(sum, ans);
}

void check_2(int y, int x)
{
// *
//**
// *
	if (y + 3 > N || x + 2 > M)
		return ;
	int sum = 0;
	sum += map[y][x + 1];
	sum += map[y + 1][x];
	sum += map[y + 1][x + 1];
	sum += map[y + 2][x + 1];
	ans = max(sum, ans);
}

void check_3(int y, int x)
{
// *
//***
	if (y + 2 > N || x + 3 > M)
		return ;
	int sum = 0;
	sum += map[y][x + 1];
	sum += map[y + 1][x];
	sum += map[y + 1][x + 1];
	sum += map[y + 1][x + 2];
	ans = max(sum, ans);
}

void check_4(int y, int x)
{
	// *
	// **
	// *
	if (y + 3 > N || x + 2 > M)
		return ;
	int sum = 0;
	sum += map[y][x];
	sum += map[y + 1][x];
	sum += map[y + 1][x + 1];
	sum += map[y + 2][x];
	ans = max(sum, ans);
}

void check_special_shape(int y, int x)
{
	check_1(y, x);
	check_2(y, x);
	check_3(y, x);
	check_4(y, x);
}


/*
 * bfs로는 풀 수가 없다.. 되돌아갈 수 없더라고..
 */
//void bfs(int i, int j)
//{
//	queue<tuple<int, int, int, int>> Q;
//	int dist[500][500];
//	memset(dist, -1, sizeof(dist));
//	dist[i][j] = 0;
//	Q.push({i, j, map[i][j], 1});
//	cout << "i: " << i << " j: " << j << '\n';
//	cout << "map[i][j]: " << map[i][j] << '\n';
//	while (!Q.empty())
//	{
//		auto cur = Q.front(); Q.pop();
//		int y = get<0>(cur);
//		int x = get<1>(cur);
//		int sum = get<2>(cur);
//		int cnt = get<3>(cur);
//		cout << y << ' ' << x << ' ' << sum << ' '  << dist[y][x] << '\n';
//		if (cnt == 4)
//		{
//			ans = max(ans, sum);
//			cout << "sum: " << sum << '\n';
//		}
//		for (int dir = 0; dir < 4; ++dir) 
//		{
//			int ny = y + dy[dir];
//			int nx = x + dx[dir];
//			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
//				continue ;
//			if (dist[ny][nx] != -1)
//				continue ;
//			dist[ny][nx] = dist[y][x] + 1;
//			Q.push({ny, nx, sum + map[ny][nx], cnt + 1});
//		}
//	}
//}

bool is_selected[500][500];


void dfs(int y, int x, int depth, int sum)
{
	if (depth == 4)
	{
//		cout << "sum: " << sum << '\n';
		ans = max(ans, sum);
		return ;
	}
	for (int dir = 0; dir < 4; ++dir) 
	{
		int ny = y + dy[dir];
		int nx = x + dx[dir];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue ;
		if (!is_selected[ny][nx])
		{
			is_selected[ny][nx] = true;
			sum += map[ny][nx];
			dfs(ny, nx, depth + 1, sum);
			sum -= map[ny][nx];
			is_selected[ny][nx] = false;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			dfs(i, j, 0, 0);
			check_special_shape(i, j);
		}
	}
	cout << ans << '\n';
}
