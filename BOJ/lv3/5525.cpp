#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M;
	string S;

	cin >> N >> M >> S;
	int pn_cnt = 0;
	for (int idx = 0; idx < M; idx++)
	{
		if (S[idx] == 'O')
			continue;
		int o_cnt = 0;
		while (S[idx + 1] == 'O' && S[idx + 2] == 'I')
		{
			o_cnt++;
			if (o_cnt == N)
			{
				o_cnt--;
				pn_cnt++;
			}
			idx += 2;
		}
	}
	cout << pn_cnt;
}
