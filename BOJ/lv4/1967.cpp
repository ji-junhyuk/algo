#include <bits/stdc++.h>
using namespace std;

int N, max_node, max_dist;
vector<pair<int, int>> v1[10001];
int visited[10001];

void dfs(int cur, int dist) 
{
	if (visited[cur]) 
		return;
	if (max_dist < dist) 
	{
		max_dist = dist;
		max_node = cur;
	}
	visited[cur] = 1;
	for (int x = 0; x < v1[cur].size(); x++) 
	{
		int n_cur = v1[cur][x].first;
		int n_dist = v1[cur][x].second + dist;
		dfs(n_cur, n_dist);
	}
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a, b, c;
	cin >> N;
	for (int idx = 0; idx < N-1; idx++)
	{
		cin >> a >> b >> c;
		v1[a].push_back({b, c});
		v1[b].push_back({a, c});
	}
	dfs(1, 0);
	memset(visited, 0, sizeof(visited));
	max_dist = 0;
	dfs(max_node, 0);
	cout << max_dist;
	return 0;
}
