#include <iostream>
#include <stack>
#include <queue>
using namespace std;
typedef long long ll;

int arr[4];
int ans;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	for (int idx = 0; idx < 4; ++idx) 
		cin >> arr[idx];
	int x, y, r;
	cin >> x >> y >> r;
	for (int idx = 0; idx < 4; ++idx) 
	{
		if (arr[idx] == x)
		{
			ans = idx + 1;
		}
	}
	cout << ans;
}
