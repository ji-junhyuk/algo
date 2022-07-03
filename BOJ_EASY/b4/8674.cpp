#include <iostream>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long long a, b;
	cin >> a >> b;
	
	if (a % 2 && b % 2)
	{
		if (a < b)
			cout << a;
		else
			cout << b;
	}
	else
		cout << 0;
}
