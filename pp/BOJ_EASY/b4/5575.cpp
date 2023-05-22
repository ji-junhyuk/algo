#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int a1, a2, a3, a4, a5, a6;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 3; ++idx)
	{
		cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
		if (a3 > a6)
		{
			a5--;
			a6 += 60;
		}
		int s = a6 - a3;
		if (a2 > a5)
		{
			a4--;
			a5 += 60;
		}
		int m = a5 - a2;
		int h = a4 - a1;
		cout << h << ' ' << m << ' ' << s << '\n';
	}
}
