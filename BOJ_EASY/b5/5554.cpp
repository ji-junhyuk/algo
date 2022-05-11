#include <iostream>
using namespace std;

int arr[4];
int sum;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 4; ++idx)
	{
		int temp;
		cin >> temp;
		sum += temp; 
	}
	cout << sum / 60 << '\n' << sum % 60;
}
