#include <iostream>
using namespace std;
typedef long long ll;
#define MAX 100000

ll n;
ll memo[MAX];

ll recur(ll index)
{
	if (index <= 1)
		return (index);
	if (memo[index])
		return (memo[index]);
	memo[index] = recur(index - 2) + recur(index - 1);
	return (memo[index]);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	cout << recur(n);
}
