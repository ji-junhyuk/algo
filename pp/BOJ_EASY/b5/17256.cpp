#include <iostream>
using namespace std;
#define ll long long

ll a1, a2, a3;
ll c1, c2, c3;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a1 >> a2 >> a3 >> c1 >> c2 >> c3;
	cout << c1 - a3 << ' ' << c2 / a2 << ' ' << c3 - a1;
}
