#include <iostream>
using namespace std;
#define ll long long

ll N;
ll cnt;

void hanoi_cnt(int a, int c, int num)
{
	++cnt;
	if (num == 1)
		return ;
	else
	{
		hanoi_cnt(a, 6 - a - c, num - 1);
		hanoi_cnt(6 - a - c, c, num - 1);
	}
}

void hanoi(int a, int c, int num)
{
	if (num == 1)
		cout << a << ' ' << c << '\n';
	else
	{
		hanoi(a, 6 - a - c, num - 1);
		cout << a << ' ' << c << '\n';
		hanoi(6 - a - c, c, num - 1);
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	hanoi_cnt(1, 3, N);
	cout << cnt << '\n';
	hanoi(1, 3, N);
}
