#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

string cr[5];
bool selected[25] = {};
int cnt;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void get_input()
{
	for (int i = 0; i < 5; ++i) 
	{
		cin >> cr[i];
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	get_input();
	pair<int, int> arr[25];
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			arr[i * 5 + j] = {i, j};
		}
	}
	fill(selected + 7, selected + 25, 1);
	do {
		int Y = 0;
		int S = 0;
		int is_first = 1;
		queue<pair<int, int>> Q;
		bool is_visited[5][5] = {};
		bool is_checked[5][5] = {};
		for (int i = 0; i < 25; ++i) 
		{
			if (Y > 3)
				break ;
			if (!selected[i])
			{
				int y = arr[i].first;
				int x = arr[i].second;
				if (cr[y][x] == 'Y')
				{
					++Y;
				}
				else
					++S;
				if (is_first == 1)
				{
					is_first = 0;
					Q.push({y, x});
					is_visited[y][x] = 1;
				}
				is_checked[y][x] = 1;
			}
		}
		int connected_number = 0;;
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			++connected_number;
			for (int dir = 0; dir < 4; ++dir) 
			{
				int ny = cur.first + dy[dir];
				int nx = cur.second + dx[dir];
				if (ny < 0 || ny > 4 || nx < 0 || nx > 4)
					continue ;
				if (is_visited[ny][nx] || !is_checked[ny][nx])
					continue ;
				is_visited[ny][nx] = 1;
				Q.push({ny, nx});
			}
		}
		if (S > 3 && S > 0 && connected_number == 7)
			++cnt;
	} while (next_permutation(selected, selected + 25));
	cout << cnt << '\n';
}
