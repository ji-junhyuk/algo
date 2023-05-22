#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long n;
	cin >> n;
	long long min;
	long long sum;
	int level;
	
	level = 0;
	sum = 2;
	while (sum <= n)
	{
		sum += 6 * level;
		level++;
	}
	if (n == 1)
		level = 1;
	cout << level;
	return (0);
}
