#include <iostream>
using namespace std;
#define MAX_CNT 10000

long long N, M;
long long lan_line[MAX_CNT];
long long low, high, mid;
long long cnt;
long long ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> lan_line[idx];
		if (high < lan_line[idx])
			high = lan_line[idx];
	}
	low = 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = 0;
		for (int idx = 0; idx < N; ++idx)
			cnt += (lan_line[idx] / mid);
		if (cnt >= M)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
}
