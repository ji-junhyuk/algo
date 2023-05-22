#include <iostream>
using namespace std;
#define MAX_CNT 100000

int N, M;
int sum;
int	high, low, mid;
int	cnt;
int lecture[MAX_CNT];

int	find_cnt(int mid)
{
	sum = 0;
	cnt = 1;
	for (int idx = 0; idx < N; ++idx)
	{
		if (sum + lecture[idx] > mid)
		{
			sum = 0;
			++cnt;
		}
		sum += lecture[idx];
	}
	return (cnt);
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	for (int idx = 0; idx < N; ++idx)
	{
		cin >> lecture[idx];
		sum += lecture[idx];
		if (low < lecture[idx])
			low = lecture[idx];
	}
	high = sum;
	while (low <= high)
	{
		mid = (low + high) / 2;
		cnt = find_cnt(mid);
		if (cnt <= M)
			high = mid - 1;
		else
			low = mid + 1;
	}
	cout << low;
	return (0);
}
