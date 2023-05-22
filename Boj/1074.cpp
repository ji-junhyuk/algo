#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int	recur(int N, int r, int c)
{
	if (N == 0)
		return 0;
	int half = (1 << N) / 2;
	if (r < half && c < half)
	{
		return recur(N - 1, r, c);
	}
	else if (r < half && c >= half)
	{
		return half * half + recur(N - 1, r, c - half);
	}
	else if (r >= half && c < half)
	{
		return (2 * half * half) + recur(N - 1, r - half, c);
	}
	else
	{
		return (3 * half * half) + recur(N - 1, r - half, c - half);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, r, c;

	cin >> N >> r >> c;
	cout << recur(N, r, c) << '\n';
}
