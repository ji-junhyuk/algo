#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N;
int matrix[2187][2187];

int cnt[3];
/*
 * -1: cnt[0];
 * 0 : cnt[1];
 * 1 : cnt[2];
 */
bool	is_one_color(int N, int y, int x)
{
	char c = matrix[y][x];
	for (int i = y; i < N + y; ++i) 
	{
		for (int j = x; j < N + x; ++j) 
		{
			if (matrix[i][j] != c)
				return false;
		}
	}
	return (true);
}

void recur(int N, int y, int x)
{
	if (is_one_color(N, y, x))
	{
		cnt[matrix[y][x] + 1]++;
		return ;
	}
	int half = N / 3;
	recur(N / 3, y, x);
	recur(N / 3, y, x + half);
	recur(N / 3, y, x + 2 * half);
	recur(N / 3, y + half, x + 0);
	recur(N / 3, y + half, x + 0 + half);
	recur(N / 3, y + half, x + 0 + 2 * half);
	recur(N / 3, y + 2 * half, x + 0);
	recur(N / 3, y + 2 * half, x + 0 + half);
	recur(N / 3, y + 2 * half, x + 2 * half);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> matrix[i][j];
		}
	}
	recur(N, 0, 0);
	for (int i = 0; i < 3; ++i) 
	{
		cout << cnt[i] << '\n';
	}
}
