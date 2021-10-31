#include <iostream>
using namespace std;

int func4(int N)
{
	int power;
	int result;

	if (N < 2)
		return 1;
	result = 2;
	power = 2;
	while (result * power <= N)
		result *= power;
	return result;
}

int main()
{
	int N;

	cin >> N;
	cout << func4(N);
}
