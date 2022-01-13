#include <bits/stdc++.h>
using namespace std;

int p[101];

int find_p(int n)
{
	if (n <= 3)
		return 1;
	else if (p[n] == 0)
		p[n] = find_p(n - 2) + find_p(n - 3);
	return p[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int T, N;

	cin >> T;
	while (T--)
	{
		cin >> N;
		cout << find_p(N) << '\n';
	}
}
