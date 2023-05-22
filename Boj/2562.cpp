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

	int arr[9];
	int max = -1;
	int sequence = -1;
	for (int i = 0; i < 9; ++i) 
	{
		cin >> arr[i];
		if (max < arr[i])
		{
			max = arr[i];
			sequence = i + 1;
		}
	}
	cout << max << '\n' << sequence << '\n';
}
