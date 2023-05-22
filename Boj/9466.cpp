#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int n;
int student[100001];
int state[100001];
int not_visited = 0;
int is_visited = 1;
int is_cycle = 2;
int not_cycle = 3;

void	check_cycle(int x)
{
	int cur = x;
	while (1)
	{
		state[cur] = is_visited;
		cur = student[cur];
		if (state[cur] == is_cycle || state[cur] == not_cycle)
		{
			// 언제까지 not_cycle?
			// 재방문할 때까지.
			//not_cycle;
//			int now = student[cur];
//			cur = x;
//			while (cur != now)
//			{
//				state[cur] = not_cycle;
//				cur = student[cur];
//			}
			cur = x;
			while (state[cur] == is_visited)
			{
				state[cur] = not_cycle;
				cur = student[cur];
			}
			return ;
		}
		else if (state[cur] == is_visited && cur != x)
		{
			// 1. 재방문을 하고 나서부터는 is_cycle
			// 2. 재방문하기 전까지 not_cycle
			while (state[cur] != is_cycle)
			{
				state[cur] = is_cycle;
				cur = student[cur];
			}
			cur = x;
			while (state[cur] != is_cycle)
			{
				state[cur] = not_cycle;
				cur = student[cur];
			}
			return ;
		}
		else if (state[cur] == is_visited && cur == x)
		{
			while (state[cur] != is_cycle)
			{
				state[cur] = is_cycle;
				cur = student[cur];
			}
			return ;
		}
	}
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		memset(student, 0, sizeof(student));
		memset(state, 0, sizeof(state));
		for (int i = 1; i <= n; ++i) 
		{
			cin >> student[i];
		}
		for (int i = 1; i <= n; ++i) 
		{
			if (state[i] == not_visited)
				check_cycle(i);
		}
		int count = 0;
		for (int i = 1; i <= n; ++i) 
		{
			if (state[i] == not_cycle)
				++count;
		}
		cout << count << '\n';

	}
}
