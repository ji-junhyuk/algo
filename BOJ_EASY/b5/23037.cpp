#include <iostream>
#include <math.h>
using namespace std;
typedef long long ll;

int	number;
int sum;
int five_mult;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> number;
	while (number)
	{
		five_mult = number % 10;
		sum += pow(five_mult, 5);
		number /= 10;
	}
	cout << sum << '\n';
}
