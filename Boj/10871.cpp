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

	int N, X;
	int num;
	cin >> N >> X;
	for (int i = 0; i < N; ++i) 
	{
		cin >> num;
		if (num < X)
			cout << num << ' ';
	}
}
