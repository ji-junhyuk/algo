#include <iostream>
#include <vector>
#define MAX 56
using namespace std;

long long A, B;
long long subtotal[MAX];

long long find_one(long long n)
{
	vector<int> v;
	long long temp = n;
	while (temp != 0) 
	{
		v.push_back(temp % 2);
		temp /= 2;
	}
	long long ans = 0;
	for (int idx = (int)v.size() - 1; idx >= 0; idx--)
	{
		if (v[idx] == 1)
		{
			ans += subtotal[idx - 1] + n - ((long long)1 << idx) + 1;
			n -= ((long long)1 << idx);
		}
	}
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	subtotal[0] = 1;
	for (int idx = 1; idx <= 55; ++idx)
		subtotal[idx] = subtotal[idx - 1] * 2 + ((long long)1 << idx);
	cout << find_one(B) - find_one(A - 1);
}
