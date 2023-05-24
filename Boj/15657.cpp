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

int selected[8];
int arr[8];

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
	int start = 0;
	if (depth)
		start = selected[depth - 1];
	for (int i = 0; i < N; ++i) 
	{
		if (start <= arr[i])
		{
			selected[depth] = arr[i];
			bt(depth + 1);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	bt(0);
}
