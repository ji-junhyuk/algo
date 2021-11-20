#include <bits/stdc++.h>
using namespace std;

int cnt[3];
int arr[2187][2187];
int check(int x, int y, int z)
{
	int idx;
	int jdx;

	idx = x - 1;
	while (++idx < x + z)
	{
		jdx = y - 1;
		while (++jdx < y + z)
			if (arr[x][y] != arr[idx][jdx])
				return 0;
	}
	return 1;
}

void find(int x, int y, int z)
{
	int n;
	int idx;
	int jdx;

	if (check(x, y, z))
	{
		cnt[arr[x][y] + 1] += 1;
		return ;
	}
	n = z / 3;
	idx = -1;
	while (++idx < 3)
	{
		jdx = -1;
		while (++jdx < 3)
			find(x + idx * n, y + jdx * n, n);
	}
}

int main()
{
	int N;
	int idx;
	int jdx;

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		while (++jdx < N)
			cin >> arr[idx][jdx];
	}
	find(0, 0, N);
	idx = -1;
	while (++idx < 3)
		cout << cnt[idx] << '\n';
	return (0);
}
