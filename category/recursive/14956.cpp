#include <iostream>
using namespace std;
typedef long long ll;

ll n, m;

pair<ll, ll> recur(ll n, ll m)
{
	pair<ll, ll> coord;

	if (n == 2)
	{
		if (m == 0)
		{
			coord.first = 1; coord.second = 1;
			return (coord);
		}
		if (m == 1)
		{
			coord.first = 1; coord.second = 2;
			return (coord);
		}
		if (m == 2)
		{
			coord.first = 2; coord.second = 2;
			return (coord);
		}
		if (m == 3)
		{
			coord.first = 2; coord.second = 1;
			return (coord);
		}
	}
	ll new_n = (n >> 1);
	ll quadrant = m / (new_n * new_n);
	ll new_m = m % (new_n * new_n);
	coord = recur(new_n, new_m);
	if (quadrant == 0)
	{
		swap(coord.first, coord.second);
		return (coord);
	}
	if (quadrant == 1)
	{
		coord.second += new_n;
		return (coord);
	}
	if (quadrant == 2)
	{
		coord.first += new_n; coord.second += new_n;
		return (coord);
	}
	ll temp;
	temp = coord.first;
	coord.first = 2 * new_n - coord.second + 1; 
	coord.second = new_n - temp + 1;
	return (coord);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	pair<ll, ll> ans = recur(n, m - 1);
	cout << ans.first << ' ' << ans.second;
	return (0);
}
