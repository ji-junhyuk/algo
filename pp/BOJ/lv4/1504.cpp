#include <bits/stdc++.h>
using namespace std;
#define MAX INT_MAX

/*
   s->v1->v2->N
   s->v2->v1->N
*/

int N, E;
int v1, v2;
int sToV1, sToV2, v1ToV2, v1ToN, v2ToN;
vector<pair<int, int>> v[801];
int dist[801];
int ret = MAX;

void dijkstra(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for (int idx = 0; idx <= N; idx++)
		dist[idx] = MAX;
	dist[start] = 0;
	q.push({0, start});
	while (!q.empty())
	{
		int cur = q.top().second;
		int curDist = q.top().first;
		q.pop();
		for (int idx = 0; idx < v[cur].size(); idx++)
		{
			int next = v[cur][idx].first;
			int nextDist = v[cur][idx].second;
			if (dist[next] > curDist + nextDist)
			{
				dist[next] = curDist + nextDist;
				q.push({dist[next], next});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> E;
	while (E--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}
	cin >> v1 >> v2;
	dijkstra(1);
	sToV1 = dist[v1];
	sToV2 = dist[v2];
	dijkstra(v1);
	v1ToV2 = dist[v2];
	v1ToN = dist[N];
	dijkstra(v2);
	v2ToN = dist[N];

	ret = min(ret, sToV1 + v1ToV2 + v2ToN);
	ret = min(ret, sToV2 + v1ToV2 + v1ToN);
	if (v1ToV2 == MAX || ret == MAX)
		cout << -1;
	else
		cout << ret;
}
