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
	int cnt = 0;
	for (int i = 0; i < N; ++i) 
	{
		stack<char> S;
		string str;
		cin >> str;
		for (int i = 0; i < str.size(); ++i) 
		{
			if (str[i] == 'A' || str[i] == 'B')
			{
				if (!S.empty() && str[i] == 'A')
				{
					if (S.top() == 'A')
					{
						S.pop();
						continue ;
					}
				}
				else if (!S.empty() && str[i] == 'B')
				{
					if (S.top() == 'B')
					{
						S.pop();
						continue ;
					}
				}
			}
			S.push(str[i]);

		}
//		cout << "S.size: " << S.size() << '\n';
		if (S.empty())
			++cnt;
	}
	cout << cnt << '\n';
}
