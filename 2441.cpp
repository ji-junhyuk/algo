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
	i = -1;
	while (++i < N)
	{
		j = -1;
		while (++j < i)
			cout << ' ';
		j = -1;
		while (++j < N - i)
			cout << '*';
		cout << '\n';
	}
}
