#include <iostream>
#include <algorithm>
using namespace std;

long long	N, K;
long long	low, high, mid;
long long	cnt, ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	low = 1;
	high = K;
	while (low <= high)
	{
		cnt = 0;
		mid = (low + high) / 2;
		for (int idx = 1; idx <= N; ++idx)
			cnt += min(mid / idx, N);
		if (cnt >= K)
		{
			ans = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << ans << '\n';
	return (0);
}
