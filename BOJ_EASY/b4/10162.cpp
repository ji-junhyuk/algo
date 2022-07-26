#include <iostream>
using namespace std;

typedef long long ll;

int cnt[3];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T >= 300)
	{
		T -= 300;
		++cnt[0];
	}
	while (T >= 60)
	{
		T -= 60;
		++cnt[1];
	}
	while (T >= 10)
	{
		T -= 10;
		++cnt[2];
	}
	if (T)
		cout << -1;
	else
	{
		for (int i = 0; i < 3; i++) 
		{
			cout << cnt[i] << ' ';
		}
	}
}
