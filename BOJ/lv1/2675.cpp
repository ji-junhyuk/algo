#include <bits/stdc++.h>
using namespace std;

char character[21];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int T;
	int idx;
	int R;
	int r;

	cin >> T;
	while (T--)
	{
		cin >> R;
		cin >> character;
		idx = -1;
		while (character[++idx])
		{
			r = R;
			while (r-- > 0)
				cout << character[idx];
			if (!character[idx + 1])
				break ;
		}
		cout << '\n';
	}
}
