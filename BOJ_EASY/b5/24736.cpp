#include <iostream>
using namespace std;

int a, b, c, d, e;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c >> d >> e;
	cout << ((a * 6) + (b * 3) + (c * 2) + (d * 1) + (e * 2)) << ' ';
	cin >> a >> b >> c >> d >> e;
	cout << ((a * 6) + (b * 3) + (c * 2) + (d * 1) + (e * 2));
	
}
