#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int cnt = 0;
	int init = 666;
	int temp;

	cin >> N;
	while (true)
	{
		temp = init;
		do
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			temp /= 10;
		} while (temp > 0);
		
		if (cnt == N)
		{
			cout << init << '\n';
			break;
		}
		init++;
	}
}
