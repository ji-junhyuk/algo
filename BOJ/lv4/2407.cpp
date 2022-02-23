/*
0C0= 1
1C0= 1, 1C0 = 1
2C0 = 1, 2C1 = 2, 2C2 = 1
3C0 = 1, 3C1 = 3, 3C2 = 3, 3C3 =1
4C0 = 1, 4C1 = 4, 4C2 = 6, 4C3 = 4, 4C4 =1

파스칼 알고리즘
dp[n][r] = dp[n - 1][r - 1] + dp[n - 1][r];
*/

#include <iostream>
#include <string.h>
using namespace std;

string dp[101][101];
int n, m;

string add_num(string a, string b)
{
	string result = "";
	if (a.length() > b.length())
	{
		while (a.length() != b.length())
			b = '0' + b;
	}
	else
	{
		while (a.length() != b.length())
			a = '0' + a;
	}
	int sum = 0;
	for (int idx = a.length() - 1; idx >= 0; idx--)
	{
		sum += a[idx] - '0';
		sum += b[idx] - '0';
		result = to_string(sum % 10) + result;
		if (sum >= 10)
			sum = 1;
		else
			sum = 0;
	}
	if (sum == 1)
		return '1' + result;
	return result;
}

void make_dp(void)
{
	dp[0][0] = "1";
	dp[1][0] = "1";
	dp[1][1] = "1";
	for (int idx = 2; idx <= n; idx++)
	{
		for (int jdx = 0; jdx <= m; jdx++)
		{
			if (idx == jdx || jdx == 0)
				dp[idx][jdx] = "1";
			else
				dp[idx][jdx] = add_num(dp[idx - 1][jdx - 1], dp[idx - 1][jdx]);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	make_dp();
	cout << dp[n][m];
	return (0);
}
