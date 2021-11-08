#include <bits/stdc++.h>
using namespace std;

int arr[101];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int i;
	int number;
	int v;
	int count;

	i = -1;
	cin >> N;
	while (++i < N)
	{
		cin >> number;
		arr[i] = number;
	}
	cin >> v;

	i = -1;
	count = 0;
	while (++i < N)
		if (arr[i] == v)
			count++;
	cout << count;
}
