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
	i = N;
	while (--i > 0)
	{
		j = -1;
		while (++j < N - i)
			cout << '*';
		j = -1;
		while (++j < (2 * i))
			cout << ' ';
		j = -1;
		while (++j < N - i)
			cout << '*';
		cout << '\n';
	}
	i = -1;
	while (++i < 2 * N)
		cout << '*';
	cout << '\n';
	
	i = 0;
	while (++i < N)
	{
		j = -1;
		while (++j < N - i)
			cout << '*';
		j = -1;
		while (++j < (2 * i))
			cout << ' ';
		j = -1;
		while (++j < N - i)
			cout << '*';
		cout << '\n';
	}
}
