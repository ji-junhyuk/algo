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
int cnt;
bool is_col[14];
bool is_diag1[43];
bool is_diag2[43];

void	bt(int row)
{
	if (row == N)
	{
		++cnt;
		return ;
	}
	for (int col = 0; col < N; ++col) 
	{
		if (!is_col[col] && !is_diag1[row + col] && !is_diag2[N - row + col])
		{
			is_col[col] = 1;
			is_diag1[row + col] = 1;
			is_diag2[N - row + col] = 1;
			bt(row + 1);
			is_col[col] = 0;
			is_diag1[row + col] = 0;
			is_diag2[N - row + col] = 0;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N; // 4
	bt(0); // row
	cout << cnt << '\n';
}
