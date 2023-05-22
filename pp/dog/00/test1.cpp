#include <iostream>
using namespace std;
int solution(int arr[])
{
	int	max;
	int i;

	max = arr[0];
	i = 0;
	while (arr[i])
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return max;
}

int solution2(int arr[])
{
	return *max_element(arr, arr + 4);
}
