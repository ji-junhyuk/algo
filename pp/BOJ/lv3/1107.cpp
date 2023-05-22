#include <bits/stdc++.h>
using namespace std;

int button[10];
int is_possible(int num, int *length)
{
	if (num == 0)
	{
		(*length)++;
		if (button[num % 10] == 0)
			return 0;
	}
	while (num)
	{
		if (button[num % 10] == 0)
			return 0;
		(*length)++;
		num /= 10;
	}
	return 1;
}

int find_min(int num)
{
	int start_100;
	int min_value;
	int length;
	int temp;
	
   	start_100 = abs(num - 100);
	min_value = 1000000; // N 500,000일 때 3456금지, 700,000에서 찾는게 빠를 수 있다
	for (int idx = 0; idx <= 1000000; idx++)
	{
		length = 0;
		if (is_possible(idx, &length))
		{
			temp = 0;
		   	temp += length;
			temp += abs(idx - num);
			min_value = min(min_value, temp);
		}
	}
	return min(start_100, min_value);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int N, M;

	cin >> N >> M;
	for (int idx = 0; idx < 10; idx++)
		button[idx] = 1;
	while (M--)
	{
		int break_button;
		cin >> break_button;
		button[break_button] = 0;
	}
	cout << find_min(N) << '\n';
}
