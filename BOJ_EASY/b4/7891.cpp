#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;

	cin >> T;
	for (int idx = 0; idx < T; ++idx)
	{
		long long x, y;
		cin >> x >> y;
		cout << x + y << '\n';
	}
}

