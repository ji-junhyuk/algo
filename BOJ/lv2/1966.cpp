#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int cnt;
	int T;
	int N, M, ipt;

	cin >> T;
	while (T--)
	{
		cnt = 0;
		cin >> N >> M;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		for (int idx = 0; idx < N; idx++)
		{
			cin >> ipt;
			q.push({idx, ipt});
			pq.push(ipt);
		}
		while (!q.empty())
		{
			int index = q.front().first;
			int q_ipt = q.front().second;
			q.pop();
			if (pq.top() == q_ipt)
			{
				pq.pop();
				cnt++;
				if (index == M)
				{
					cout << cnt << '\n';
					break;
				}
			}
			else
				q.push({index, q_ipt});
		}
	}
}
