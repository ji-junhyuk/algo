#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	char arr[6];
	int number;
	int idx;
	int jdx;
	int length;
	int pell;

	idx = -1;
	while (++idx < 5)
		arr[idx] = -1;
	while (1)
	{
		cin >> number;
		if (!number)
			break;
		idx = -1;
		length = 0;
		while (number)
		{
			arr[++idx] = number % 10;
			number /= 10;
			length++;
		}
		idx = -1;
		jdx = length;
		pell = 1;
		while (++idx < length)
		{
			if (arr[idx] != arr[--jdx])
			   pell = 0;
		}	
		if (pell)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}
