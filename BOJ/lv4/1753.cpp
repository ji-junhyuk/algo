#include <bits/stdc++.h>
using namespace std;
#define MAX 20001
#define INF INT_MAX

int V, E, Start;
int Dist[MAX];
vector<pair<int, int>> Vec[MAX];

void dijkstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({0, Start});
	Dist[Start] = 0;
	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		for (int idx = 0; idx < Vec[cur].size(); idx++)
		{
			int next = Vec[cur][idx].first;
			int nCost = Vec[cur][idx].second;
			if (Dist[next] > cost + nCost)
			{
				Dist[next] = cost + nCost;
				pq.push({-Dist[next], next});
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> V >> E >> Start;
	for (int idx = 0; idx < E; idx++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		Vec[a].push_back({b, c});
	}
	for (int idx = 1; idx <= V; idx++)
		Dist[idx] = INF;
	dijkstra();
	for (int idx = 1; idx <= V; idx++)
	{
		if (Dist[idx] == INF)
			cout << "INF" << '\n';
		else
			cout << Dist[idx] << '\n';
	}
}
