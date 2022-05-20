#include <iostream>
using namespace std;
#define MAX_DAY 100000

int N, M;
int cost[MAX_DAY];
int	low, high, mid;
int	money;
int Max;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> cost[idx];
		if (low < cost[idx])
			low = cost[idx];
		high += cost[idx];
	}
	while (low <= high)
	{
		mid = (low + high) / 2;
		money = mid;
		int cnt = 1;
		for (int idx = 0; idx < N; ++idx)
		{
			money -= cost[idx];
			if (money <= 0)
			{
				money = mid - cost[idx];
				++cnt;
			}
		}
		if (cnt > M)
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout << mid;
}
