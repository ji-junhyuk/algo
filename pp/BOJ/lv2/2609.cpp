#include <bits/stdc++.h>
using namespace std;

int find_gcd(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int find_lcm(int a, int b, int gcd)
{
	return (a * b) / gcd;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	int gcd;
	int lcm;

	cin >> a >> b;
	gcd = find_gcd(a, b);
	lcm = find_lcm(a, b, gcd);

	cout << gcd << '\n' << lcm;
}
