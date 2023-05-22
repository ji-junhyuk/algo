#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[21];
int temp[21];

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 21; ++i) 
	{
		arr[i] = i;
	}
	for (int i = 0; i < 10; ++i) 
	{
		int start, end;
		cin >> start >> end;
		for (int j = start; j <= end; ++j) 
		{
			temp[j] = arr[j];
		}
		int k = start;
		for (int j = end; j >= start; --j) 
		{
			arr[k++] = temp[j];
		}
	}
	for (int i = 1; i < 21; ++i) 
	{
		cout << arr[i] << ' ';
	}
}
