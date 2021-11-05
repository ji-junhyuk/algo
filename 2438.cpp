#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int j;
	int N;

	cin >> N;
	i = -1;
	while (++i < N)
	{
		j = -2;
		while (++j < i)
			cout << '*';
		cout << '\n';
	}
}
