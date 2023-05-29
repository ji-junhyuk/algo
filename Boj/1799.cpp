#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N;
int chess[10][10];
int white, black;
bool is_visited[10][10];

vector<pair<int, int>> V;

bool is_possible(int y, int x)
{
	int ny = y;
	int nx = x;
	while (1)
	{
		if (ny < 0 || nx < 0)
			break ;
		if (is_visited[ny][nx])
		{
			return false;
		}
		ny--;
		nx--;
	}
	ny = y;
	nx = x;
	while (1)
	{
		if (ny < 0 || nx >= N)
			break ;
		if (is_visited[ny][nx])
		{
			return false;
		}
		ny--;
		nx++;
	}
	return true;
}

void find_black(int start, int cnt)
{
	black = max(black, cnt);
	for (int i = start; i < V.size(); ++i) 
	{
		int y = V[i].first;
		int x = V[i].second;
		if (y % 2 == 0 && x % 2 == 1)
			continue ;
		if (y % 2 == 1 && x % 2 == 0)
			continue ;
		if (!is_visited[y][x] && is_possible(y, x))
		{
			is_visited[y][x] = true;
			find_black(i + 1, cnt + 1);
			is_visited[y][x] = false;
		}
	}
}

void find_white(int start, int cnt)
{
	white = max(white, cnt);

	for (int i = start; i < V.size(); ++i) 
	{
		int y = V[i].first;
		int x = V[i].second;
		if (y % 2 == 0 && x % 2 == 0)
			continue ;
		if (y % 2 == 1 && x % 2 == 1)
			continue ;
		if (!is_visited[y][x] && is_possible(y, x))
		{
			is_visited[y][x] = true;
			find_white(i + 1, cnt + 1);
			is_visited[y][x] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		for (int j = 0; j < N; ++j) 
		{
			cin >> chess[i][j];
			if (chess[i][j] == 1)
				V.push_back({i, j});;
		}
	}
	int ans = 0;
	find_black(0, 0);
	find_white(0, 0);
	ans = white + black;
	cout << ans << '\n';
}
