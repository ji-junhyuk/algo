#include <bits/stdc++.h>
using namespace std;

long long memo[40] = {0, 1, };
long long fibo(int n)
{
	if (n == 0 || n == 1)
		return memo[n];
	else if (memo[n] == 0)
		memo[n] = fibo(n - 1) + fibo(n - 2);
	return memo[n];
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	/*
	   N = 0, 1 0
	   N = 1, 0 1
	   N = 2, 1 1
	   N = 3, 1 2
	   N = 4, 2 3
	*/
	int T;

	cin >> T;
	while (T--)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
			cout << "1 0\n";
		else
			cout << fibo(temp - 1) << ' ' << fibo(temp) << '\n';
	}
}
