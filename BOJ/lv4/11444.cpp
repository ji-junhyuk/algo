#include <bits/stdc++.h>
using namespace std;

long long n;
long long mod = 1000000007;
typedef vector<vector<long long>> matrix;

matrix operator *(matrix &a, matrix &b)
{
	matrix c(2, vector<long long>(2));

	for (int idx = 0; idx < 2; idx++)
	{
		for (int jdx = 0; jdx < 2; jdx++)
		{
			for (int kdx = 0; kdx < 2; kdx++)
				c[idx][jdx] += (a[idx][kdx] * b[kdx][jdx]);
			c[idx][jdx] %= mod;
		}
	}
	return c;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	matrix ans = {{1, 0}, {0, 1}};
	matrix a = {{1, 1}, {1, 0}};
	while (n > 0)
	{
		if (n % 2)
			ans = ans * a;
		a = a * a;
		n /= 2;
	}
	cout << ans[0][1] << '\n';
}
