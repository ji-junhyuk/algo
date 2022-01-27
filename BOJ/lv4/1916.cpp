#include <bits/stdc++.h>
#define INF INT_MAX
using namespace std;

int dist[1001];
vector<pair<int, int>> v[100001];

void dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({dist[start], start});
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int distance = -pq.top().first;
		pq.pop();
		if (dist[cur] < distance)
			continue;
		for (int idx = 0; idx < v[cur].size(); idx++)
		{
			int next = v[cur][idx].first;
			int nextDistance = distance + v[cur][idx].second;
			if (nextDistance < dist[next])
			{
				dist[next] = nextDistance;
				pq.push({-nextDistance, next});
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	cin >> N >> M;
	for (int idx = 1; idx <= N; idx++)
		dist[idx] = INF;
	for (int idx = 0; idx < M; idx++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	int start, end;
	cin >> start >> end;
	dijkstra(start);
	cout << dist[end];
}
