#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


// rotate 2차원 평면
int maze[5][5][5];
int copy_maze[5][5][5];
int copy_maze2[5][5][5];
int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};
int min_dist = 0x7fffffff;

void rotate(int index)
{
	int temp[5][5];
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			temp[i][j] = copy_maze2[index][i][j];
		}
	}
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			copy_maze2[index][j][5 - 1 - i] = temp[i][j];
		}
	}
}

void bfs()
{
	if (copy_maze2[0][0][0] == 0)
		return ;
	if (copy_maze2[4][4][4] == 0)
		return ;
	int dist[5][5][5];
	memset(dist, -1, sizeof(dist));
	queue<tuple<int, int, int>> Q;
	Q.push({0, 0, 0});
	dist[0][0][0] = 0;
	while (!Q.empty())
	{
		int z, y, x;
		tie(z, y, x) = Q.front(); Q.pop();
		if (z == 4 && y == 4 && x == 4)
		{
			min_dist = min(dist[4][4][4], min_dist);
			return ;
		}
		if (dist[z][y][x] > min_dist)
			return ;
		for (int dir = 0; dir < 6; ++dir) 
		{
			int nz = z + dz[dir];
			int ny = y + dy[dir];
			int nx = x + dx[dir];
			if (nz < 0 || nz >= 5 || ny < 0 || ny >= 5 || nx < 0 || nx >= 5)
				continue ;
			if (dist[nz][ny][nx] != -1 || copy_maze2[nz][ny][nx] == 0)
				continue ;
			dist[nz][ny][nx] = dist[z][y][x] + 1;
			Q.push({nz, ny, nx});
		}
	}
}
//!!! 아.. 조합이 있구나 이판을 쌓는 순서가 달라질 수 있구나..
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	// 판의조합
	// 0(정면) 1(오른쪽으로 회전) 2(오른쪽으로 2번 회전) 3
	// 경우의 수 4^5
	//  2 << (2 * 5)
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			for (int k = 0; k < 5; ++k) 
			{
				cin >> maze[i][j][k];
			}
		}
	}
	
	int arr[5] = {0, 1, 2, 3, 4};
	do {
		for (int idx = 0; idx < 5; ++idx) 
		{
			for (int jdx = 0; jdx < 5; ++jdx) 
			{
				for (int kdx = 0; kdx < 5; ++kdx) 
				{
					copy_maze[arr[idx]][jdx][kdx] = maze[idx][jdx][kdx];
				}
			}
		}
		for (int tom = 0; tom < 2 << (2 * 5); ++tom) 
		{
			for (int idx = 0; idx < 5; ++idx) 
			{
				for (int jdx = 0; jdx < 5; ++jdx) 
				{
					for (int kdx = 0; kdx < 5; ++kdx) 
					{
						copy_maze2[idx][jdx][kdx] = copy_maze[idx][jdx][kdx];
					}
				}
			}
			int num = tom;
			for (int j = 0; j < 5; ++j) 
			{
				int ro = num % 4;
				while (--ro >= 0)
					rotate(j);
				num /= 4;
			}
			bfs();
		}
	} while (next_permutation(arr, arr + 5));
	if (min_dist == 0x7fffffff)
		cout << -1 << '\n';
	else
		cout << min_dist << '\n';
}
