#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long A;
	long long B;
	cin >> A >> B;
	if (A < B)
		cout << B - A - 1 << '\n';
	else if (A > B) 
		cout << A - B - 1 << '\n';
	else
		cout << 0 << '\n';
	long long i;
	if (A < B)
	{
		i = A;
		while (++i < B)
			cout << i << ' ';
	}
	else
	{
		i = B;
		while (++i < A)
			cout << i << ' ';
	}
}
