#include <bits/stdc++.h>
using namespace std;

int number[10];
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	int i;
	int max;

	cin >> N;
	while (N)
	{
		number[N % 10]++;
		N /= 10;
	}
	number[6] = (number[6] + number[9] + 1) / 2;
	number[9] = 0;
	max = 1;
	i = -1;
	while (++i < 10)
		if (number[i] > max)
			max = number[i];
	cout << max;
}
