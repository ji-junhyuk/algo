#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 100000 + 1
using namespace std;

int vertex, edge;
int mst;
int max_cost;
int parent[MAX];
vector<pair<int, pair<int, int>>> vec;

int get_parent(int x)
{
    if (parent[x] == x)
		return x;
    else
		return parent[x] = get_parent(parent[x]);
}

void union_parent(int x, int y)
{
    x = get_parent(x);
    y = get_parent(y);
	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
	vertex--;
}

bool find_parent(int x, int y)
{
    x = get_parent(x);
    y = get_parent(y);

    if (x == y)
                return true;
    else
                return false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> vertex >> edge;
    for (int idx = 0; idx < edge; idx++)
    {
        int from, to, cost;
        cin >> from >> to >> cost;
        vec.push_back(make_pair(cost, make_pair(from, to)));
    }
    sort(vec.begin(), vec.end());
    for (int idx = 1; idx <= vertex; idx++)
        parent[idx] = idx;
    for (int idx = 0; idx < edge; idx++)
    {
        if (find_parent(vec[idx].second.first, vec[idx].second.second) == false)
        {
			max_cost = max(max_cost, vec[idx].first);
            union_parent(vec[idx].second.first, vec[idx].second.second);
            mst += vec[idx].first;
        }
    }
    cout << mst - max_cost;
    return 0;
}
