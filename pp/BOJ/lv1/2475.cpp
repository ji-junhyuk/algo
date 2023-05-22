#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int sum;
	int number;

	number = 5;
	sum = 0;
	while (number--)
	{
		cin >> N;
		sum += (N * N);
	}
	cout << sum % 10;
}
