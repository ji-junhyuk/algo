#include <iostream>
# define MAX 500000
using namespace std;

int G, P;
int i_ans;
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

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> G >> P;

	for (int idx = 1; idx <= G; ++idx)
		i_parent[idx] = idx;
	while (P--)
	{
		int i_g;
		cin >> i_g;
		int next_doking = get_parent(i_g);
		if (next_doking != 0)
		{
			union_parent(next_doking, next_doking - 1);
			i_ans++;
		}
		else
			break;
	}
	cout << i_ans;
}
