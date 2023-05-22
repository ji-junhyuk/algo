#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int paper[128][128];
int cnt[2]; // 0 white, 1 blue

bool	is_one_color(int N, int y, int x)
{
	char c = paper[y][x];
	for (int i = y; i < N + y; ++i) 
	{
		for (int j = x; j < N + x; ++j) 
		{
			if (paper[i][j] != c)
				return false;
		}
	}
	return true;
}

void	recur(int N, int y, int x)
{
	if (is_one_color(N, y, x))
	{
		cnt[paper[y][x]]++;
		return ;
	}
	int half = N / 2;
	recur(half, y, x);
	recur(half, y, x + half);
	recur(half, y + half, x);
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
		for (int j = 0; j < N; ++j) 
		{
			cin >> paper[i][j];
		}
	}
	recur(N, 0, 0);
	cout << cnt[0] << '\n' << cnt[1] << '\n';
}
