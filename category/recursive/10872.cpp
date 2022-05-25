#include <iostream>
using namespace std;
typedef long long ll;

ll N;

ll recur(ll N)
{
	if (N == 0 || N == 1)
		return 1;
	return (N * recur(N - 1));
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cout << recur(N);
}
