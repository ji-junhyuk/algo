#include <iostream>
#include <list>
using namespace std;
typedef long long ll;

int a, b, c;
int result;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;
	result = 91;
	result += (a * 1 + b * 3 + c * 1);
		cout << "The 1-3-sum is " << result;
}
