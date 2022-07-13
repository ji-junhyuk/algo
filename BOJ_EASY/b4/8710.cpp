#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;

ll k, m, w;
ll cnt;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> m >> w;
	int differ = m - k;
	while (1)
	{
		++cnt;
		differ -= w;
		if (differ <= 0)
			break ;
	}
	cout << cnt;
}
