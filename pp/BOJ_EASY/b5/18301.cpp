#include <iostream>
using namespace std;
typedef long long ll;

ll n1, n2, n3;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n1 >> n2 >> n3;
	cout << ((n1 + 1) * (n2 + 1)) / (n3 + 1) - 1;
}
