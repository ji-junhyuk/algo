#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll x, k, num;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> x >> k;
	x *= 1000;

	if (7000 * k <= x)
		k = 7000 * k;
	else if (3500 * k <= x)
		k = 3500 * k;
	else if (1750 * k <= x)
		k = 1750 * k;
	else
		k = 0;
	cout << k;
}
