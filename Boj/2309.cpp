#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int dwarf[9];
int selected[9];
bool visited[9];

void dfs(int depth, int score, int before)
{
	if (depth == 7)
	{
		if (score == 100)
		{
			int k = 0;
			for (int i = 0; i < 9; ++i) 
			{
				if (visited[i])
				{
					selected[k] = dwarf[i];
					++k;
				}
			}
			return ;
		}
	}
	for (int i = before; i < 9; ++i) 
	{
		visited[i] = true;
		dfs(depth + 1, score + dwarf[i], i + 1);
		visited[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; ++i) 
	{
		cin >> dwarf[i];
	}
	sort(dwarf, dwarf + 9);
	dfs(0, 0, 0);
	sort(selected, selected + 7);
	for (int i = 0; i < 7; ++i) 
	{
		cout << selected[i] << '\n';
	}
}
