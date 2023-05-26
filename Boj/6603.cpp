#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int k;
int arr[50];
bool is_selected[50];
int selected[50];

void	bt(int depth, int start)
{
	if (depth == 6)
	{
		for (int i = 0; i < 6; ++i) 
		{
			cout << selected[i] << ' ';
		}
		cout << '\n';
		return ;
	}
	for (int i = start; i < k; ++i) 
	{
		if (!is_selected[i])
		{
			is_selected[i] = true;
			selected[depth] = arr[i];
			bt(depth + 1, i + 1);
			is_selected[i] = false;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (1)
	{
		cin >> k;
		if (!k)
			break ;
		memset(arr, 0, sizeof(arr));
		memset(is_selected, 0, sizeof(is_selected));
		memset(selected, 0, sizeof(selected));
		for (int i = 0; i < k; ++i) 
		{
			cin >> arr[i];
		}
		bt(0, 0);
		cout << '\n';
	}
}
