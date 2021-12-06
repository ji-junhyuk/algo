#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;

	int share;
	int remainder;
	int min;

	cin >> N;
	if (N % 5 == 0)
	{
		min = N / 5;
		cout << min;
		return 0;
	}	
	else
	{
		share = N / 5;
		while (share)
		{
			remainder = N - share * 5;
			if (remainder % 3 == 0)
			{
				min = share + remainder / 3;
				cout << min;
				return 0;
			}
			else
				share--;
		}
		if (N % 3 == 0)
			cout << N / 3;
		else
			cout << -1;
	}
}
