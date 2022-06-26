#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int d, h, m;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int minutes = 0;
	cin >> d >> h >> m;
	if (m < 11)
	{
		h--;
		m += 60;
	}
	m -= 11;
	if (h < 11)
	{
		d--;
		h += 24;
	}
	h -= 11;
	m += (h * 60);
	m += (d - 11) * 1440;
	if (m < 0)
		cout << -1;
	else
		cout << m;
}
