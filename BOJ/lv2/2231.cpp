#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N;
	int idx;
	int length;
	int constructor;
	int temp;
	int temp2;
	int find;

	cin >> N;
	temp = N;
	find = 0;
	length = 0;
	while (temp)
	{
		temp /= 10;
		length++;
	}
	if (length == 1)
		temp = 1;
	else
		temp = N - (length * 9);
 	for (temp; temp < N; temp++)
 	{
 		temp2 = temp;
 		constructor = 0;
 		while (temp2)
 		{
 			constructor += temp2 % 10;
 			temp2 /= 10;
 		}
		if (N == (temp + constructor))
		{
			find = 1;
			cout << temp;
			break;
		}
	}
	if (!find)
		cout << '0';
}
