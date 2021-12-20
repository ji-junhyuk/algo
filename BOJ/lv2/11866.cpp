#include <bits/stdc++.h>
using namespace std;

int pre[1001];
int nxt[1001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v;
	int N, K;
	int len;
	
	cin >> N >> K;
	len = 0;
	for (int idx = 1; idx <= N; idx++)
	{
		pre[idx] = (idx == 1) ? N : idx - 1;
		nxt[idx] = (idx == N) ? 1 : idx + 1;
		len++;
	}

	int idx = 1;
	for (int cur = 1; len != 0; cur = nxt[cur])
	{
		if (idx == K)
		{
			pre[nxt[cur]] = pre[cur];
			nxt[pre[cur]] = nxt[cur];
			v.push_back(cur);
			len--;
			idx = 1;
		} 
		else
			idx ++;
	}
	cout << '<';
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i];
		if (i != v.size() - 1)
			cout << ", ";
	}
	cout << '>';
}
