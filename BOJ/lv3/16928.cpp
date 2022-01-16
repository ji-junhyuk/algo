#include <bits/stdc++.h>
using namespace std;

int board[101];
int cnt[101];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; 

	cin >> N >> M;
	for (int idx = 1; idx <= 100; idx++)
	{
		board[idx] = idx;
		cnt[idx] = -1;
	}
	for (int idx = 0; idx < N + M; idx++)
	{
		int x, y;
		cin >> x >> y;
		board[x] = y;
	}
	cnt[1] = 0;
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int idx = 1; idx <= 6; idx++)
		{
			int y = x + idx;
			if (y > 100)
				continue;
			y = board[y];
			if (cnt[y] == -1)
			{
				cnt[y] = cnt[x] + 1;
				q.push(y);
			}
		}
	}
	cout << cnt[100];
}
