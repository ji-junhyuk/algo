#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[20];
	int N;
	int i;
	int Y;
	int M;

	cin >> N;
	Y = 0;
	M = 0;
	i = -1;
	while (++i < N)
		cin >> arr[i];
	i = -1;
	while (++i < N)
		Y += (10 + (arr[i] / 30) * 10);
	i = -1;
	while (++i < N)
		M += (15 + (arr[i] / 60) * 15);
	if (Y > M)
		cout << 'M' << ' ' << M;
	else if (Y < M)
		cout << 'Y' << ' ' << Y;
	else
		cout << 'Y' << ' ' << 'M' << ' ' << Y;
}
