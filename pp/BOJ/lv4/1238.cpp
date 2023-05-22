#include <bits/stdc++.h>
using namespace std;

#define INF INT_MAX
int N, M, X;
int dist[1001], res[1001];
vector<pair<int, int>> v[1001];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({0, start});
	while (!pq.empty())
	{
		int cost = -pq.top().first; // 최소힙 사용
		int cur = pq.top().second;
		pq.pop();
		for (int idx = 0; idx < v[cur].size(); idx++)
		{
			int nx = v[cur][idx].first;
			int ny = v[cur][idx].second;
			if (dist[nx] > cost + ny)
			{
				dist[nx] = cost + ny;
				pq.push({-dist[nx], nx});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M >> X;
	for (int idx = 0; idx < M; idx++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
	}
	for (int idx = 1; idx <= N; idx++)
	{
		for (int jdx = 1; jdx <= N; jdx++)
			dist[jdx] = INF;
		dijkstra(idx);
		res[idx] = dist[X];
	}
	for (int jdx = 1; jdx <= N; jdx++)
		dist[jdx] = INF;
	dijkstra(X);
	for (int idx = 1; idx <= N; idx++)
		res[idx] = res[idx] + dist[idx];
	sort(res + 1, res + N + 1);
	cout << res[N];;
}
