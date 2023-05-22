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
		stack<char> S;
		string str;
		getline(cin, str);
		if (str == ".")
		{
			break ;
		}
		bool is_correct = true;
		for (int i = 0; i < str.size(); ++i) 
		{
			if (str[i] == '(' || str[i] == '[')
				S.push(str[i]);
			else if (str[i] == ')')
			{
				if (S.empty() || S.top() != '(')
				{
					is_correct = false;
					break ;
				}
				S.pop();
			}
			else if (str[i] == ']')
			{
				if (S.empty() || S.top() != '[')
				{
					is_correct = false;
					break ;
				}
				S.pop();
			}
		}
		if (!S.empty())
		{
			is_correct = false;
		}
		if (is_correct)
			cout << "yes" << '\n';
		else 
			cout << "no" << '\n';
	}
}
