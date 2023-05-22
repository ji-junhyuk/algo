#include <bits/stdc++.h>
using namespace std;

int cnt;
int min_second;
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
		visited[Start] = 1;
		if (min_second && min_second == Time && Start == End)
			cnt++;
		if (!min_second && Start == End)
		{
			min_second = Time;
			cnt++;
		}
		if (Start + 1 < 100001 && !visited[Start + 1])
			q.push({Start + 1, Time + 1});
		if (Start - 1 >= 0 && !visited[Start - 1])
			q.push({Start - 1, Time + 1});
		if (Start * 2 < 100001 && !visited[Start * 2])
			q.push({Start * 2, Time + 1});
	}
	return (min_second);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	cin >> N >> K;
	cout << find_min_second(N, K) << '\n';
	cout << cnt << '\n';
}
