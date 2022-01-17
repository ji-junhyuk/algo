#include <bits/stdc++.h>
using namespace std;

vector<int> connected[1001];
int visited[1001];
int cnt;

void dfs(int n)
{
	visited[n] = 1;
	for (int idx = 0; idx < connected[n].size(); idx++)
	{
		int next = connected[n][idx];
		if (!visited[next])
			dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; // 정점, 간선

	cin >> N >> M;
	for (int idx = 0; idx < M; idx++)
	{
		int u, v;
		cin >> u >> v;
		connected[u].push_back(v);
		connected[v].push_back(u);
		//same 2matrix
	}
	for (int idx = 1; idx <= N; idx++)
	{
		if (!visited[idx])
		{
			cnt++;
			dfs(idx);
		}
	}
	cout << cnt;
}
