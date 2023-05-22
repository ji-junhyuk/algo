#include <bits/stdc++.h>
using namespace std;

/*
bfs: 너비우선탐색, 가장 가까운 곳들을 먼저 탐색하고 그 다음 거리에 있는 것들을 탐색하는 방법.
dfs를 사용하게 되면 -1 +1 때문에 시간초과일 것.
*/
int visited[100001];

void bfs(int N, int K)
{
	queue<pair <int, int>> q;
	//q.push(make_pair(N, 0));
	//q.push({N,0});
	q.emplace(N, 0);
	visited[N] = 1;

	while (!q.empty())
	{
		int locate = q.front().first;
		int time = q.front().second;
		q.pop();
		if (locate == K)
		{
			cout << time;
			break;
		}
		if (locate + 1 < 100001 && !visited[locate + 1])
		{
			//q.push(make_pair(locate + 1, time + 1));
			//q.push({locate + 1, time + 1});
			q.emplace(locate + 1, time + 1);
			visited[locate + 1] = 1;
		}
		if (locate - 1 >= 0 && !visited[locate - 1])
		{
			//q.push(make_pair(locate - 1, time + 1));
			//q.push({locate - 1, time + 1});
			q.emplace(locate - 1, time + 1);
			visited[locate - 1] = true;
		}
		if (locate * 2 < 100001 && !visited[locate * 2])
		{
			//q.push(make_pair(locate * 2, time + 1));
			//q.push({locate * 2, time + 1});
			q.emplace(locate * 2, time + 1);
			visited[locate * 2] = 1;
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, K; // 수빈이 위치, 동생 위치
	
	cin >> N >> K;
	bfs(N, K);
}
