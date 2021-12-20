#include <bits/stdc++.h>
using namespace std;

int is_prime(int number)
{
	int idx;

	if (number == 1)
		return 0;
	if (number == 2 || number == 3)
		return 1;
	idx = 1;
	while (++idx * idx <= number)
	{
		if (number % idx == 0)
			return 0;
	}
	return 1;
}
	
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int temp;
	int cnt;

	cin >> N;
	cnt = 0;
	while (N--)
	{
		cin >> temp;
		if (is_prime(temp))
			cnt++;
	}
	cout << cnt;
}
