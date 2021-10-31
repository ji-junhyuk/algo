#include <iostream>
using namespace std;

int main()
{
	int N;
	int sum;
	int i;

	cin >> N;
	sum = 0;
	i = 1;
	while (i <= N)
	{
		if (i % 3 == 0 || i % 5 == 0)
			sum += i;
		i++;
	}
	cout << sum;
}
