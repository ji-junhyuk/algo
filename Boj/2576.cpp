#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int arr[7];
	int score = 0;
	int last = 0x7fffffff;
	for (int i = 0; i < 7; ++i) 
	{
		cin >> arr[i];
		if (arr[i] % 2)
		{
			if (last > arr[i])
				last = arr[i];
			score += arr[i];
		}
	}
	if (last == 0x7fffffff)
	{
		cout << -1 << '\n';
		return (0);
	}
	cout << score << '\n' << last << '\n';
}
