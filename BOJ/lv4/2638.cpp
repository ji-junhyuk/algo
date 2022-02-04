#include <bits/stdc++.h>
using namespace std;

int board[101][101];
int visited[101][101];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<pair<pair<int, int>, bool>> V;
vector<pair<int, int>> C;
queue<pair<int, int>> A;
int N, M;

int	no_cheese()
{
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < M; jdx++)
		{
			if (board[idx][jdx] == 1)
				return 0;
		}
	}
	return 1;
}

void	find_cheese()
{
	for (int idx = 0; idx < V.size(); idx++)
	{
		if (V[idx].second == 1)
			continue;
		int x = V[idx].first.first;
		int y = V[idx].first.second;
		int cnt = 0;
		for (int jdx = 0; jdx < 4; jdx++)
		{
			int nx = x + dx[jdx];
			int ny = y + dy[jdx];
			if (board[nx][ny] == 0 && visited[nx][ny] == 1)
				cnt++;
		}
		if (cnt >= 2)
		{
			C.push_back({x, y});
			V[idx].second = 1;
		}
	}
}

void melt_cheese()
{
	for (int idx = 0; idx < C.size(); idx++)
	{
		int x = C[idx].first;
		int y = C[idx].second;
		board[x][y] = 0;
		A.push({x, y});
	}
}

void merge_air()
{
	while (!A.empty())
	{
		int x = A.front().first;
		int y = A.front().second;
		A.pop();
		visited[x][y] = 1;
		for (int idx = 0; idx < 4; idx++)
		{
			int nx = x + dx[idx];
			int ny = y + dy[idx];
			if (visited[nx][ny] == 0)
			{
				visited[nx][ny] = 1;
				A.push({nx, ny});
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < M; jdx++)
		{
			cin >> board[idx][jdx];
			if (board[idx][jdx] == 1)
			{
				V.push_back({{idx, jdx}, 0});
				visited[idx][jdx] = -1;
			}
		}
	}
	// 외부공기와 내부공기 나누기.
	queue<pair<int, int>> Q;
	Q.push({0, 0});
	visited[0][0] = 1;

	while (!Q.empty())
	{
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int idx = 0; idx < 4; idx++)
		{
			int nx = x + dx[idx];
			int ny = y + dy[idx];
			if (nx >= 0 && ny >= 0 && nx < N && ny < M)
			{
				if (visited[nx][ny] == 0)
				{
					visited[nx][ny] = 1;
					Q.push({nx, ny});
				}
			}
		}
	}
	visited[0][0] = 1;
	
	int time = 0;
	while (1)
	{
		if (no_cheese() == 1)
			break;
		find_cheese();
		melt_cheese();
		merge_air();
		time++;
	}
	cout << time;
}
