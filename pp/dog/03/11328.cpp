#include <bits/stdc++.h>
using namespace std;

char alpha[1001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int idx;
	int jdx;
	int is_possible;
	int lower[26];

	cin >> N;
	idx = -1;
	while (++idx < N)
	{
		jdx = -1;
		is_possible = 1;
		while (++jdx < 26)
			lower[jdx] = 0;
		cin >> alpha;
		jdx = -1;
		while (alpha[++jdx])
			lower[alpha[jdx] - 'a']++;
		cin >> alpha;
		jdx = -1;
		while (alpha[++jdx])
			lower[alpha[jdx] - 'a']--;
		jdx = -1;
		while (++jdx < 26)
			if (lower[jdx] != 0)
				is_possible = 0;
		if (is_possible)
			cout << "Possible\n";
		else
			cout << "Impossible\n";
	}
}
