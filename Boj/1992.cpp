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
string dat[64];

bool	is_one_color(int N, int y, int x)
{
	char c = dat[y][x];
	for (int i = y; i < N + y; ++i) 
	{
		for (int j = x; j < N + x; ++j) 
		{
			if (dat[i][j] != c)
				return false;
		}
	}
	return (true);
}

void	recur(int N, int y, int x)
{
	if (is_one_color(N, y, x))
	{
		cout << dat[y][x];
		return ;
	}
	cout << '(';
	int half = N / 2;
	recur(half, y, x);
	recur(half, y, x + half);
	recur(half, y + half, x);
	recur(half, y + half, x + half);
	cout << ')';
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> dat[i];
	}
	recur(N, 0, 0);
}
