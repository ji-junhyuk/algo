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
int arr[10];
bool isused[10];

void	bt(int depth)
{
	if (depth == M)
	{
		for (int i = 0; i < M; ++i) 
		{
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = 1; i <= N; ++i) 
	{
		if (!isused[i])
		{
			arr[depth] = i;
			isused[i] = 1;
			bt(depth + 1);
			isused[i] = 0;
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
