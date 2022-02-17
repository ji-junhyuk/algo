#include <iostream>
using namespace std;

using ll = long long;
ll MOD = 1000000007;

ll f(ll x, ll y)
{
	if (y == 1)
		return x;
	if (y % 2 == 1)
		return (x * f(x, y - 1) % MOD);
	ll p = f(x, y / 2);
	return (p * p % MOD);
}

ll find_gcd(ll a, ll b)
{
	ll temp, n;

	if (a < b)
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (b != 0)
	{
		n = a % b;
		a = b;
		b = n;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	ll M, N, S;
	ll ans = 0;

	cin >> M;
	while (M--)
	{
		cin >> S >> N;
		ll gcd = find_gcd(N, S);
		S /= gcd;
		N /= gcd;
		ans += N * f(S, MOD - 2) % MOD;
		ans %= MOD;
	}
	cout << ans;
}
