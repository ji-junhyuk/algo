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
bool is_selected[9];
int	selected[9];

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
	int start = 1;
	if (depth)
		start = selected[depth - 1] + 1;
	for (int i = start; i <= N; ++i) 
	{
		selected[depth] = i;
		bt(depth + 1);
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	bt(0);
}
