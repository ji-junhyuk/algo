#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
#include <string.h>
#include <list>
using namespace std;
#define ll long long

ll recur(ll a, ll b, ll m)
{
	if (b == 1)
		return (a % m);
	ll val = recur(a, b / 2, m);
	val = val * val % m;
	if (b % 2 == 0)
		return (val);
	return (val * a % m);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int A, B, M;
	cin >> A >> B >> M;
	cout << recur(A, B, M);
}
