#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


int dist[1'000'001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;
	memset(dist, -1, sizeof(dist));
	queue<int> Q;
	for (int i = 0; i < M; ++i) 
	{
		int num;
		cin >> num;
		dist[num] = 0;
		Q.push(num);
	}
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int next;
		for (int j = 0; j < 31; ++j) 
		{
			if (cur & (1 << j))
			{
				next = cur & ~(1 << j);
			}
			else
			{
				next = cur | (1 << j);
			}
			if (next > N)
				continue ;
			if (dist[next] >= 0)
				continue ;
			dist[next] = dist[cur] + 1;
			Q.push({next});
		}
	}
	int ans = 0;
	for (int i = 0; i <= N; ++i)
	{
		ans = max(ans, dist[i]);
	}
	cout << ans << '\n';
}
