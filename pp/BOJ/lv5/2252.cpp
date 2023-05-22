#include <iostream>
#include <vector>
#include <queue>
#define MAX 32000
using namespace std;

int N, M;
vector<int> vec_edge[MAX + ];
int i_in_degree[MAX + 1];

void bfs(void) 
{
    queue<int> q;
    for (int idx = 1; idx <= N; ++idx)
	{
        if (!i_in_degree[idx])
            q.push(idx);
	}
    while (!q.empty()) 
	{
        int i_cur = q.front();
        q.pop();
        cout << i_cur << ' ';
        for (int idx = 0; idx < vec_edge[i_cur].size(); ++idx) 
		{
            i_in_degree[vec_edge[i_cur][idx]]--;
            if (!i_in_degree[vec_edge[i_cur][idx]])
                q.push(vec_edge[i_cur][idx]);
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

