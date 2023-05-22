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
	stack<pair<int,int>> towers;
	int tower;
	cin >> tower;
	towers.push({tower, 1});
	queue<int> ans;
	ans.push(0);
	
	for (int i = 2; i <= N; ++i) 
	{
		cin >> tower;
		bool is_searched = true;
		while (!towers.empty())
		{
			if (tower > towers.top().first)
			{
				towers.pop();
			}
			else
			{
				ans.push(towers.top().second);
				break ;
			}
			if (towers.empty())
				ans.push(0);
		}
		towers.push({tower, i});
	}

	while (!ans.empty())
	{
		cout << ans.front() << ' ';
		ans.pop();
	}
}
