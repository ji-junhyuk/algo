#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int dice[4][3];

void rotate_south()
{
	int temp[4][3] = {};
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			temp[i][j] = dice[i][j];
		}
	}
	dice[0][1] = temp[1][1];
	dice[1][1] = temp[2][1];
	dice[2][1] = temp[3][1];
	dice[3][1] = temp[0][1]; 
}

void rotate_north()
{
	int temp[4][3] = {};
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			temp[i][j] = dice[i][j];
		}
	}
	dice[0][1] = temp[3][1];
	dice[1][1] = temp[0][1];
	dice[2][1] = temp[1][1];
	dice[3][1] = temp[2][1]; 
}
void rotate_east()
{
	int temp[4][3] = {};
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			temp[i][j] = dice[i][j];
		}
	}
	dice[1][0] = temp[1][1];
	dice[1][1] = temp[1][2];
	dice[1][2] = temp[3][1];
	dice[3][1] = temp[1][0]; 
}
//  2
//4 1 3
//  5
//  6
//  서쪽
//  2(X)
//6  4  1
//   5(X)
//   3
void rotate_west()
{
	int temp[4][3] = {};
	for (int i = 0; i < 4; ++i) 
	{
		for (int j = 0; j < 3; ++j) 
		{
			temp[i][j] = dice[i][j];
		}
	}
	dice[1][0] = temp[3][1];
	dice[1][1] = temp[1][0];
	dice[1][2] = temp[1][1];
	dice[3][1] = temp[1][2]; 
}
// 주사위 상단 [3][1]
// 주사위 하단 [1][1]
//  2
//4 1 3
//  5
//  6
// 남쪽으로 굴렸을 때
//   1
// 4 5 3
//   6
//   2
//
// 북쪽
//  6
//4(X) 2 3(X)
//  1
//  5
//
// 동쪽
//  2(X)
//1 3 6  
//  6(X)
//  4
//
//  서쪽
//  2(X)
//6  4  1
//   5(X)
//   3
int map[20][20];
// 3이 남쪽, 2북쪽 1은 서쪽 0 동쪽ㅓ
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, y, x, k;
	cin >> N >> M >> y >> x >> k;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < k; ++i) 
	{
		int dir;
		cin >> dir;
		y += dy[dir - 1];
		x += dx[dir - 1];
		if (y >= N || y < 0 || x >= M || x < 0)
		{
			y -= dy[dir - 1];
			x -= dx[dir - 1];
			continue ;
		}
//		cout << "y: " << y << " x: " << x << '\n';
		if (dir == 4)
		{
			rotate_south();
		}
		else if (dir == 3)
		{
			rotate_north();
		}
		else if (dir == 2)
		{
			rotate_west();
		}
		else
		{
			rotate_east();
		}
		if (map[y][x] == 0)
			map[y][x] = dice[1][1];
		else
		{
			dice[1][1] = map[y][x];
			map[y][x] = 0;
		}
		cout << dice[3][1] << '\n'; // 0
//		cout << "dice\n";
//		for (int idx = 0; idx < 4; ++idx) 
//		{
//			for (int jdx = 0; jdx < 3; ++jdx) 
//			{
//				cout << dice[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
	}
}
