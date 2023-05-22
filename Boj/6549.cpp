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

	while (1)
	{
		int N;
		cin >> N;
		if (N == 0)
			break ;

		stack<pair<long long, long long>> S; // height, idx
		long long ans = 0;
		for (int i = 0; i < N; ++i) 
		{
			int height;

			cin >> height;
			int idx = i;
			while (!S.empty() && S.top().first >= height)
			{
				ans = max(ans, (i - S.top().second) * S.top().first);
				idx = S.top().second;
				S.pop();
			}
			S.push({height, idx}); 
		}
		while (!S.empty())
		{
			ans = max(ans, (N - S.top().second) * S.top().first);
			S.pop();
		}
		cout << ans << '\n';
	}

}
