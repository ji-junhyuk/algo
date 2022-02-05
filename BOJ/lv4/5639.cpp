#include <bits/stdc++.h>
using namespace std;

int	node[1000001][2];

void post_order(int root)
{
	if (node[root][0] != 0)
		post_order(node[root][0]);
	if (node[root][1] != 0)
		post_order(node[root][1]);
	if (root != -1)
		cout << root << '\n';	
}

void pre_order(int cur, int root)
{
	if (cur > root)
	{
		if (node[root][1] == 0)
		{
			node[root][1] = cur;
			return ;
		}
		else
			pre_order(cur, node[root][1]);
	}
	else if (cur < root)
	{
		if (node[root][0] == 0)
		{
			node[root][0] = cur;
			return ;
		}
		else
			pre_order(cur, node[root][0]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, root;

	root = -1;
	n = 0;

	while (1)
	{
		cin >> n;
		if (cin.eof() == 1)
			break;
		if (root == -1)
			root = n;
		else
			pre_order(n, root);
	}
	post_order(root);
}
