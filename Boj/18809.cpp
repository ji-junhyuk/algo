#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M, G, R;
int land[50][50];
vector<pair<int, int>> L;
int brute[10];
int ans = 0;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

int bfs()
{
	int cnt = 0;
	pair<int, int> state[50][50]; // arrive, color
	queue<pair<int, int>> Q; 
	for (int i = 0; i < L.size(); ++i) 
	{
		if (brute[i] == GREEN || brute[i] == RED)
		{
			state[L[i].first][L[i].second] = {0, brute[i]};
			Q.push(L[i]);
		}
	}

	while (!Q.empty())
	{
		auto cur = Q.front(); Q.pop();
		int curtime = state[cur.first][cur.second].first;
		int curcolor = state[cur.first][cur.second].second;
		if (state[cur.first][cur.second].second == FLOWER)
			continue ;
		for (int dir = 0; dir < 4; ++dir) 
		{
			int ny = cur.first + dy[dir];
			int nx = cur.second + dx[dir];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M)
				continue ;
			if (land[ny][nx] == 0)
				continue ;
			if (state[ny][nx].second == GREEN)
			{
				if (curcolor == RED && state[ny][nx].first == curtime + 1)
				{
					++cnt;
					state[ny][nx].second = FLOWER;
				}
			}
			else if (state[ny][nx].second == RED)
			{
				if (curcolor == GREEN && state[ny][nx].first == curtime + 1)
				{
					++cnt;
					state[ny][nx].second = FLOWER;
				}
			}
			else if (state[ny][nx].second == EMPTY)
			{
				state[ny][nx] = {curtime + 1, curcolor};
				Q.push({ny, nx});
			}
		}
	}
	return cnt;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> G >> R;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < M; ++j) 
		{
			cin >> land[i][j];
			if (land[i][j] == 2)
			{
				L.push_back({i, j});
			}
		}
	}
	fill(brute + L.size() - G, brute + L.size(), GREEN);
	fill(brute + L.size() - G - R, brute + L.size() - G, RED); 
	do {
		ans = max(ans, bfs());
	} while (next_permutation(brute, brute + L.size()));
	cout << ans << '\n';
}
