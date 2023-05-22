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

	int N;
	cin >> N;
	stack<pair<long, long>> basis;
	stack<pair<long, long>> ans;

	for (int i = 0; i < N; ++i) 
	{
		int building;
		cin >> building;
		basis.push({building, 0});
	}
	long long real_ans = 0;
	for (int i = 0; i < N; ++i) 
	{
		int top = basis.top().first;
		long long count = 0;
		if (!ans.empty())
		{
			while (!ans.empty() && ans.top().first < top)
			{
				count += ans.top().second;
				ans.pop();
				++count;
			}
			real_ans += count;
		}
		basis.pop();
		ans.push({top, count});
	}
	cout << real_ans;
}
