#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

char rect[2200][2200];

// 3 -> 1, 1 만 스페이스
// 9 -> 4 ~ 6 만 스페이스
// 27 -> 10 ~ 18만 스페이스

void	draw(int N, int y, int x)
{
	int c_y = 1 + y;
	int c_x = 1 + x;
	
	for (int i = y; i < N + y; ++i) 
	{
		for (int j = x; j < N + x; ++j) 
		{
			if (i == c_y && j == c_x)
				rect[i][j] = ' ';
			else
				rect[i][j] = '*';
		}
	}
}

void	recur(int N, int y, int x)
{
	if (N == 3)
	{
		draw(N, y, x);
		return ;
	}
	int third = N / 3;
	recur(third, y, x);
	recur(third, y, x + third);
	recur(third, y, x + 2 * third);
	recur(third, y + third, x);
	recur(third, y + third, x + 2 * third);
	recur(third, y + 2 * third, x);
	recur(third, y + 2 * third, x + third);
	recur(third, y + 2 * third, x + 2 * third);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		fill(rect[i], rect[i] + N, ' ');
	}
	recur(N, 0, 0);
	
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cout << rect[i][j];
		}
		cout << '\n';
	}
}
// N - 3
// ***
// * *
// ***
//
// N - 9
// *********
// * ** ** * 
// *********
// ***   ***
// * *   * *
// ***   ***
// *********
