#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int arr[3];
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> arr[0] >> arr[1] >> arr[2];

	int eq_tri = 0;
	int r_tri = 0;
	if (arr[0] == arr[1] && arr[1] == arr[2])
		eq_tri = 1;
	sort(arr, arr + 3);
	if (arr[2] * arr[2] == (arr[0] * arr[0] + arr[1] * arr[1]))
		r_tri = 1;
	if (eq_tri)
		cout << 2;
	else if (r_tri)
		cout << 1;
	else
		cout << 0;
}
