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

	int arr[1000001] = {};
	int numbers[1000001] = {};
	int n;
	int x;
	cin >> n;
	for (int i = 1; i <= n; ++i) 
	{
		int num;
		cin >> num;
		arr[num]++;
		numbers[i] = num;
	}
	cin >> x;
	int count = 0;
	for (int i = 1; i <= n; ++i) 
	{
		if (numbers[i] >= x || numbers[i] * 2 == x)
			continue;
		else
		{
			if (arr[x - numbers[i]])
			{
				++count;
				arr[numbers[i]] = 0;
				arr[x - numbers[i]] = 0;
			}
		}
	}
	cout << count;

}
