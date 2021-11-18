#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int i;
	int j;

	cin >> N;
	i = N + 1;
	while (--i > 0)
	{
		j = 0;
		while (j++ < N - i)
			cout << ' ';
		j = -1;
		while (++j < (2 * i - 1))
			cout << '*';
		cout << '\n';
	}
	i = 1;
	while (++i < N + 1)
	{
		j = 0;
		while (++j < N + 1 - i)
			cout << ' ';
		j = -1;
		while (++j < (2 * i - 1))
			cout << '*';
		cout << '\n';
	}
}
