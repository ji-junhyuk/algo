#include <bits/stdc++.h>
using namespace std;

int cnt;
void hanoi2(int a, int b, int N)
{
	cnt++;
	if (N == 1)
		return ;
	else
	{
		hanoi2(a, 6 - a - b, N - 1);
		hanoi2(6 - a - b, b, N - 1);
	}
}

void hanoi(int a, int b, int N)
{
	if (N == 1)
		cout << a << ' ' << b << '\n';
	else
	{
		hanoi(a, 6 - a - b, N - 1);
		cout << a << ' ' << b << '\n';
		hanoi(6 - a - b, b, N - 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	cin >> N;
	hanoi2(1, 3, N);
	cout << cnt << '\n';
	hanoi(1, 3, N);
}
