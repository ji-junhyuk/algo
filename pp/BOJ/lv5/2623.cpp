#include <iostream>
#include <vector>
#include <queue>
#define MAX 1000 + 1
using namespace std;

int N, M;
vector<int> vec_edge[MAX + 1];
int i_in_degree[MAX + 1];

void bfs(void)
{
	queue<int> q;
    for (int idx = 1; idx <= N; ++idx)
    {
		if (!i_in_degree[idx])
			q.push(idx);
	}
	vector<int> vec_ans;
    while (!q.empty())
	{
        int i_cur = q.front();
        q.pop();
		vec_ans.push_back(i_cur);
        for (int idx = 0; idx < (int)vec_edge[i_cur].size(); ++idx)
		{
            --i_in_degree[vec_edge[i_cur][idx]];
            if (!i_in_degree[vec_edge[i_cur][idx]])
				q.push(vec_edge[i_cur][idx]);
        }
    }
	if ((int)vec_ans.size() != N)
		cout << 0;
	else
	{
		for (int idx = 0; idx < (int)vec_ans.size(); ++idx)
			cout << (int)vec_ans[idx] << '\n';
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    cin >> N >> M;
	for (int idx = 0; idx < M; ++idx)
	{
		vector<int> vec_pd;
		int num;
		cin >> num;
		for (int jdx = 0; jdx < num; ++jdx)
		{
			int singer;
			cin >> singer;
			vec_pd.push_back(singer);
		}
		for (int jdx = 0; jdx < (int)vec_pd.size(); ++jdx)
		{
			for (int kdx = jdx + 1; kdx < (int)vec_pd.size(); ++kdx)
			{
				vec_edge[vec_pd[jdx]].push_back(vec_pd[kdx]);
				i_in_degree[vec_pd[kdx]]++;
			}
		}
	}
    bfs();
    return 0;
}
