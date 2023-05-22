#include <iostream>
using namespace std;
typedef long long ll;

int	A, B, C;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B >> C;
	if (B + C < 60)
		cout << A << ' ' << (B + C);
	else
	{
		if (A + ((B + C) / 60 ) >= 24)
			cout << A + ((B + C) / 60) - 24 << ' ' << (B + C) % 60;
		else
			cout << (A + (B + C) / 60) << ' ' << (B + C) % 60;
	}
}
