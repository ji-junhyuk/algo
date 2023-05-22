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
	stack<int> basis;
	stack<int> ans;
	stack<int> S;
	for (int i = 0; i < N; ++i) 
	{
		int num;
		cin >> num;
		basis.push(num);
	}
	while (!basis.empty())
	{
		int top = basis.top();
		if (!S.empty())
		{
			while (!S.empty())
			{
				if (S.top() > top)
				{
					ans.push(S.top());
					break ;
				}
				S.pop();
			}
			if (S.empty())
				ans.push(-1);
			S.push(top);
			basis.pop();
		}
		else
		{
			ans.push(-1);
			S.push(top);
			basis.pop();
		}
//		cout << "top: " << top << "ans.top(): " << ans.top() << '\n';
	}
	while (!ans.empty())
	{
		cout << ans.top() << ' ';
		ans.pop();
	}


}
