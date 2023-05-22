#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 200000

long long	N, C;
long long	house[MAX];
long long	low, high, mid;
long long	router;
long long	ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> C;
	for (int idx = 0; idx < N; ++idx)
		cin >> house[idx];
	sort(house, house + N); 
	high = house[N - 1];
	while (low <= high)
	{
		router = 1;
		int pre_idx = 0;
		mid = (low + high) / 2;
		for (int idx = 1; idx < N; ++idx)
		{
			if (house[idx] - house[pre_idx] >= mid)
			{
				pre_idx = idx;
				router++;
			}
		}
		if (router >= C)
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << ans;
}
