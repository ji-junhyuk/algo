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

	stack<char>S;
	string str;
	cin >> str;
	bool is_valid = true;
	int mult = 1;
	int ans = 0;
	char before = 0;

	for (auto c : str)
	{
		if (c == '(')
		{
			S.push(c);
			mult *= 2;
		}
		else if (c == '[')
		{
			S.push(c);
			mult *= 3;
		}
		else if (c == ')')
		{
			if (S.empty() || S.top() != '(')
			{
				is_valid = false;
				break ;
			}
			if (before == '(')
				ans += mult;
			mult /= 2;
			S.pop();
		}
		else if (c == ']')
		{
			if (S.empty() || S.top() != '[')
			{
				is_valid = false;
				break ;
			}
			if (before == '[')
				ans += mult;
			mult /= 3;
			S.pop();
		}
		before = c;
	}
	if (!S.empty())
		is_valid = false;
	if (is_valid)
	{
		cout << ans << '\n';
	}
	else
	{
		cout << 0 << '\n';
	}
}
