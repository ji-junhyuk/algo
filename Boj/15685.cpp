#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

// 문제에서 말하는 x,y좌표가 내가 쓰는 좌표와 달라서 많이 헤멤
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
int grid[101][101];
void dragon_curve(int y, int x, int dir, int depth)
{
	int d = dir;
	int now = 0;
	deque<int> direct;
	direct.push_front(d);
	int direct_size;
	for (int i = 1; i <= depth; ++i) 
	{
		direct_size = direct.size();
		int cnt = 0;
		for (int j = 0; j < direct_size; ++j) 
		{
			direct.push_front((direct[j + cnt] + 1) % 4);
			++cnt;
		}
	}
	direct_size = direct.size();
	grid[y][x] = 1;
	for (int i = direct_size - 1; i >= 0; --i) 
	{
		y += dy[direct[i]];
		x += dx[direct[i]];
		grid[y][x] = 1;
	}
}
int N;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		int y, x, dir, depth;
		cin >> x >> y >> dir >> depth;
		dragon_curve(y, x, dir, depth);
	}
	int cnt = 0;
	for (int i = 0; i < 101; ++i) 
	{
		for (int j = 0; j < 101; ++j) 
		{
			if (grid[i][j] == 1 && grid[i][j + 1] == 1 
					&& grid[i + 1][j] == 1 && grid[i + 1][j + 1] == 1)
				++cnt;
		}
	}
	cout << cnt << '\n';
}
