#include <iostream>
using namespace std;

int	X;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> X;
	X++;
	cout << 2 * X << ' ' << 3 * X;
}
