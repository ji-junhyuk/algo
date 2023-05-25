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
bool is_selected[8];

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
	int last = 0;
	for (int i = 0; i < N; ++i) 
	{
		if (!is_selected[i] && arr[i] >= start && arr[i] != last)
		{
			is_selected[i] = 1;
			start = arr[i];
			last = arr[i];
			selected[depth] = arr[i];
			bt(depth + 1);
			is_selected[i] = 0;
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