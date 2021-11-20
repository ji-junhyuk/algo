#include <bits/stdc++.h>
using namespace std;

void hanoi2(int a, int b, int N, int *cnt)
{
	(*cnt)++;
	if (N == 1)
		return ;
	else
	{
		hanoi2(a, 6 - a - b, N - 1, cnt);
		hanoi2(6 - a - b, b, N - 1, cnt);
	}
}

void hanoi(int a, int b, int N)
{
	if (N == 1)
		cout << a << '*' << ' ' << b << '\n';
	else
	{
		hanoi(a, 6 - a - b, N - 1);
		cout << a << '&' << ' ' << b << '\n';
		hanoi(6 - a - b, b, N - 1);
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int cnt;

	cnt = 0;
	cin >> N;
	hanoi2(1, 3, N, &cnt);
	cout << cnt << '\n';
	hanoi(1, 3, N);
}
