#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

char map[3072][3072 * 2];

void	recur(int N, int y, int x)
{
	if (N == 3)
	{
		map[y][x] = '*';
		map[y + 1][x - 1] = '*';
		map[y + 1][x + 1] = '*';
		for (int i = 0; i < 5; ++i) 
		{
			map[y + 2][x - 2 + i] = '*';
		}
		return ;
	}
	int half = N >> 1;
	recur(half, y, x);
	recur(half, y + half, x - half);
	recur(half, y + half, x + half);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		fill(map[i], map[i] + 2 * N, ' ');
	}
	recur(N, 0, N - 1);
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < 2 * N; ++j) 
		{
			cout << map[i][j];
		}
		cout << '\n';
	}
}

// N이 24일땐 밑변이 48인 삼각형 1개
// 밑변이 24인 삼각형 3개를 만든다.
//
// N이 12일땐 밑변이 24인 삼각형 1개
// 밑변이 12인 삼각형 12개를 만든다.
//
// N이 6일땐 밑변이 12인 삼각형 1개
// 밑변이 6인 삼각형 3개
//
// N이 3일땐 삼각형 1개를 만든다.
//
