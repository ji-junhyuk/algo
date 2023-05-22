#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
typedef long long ll;

int Z, W, K;
int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> Z;
	int space;
	while (Z--)
	{
		int cnt = 0;
		cin >> W >> K;
		space = (W * K);
		cout << space / 2 << '\n';
	}
}
