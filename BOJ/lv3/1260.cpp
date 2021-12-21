#include <bits/stdc++.h>
using namespace std;

/*
   bfs는 파고들고
   dfs는 찍먹느낌
*/
int board[1001][1001];
int visited[1001];
queue<int> q;

void dfs(int v, int n)
{
	visited[v] = 1;
	cout << v << " ";

	for (int idx = 1; idx <= n; idx++)
	{
		if (board[v][idx] == 1 && visited[idx] == 0)
			dfs(idx, n);
	}
}

void bfs(int v, int n)
{
	q.push(v);
	visited[v] = 1;
	cout << v << " ";
	while (!q.empty())
	{
		v = q.front();
		q.pop();

		for (int idx = 1; idx <= n; idx++)
		{
			if (board[v][idx] == 1 && visited[idx] == 0)
			{
				q.push(idx);
				visited[idx] = true;
				cout << idx << " ";
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, V; // 정점 수, 간선 수, 시작하는 정점

	cin >> N >> M >> V;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}
	dfs(V, N);
	cout << '\n';
	for (int idx = 0; idx <= N; idx++)
		visited[idx] = 0;
	bfs(V, N);
}
