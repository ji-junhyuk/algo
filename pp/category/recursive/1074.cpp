#include <iostream>
using namespace std;
#define ll long long

ll N, r, c;

ll recur(ll N, ll r, ll c)
{
	if (N == 0)
		return (0);
	ll square_side = 1 << (N - 1);
	if (r < square_side && c < square_side)
		return recur(N - 1, r, c);
	if (r < square_side && c >= square_side)
		return (square_side * square_side + (recur(N - 1, r, c - square_side)));
	if (r >= square_side && c < square_side)
		return (2 * square_side * square_side + recur(N - 1, r - square_side, c));
	return (3 * square_side * square_side + recur(N - 1, r - square_side, c - square_side));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> r >> c;
	cout << recur(N, r, c);
}
