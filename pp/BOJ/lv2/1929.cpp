#include <bits/stdc++.h>
using namespace std;

int is_prime(int n)
{
	int idx;
	if (n == 1)
		return 0;
	if (n == 2 || n == 3)
		return 1;
	idx = 1;
	while (++idx * idx <= n)
	{
		if (n % idx == 0)
			return 0;
	}
	return 1;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int M, N;
	
	cin >> M >> N;

	for (int idx = M; idx <= N; idx++)
	{
		if (is_prime(idx))
			cout << idx << '\n';
	}
}
