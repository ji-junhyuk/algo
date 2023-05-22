#include <bits/stdc++.h>
using namespace std;

char num1[4];
char num2[4];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int A;
	int B;
	int idx;
	int result_a;
	int result_b;

	cin >> A >> B;
	idx = -1;
	while (A)
	{
		num1[++idx] = A % 10;
		A /= 10;
	}
	idx = -1;
	while (B)
	{
		num2[++idx] = B % 10;
		B /= 10;
	}
	idx = -1;
	result_a = 0;
	while (++idx < 3)
	{
		result_a *= 10;
		result_a += num1[idx];
	}
	idx = -1;
	result_b = 0;
	while (++idx < 3)
	{
		result_b *= 10;
		result_b += num2[idx];
	}
	if (result_a > result_b)
		cout << result_a;
	else
		cout << result_b;
}
