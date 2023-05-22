#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

void hanoi(int N, int start, int end)
{
	if (N == 1)
	{
		cout << start << ' ' << end << '\n';
		return ;
	}
	int center = 6 - end - start;
	hanoi(N - 1, start, center);
	cout << start << ' ' << end << '\n';
	hanoi(N - 1, center, end);
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	cout << (1 << N) - 1 << '\n';
	hanoi(N, 1, 3);
}
