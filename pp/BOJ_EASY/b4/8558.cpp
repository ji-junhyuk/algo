#include <iostream>
using namespace std;

int n;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int result = 1;
	for (int idx = 1; idx <= n; ++idx)
	{
		result *= idx;
		result %= 10;
	}
	cout << result;
}
