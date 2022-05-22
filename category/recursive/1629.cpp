#include <iostream>
using namespace std;
#define ll long long

ll a, b, c;

ll pow(ll a, ll b, ll mod)
{
	if (b == 1)
		return (a % mod);
	ll value = pow(a, b / 2, mod);
	value = value * value % mod;
	if (b % 2)
		return value * a % mod;
	return (value);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	cout << pow(a, b, c);
}
