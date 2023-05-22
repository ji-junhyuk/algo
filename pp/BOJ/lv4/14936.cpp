#include <iostream>
using namespace std;

#define INF 987654321

int n, m, r, t ;
int a, b, l;
int dist[101][101];
int item[101];
int item_count;
int max_item;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m >> r;
	for (int idx = 1; idx <= n; ++idx)
	{
		for (int jdx = 1; jdx <= n; ++jdx)
		{
			if (idx != jdx)
				dist[idx][jdx] = INF;
		}
	}
	for (int idx = 1; idx <= n; ++idx)
		cin >> item[idx];
	for (int idx = 0; idx < r; ++idx)
	{
		cin >> a >> b >> l;
		dist[a][b] = l;
		dist[b][a] = l;
	}
	for (int kdx = 1; kdx <= n; ++kdx)
	{
		for (int idx = 1; idx <= n; ++idx)
		{
			for (int jdx = 1; jdx <= n; ++jdx)
			{
				if (dist[idx][kdx] + dist[kdx][jdx] < dist[idx][jdx])
					dist[idx][jdx] = dist[idx][kdx] + dist[kdx][jdx];
			}
		}
	}
	for (int idx = 1; idx <= n; ++idx)
	{
		item_count = item[idx];
		for (int jdx = 1; jdx <= n; ++jdx)
		{
			if (idx != jdx && dist[idx][jdx] <= m)
				item_count += item[jdx];
		}
		max_item = max(max_item, item_count);
	}
	cout << max_item;
}
