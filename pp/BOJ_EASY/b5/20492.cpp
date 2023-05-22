#include <iostream>
using namespace std;
typedef long long ll;

ll N;
ll a, b;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	a = N * 0.78;
	b = N - (N * 0.2 * 0.22);
	cout << a << ' ' << b;
}
