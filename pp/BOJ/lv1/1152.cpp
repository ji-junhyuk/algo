#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string a;
	getline(cin, a);
	int idx;
	int count;

	count = 1;
	idx = -1;
	while (a[++idx])
	{
		if (idx == 0 && a[idx] == ' ' && !a[idx + 1])
			count--;
		if (idx == 0 && a[idx] == ' ')
			idx++;
		if (a[idx] == ' ' && a[idx + 1])
			count++;
	}
	cout << count;
}
