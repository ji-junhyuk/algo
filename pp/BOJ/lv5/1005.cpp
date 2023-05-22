#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
# define MAX 1001
using namespace std;

int T, N, K, W;
int i_time[MAX];
int i_complete_time[MAX];
int i_in_degree[MAX];
vector<int> vec_edge[MAX];

void bfs()
{
    queue<int> q;
    for (int idx = 1; idx <= N; idx++)
    {
        if (i_in_degree[idx] == 0)
        {
            q.push(idx);
            i_complete_time[idx] = i_time[idx];
        }
    }
    while (!q.empty())
    {
        int i_cur = q.front();
        q.pop();
        for (int idx = 0; idx < vec_edge[i_cur].size(); idx++)
        {
            int i_next = vec_edge[i_cur][idx];
            i_complete_time[i_next] = max(i_complete_time[i_next], i_complete_time[i_cur] + i_time[i_next]);
            i_in_degree[i_next]--;
            if (i_in_degree[i_next] == 0)
                                q.push(i_next);
        }
    }
    cout << i_complete_time[W] << '\n';
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> T;
	while (T--)
	{
		memset(i_time, 0, sizeof(i_time));
		memset(i_complete_time, 0, sizeof(i_complete_time));
		memset(i_in_degree, 0, sizeof(i_in_degree));
		for (int idx = 0; idx < MAX; idx++)
				vec_edge[idx].clear();
		cin >> N >> K;
		for (int idx = 1; idx <= N; idx++) cin >> i_time[idx];
		for (int idx = 0; idx < K; idx++)
		{
			int from, to;
			cin >> from >> to;
			vec_edge[from].push_back(to);
			i_in_degree[to]++;
		}
		cin >> W;
		bfs();
	}
	return 0;
}
