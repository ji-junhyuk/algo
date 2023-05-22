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
	for (int i = 0; i < N; ++i) 
	{
		for (int j = i; j < N - 1; ++j) 
		{
			cout << " ";
		}
		for (int j = 0; j < i + 1; ++j) 
		{
			cout << "*";
		}
		cout << '\n';
	}
}
