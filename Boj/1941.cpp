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
int cnt;

pair<int, int>selected[25];
pair<int, int>coord[25];
bool is_selected[25];

bool	is_connected(int depth, int i) // 지금 보고 있는 점이랑 selected[depth]에 있는점이랑...
{
	if (!depth)
		return true;
	if (abs(coord[depth - 1].first - coord[i].first) <= 1 && 
			abs(coord[depth - 1].second - coord[i].second) <= 1)
		return true;
	return false;
}

void	bt(int depth, int S, int Y)
{
	if (depth == 7)
	{
		if (S >= 4 && Y >= 1)
		{
			++cnt;
		}
		return ;
	}
	if (Y > 3)
		return ;
	for (int i = 0; i < 25; ++i) 
	{
		if (!is_selected[i] && is_connected(depth, i))
		{
			int s = 0;
			int y = 0;
			is_selected[i] = true;
			selected[depth] = coord[i];
			if (cr[coord[i].first][coord[i].second] == 'Y')
			{
				y = 1;
			}
			else
			{
				s = 1;
			}
			S += s;
			Y += y;
			bt(depth + 1, S, Y);
			is_selected[i] = false;
			S -= s;
			Y -= y;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 5; ++i) 
	{
		cin >> cr[i];
	}
	for (int i = 0; i < 5; ++i) 
	{
		for (int j = 0; j < 5; ++j) 
		{
			coord[i * 5 + j] = {i, j};
		}
	}
	bt(0, 0, 0);
	cout << cnt << '\n';
}
