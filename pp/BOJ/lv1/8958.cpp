#include <bits/stdc++.h>
using namespace std;

char oxa[81];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T;
	int combo;
	int score;
	int idx;

	cin >> T;
	while (T--)
	{
		score = 0;
		combo = 1;
		idx = -1;
		cin >> oxa;
		while (oxa[++idx])
		{
			if (oxa[idx] == 'O')
			{
				score += combo;
				combo++;
			}
			else
				combo = 1;
		}
		cout << score << '\n';
	}		
}
