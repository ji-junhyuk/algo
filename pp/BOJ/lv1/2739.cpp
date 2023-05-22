#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int idx;

	idx = 0;
	cin >> N;
	while (++idx < 10)
		cout << N << " * " << idx << " = " << N * idx << '\n';
}
