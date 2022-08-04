#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int arr[4];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int idx = 0; idx < 4; ++idx) 
		cin >> arr[idx];
	sort(arr, arr + 4);
	int diff = (arr[0] + arr[3]) - (arr[1] + arr[2]);
	if (diff < 0)
		diff *= -1;
	cout << diff;
}
