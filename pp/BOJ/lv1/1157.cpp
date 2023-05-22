#include <bits/stdc++.h>
using namespace std;

char arr[1000001];
int alpha[26];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int idx;
	int count;
	int number;
	char max;
	
	count = 0;
	max = 0;
	number = 0;
	idx = -1;
	cin >> arr;
	while (arr[++idx])
	{
		if (arr[idx] >= 'a' && arr[idx] <= 'z')
			arr[idx] = arr[idx] - 'a' + 'A';
		alpha[arr[idx] - 'A']++;
	}
	idx = -1;
	while (++idx < 26)
	{
		if (alpha[idx] > count)
		{
			count = alpha[idx];
			max = idx + 'A';
		}
	}
	idx = -1;
	while (++idx < 26)
	{
		if (alpha[idx] == count)
			number++;
	}
	if (number == 1)
		cout << max;
	else
		cout << '?';
}
