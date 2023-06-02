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
int board[20][20];
int copy_board[20][20];
int ans = 0;

void rotate_board()
{
//	cout << "rotate\n";
	int temp[20][20];
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			temp[i][j] = copy_board[i][j];
		}
	}
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			copy_board[j][N - 1 - i] = temp[i][j];
		}
	}
}

void tilt(int rotate)
{
	while (--rotate >= 0)
	{
		rotate_board();
	}
	for (int i = 0; i < N; ++i) 
	{
		int temp[20] = {};
		int idx = 0;
		for (int j = 0; j < N; ++j) 
		{
			if (copy_board[i][j] == 0)
			{
				continue ;
			}
			if (temp[idx] == 0)
			{
				temp[idx] = copy_board[i][j];
				continue ;
			}
			if (copy_board[i][j] == temp[idx])
			{
				temp[idx++] *= 2;
			}
			else
			{
				temp[++idx] = copy_board[i][j];
			}
		}
		for (int j = 0; j < N; ++j) 
		{
			copy_board[i][j] = temp[j];
		}
	}
//	cout << '\n';
//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			cout << copy_board[i][j] << ' ';
//		}
//		cout << '\n';
//	}
//	cout << '\n';
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
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < (1 << 2 * 5); ++i) 
	{
		/* copy */
		for (int i = 0; i < N; ++i) 
		{
			for (int j = 0; j < N; ++j) 
			{
				copy_board[i][j] = board[i][j];
			}
		}
		int brute = i;
		for (int j = 0; j < 5; ++j) 
		{
			tilt(brute % 4);
			brute /= 4;
		}
		for (int n = 0; n < N; ++n) 
		{
			for (int m = 0; m < N; ++m) 
			{
				ans = max(ans, copy_board[n][m]);
			}
		}
	}
	cout << ans;

//	for (int i = 0; i < N; ++i) 
//	{
//		for (int j = 0; j < N; ++j) 
//		{
//			copy_board[i][j] = board[i][j];
//		}
//	}
//	tilt(4);
}
