#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; ++i) 
	{
		for (int j = i; j < N; ++j) 
		{
			cout << " ";
		}
		for (int j = 1; j <= i * 2 - 1; ++j) 
		{
			cout << "*";
		}
		cout << '\n';
	}
}
