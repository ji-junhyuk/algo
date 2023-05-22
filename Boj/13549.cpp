#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int N, K;
int is_visited[100001];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	queue<pair<int, int>> Q; // locate, time
	Q.push({N, 0});
	is_visited[N] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
//		cout << cur.first << ' ' << cur.second << '\n';
		if (cur.first == K)
		{
			cout << cur.second << '\n';
			break ;
		}
		if (cur.first * 2 <= 100000 && !is_visited[cur.first * 2])
		{
			is_visited[cur.first * 2] = 1;
			Q.push({cur.first * 2, cur.second});
		}
		if (cur.first - 1 >= 0 && !is_visited[cur.first - 1])
		{
			is_visited[cur.first - 1] = 1;
			Q.push({cur.first - 1, cur.second + 1});
		}
		if (cur.first + 1 <= 100000 && !is_visited[cur.first + 1])
		{
			is_visited[cur.first + 1] = 1;
			Q.push({cur.first + 1, cur.second + 1});
		}
	}
}
