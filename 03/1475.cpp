#include <bits/stdc++.h>
using namespace std;

char N[1000001];
int number[10];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int i;
	int max;

	cin >> N;

	i = -1;
	while (++i < 1000001)
		number[N[i] - '0']++; 
	max = 0;
	i = -1;
	while (++i < 10)
	{
		if (max < number[i])
			max = number[i];
	}
	if (max == number[6] || max == number[9])
	{
		max = number[6] + number[9];
		if (max % 2)
			cout << 1 + (max /= 2);
		else
			cout << (max /= 2);
	}
	else
		cout << max;
}
