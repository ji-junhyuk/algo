#include <bits/stdc++.h>

#define INF 987654321
using namespace std;


int n, m; 
int Start, End;
int dist[1001];
int route[1001];//route[1] = 2, 1번 도시로 가기위해선 최소 2번 도시에서 와야 한다.
vector<pair<int, int>> v[1001];

void dijkstra(int Start)
{
	dist[Start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({Start, 0});

	while (!pq.empty())
	{
		int cur = pq.top().first;
		int cost = -pq.top().second;

		pq.pop();
		for (int idx = 0; idx < v[cur].size(); ++idx)
		{
			int next = v[cur][idx].first;
			int ncost = v[cur][idx].second + cost;

			if (ncost < dist[next])
			{
				dist[next] = ncost;
				pq.push({next, -ncost});
				route[next] = cur;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	for (int idx = 1; idx <= n; idx++)
		dist[idx] = INF;
	for (int idx = 0; idx < m; idx++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int flag = 1;
		for (int idx = 0; idx < v[a].size(); idx++)
		{
			if (v[a][idx].first == b)
			{
				flag = 0;
				if (v[a][idx].second > c)
					v[a][idx].second = c;
				break ;
			}
		}
		if (flag)
			v[a].push_back({b, c});
	}
	cin >> Start >> End;

	dijkstra(Start);

	cout << dist[End] << '\n';
	vector<int> route_back;
	int node = End;
	while (node)
	{
		route_back.push_back(node);
		node = route[node];
	}
	cout << route_back.size() << '\n';
	for (int idx = route_back.size() - 1; idx >= 0; --idx)
		cout << route_back[idx] << ' ';
}
