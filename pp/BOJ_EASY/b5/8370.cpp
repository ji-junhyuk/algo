#include <iostream>
using namespace std;

int n1, k1, n2, k2;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n1 >> k1 >> n2 >> k2;
	cout << n1 * k1 + n2 * k2;
}
