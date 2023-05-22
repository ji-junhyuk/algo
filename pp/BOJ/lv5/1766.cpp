#include <iostream>
#include <vector>
#include <queue>
#define MAX 32000 + 1
using namespace std;

int N, M;
vector<int> vec_edge[MAX + 1];
int i_in_degree[MAX + 1];

void bfs(void)
{
	priority_queue<int, vector<int>, greater<int>> pq; //meanheap
    for (int idx = 1; idx <= N; ++idx)
    {
		if (!i_in_degree[idx])
			pq.push(idx);
	}
    while (!pq.empty())
	{
        int i_cur = pq.top();
        pq.pop();
        cout << i_cur << ' ';
        for (int idx = 0; idx < (int)vec_edge[i_cur].size(); ++idx)
		{
            --i_in_degree[vec_edge[i_cur][idx]];
            if (!i_in_degree[vec_edge[i_cur][idx]])
				pq.push(vec_edge[i_cur][idx]);
        }
    }
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N >> M;
    for (int idx = 0; idx < M; ++idx)
	{
        int from, to;
        cin >> from >> to;
        vec_edge[from].push_back(to);
        i_in_degree[to]++;
    }
    bfs();
    return 0;
}
