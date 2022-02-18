#include <bits/stdc++.h>
using namespace std;

int ans;
int visited[100001];
int	find_min_second(int N, int End)
{
	queue<pair<int, int>> q;

	q.push({N, 0});
	visited[N] = 1;
	while (!q.empty())
	{
			int Start = q.front().first;
			int Time = q.front().second;
			q.pop();
			if (Start == End)
			{
					ans = Time;
					break ;
			}
			if (Start * 2 < 100001 && !visited[Start * 2])
			{
					q.push({Start * 2, Time});
					visited[Start * 2] = 1;
			}
			if (Start - 1 >= 0 && !visited[Start - 1])
			{
					q.push({Start - 1, Time + 1});
					visited[Start - 1] = 1;
			}
			if (Start + 1 < 100001 && !visited[Start + 1])
			{
					q.push({Start + 1, Time + 1});
					visited[Start + 1] = 1;
			}
	}
	return ans;
}

int main(void)
{
        ios::sync_with_stdio(false);
        cin.tie(0);

        int N, K;
        cin >> N >> K;
        cout << find_min_second(N, K);
}
