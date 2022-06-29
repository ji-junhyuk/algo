#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int a, b, c, d;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c >> d;

	if (a > b && b > c && c > d)
		cout << "Fish Diving";
	else if (a < b && b < c && c < d)
		cout << "Fish Rising";
	else if (a == b && b == c && c == d)
		cout << "Fish At Constant Depth";
	else
		cout << "No Fish";
}
