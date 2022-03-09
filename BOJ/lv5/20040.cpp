#include <iostream>
# define MAX 500000
using namespace std;

int i_n, i_m;
int i_gen_cycle;
int i_parent[MAX];

int get_parent(int i_x)
{
	if (i_parent[i_x] == i_x)
		return i_x;
	else
		return i_parent[i_x] = get_parent(i_parent[i_x]);
}

void union_parent(int i_x, int i_y)
{
	i_x = get_parent(i_x);
	i_y = get_parent(i_y);
	if (i_x < i_y)
		i_parent[i_y] = i_x;
	else
		i_parent[i_x] = i_y;
}

bool find_same_parent(int i_x, int i_y)
{
	i_x = get_parent(i_x);
	i_y = get_parent(i_y);
	if (i_x == i_y)
		return true;
	else
		return false;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> i_n >> i_m;

	for (int idx = 0; idx < i_n; ++idx)
		i_parent[idx] = idx;
	for (int idx = 0; idx < i_m; ++idx)
	{
		int from, to;
		cin >> from >> to;
		if (find_same_parent(from, to) == true)
		{
			i_gen_cycle = idx + 1;
			break;
		}
		union_parent(from, to);
	}
	cout << i_gen_cycle;
}
