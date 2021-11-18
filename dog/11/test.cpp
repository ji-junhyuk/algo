#include <bits/stdc++.h>
using namespace std;

long long func1(int a, int b, int m)
{
	long long init;
   
	init = 1;
	while (b--)
		init = init * a % m;
	return init;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int a;
	int b;
	int c;
	cin >> a >> b >> c;
	cout << func1(a, b, c);
}
