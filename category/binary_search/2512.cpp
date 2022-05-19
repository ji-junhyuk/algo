#include <iostream>
#define MAX_BUDGET 1000000000
#define MAX_REGION 10000
using namespace std;

int N, M;
int region[MAX_REGION];
int	Max, temp, low, high, center, ans, sum;

int find_sum(int cost)
{
	int sum = 0;

	for (int idx = 0; idx < N; idx++)
	{
		if (region[idx] <= cost)
			sum += region[idx];
		else
			sum += cost;
	}
	if (sum <= M)
		return (1);
	else
		return (0);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> region[idx];
		if (Max < region[idx])
			Max = region[idx];
		sum += region[idx];
	}
	cin >> M;
	if (sum <= M)
		cout << Max;
	else
	{
		low = 0;
		high = Max;
		while (low <= high)
		{
			center = (low + high) / 2;
			if (find_sum(center))
			{
				ans = center;
				low = center + 1;
			}
			else
				high = center - 1;
		}
		cout << ans;
	}
}
