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
	long long ans = 0;
	
	cin >> N;
	stack<pair<long long, long long>> S;
	for (int i = 0; i < N; ++i) 
	{
		long long height;
		cin >> height;
		long long cnt = 1;
		while (!S.empty() && S.top().first <= height)
		{
			if (S.top().first == height)
				cnt += S.top().second;
			ans += S.top().second;
			S.pop();
		}
		if (!S.empty())
			++ans;
		S.push({height, cnt});
	}
	cout << ans;
}
