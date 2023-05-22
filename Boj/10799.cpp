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

	string str;

	cin >> str;
	stack<char> S;

	int cnt = 0;
	char before = 0;
	for (auto c : str)
	{
		if (c == '(')
		{
			S.push(c);
		}
		else if (c == ')')
		{
			if (before == '(')
			{
				S.pop();
				cnt += S.size();
			}
			else if (before == ')')
			{
				S.pop();
				++cnt;
			}
		}
		before = c;
	}
	cout << cnt << '\n';
}
