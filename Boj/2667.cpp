#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string map[25];
int N;
bool visited[25][25];
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, 1, -1};
queue<pair<int, int>> Q;
vector<int> V;

void bfs()
{
	int count = 0;
	while (!Q.empty())
	{
		++count;
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)
				continue ;
			if (map[ny][nx] == '0' || visited[ny][nx])
				continue ;
			visited[ny][nx] = 1;
			Q.push({ny, nx});
		}
	}
	V.push_back(count);
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> map[i];
	}
	int count = 0;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			if (map[i][j] == '1' && !visited[i][j])
			{
				++count;
				visited[i][j] = 1;
				Q.push({i, j});
				bfs();
			}
		}
	}
	sort(V.begin(), V.end());
	cout << count << '\n';
	for (int i = 0; i < V.size(); ++i) 
	{
		cout << V[i] << '\n';
	}
}
