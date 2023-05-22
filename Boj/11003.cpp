#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, L;

	cin >> N >> L;
	deque<pair<int, int>> Q; // num, index
	for (int i = 0; i < N; ++i) 
	{
		int num;
		cin >> num;

		while (!Q.empty() && Q.back().first >= num)
		{
			Q.pop_back();
		}
		if (!Q.empty() && i - L >= Q.front().second)
			Q.pop_front();
		Q.push_back({num, i});
		cout << Q.front().first << ' ';
	}
}
