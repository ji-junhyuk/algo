#include <bits/stdc++.h>
using namespace std;

int lower[26];
char alpha[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx;
	int	sum;

	cin >> alpha;
	idx = -1;
	while (alpha[++idx])
		lower[alpha[idx] - 'a']++;
	cin >> alpha;
	idx = -1;
	while (alpha[++idx])
		lower[alpha[idx] - 'a']--;
	idx = -1;
	sum = 0;
	while (++idx < 26)
	{
		if (lower[idx] < 0)
			lower[idx] *= -1;
		sum += lower[idx];
	}
	cout << sum;
}
