#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int arr[6];
int max;
int Min;
int sum;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 6; ++idx) 
	{
		cin >> arr[idx];
		sum += arr[idx];
	}
	Min = 123;
	for (int idx = 0; idx < 4; ++idx) 
	{
		if (arr[idx] < Min)
			Min = arr[idx];
	}
	sum -= Min;
	Min = 123;
	for (int idx = 4; idx < 6; ++idx) 
	{
		if (arr[idx] < Min)
			Min = arr[idx];
	}
	sum -= Min;
	cout << sum;
}
