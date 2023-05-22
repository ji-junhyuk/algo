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

	int n;
	cin >> n;
	stack<int> S;
	queue<char> cmd;
	int top = 0;
	bool flag = true;
	for (int i = 0; i < n; ++i) 
	{
		int num;
		cin >> num;
		if (top < num)
		{
			top += 1;
			while (top <= num)
			{
				S.push(top++);
				cmd.push('+');
//				cout << "push: " << top - 1 << '\n';
			}
			top = S.top(); // 6
//			cout << "top: " << top << '\n';
			cmd.push('-');
			S.pop(); // 5
		}
		else // top >= num
		{
			if (S.top() != num)
			{
//				cout << S.top() << ' ' << num << '\n';
				flag = false;
				break ;
			}
			if (!S.empty())
			{
//				cout << "before pop, top: " << S.top() << '\n';
				S.pop();
				cmd.push('-');
			}
		}
	}
	if (flag)
	{
		while (!cmd.empty())
		{
			cout << cmd.front() << '\n';
			cmd.pop();
		}
	}
	else
		cout << "NO";
}
