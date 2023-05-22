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

	int K;
	cin >> K;
	stack<int> S;
	while (K--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (!S.empty())
			{
				S.pop();
			}
		}
		else
			S.push(x);
	}
	int sum = 0;
	while (!S.empty())
	{
		sum += S.top();
		S.pop();
	}
	cout << sum;
}
