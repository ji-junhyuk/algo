#include <iostream>
using namespace std;

int a, b;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b;
	if (a < 100)
	{
		cout << "1";
		return 0;
	}
	if ((a * (100 - b) / 100) >= 100)
		cout << "0";
	else
		cout << "1";
}
