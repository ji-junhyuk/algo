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
	
	cin >> N;

	for (int i = 1; i <= N; ++i) 
	{
		for (int j = i; j <= N - 1; ++j) 
		{
			cout << " ";
		}
		for (int j = 1; j <= 2 * i - 1; ++j) 
		{
			cout << "*";
		}
		cout << '\n';
	}
	for (int i = 1; i <= N - 1; ++i) 
	{
		for (int j = 1; j <= i; ++j) 
		{
			cout << " ";
		}
		for (int j = 1; j <= (N - i) * 2 - 1; ++j) 
		{
			cout << "*";
		}
		cout << '\n';
	}
}
