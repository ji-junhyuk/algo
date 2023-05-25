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
int arr[8];
int selected[8];

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
	int last = 0;
	for (int i = 0; i < N; ++i) 
	{
		if (arr[i] != last)
		{
			last = arr[i];
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
