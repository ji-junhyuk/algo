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

// 1. 모든 점을 기준점으로 한다. 20 * 20
// 2. 구역을 나눈다.
//  - 5개 선거구역 나와야함
//  - 20 * 20
//  - 여기에 가능한 dy, dx조합 20
//  N^2 * N^2
// 3. bfs를 한다.
//  매번 bfsN^2; 
//  최대값과 최소값을 구한다.
//  ans = min(최대값 - 최소값);
//  n^6 알고리즘이구나!
//
// 공간을 채울 때
// 1. 5번을 먼저 채운다.
// 	- 기준점 아래 점에서 bfs를 하며 5를 꽉 채운다.
// 2. 1~4번을 채울 때 비워있는 것에 대해서만 각자의 번호를 매긴다.
// - bfs1번만으로는 되지 않는 경우가 있음.
//
// 공간을 채울 떄
// 정사각형 각 끝점에서 push해서 1,2,3,4채우기

int city[21][21];
int border[21][21];
int N;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};
int ans = 0x7fffffff;

void bfs(int y, int x, int d1, int d2)
{
	queue<pair<int, int>> queue;
	queue.push({1, 1});
	border[1][1] = 1;
	queue.push({1, N});
	border[1][N] = 2;
	queue.push({N, 1});
	border[N][1] = 3;
	queue.push({N, N});
	border[N][N] = 4;
	while (!queue.empty())
	{
		int r, c;
		int color = border[y][x];
		tie(r, c) = queue.front(); queue.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = r + dy[dir];
			int nx = c + dx[dir];
			
			if (ny < 1 || ny > N || nx < 1 || nx > N)
				continue;
			if (border[ny][nx] == 5 || border[ny][nx])
				continue ;
			if ((1 <= ny && ny < y + d1) && (1 <= nx && nx <= x))
				border[ny][nx] = 1;
			if ((1 <= ny && ny <= y + d2) && (x < nx && nx <= N))
				border[ny][nx] = 2;
			if ((y + d1 <= ny && ny <= N) && (1 <= nx && nx < x - d1 + d2))
				border[ny][nx] = 3;
			if ((y + d2 < ny && ny <= N) && (x - d1 + d2 <= nx && nx <= N))
				border[ny][nx] = 4;
			queue.push({ny, nx});
		}
	}
//	cout << "city" << '\n';
//	for (int i = 1; i <= N; ++i) 
//	{
//		for (int j = 1; j <= N; ++j) 
//		{
//			cout << border[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
}

void devide_city(int y, int x)
{
	for (int d1 = 1; d1 < 20; ++d1) 
	{
		for (int d2 = 1; d2 < 20; ++d2) 
		{
			memset(border, 0, sizeof(border));
			if (y + d1 > N || x - d1 < 1)
				continue ;
			if (y + d2 > N || x + d2 > N)
				continue ;
			if (y + d1 + d2 > N)
				continue ;
			for (int i = 0; i <= d1; ++i) 
			{
				border[y + i][x - i] = 5;
				border[y + d2 + i][x + d2 - i] = 5;
			}
			for (int i = 0; i <= d2; ++i) 
			{
				border[y + i][x + i] = 5;
				border[y + d1 + i][x - d1 + i] = 5;
			}
			bfs(y, x, d1, d2);
			// 여기에서 갯수세자
			int population[5] = {};
			for (int i = 1; i <= N; ++i) 
			{
				for (int j = 1; j <= N; ++j) 
				{
					if (border[i][j] == 1)
						population[0] += city[i][j];
					else if (border[i][j] == 2)
						population[1] += city[i][j];
					else if (border[i][j] == 3)
						population[2] += city[i][j];
					else if (border[i][j] == 4)
						population[3] += city[i][j];
					else 
						population[4] += city[i][j];
				}
			}
//			cout << "pop\n";
//			for (int i = 0; i < 5; ++i) 
//			{
//				cout << population[i] << ' ';
//			}
//			cout << '\n';
			sort(population, population + 5);
			
			int cnt = population[4] - population[0];
			ans = min(ans, cnt);

		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			cin >> city[i][j];
		}
	}
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = 1; j <= N; ++j) 
		{
			devide_city(i, j);
		}
	}
	cout << ans << '\n';
}
