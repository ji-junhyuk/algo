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
	int idx;
	
	idx = 0;
	sum = 2;
	while (sum <= n)
	{
		sum += 6 * idx;
		idx++;
	}
	if (n == 1)
		idx = 1;
	cout << idx;
	return (0);
}
