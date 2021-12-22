#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int result[101];
int connect[101];
int visited[101];

void bfs(int a, int N)
{
	queue<int> Q;
	Q.push(a);
	visited[a] = 1;

	while (!Q.empty())
	{
		int x = Q.front();
		Q.pop();

		for (int idx = 1; idx <= N; idx++)
		{
			if (board[x][idx] == 1 && visited[idx] == 0)
			{
				visited[idx] = 1;
				Q.push(idx);
				connect[idx] = connect[x] + 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; //유저의 수, 친구관계의 수

	cin >> N >> M;
	for (int idx = 0; idx < M; idx++)
	{
		int a, b;
		cin >> a >> b;
		board[a][b] = 1;
		board[b][a] = 1;
	}
	for (int idx = 1; idx <= N; idx++)
	{
		bfs(idx, N);
		for (int jdx = 1; jdx <= N; jdx++)
			result[idx] = result[idx] + connect[jdx];
		memset(visited, 0, sizeof(visited));
		memset(connect, 0, sizeof(connect));
	}
	int ans = result[1];
	int min_person = 1;
	for (int idx = 2; idx <= N; idx++)
	{
		if (ans > result[idx])
		{
			ans = result[idx];
			min_person = idx;
		}
	}
	ans = min_person;
	cout << ans << '\n';
}
