#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, M;
int selected[10];
bool is_selected[10];

void	bt(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i) 
		{
			cout << selected[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= N; ++i) 
	{
		if (!is_selected[i])
		{
			is_selected[i] = true;
			selected[depth] = i;
			bt(depth + 1);
			is_selected[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	bt(0);
}

