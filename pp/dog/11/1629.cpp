#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fow(int a, int b, int c)
{
	ll remainder;

	if (b == 1)
	{
		cout << a << c << '\n';
		return a % c;
	}
	remainder = fow(a, b / 2, c);
	remainder = remainder * remainder % c;
	if (b % 2)
		remainder = remainder * a % c;
	return remainder;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a;
	int b;
	int c;
	
	cin >> a >> b >> c;
	cout << fow(a, b, c);
}
