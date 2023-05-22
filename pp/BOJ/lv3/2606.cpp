#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited[101];
queue<int> q;

int dfs(int v, int N)
{
	int cnt;

	cnt = 0;
	visited[v] = 1;
	q.push(v);
	while (!q.empty())
	{
		v = q.front();
		q.pop();
		for (int idx = 1; idx <= N; idx++)
		{
			if (visited[idx] == 0 && board[v][idx] == 1)
			{
				q.push(idx);
				visited[idx] = 1;
				cnt++;
			}
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int network;

	cin >> N >> network;
	for (int idx = 0; idx < network; idx++)
	{
		int x, y;
		cin >> x >> y;
		board[x][y] = 1;
		board[y][x] = 1;
	}
	cout << dfs(1, N);
}
