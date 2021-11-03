#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[12];
	int i = 0;
	int sum = 0;
	int sum2 = 0;
	int sum3 = 0;
	while (i < 12)
	{
		cin >> arr[i];
		i++;
	}
	i = 0;
	while (i < 12)
	{
		if (i < 4)
			sum += arr[i];
		else if (i < 8)
			sum2 += arr[i];
		else
			sum3 += arr[i];
		i++;
	}
	if (sum == 0)
		cout << "D";
	else if (sum == 1)
		cout << "C";
	else if (sum == 2)
		cout << "B";
	else if (sum == 3)
		cout << "A";
	else
		cout << "E";
	cout << '\n';
	if (sum2 == 0)
		cout << "D";
	else if (sum2 == 1)
		cout << "C";
	else if (sum2 == 2)
		cout << "B";
	else if (sum2 == 3)
		cout << "A";
	else
		cout << "E";
	cout << '\n';
	if (sum3 == 0)
		cout << "D";
	else if (sum3 == 1)
		cout << "C";
	else if (sum3 == 2)
		cout << "B";
	else if (sum3 == 3)
		cout << "A";
	else
		cout << "E";
}
