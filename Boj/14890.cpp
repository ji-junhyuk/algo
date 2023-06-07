#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, L;
int map[100][100];

bool check_row(int row)
{
	int flat = 1;
	for (int col = 1; col < N; ++col) 
	{
		int diff = map[row][col] - map[row][col - 1];
		if (diff > 1 || diff < -1)
			return false;
		if (diff > 0) // 현재것이 더 큼
		{
			if (flat < L)
				return false;
			flat = 1;
		}
		else if (diff < 0) // 3 3 2 2 2 3
		{
			// 2, 3 < 4
			// 2, 3 < 3
			if (col + L > N)
				return false;
			for (int i = col + 1; i < col + L; ++i) 
			{
				if (map[row][col] != map[row][i])
					return false;
			}
			col += L - 1;
			flat = 0;
		}
		else
			++flat;
	}
	return true;
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> L;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> map[i][j];
		}
	}
	
	int cnt = 0;
	for (int i = 0; i < N; ++i) 
	{
		cnt += check_row(i);
	}
	int copy[100][100] = {};
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			copy[i][j] = map[i][j];
		}
	}
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			map[j][N - 1 - i] = copy[i][j];
		}
	}
	for (int i = 0; i < N; ++i) 
	{
		cnt += check_row(i);
	}
	cout << cnt << '\n';
}
