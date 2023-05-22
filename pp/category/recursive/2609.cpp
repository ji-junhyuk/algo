#include <iostream>
using namespace std;
typedef long long ll;

int find_gcd(int a, int b)
{
	if (b == 0)
		return (a);
	else
		return (find_gcd(b, a % b));
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
