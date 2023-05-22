#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;

int F, S, G, U, D;
bool visited[1000001];
queue<pair<int, int>> Q;


void bfs()
{
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.first == G)
		{
			cout << cur.second << '\n';
			return ;
		}
		if (cur.first + U <= F && !visited[cur.first + U])
		{
			visited[cur.first + U] = 1;
			Q.push({cur.first + U, cur.second + 1});
		}
		if (cur.first - D >= 1 && !visited[cur.first - D])
		{
			visited[cur.first - D] = 1;
			Q.push({cur.first - D, cur.second + 1});
		}
	}
	cout << "use the stairs" << '\n';
}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> F >> S >> G >> U >> D;
	visited[S] = 1;
	Q.push({S, 0});
	bfs();
}
