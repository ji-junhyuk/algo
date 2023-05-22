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

	int N;
	int arr[100] = {};
	cin >> N;
	for (int i = 0; i < N; ++i) 
	{
		cin >> arr[i];
	}
	int v;
	cin >> v;
	int count = 0;
	for (int i = 0; i < N; ++i) 
	{
		if (arr[i] == v)
			++count;
	}
	cout << count;
}
