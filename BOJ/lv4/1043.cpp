#include <bits/stdc++.h>
using namespace std;

int parent[51];
int know_true[51];
int party[51][51];
int ans;

//union-find algo

int find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = find(parent[x]);
}

void uni(int x, int y)
{
	parent[find(y)] = find(x);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M; // 사람, 파티
	int TR; // 진실

	cin >> N >> M;
	cin >> TR;
	for (int idx = 1; idx <= N; idx++)
		parent[idx] = idx;
	for (int idx = 0; idx < TR; idx++)
		cin >> know_true[idx];
	for (int idx = 0; idx < M; idx++)
	{
		int num;
		cin >> num;
		cin >> party[idx][0];
		for (int jdx = 1; jdx <= num - 1; jdx++)
		{
			cin >> party[idx][jdx];
			uni(party[idx][0], party[idx][jdx]);
		}
	}
	for (int idx = 0; idx < M; idx++)
	{
		int ok = 1;
		for (int jdx = 0; jdx < TR; jdx++)
		{
			if (find(party[idx][0]) == find(know_true[jdx]))
			{
				ok = 0;
				break;
			}
		}
		if (ok)
			ans++;
	}
	cout << ans;
}
