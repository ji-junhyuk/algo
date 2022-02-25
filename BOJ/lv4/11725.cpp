#include <iostream>
#include <vector>
# define MAX 100001
using namespace std;

int N;
bool visited[MAX];
int parent[MAX];
vector<int> tree[MAX];

void dfs(int node)
{
	visited[node] = true;

	for (int idx = 0; idx < tree[node].size(); idx++)
	{
		int next = tree[node][idx];
		if (!visited[next])
		{
			parent[next] = node;
			dfs(next);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N - 1; idx++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(1);
	for (int idx = 2; idx <= N; idx++)
		cout << parent[idx] << '\n';
}
