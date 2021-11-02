#include <iostream>
using namespace std;

int arr[10000];

int	main(void)
{
	int N;
	int X;
	int i;

	cin >> N >> X;
	i = 1;
	while (i <= N)
	{
		cin >> arr[i];
		i++;
	}
	i = 1;
	while (i <= N)
	{
		if (arr[i] < X)
			cout << arr[i];
		i++;
	}
}


