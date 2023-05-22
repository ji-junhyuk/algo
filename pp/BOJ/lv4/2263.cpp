#include <bits/stdc++.h>
using namespace std;

int in_order[100001];
int post_order[100001];
int pos[100001];

void	solve(int start, int end, int post_start, int post_end)
{
	if (start > end || post_start > post_end)
		return ;
	int root = post_order[post_end];
	cout << root << ' ';
	int p = pos[root];
	int left = p - start;
	solve(start, p - 1, post_start, post_start + left - 1);
	solve(p + 1, end, post_start + left, post_end - 1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	for (int idx = 0; idx < n; idx++)
		cin >> in_order[idx];
	for (int jdx = 0; jdx < n; jdx++)
	{
		cin >> post_order[jdx];
		pos[in_order[jdx]] = jdx;
	}
	solve(0, n - 1, 0, n - 1);
}
