#include <iostream>
using namespace std;
#define ll long long

ll N, T, C, P;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> T >> C >> P;

	ll cnt = (N - 1) / T;
	cout << (C * cnt * P);
	return (0);
}
