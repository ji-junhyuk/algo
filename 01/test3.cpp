#include <iostream>
using namespace std;
int	func(int N)
{
	int i;

	i = 2;
	if (N == 1)
		return 1;
	while (i <= N / i)
	{
		if (i * i == N)
			return 1;
		i++;
	}
	return 0;
}

int main()
{
	cout << func(756580036);
}
