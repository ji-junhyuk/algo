#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M, H;

int map[32][11];
bool is_visited[32][11];
vector<pair<int, int>> bridge;

bool check_bridge()
{
	for (int col = 1; col <= N; ++col) 
	{
		int start_x = col;
		for (int i = 1; i <= H; ++i) 
		{
			if (map[i][start_x])
				++start_x;
			else if (map[i][start_x - 1])
				--start_x;
		}
		if (start_x != col) 
			return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 0; i < M; ++i) 
	{
		int y, x;
		cin >> y >> x;
		map[y][x] = 1;
	}
	for (int i = 1; i <= H; ++i)
	{
		for (int j = 1; j < N; ++j) 
		{
			if (map[i][j] == 1 || map[i][j - 1] == 1 || map[i][j + 1] == 1)
				continue ;
			bridge.push_back({i, j});
		}
	}
	
	if (check_bridge())
	{
		cout << 0 << '\n';
		return 0;
	}
	int ans = 0x7fffffff;
	int size = bridge.size();
	for (int i = 0; i < size; ++i) 
	{
		map[bridge[i].first][bridge[i].second] = 1;
//		for (int idx = 0; idx <= H + 1; ++idx) 
//		{
//			for (int jdx = 0; jdx <= N; ++jdx) 
//			{
//				cout << map[idx][jdx] << ' ';
//			}
//			cout << '\n';
//		}
//		cout << '\n';
		if (check_bridge())
		{
			ans = min(ans, 1);
		}
		for (int j = i + 1; j < size; ++j) 
		{
			map[bridge[j].first][bridge[j].second] = 1;
			if (check_bridge())
				ans = min(ans, 2);
			for (int k = j + 1; k < size; ++k) 
			{
				map[bridge[k].first][bridge[k].second] = 1;
				if (check_bridge())
					ans = min(ans, 3);
				map[bridge[k].first][bridge[k].second] = 0;
			}
			map[bridge[j].first][bridge[j].second] = 0;
		}
		map[bridge[i].first][bridge[i].second] = 0;
	}
	if (ans == 0x7fffffff)
	{
		cout << -1 << '\n';
		return 0;
	}
	cout << ans << '\n';
}
