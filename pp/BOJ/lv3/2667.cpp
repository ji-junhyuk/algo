#include <bits/stdc++.h>
using namespace std;

int board[26][26];
int visited[26][26];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
vector<int> v;

int cnt;
void dfs(int x, int y, int N)
{
	cnt++;
	visited[x][y] = 1;
	for (int idx = 0; idx < 4; idx++)
	{
		int nx = x + dx[idx];
		int ny = y + dy[idx];
		if (nx < 0 || ny >= N || ny < 0 || ny >= N)
			continue;
		if (board[nx][ny] == 1 && visited[nx][ny] == 0)
			dfs(nx, ny, N);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	for (int idx = 0; idx < N; idx++)
	{
		string temp;
		cin >> temp;
		for (int jdx = 0; jdx < N; jdx++)
			board[idx][jdx] = temp[jdx] - '0';
	}
	for (int idx = 0; idx < N; idx++)
	{
		for (int jdx = 0; jdx < N; jdx++)
		{
			if (board[idx][jdx] == 1 && visited[idx][jdx] == 0)
			{
				cnt = 0;
				dfs(idx, jdx, N);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << '\n';
	for (int idx = 0; idx < v.size(); idx++)
		cout << v[idx] << '\n';
}

