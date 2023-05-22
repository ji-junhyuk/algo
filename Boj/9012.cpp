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

	int T;
	cin >> T;
	while (T--)
	{
		string str;
		cin >> str;
		stack<char> S;
		bool is_valid = true;
		for (auto c : str)
		{
			if (c == '(')
			{
				S.push('(');
			}
			else if (c == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					is_valid = false;
					break ;
				}
				S.pop();
			}
		}
		if (!S.empty())
			is_valid = false;
		if (is_valid)
		{
			cout << "YES" << '\n';
		}
		else 
			cout << "NO" << '\n';
	}
}
