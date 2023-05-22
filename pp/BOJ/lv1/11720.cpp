#include <bits/stdc++.h>
using namespace std;

char arr[101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int sum;
	int idx;

	sum = 0;
	cin >> N;
	idx = -1;
	cin >> arr;
	while (++idx < N)
		sum += arr[idx] - '0';
	cout << sum;
}
