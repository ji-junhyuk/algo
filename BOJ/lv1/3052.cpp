#include <bits/stdc++.h>
using namespace std;

int arr[10];
int devide[41];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx;
	int count;

	count = 0;
	idx = -1;
	while (++idx < 10)
		cin >> arr[idx];
	idx = -1;
	while (++idx < 10)
		arr[idx] = arr[idx] % 42;
	idx = -1;
	while (++idx < 10)
		devide[arr[idx]]++;
	idx = -1;
	while (++idx < 42)
		if (devide[idx] > 0)
			count++;
	cout << count;
}
