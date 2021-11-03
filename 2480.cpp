#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A;
	int B;
	int C;
	int max;
	int arr[3];
	cin >> A >> B >> C;
	if (A == B && B == C)
	{
		cout << 10000 + A * 1000;
	}
	else if (A == B || B == C || A == C)
	{
		if (A == B || B == C)
			cout << 1000 + B * 100;
		else
			cout << 1000 + A * 100;
	}
	else
	{
		int i;
		int j;
		int temp;
		i = 0;
		while (i < 3)
		{
			j = 0;
			while (j < 2)
			{
				if (arr[j] > arr[j + 1])
				{
					temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
				j++;
			}
			i++;
		}
		cout << arr[2] * 100;
	}
}
