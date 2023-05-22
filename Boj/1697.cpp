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
int is_visited[200001];
queue<pair<int, int>> Q; //sumin, time

void bfs()
{
	Q.push({N, 0});
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.first == K)
		{
			cout << cur.second;
			break ;
		}
		if (cur.first + 1 <= 100000 && !is_visited[cur.first + 1])
		{
			is_visited[cur.first + 1] = 1;
			Q.push({cur.first + 1, cur.second + 1});
		}
		if (cur.first * 2 <= 200000 && !is_visited[cur.first * 2])
		{
			is_visited[cur.first * 2] = 1;
			Q.push({cur.first * 2, cur.second + 1});
		}
		if (cur.first - 1 >= 0 && !is_visited[cur.first - 1])
		{
			is_visited[cur.first - 1] = 1;
			Q.push({cur.first - 1, cur.second + 1});
		}
	}

}
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> K;
	bfs();
}
